#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_socket(new QUdpSocket(this)),
    m_openState(false),
    m_airID(0x10),
    m_QueryState(false),
    m_newRecvCmdFlag(false),
    m_Timer(new QTimer(this)),    
    m_TemperatureID(0x11),
    m_TemperatureTimer(new QTimer(this)),
    m_QueryTimer(new QTimer(this)),
    m_startDeviceID(0),
    m_endDeviceID(0),
    m_currentQueryID(0)
{
    ui->setupUi(this);
    ui->pushButton_indexStopQuery->setEnabled(false);
    connect(m_socket, SIGNAL(readyRead()),this, SLOT(receiveData()));
    connect(m_Timer,SIGNAL(timeout()),this,SLOT(on_timeout()));
    connect(m_TemperatureTimer,SIGNAL(timeout()),this,SLOT(on_temperaturetimeout()));
    connect(m_QueryTimer,SIGNAL(timeout()),this,SLOT(on_querytimeout()));

    m_Timer->setSingleShot(true);
    QFile file("config.xml");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(this, QString(u8"错误"),QString(u8"config.xml打开失败"));
        return;
    }


    QString errorStr;
    int errorLine;
    int errorColumn;

    QDomDocument doc;
    if (!doc.setContent(&file, false, &errorStr, &errorLine,&errorColumn))
    {
        QMessageBox::critical(this, QString(u8"错误"),
                              tr("Parse error at line %1, column %2: %3")
                                .arg(errorLine).arg(errorColumn).arg(errorStr));
        file.close();
        return;
    }

    file.close();

    QDomElement root = doc.documentElement();
    for(QDomNode n = root.firstChild(); !n.isNull(); n = n.nextSibling())
    {
        if(n.toElement().tagName().contains("brand"))
        {
            auto brandName = n.toElement().attribute("name");
            auto airIndex = n.toElement().attribute("index");

            ui->comboBox_airBrand->addItem(brandName);
            m_airBrands[brandName] = parseAirIndex(airIndex);
        }
        else if(n.toElement().tagName().contains("deviceID"))
        {
            auto tempStr = n.toElement().attribute("id");
            if(!tempStr.isEmpty())
            {
                m_airID = tempStr.toUInt(nullptr,16);
            }

        }
        else if(n.toElement().tagName().contains("temperatureID"))
        {
            auto tempStr = n.toElement().attribute("id");
            if(!tempStr.isEmpty())
            {
                m_TemperatureID = tempStr.toUInt(nullptr,16);

            }
        }
        else{}

    }

    ui->lineEditd_curentTempID->setText(QString::number(m_TemperatureID,16));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_open_clicked()
{
    if(!m_openState)
    {
        if(m_socket)
        {
            qint16 localPort = ui->lineEdit_localPort->text().toInt();

            if( m_socket->bind(QHostAddress::AnyIPv4,localPort))
            {
                m_openState = true;
                addLog(QString(u8"本地网络端口%1绑定成功").arg(localPort));
                ui->pushButton_open->setText(u8"关闭网络");
            }
            else
            {
               addLog(QString(u8"本地网络端口绑定失败"));
            }

        }
    }
    else
    {
         if(m_socket)
         {
             m_socket->close();

             m_openState = false;
             addLog(QString(u8"本地网络关闭"));
             ui->pushButton_open->setText(u8"打开网络");

         }
    }

}

