#ifndef WIDGET_H
#define WIDGET_H

#include <QtCore/QtCore>
#include <QtWidgets/QtWidgets>
#include <QtNetwork/QtNetwork>
#include <QtXml/QtXml>

namespace Ui {
class Widget;
}

typedef union
{
    unsigned short crcData;
    unsigned char crcByte[2];
}CRCData;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void receiveData();

    void on_pushButton_open_clicked();

    void on_pushButton_setID_clicked();

    void on_pushButton_verifyID_clicked();

    void on_pushButton_openAir_clicked();

    void on_pushButton_closeAir_clicked();

    void on_pushButton_airIndex_clicked();

    void on_pushButton_indexQuery_clicked();

    void on_pushButton_indexStopQuery_clicked();

    void on_pushButton_clicked();

    void on_timeout();

    void on_temperaturetimeout();

    void on_querytimeout();

    void on_pushButton_setTemp_clicked();

    void on_pushButton_tempCmd_clicked();

    void on_pushButton_relayCmd_clicked();

    void on_pushButton_query_clicked();

private:
    void addLog(const QString& log);
    unsigned int chkcrc(unsigned char *buf,unsigned char len);
    unsigned int calccrc(unsigned char crcbuf,unsigned int crc);

    QVector<qint16> parseAirIndex(const QString& index);
    QVector<qint16> parseMinorAirIndex(const QString& index);
    void writeAirInedexInXml();
    void writeDeviceIDInXml();
    void writeTemperatureIDInXml();

    void startTimer() {m_Timer->start(1500);}

private:
    Ui::Widget *ui;

    QUdpSocket* m_socket;
    bool m_openState;
    quint8 m_airID;

    QHash<QString,QVector<qint16>> m_airBrands;
    QHash<qint8,qint16> m_airIndex;

    bool m_QueryState;
    bool m_newRecvCmdFlag;

    QTimer* m_Timer;

    quint8 m_TemperatureID;
    QTimer* m_TemperatureTimer;
    QTimer* m_QueryTimer;

    quint8 m_startDeviceID;
    quint8 m_endDeviceID;
    quint8 m_currentQueryID;

};

#endif // WIDGET_H