void Widget::receiveData()
{

    while (m_socket->hasPendingDatagrams())
    {
        auto receiveCmd = m_socket->receiveDatagram().data();

//        if(((quint8)receiveCmd[0] == m_airID) && ((quint8)receiveCmd[1] == 0x10))
//        {
//            m_airID = ui->comboBox_airID->currentText().toUInt(nullptr,16);
//            writeDeviceIDInXml();
//            addLog(QString(u8"空调控制器ID设置成功"));
//        }
//        else if(((quint8)receiveCmd[0] == m_airID)
//                && ((quint8)receiveCmd[1] == 0x03))
//        {
//            addLog(QString(u8"空调控制器ID为%1").arg((quint8)receiveCmd[4],2,16));
//        }
       if(((quint8)receiveCmd[0] == 0x0F) && ((quint8)receiveCmd[1] == 0xFF))
        {
            m_newRecvCmdFlag = true;
            m_airID = (quint8)receiveCmd[8];
            writeDeviceIDInXml();
            addLog(u8"接收到设置ID命令返回值");
        }
        else if(((quint8)receiveCmd[0] == 0xFF) && ((quint8)receiveCmd[1] == 0x0F))
        {
            m_newRecvCmdFlag = true;
            m_airID = (quint8)receiveCmd[8];
            writeDeviceIDInXml();
            addLog(QString(u8"接收到读取ID命令返回值,空调控制器ID为%1").arg((quint8)receiveCmd[8],2,16));
        }
       else if(((quint8)receiveCmd[0] == m_airID) && ((quint8)receiveCmd[1] == 0x43))
       {
            m_newRecvCmdFlag = true;
            addLog(u8"接收到发送命令返回值");
       }
       else if((receiveCmd.length() == 12) && ((quint8)receiveCmd[1] == 0x10))
       {
           m_TemperatureID = ui->lineEdit_setTempID->text().toUInt(nullptr,16);
           ui->lineEditd_curentTempID->setText(ui->lineEdit_setTempID->text());
           addLog(u8"环境主机设置成功");
           writeTemperatureIDInXml();
       }
       else if((receiveCmd.length() == 13) && ((quint8)receiveCmd[1] == 0x03))
       {
           quint8 deviceID = (quint8)receiveCmd[0];

           quint16 tmptemperature = (UCHAR)(receiveCmd[7]) * 256 + (UCHAR)receiveCmd[8];

           float sign = -1.0;
           if((tmptemperature & (1 << 15)) == 0)
           {
               sign = 1.0;
           }
           tmptemperature &= 0x7FFF;
           FLOAT temperature = tmptemperature * sign / 10.0;
           temperature += (CHAR)receiveCmd[5] / 10.0;

           quint16 tmphumidity = (UCHAR)(receiveCmd[9]) * 256 + (UCHAR)receiveCmd[10];
           FLOAT humidity = tmphumidity / 10.0;

           QString log = QString(u8"设备%1返回的温度%2，湿度%3").arg(deviceID,0,16).arg(temperature).arg(humidity);
           addLog(log);
       }
       else if((receiveCmd.length() == 10) && ((quint8)receiveCmd[1] == 0x05))
       {
           addLog(QString(u8"操作成功"));
       }
        else
        {
            if((receiveCmd.length() == 7) &&
                    ((quint8)receiveCmd[3] == 0x45) &&
                    ((quint8)receiveCmd[4] == 0x52))
            {
               addLog(QString(u8"操作失败"));
            }
        }

    }
}

void Widget::addLog(const QString &log)
{
    auto logMessage = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss  ");
    logMessage += log;
    ui->listWidget_log->addItem(logMessage);
    if(ui->listWidget_log->count() >= 600)
    {
        for(auto row = 0; row <= 400; row++)
        {
            auto item = ui->listWidget_log->takeItem(row);
            delete item;
        }
    }

    ui->listWidget_log->scrollToBottom();
}

unsigned int Widget::chkcrc(unsigned char *buf, unsigned char len)
{
    unsigned char hi,lo;
    unsigned int i;
    unsigned int crc;
    crc=0xFFFF;
    for(i=0;i<len;i++)
    {
        crc=calccrc(*buf,crc);
        buf++;
    }
    hi=(unsigned char)(crc%256);
    lo=(unsigned char)(crc/256);
    crc=(((unsigned int)(hi))<<8)|lo;
    return crc;
}

unsigned int Widget::calccrc(unsigned char crcbuf, unsigned int crc)
{
    unsigned char i;
    unsigned char chk;
    crc=crc ^ crcbuf;
    for(i=0;i<8;i++)
    {
        chk=( unsigned char)(crc&1);
        crc=crc>>1;
        crc=crc&0x7fff;
        if (chk==1)
            crc=crc^0xa001;
        crc=crc&0xffff;
    }
    return crc;
}

QVector<qint16> Widget::parseAirIndex(const QString &index)
{
    auto indexStringList = index.split(',',QString::SkipEmptyParts);

    QVector<qint16> airIndex;
    for(auto minorIndex : indexStringList)
    {
       auto tmpAirIndex = parseMinorAirIndex(minorIndex);
       airIndex.append(tmpAirIndex);
    }

    return airIndex;
}

QVector<qint16> Widget::parseMinorAirIndex(const QString &index)
{
    QVector<qint16> tmpIndex;
    if(index.contains('-'))
    {
        auto subIndexStringList = index.split('-',QString::SkipEmptyParts);

        QString lowerBoundStr = subIndexStringList.at(0);
        QString upperBoundStr = subIndexStringList.at(1);

        auto lowerBound = lowerBoundStr.toInt();
        auto upperBound = upperBoundStr.toInt();

        for(auto i = lowerBound; i <= upperBound; i++)
        {
            tmpIndex.append(i);
        }
    }
    else
    {
        tmpIndex.append(index.toInt());
    }

    return tmpIndex;
}

void Widget::writeAirInedexInXml()
{

    auto channel = ui->comboBox_channelForIndex->currentIndex() + 1;
    QString tagName = QString("airIndex_%1").arg(channel);
    auto airIndex = ui->lineEdit_airIndex->text();

    QFile file("config.xml");
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(this, QString(u8"错误"),QString(u8"config.xml打开失败"));
        return;
    }

    QString errorStr;
    int errorLine;
    int errorColumn;

    QDomDocument doc;
    if (!doc.setContent(&file, false, &errorStr, &errorLine,&errorColumn))
    {
        QMessageBox::critical(this, QString(u8"错误"),
                              tr("Parse error at line %1, column %2: %3")
                                .arg(errorLine).arg(errorColumn).arg(errorStr));
        file.close();
        return;
    }

    file.close();

    QDomElement root = doc.documentElement();
    for(QDomNode n = root.firstChild(); !n.isNull(); n = n.nextSibling())
    {
        if(n.toElement().tagName().contains(tagName))
        {
            n.toElement().setAttribute("id",airIndex);
        }
    }

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, QString(u8"错误"),QString(u8"config.xml打开失败"));
        file.close();
        return;
    }

    QTextStream  out(&file);
    doc.save(out,4);
    file.close();

}

void Widget::writeDeviceIDInXml()
{
    QFile file("config.xml");
       if (!file.open(QFile::ReadOnly | QFile::Text))
       {
           QMessageBox::critical(this, QString(u8"错误"),QString(u8"config.xml打开失败"));
           return;
       }

       QString errorStr;
       int errorLine;
       int errorColumn;

       QDomDocument doc;
       if (!doc.setContent(&file, false, &errorStr, &errorLine,&errorColumn))
       {
           QMessageBox::critical(this, QString(u8"错误"),
                                 tr("Parse error at line %1, column %2: %3")
                                   .arg(errorLine).arg(errorColumn).arg(errorStr));
           file.close();
           return;
       }

       file.close();

       QDomElement root = doc.documentElement();
       for(QDomNode n = root.firstChild(); !n.isNull(); n = n.nextSibling())
       {
           if(n.toElement().tagName().contains("deviceID"))
           {
                n.toElement().setAttribute("id",QString::number(m_airID,16));
           }
       }

       if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
       {
           QMessageBox::critical(this, QString(u8"错误"),QString(u8"config.xml打开失败"));
           file.close();
           return;
       }

       QTextStream  out(&file);
       doc.save(out,4);
       file.close();
}

void Widget::writeTemperatureIDInXml()
{
    QFile file("config.xml");
       if (!file.open(QFile::ReadOnly | QFile::Text))
       {
           QMessageBox::critical(this, QString(u8"错误"),QString(u8"config.xml打开失败"));
           return;
       }

       QString errorStr;
       int errorLine;
       int errorColumn;

       QDomDocument doc;
       if (!doc.setContent(&file, false, &errorStr, &errorLine,&errorColumn))
       {
           QMessageBox::critical(this, QString(u8"错误"),
                                 tr("Parse error at line %1, column %2: %3")
                                   .arg(errorLine).arg(errorColumn).arg(errorStr));
           file.close();
           return;
       }

       file.close();

       QDomElement root = doc.documentElement();
       for(QDomNode n = root.firstChild(); !n.isNull(); n = n.nextSibling())
       {
           if(n.toElement().tagName().contains("temperatureID"))
           {
                n.toElement().setAttribute("id",QString::number(m_TemperatureID,16));
           }
       }

       if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
       {
           QMessageBox::critical(this, QString(u8"错误"),QString(u8"config.xml打开失败"));
           file.close();
           return;
       }

       QTextStream  out(&file);
       doc.save(out,4);
       file.close();
}

void Widget::on_pushButton_setID_clicked()
{
    if(!m_openState)
    {
        return;
    }

    auto airID = ui->comboBox_airID->currentText().toInt(nullptr,16);

    m_newRecvCmdFlag = false;
    char cmd[11] = {0};
    cmd[0] = 0x0F;
    cmd[1] = 0xFF;
    cmd[2] = 0;
    cmd[3] = 0;
    cmd[4] = 0;
    cmd[5] = 0x01;
    cmd[6] = 0x02;
    cmd[7] = 0;
    cmd[8] = airID;

    CRCData CRCCheckData;
    CRCCheckData.crcData = chkcrc((unsigned char*)cmd,9);
    cmd[9] = CRCCheckData.crcByte[1];
    cmd[10] = CRCCheckData.crcByte[0];

    QHostAddress airIP(ui->lineEdit_airIP->text());
    auto len = m_socket->writeDatagram(cmd,11,airIP,26);

    if(len < 0)
    {
        addLog(QString(u8"发送命令失败"));
        addLog(m_socket->errorString());
        return;
    }

    startTimer();

    QString log = QString(u8"发送空调控制器设置ID命令，设置ID为%1").arg(airID,0,16);
    addLog(log);
}

void Widget::on_pushButton_verifyID_clicked()
{
    if(!m_openState)
    {
        return;
    }

    m_newRecvCmdFlag = false;
    char cmd[11] = {0};
    cmd[0] = 0xFF;
    cmd[1] = 0x0F;
    cmd[2] = 0;
    cmd[3] = 0;
    cmd[4] = 0;
    cmd[5] = 0x01;
    cmd[6] = 0x02;
    cmd[7] = 0x03;
    cmd[8] = 0x03;

    CRCData CRCCheckData;
    CRCCheckData.crcData = chkcrc((unsigned char*)cmd,9);
    cmd[9] = CRCCheckData.crcByte[1];
    cmd[10] = CRCCheckData.crcByte[0];

    QHostAddress airIP(ui->lineEdit_airIP->text());
    auto len = m_socket->writeDatagram(cmd,11,airIP,26);

    if(len < 0)
    {
      addLog(QString(u8"命令发送失败"));
      return;
    }

    startTimer();

    QString log = QString(u8"发送空调控制器读取ID命令");
    addLog(log);

}

void Widget::on_pushButton_openAir_clicked()
{
    if(!m_openState)
    {
        return;
    }
    qint8 regAddress = 0;

    auto channel = ui->comboBox_channel->currentIndex();
    switch(channel)
    {
    case 0:
        regAddress = 0x11;
        break;
    case 1:
        regAddress = 0x21;
        break;
    case 2:
        regAddress = 0x31;
        break;
    case 3:
        regAddress = 0x41;
        break;
    default:
        break;
    }
    m_newRecvCmdFlag = false;
    char cmd[11] = {0};
    cmd[0] = m_airID;
    cmd[1] = 0x43;
    cmd[2] = 0;
    cmd[3] = regAddress;
    cmd[4] = 0;
    cmd[5] = 0x01;
    cmd[6] = 0x02;
    cmd[7] = 0;
    cmd[8] = (char)0xFF;

    CRCData CRCCheckData;
    CRCCheckData.crcData = chkcrc((unsigned char*)cmd,9);
    cmd[9] = CRCCheckData.crcByte[1];
    cmd[10] = CRCCheckData.crcByte[0];

    QHostAddress airIP(ui->lineEdit_airIP->text());
    auto len = m_socket->writeDatagram(cmd,11,airIP,26);

    if(len < 0)
    {
        addLog(QString(u8"发送命令失败"));
        return;
    }

    startTimer();

    QString log = QString(u8"发送开机命令");
    addLog(log);

}

void Widget::on_pushButton_closeAir_clicked()
{
    if(!m_openState)
    {
        return;
    }
    qint8 regAddress = 0;

    auto channel = ui->comboBox_channel->currentIndex();
    switch(channel)
    {
    case 0:
        regAddress = 0x11;
        break;
    case 1:
        regAddress = 0x21;
        break;
    case 2:
        regAddress = 0x31;
        break;
    case 3:
        regAddress = 0x41;
        break;
    default:
        break;
    }

    m_newRecvCmdFlag = false;
    char cmd[11] = {0};
    cmd[0] = m_airID;
    cmd[1] = 0x43;
    cmd[2] = 0;
    cmd[3] = regAddress;
    cmd[4] = 0;
    cmd[5] = 0x01;
    cmd[6] = 0x02;
    cmd[7] = 0;
    cmd[8] = 0;

    CRCData CRCCheckData;
    CRCCheckData.crcData = chkcrc((unsigned char*)cmd,9);
    cmd[9] = CRCCheckData.crcByte[1];
    cmd[10] = CRCCheckData.crcByte[0];

    QHostAddress airIP(ui->lineEdit_airIP->text());
    auto len = m_socket->writeDatagram(cmd,11,airIP,26);

    if(len < 0)
    {
        addLog(QString(u8"发送命令失败"));
        return;
    }

    startTimer();

    QString log = QString(u8"发送关机命令");
    addLog(log);
}

void Widget::on_pushButton_airIndex_clicked()
{
    if(!m_openState)
    {
        return;
    }
    qint8 regAddress = 0;

    auto channel = ui->comboBox_channelForIndex->currentIndex();
    switch(channel)
    {
    case 0:
        regAddress = 0x10;
        break;
    case 1:
        regAddress = 0x20;
        break;
    case 2:
        regAddress = 0x30;
        break;
    case 3:
        regAddress = 0x40;
        break;
    default:
        break;
    }

    m_newRecvCmdFlag = false;
    quint16 index = ui->lineEdit_airIndex->text().toInt();
    char cmd[11] = {0};
    cmd[0] = m_airID;
    cmd[1] = 0x43;
    cmd[2] = 0;
    cmd[3] = regAddress;
    cmd[4] = 0;
    cmd[5] = 0x01;
    cmd[6] = 0x02;
    cmd[7] = index >> 8;
    cmd[8] = static_cast<char>(index);

    CRCData CRCCheckData;
    CRCCheckData.crcData = chkcrc((unsigned char*)cmd,9);
    cmd[9] = CRCCheckData.crcByte[1];
    cmd[10] = CRCCheckData.crcByte[0];

    QHostAddress airIP(ui->lineEdit_airIP->text());
    auto len = m_socket->writeDatagram(cmd,11,airIP,26);

    if(len < 0)
    {
        addLog(QString(u8"发送命令失败"));
        return;
    }

    startTimer();
    QString log = QString(u8"发送设置空调编码命令,设置的空调编码为%1").arg(index);
    addLog(log);
}

void Widget::on_pushButton_indexQuery_clicked()
{
    if(!m_openState)
    {
        return;
    }

    ui->pushButton_indexQuery->setEnabled(false);
    ui->pushButton_indexStopQuery->setEnabled(true);

    m_QueryState = true;

    auto brand = ui->comboBox_airBrand->currentText();
    QVector<qint16> index = m_airBrands[brand];

    QHostAddress airIP(ui->lineEdit_airIP->text());

    for(auto item = index.cbegin(); item != index.cend(); item++)
    {
        qint8 regAddress = 0;

        auto channel = ui->comboBox_channelForIndex->currentIndex();
        ui->lineEdit_airIndex->setText(QString::number(*item));

        switch(channel)
        {
        case 0:
            regAddress = 0x10;
            break;
        case 1:
            regAddress = 0x20;
            break;
        case 2:
            regAddress = 0x30;
            break;
        case 3:
            regAddress = 0x40;
            break;
        default:
            break;
        }

        m_newRecvCmdFlag = false;
        char cmd[11] = {0};
        cmd[0] = m_airID;
        cmd[1] = 0x43;
        cmd[2] = 0;
        cmd[3] = regAddress;
        cmd[4] = 0;
        cmd[5] = 0x01;
        cmd[6] = 0x02;
        cmd[7] = (*item) >> 8;
        cmd[8] = static_cast<char>(*item);

        CRCData CRCCheckData;

        CRCCheckData.crcData = chkcrc((unsigned char*)cmd,9);
        cmd[9] = CRCCheckData.crcByte[1];
        cmd[10] = CRCCheckData.crcByte[0];

        auto len = m_socket->writeDatagram(cmd,11,airIP,26);

        if(len < 0)
        {
            addLog(QString(u8"发送命令失败"));
            return;
        }

        startTimer();

        QString log = QString(u8"发送设置空调编码命令,设置的空调编码为%1").arg(*item);
        addLog(log);

        for(auto cnt = 0;cnt <= 5*10;cnt++)
        {
            QThread::msleep(100);
            qApp->processEvents();

            if(!m_QueryState)
            {
                return;
            }
        }

        /////////////////////////////////////////////////////////////


        switch(channel)
        {
        case 0:
            regAddress = 0x11;
            break;
        case 1:
            regAddress = 0x21;
            break;
        case 2:
            regAddress = 0x31;
            break;
        case 3:
            regAddress = 0x41;
            break;
        default:
            break;
        }

        m_newRecvCmdFlag = false;
        char cmdOpen[11] = {0};
        cmdOpen[0] = m_airID;
        cmdOpen[1] = 0x43;
        cmdOpen[2] = 0;
        cmdOpen[3] = regAddress;
        cmdOpen[4] = 0;
        cmdOpen[5] = 0x01;
        cmdOpen[6] = 0x02;
        cmdOpen[7] = 0;
        cmdOpen[8] = (char)0xFF;

        CRCCheckData.crcData = chkcrc((unsigned char*)cmdOpen,9);
        cmdOpen[9] = CRCCheckData.crcByte[1];
        cmdOpen[10] = CRCCheckData.crcByte[0];

        len = m_socket->writeDatagram(cmdOpen,11,airIP,26);

        if(len < 0)
        {
            addLog(QString(u8"发送命令失败"));
            return;
        }
        startTimer();

        log = QString(u8"发送开机命令");
        addLog(log);

        for(auto cnt = 0;cnt <= 5*10;cnt++)
        {
            QThread::msleep(100);
            qApp->processEvents();

            if(!m_QueryState)
            {
                return;
            }
        }

    }

}

void Widget::on_pushButton_indexStopQuery_clicked()
{
    m_QueryState = false;

    ui->pushButton_indexQuery->setEnabled(true);
    ui->pushButton_indexStopQuery->setEnabled(false);

    writeAirInedexInXml();
}

void Widget::on_pushButton_clicked()
{
    ui->listWidget_log->clear();
}

void Widget::on_timeout()
{
   if(!m_newRecvCmdFlag)
   {
       addLog(u8"没有接收到发送命令返回值");
   }
}

void Widget::on_temperaturetimeout()
{
    if(!m_openState)
    {
        return;
    }

    char cmd[8] = {'\0'};
    cmd[0] = (quint8)m_TemperatureID;
    cmd[1] = 0x03;
    cmd[2] = 0;
    cmd[3] = 0;
    cmd[4] = 0;
    cmd[5] = 0x05;

    CRCData CRCCheckData;
    CRCCheckData.crcData = chkcrc((unsigned char*)cmd,6);
    cmd[6] = CRCCheckData.crcByte[1];
    cmd[7] = CRCCheckData.crcByte[0];

    QHostAddress airIP(ui->lineEdit_airIP->text());
    auto len = m_socket->writeDatagram(cmd,8,airIP,26);

    if(len < 0)
    {
        addLog(QString(u8"发送命令失败"));
        return;
    }

    QString log = QString(u8"发送环境主机温湿度采集命令");
    addLog(log);
}

void Widget::on_querytimeout()
{
    if(!m_openState)
    {
        return;
    }

    if(m_currentQueryID > m_endDeviceID)
    {
        m_QueryTimer->stop();
        ui->pushButton_query->setText(u8"开始");
        return;
    }

    char cmd[8] = {'\0'};
    cmd[0] = (quint8)m_currentQueryID;
    cmd[1] = 0x03;
    cmd[2] = 0;
    cmd[3] = 0;
    cmd[4] = 0;
    cmd[5] = 0x05;

    CRCData CRCCheckData;
    CRCCheckData.crcData = chkcrc((unsigned char*)cmd,6);
    cmd[6] = CRCCheckData.crcByte[1];
    cmd[7] = CRCCheckData.crcByte[0];

    QHostAddress airIP(ui->lineEdit_airIP->text());
    auto len = m_socket->writeDatagram(cmd,8,airIP,26);

    if(len < 0)
    {
        addLog(QString(u8"发送命令失败"));
        return;
    }

    QString log = QString(u8"发送环境主机温湿度采集命令,设备ID:%1").arg(m_currentQueryID,0,16);
    addLog(log);

    m_currentQueryID++;
}

void Widget::on_pushButton_setTemp_clicked()
{
    if(!m_openState)
    {
        return;
    }

    auto tmpIDStr = ui->lineEdit_setTempID->text();
    if(tmpIDStr.isEmpty())
    {
         addLog(u8"环境子机设置ID号为空");
         return;
    }

    auto temperatureID = tmpIDStr.toUInt(nullptr,16);
    auto tempBias = ui->lineEdit_tempBias->text().toInt();
    auto humidBias = ui->lineEdit_humidBias->text().toInt();

    m_TemperatureID = ui->lineEditd_curentTempID->text().toUInt(nullptr,16);

    char cmd[12] = {'\0'};
    cmd[0] = (quint8)m_TemperatureID;
    cmd[1] = 0x10;
    cmd[2] = 0;
    cmd[3] = 0;
    cmd[4] = 0;
    cmd[5] = 0x04;
    cmd[6] = 0xC1;
    cmd[7] = (qint8)temperatureID;
    cmd[8] = (qint8)tempBias;
    cmd[9] = (qint8)humidBias;


    CRCData CRCCheckData;
    CRCCheckData.crcData = chkcrc((unsigned char*)cmd,10);
    cmd[10] = CRCCheckData.crcByte[1];
    cmd[11] = CRCCheckData.crcByte[0];


    QHostAddress airIP(ui->lineEdit_airIP->text());
    auto len = m_socket->writeDatagram(cmd,12,airIP,26);

    if(len < 0)
    {
        addLog(QString(u8"发送命令失败"));
        return;
    }

    QString log = QString(u8"发送环境主机设置命令,设备ID%1，温度偏移%2，湿度偏移%3").arg(temperatureID,0,16).arg(tempBias).arg(humidBias);
    addLog(log);

}

void Widget::on_pushButton_tempCmd_clicked()
{
    if(ui->pushButton_tempCmd->text() == u8"开始采集")
    {
        ui->pushButton_tempCmd->setText(u8"停止采集");
        m_TemperatureTimer->start(2000);

    }
    else if(ui->pushButton_tempCmd->text() == u8"停止采集")
    {
        ui->pushButton_tempCmd->setText(u8"开始采集");
        m_TemperatureTimer->stop();
    }
    else{}

}

void Widget::on_pushButton_relayCmd_clicked()
{
    if(!m_openState)
    {
        return;
    }


    char cmd[10] = {'\0'};
    cmd[0] = (quint8)m_TemperatureID;
    cmd[1] = 0x05;
    cmd[2] = 0;
    cmd[3] = 0xAA;
    cmd[4] = 0;
    cmd[5] = 0x02;

    QString logmessage = u8"发送";
    if(ui->radioButton_12on5on->isChecked())
    {
        cmd[6] = 0x83;
        logmessage += u8"两个继电器同时开命令";
    }
    else if(ui->radioButton_12off5off->isChecked())
    {
        cmd[6] = 0x80;
        logmessage += u8"两个继电器同时关命令";
    }
    else if(ui->radioButton_12on5off->isChecked())
    {
        cmd[6] = 0x82;
        logmessage += u8"继电器12V开5v关命令";
    }
    else if(ui->radioButton_12off5on->isChecked())
    {
        cmd[6] = 0x81;
        logmessage += u8"继电器12V关5v开命令";
    }
    else{}


    cmd[7] = 0;

    CRCData CRCCheckData;
    CRCCheckData.crcData = chkcrc((unsigned char*)cmd,8);
    cmd[8] = CRCCheckData.crcByte[1];
    cmd[9] = CRCCheckData.crcByte[0];

    QHostAddress airIP(ui->lineEdit_airIP->text());
    auto len = m_socket->writeDatagram(cmd,10,airIP,26);

    if(len < 0)
    {
        addLog(QString(u8"发送命令失败"));
        return;
    }

    addLog(logmessage);

}


void Widget::on_pushButton_query_clicked()
{
    if(ui->lineEditd_startID->text().isEmpty() || ui->lineEditd_endID->text().isEmpty())
    {
        addLog(u8"设备地址为空");
        return;

    }

    m_startDeviceID = ui->lineEditd_startID->text().toUInt(nullptr,16);
    m_endDeviceID = ui->lineEditd_endID->text().toUInt(nullptr,16);

    if(m_startDeviceID > m_endDeviceID)
    {
        addLog(u8"起始设备地址大于结束设备地址");
        return;
    }

    m_currentQueryID = m_startDeviceID;

    if(ui->pushButton_query->text() == u8"开始")
    {
        ui->pushButton_query->setText(u8"停止");
        m_QueryTimer->start(2000);
    }
    else if(ui->pushButton_query->text() == u8"停止")
    {
        ui->pushButton_query->setText(u8"开始");
        m_QueryTimer->stop();
    }
    else{}
}
