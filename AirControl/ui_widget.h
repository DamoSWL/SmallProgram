/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_15;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_localIP;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_airIP;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_localPort;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_airPort;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_open;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_11;
    QGroupBox *airConditioner;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBox_airID;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_setID;
    QPushButton *pushButton_verifyID;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_3;
    QComboBox *comboBox_channelForIndex;
    QSpacerItem *verticalSpacer_4;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_airIndex;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_airIndex;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *comboBox_airBrand;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_indexQuery;
    QPushButton *pushButton_indexStopQuery;
    QLabel *label_4;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QComboBox *comboBox_channel;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_openAir;
    QPushButton *pushButton_closeAir;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_14;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_22;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_7;
    QLineEdit *lineEditd_curentTempID;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_8;
    QLineEdit *lineEdit_setTempID;
    QHBoxLayout *horizontalLayout_23;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_9;
    QLineEdit *lineEdit_tempBias;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_10;
    QLineEdit *lineEdit_humidBias;
    QHBoxLayout *horizontalLayout_16;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *pushButton_setTemp;
    QPushButton *pushButton_tempCmd;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_11;
    QLineEdit *lineEditd_startID;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_12;
    QLineEdit *lineEditd_endID;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_query;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_17;
    QRadioButton *radioButton_12on5on;
    QSpacerItem *horizontalSpacer_16;
    QRadioButton *radioButton_12off5off;
    QHBoxLayout *horizontalLayout_18;
    QRadioButton *radioButton_12on5off;
    QSpacerItem *horizontalSpacer_17;
    QRadioButton *radioButton_12off5on;
    QHBoxLayout *horizontalLayout_21;
    QSpacerItem *horizontalSpacer_20;
    QPushButton *pushButton_relayCmd;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton;
    QListWidget *listWidget_log;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(630, 874);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setStyleSheet(QStringLiteral(""));
        verticalLayout_15 = new QVBoxLayout(Widget);
        verticalLayout_15->setSpacing(3);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(3, 3, 3, 3);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setSpacing(7);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(8, 8, 8, 8);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMaximumSize(QSize(100, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2->setWordWrap(true);

        horizontalLayout_2->addWidget(label_2);

        lineEdit_localIP = new QLineEdit(groupBox);
        lineEdit_localIP->setObjectName(QStringLiteral("lineEdit_localIP"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_localIP->sizePolicy().hasHeightForWidth());
        lineEdit_localIP->setSizePolicy(sizePolicy2);
        lineEdit_localIP->setMinimumSize(QSize(0, 30));
        lineEdit_localIP->setMaximumSize(QSize(120, 16777215));
        lineEdit_localIP->setFont(font1);
        lineEdit_localIP->setStyleSheet(QStringLiteral("background-color: rgb(177, 177, 177);"));
        lineEdit_localIP->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEdit_localIP);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(20, 0));
        label->setMaximumSize(QSize(100, 16777215));
        label->setFont(font1);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label->setWordWrap(true);

        horizontalLayout->addWidget(label);

        lineEdit_airIP = new QLineEdit(groupBox);
        lineEdit_airIP->setObjectName(QStringLiteral("lineEdit_airIP"));
        sizePolicy2.setHeightForWidth(lineEdit_airIP->sizePolicy().hasHeightForWidth());
        lineEdit_airIP->setSizePolicy(sizePolicy2);
        lineEdit_airIP->setMinimumSize(QSize(0, 30));
        lineEdit_airIP->setMaximumSize(QSize(120, 16777215));
        lineEdit_airIP->setFont(font1);

        horizontalLayout->addWidget(lineEdit_airIP);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(3);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMaximumSize(QSize(100, 16777215));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_5->setWordWrap(true);

        horizontalLayout_5->addWidget(label_5);

        lineEdit_localPort = new QLineEdit(groupBox);
        lineEdit_localPort->setObjectName(QStringLiteral("lineEdit_localPort"));
        sizePolicy2.setHeightForWidth(lineEdit_localPort->sizePolicy().hasHeightForWidth());
        lineEdit_localPort->setSizePolicy(sizePolicy2);
        lineEdit_localPort->setMinimumSize(QSize(0, 30));
        lineEdit_localPort->setMaximumSize(QSize(120, 16777215));
        lineEdit_localPort->setFont(font1);
        lineEdit_localPort->setReadOnly(false);

        horizontalLayout_5->addWidget(lineEdit_localPort);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(3);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMaximumSize(QSize(100, 16777215));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_6->setWordWrap(true);

        horizontalLayout_6->addWidget(label_6);

        lineEdit_airPort = new QLineEdit(groupBox);
        lineEdit_airPort->setObjectName(QStringLiteral("lineEdit_airPort"));
        sizePolicy2.setHeightForWidth(lineEdit_airPort->sizePolicy().hasHeightForWidth());
        lineEdit_airPort->setSizePolicy(sizePolicy2);
        lineEdit_airPort->setMinimumSize(QSize(0, 30));
        lineEdit_airPort->setMaximumSize(QSize(120, 16777215));
        lineEdit_airPort->setFont(font1);
        lineEdit_airPort->setStyleSheet(QStringLiteral("background-color: rgb(177, 177, 177);"));
        lineEdit_airPort->setReadOnly(true);

        horizontalLayout_6->addWidget(lineEdit_airPort);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButton_open = new QPushButton(groupBox);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_open->sizePolicy().hasHeightForWidth());
        pushButton_open->setSizePolicy(sizePolicy3);
        pushButton_open->setMinimumSize(QSize(0, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        pushButton_open->setFont(font2);

        verticalLayout_3->addWidget(pushButton_open);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 2);

        verticalLayout_15->addWidget(groupBox);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamily(QStringLiteral("Arial"));
        font3.setPointSize(12);
        tabWidget->setFont(font3);
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_11 = new QVBoxLayout(tab);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        airConditioner = new QGroupBox(tab);
        airConditioner->setObjectName(QStringLiteral("airConditioner"));
        airConditioner->setFont(font3);
        verticalLayout_10 = new QVBoxLayout(airConditioner);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        groupBox_2 = new QGroupBox(airConditioner);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QFont font4;
        font4.setFamily(QStringLiteral("Arial"));
        font4.setPointSize(9);
        groupBox_2->setFont(font4);
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        comboBox_airID = new QComboBox(groupBox_2);
        comboBox_airID->addItem(QString());
        comboBox_airID->addItem(QString());
        comboBox_airID->addItem(QString());
        comboBox_airID->setObjectName(QStringLiteral("comboBox_airID"));
        comboBox_airID->setMinimumSize(QSize(150, 30));
        comboBox_airID->setFont(font1);
        comboBox_airID->setStyleSheet(QStringLiteral(""));

        horizontalLayout_4->addWidget(comboBox_airID);

        horizontalSpacer_3 = new QSpacerItem(130, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton_setID = new QPushButton(groupBox_2);
        pushButton_setID->setObjectName(QStringLiteral("pushButton_setID"));
        pushButton_setID->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(pushButton_setID);

        pushButton_verifyID = new QPushButton(groupBox_2);
        pushButton_verifyID->setObjectName(QStringLiteral("pushButton_verifyID"));
        pushButton_verifyID->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(pushButton_verifyID);


        verticalLayout_10->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(airConditioner);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        comboBox_channelForIndex = new QComboBox(groupBox_3);
        comboBox_channelForIndex->addItem(QString());
        comboBox_channelForIndex->addItem(QString());
        comboBox_channelForIndex->addItem(QString());
        comboBox_channelForIndex->addItem(QString());
        comboBox_channelForIndex->setObjectName(QStringLiteral("comboBox_channelForIndex"));
        comboBox_channelForIndex->setMinimumSize(QSize(50, 30));
        comboBox_channelForIndex->setFont(font1);

        verticalLayout_5->addWidget(comboBox_channelForIndex);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);


        horizontalLayout_9->addLayout(verticalLayout_5);

        line = new QFrame(groupBox_3);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_9->addWidget(line);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lineEdit_airIndex = new QLineEdit(groupBox_3);
        lineEdit_airIndex->setObjectName(QStringLiteral("lineEdit_airIndex"));
        sizePolicy2.setHeightForWidth(lineEdit_airIndex->sizePolicy().hasHeightForWidth());
        lineEdit_airIndex->setSizePolicy(sizePolicy2);
        lineEdit_airIndex->setMinimumSize(QSize(0, 30));
        lineEdit_airIndex->setMaximumSize(QSize(90, 16777215));
        lineEdit_airIndex->setFont(font1);
        lineEdit_airIndex->setMaxLength(20);

        horizontalLayout_7->addWidget(lineEdit_airIndex);

        horizontalSpacer_5 = new QSpacerItem(90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        pushButton_airIndex = new QPushButton(groupBox_3);
        pushButton_airIndex->setObjectName(QStringLiteral("pushButton_airIndex"));
        sizePolicy2.setHeightForWidth(pushButton_airIndex->sizePolicy().hasHeightForWidth());
        pushButton_airIndex->setSizePolicy(sizePolicy2);
        pushButton_airIndex->setMinimumSize(QSize(0, 30));
        QFont font5;
        font5.setPointSize(10);
        pushButton_airIndex->setFont(font5);

        horizontalLayout_7->addWidget(pushButton_airIndex);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font6;
        font6.setFamily(QStringLiteral("Agency FB"));
        font6.setPointSize(10);
        label_3->setFont(font6);
        label_3->setWordWrap(true);

        horizontalLayout_7->addWidget(label_3);


        verticalLayout_4->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        comboBox_airBrand = new QComboBox(groupBox_3);
        comboBox_airBrand->setObjectName(QStringLiteral("comboBox_airBrand"));
        sizePolicy2.setHeightForWidth(comboBox_airBrand->sizePolicy().hasHeightForWidth());
        comboBox_airBrand->setSizePolicy(sizePolicy2);
        comboBox_airBrand->setMinimumSize(QSize(90, 30));
        comboBox_airBrand->setFont(font1);

        horizontalLayout_8->addWidget(comboBox_airBrand);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        pushButton_indexQuery = new QPushButton(groupBox_3);
        pushButton_indexQuery->setObjectName(QStringLiteral("pushButton_indexQuery"));
        pushButton_indexQuery->setMinimumSize(QSize(0, 30));
        pushButton_indexQuery->setFont(font5);

        horizontalLayout_8->addWidget(pushButton_indexQuery);

        pushButton_indexStopQuery = new QPushButton(groupBox_3);
        pushButton_indexStopQuery->setObjectName(QStringLiteral("pushButton_indexStopQuery"));
        pushButton_indexStopQuery->setMinimumSize(QSize(0, 30));
        pushButton_indexStopQuery->setFont(font5);

        horizontalLayout_8->addWidget(pushButton_indexStopQuery);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font6);
        label_4->setWordWrap(true);

        horizontalLayout_8->addWidget(label_4);


        verticalLayout_4->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout_4);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(2, 4);

        verticalLayout_6->addLayout(horizontalLayout_9);


        verticalLayout_10->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(airConditioner);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        comboBox_channel = new QComboBox(groupBox_4);
        comboBox_channel->addItem(QString());
        comboBox_channel->addItem(QString());
        comboBox_channel->addItem(QString());
        comboBox_channel->addItem(QString());
        comboBox_channel->setObjectName(QStringLiteral("comboBox_channel"));
        sizePolicy2.setHeightForWidth(comboBox_channel->sizePolicy().hasHeightForWidth());
        comboBox_channel->setSizePolicy(sizePolicy2);
        comboBox_channel->setMinimumSize(QSize(150, 30));
        comboBox_channel->setFont(font5);

        horizontalLayout_10->addWidget(comboBox_channel);

        horizontalSpacer_7 = new QSpacerItem(500, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);

        pushButton_openAir = new QPushButton(groupBox_4);
        pushButton_openAir->setObjectName(QStringLiteral("pushButton_openAir"));
        pushButton_openAir->setMinimumSize(QSize(0, 30));
        pushButton_openAir->setFont(font5);

        horizontalLayout_10->addWidget(pushButton_openAir);

        pushButton_closeAir = new QPushButton(groupBox_4);
        pushButton_closeAir->setObjectName(QStringLiteral("pushButton_closeAir"));
        pushButton_closeAir->setMinimumSize(QSize(0, 30));
        pushButton_closeAir->setFont(font5);

        horizontalLayout_10->addWidget(pushButton_closeAir);


        verticalLayout_7->addLayout(horizontalLayout_10);


        verticalLayout_10->addWidget(groupBox_4);


        verticalLayout_11->addWidget(airConditioner);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_14 = new QVBoxLayout(tab_2);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        QFont font7;
        font7.setPointSize(9);
        groupBox_7->setFont(font7);
        verticalLayout_12 = new QVBoxLayout(groupBox_7);
        verticalLayout_12->setSpacing(7);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_7 = new QLabel(groupBox_7);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font5);
        label_7->setWordWrap(true);

        horizontalLayout_12->addWidget(label_7);


        horizontalLayout_22->addLayout(horizontalLayout_12);

        lineEditd_curentTempID = new QLineEdit(groupBox_7);
        lineEditd_curentTempID->setObjectName(QStringLiteral("lineEditd_curentTempID"));
        lineEditd_curentTempID->setMinimumSize(QSize(0, 30));
        lineEditd_curentTempID->setMaximumSize(QSize(100, 16777215));
        lineEditd_curentTempID->setFont(font2);
        lineEditd_curentTempID->setCursor(QCursor(Qt::BlankCursor));
        lineEditd_curentTempID->setMaxLength(3);
        lineEditd_curentTempID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_22->addWidget(lineEditd_curentTempID);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_8 = new QLabel(groupBox_7);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);
        label_8->setWordWrap(true);

        horizontalLayout_13->addWidget(label_8);

        lineEdit_setTempID = new QLineEdit(groupBox_7);
        lineEdit_setTempID->setObjectName(QStringLiteral("lineEdit_setTempID"));
        lineEdit_setTempID->setMinimumSize(QSize(0, 30));
        lineEdit_setTempID->setMaximumSize(QSize(100, 16777215));
        lineEdit_setTempID->setFont(font2);
        lineEdit_setTempID->setMaxLength(3);

        horizontalLayout_13->addWidget(lineEdit_setTempID);


        horizontalLayout_22->addLayout(horizontalLayout_13);


        verticalLayout_12->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_9 = new QLabel(groupBox_7);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);
        label_9->setWordWrap(true);

        horizontalLayout_14->addWidget(label_9);

        lineEdit_tempBias = new QLineEdit(groupBox_7);
        lineEdit_tempBias->setObjectName(QStringLiteral("lineEdit_tempBias"));
        lineEdit_tempBias->setMinimumSize(QSize(0, 30));
        lineEdit_tempBias->setMaximumSize(QSize(100, 16777215));
        lineEdit_tempBias->setFont(font2);
        lineEdit_tempBias->setMaxLength(3);

        horizontalLayout_14->addWidget(lineEdit_tempBias);


        horizontalLayout_23->addLayout(horizontalLayout_14);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_10 = new QLabel(groupBox_7);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);
        label_10->setWordWrap(true);

        horizontalLayout_15->addWidget(label_10);

        lineEdit_humidBias = new QLineEdit(groupBox_7);
        lineEdit_humidBias->setObjectName(QStringLiteral("lineEdit_humidBias"));
        lineEdit_humidBias->setMinimumSize(QSize(0, 30));
        lineEdit_humidBias->setMaximumSize(QSize(100, 16777215));
        lineEdit_humidBias->setFont(font2);
        lineEdit_humidBias->setMaxLength(3);

        horizontalLayout_15->addWidget(lineEdit_humidBias);


        horizontalLayout_23->addLayout(horizontalLayout_15);


        verticalLayout_12->addLayout(horizontalLayout_23);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(2, 2, 2, 2);
        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_14);

        pushButton_setTemp = new QPushButton(groupBox_7);
        pushButton_setTemp->setObjectName(QStringLiteral("pushButton_setTemp"));
        pushButton_setTemp->setMinimumSize(QSize(0, 30));
        pushButton_setTemp->setFont(font7);

        horizontalLayout_16->addWidget(pushButton_setTemp);

        pushButton_tempCmd = new QPushButton(groupBox_7);
        pushButton_tempCmd->setObjectName(QStringLiteral("pushButton_tempCmd"));
        pushButton_tempCmd->setMinimumSize(QSize(0, 30));
        pushButton_tempCmd->setFont(font7);

        horizontalLayout_16->addWidget(pushButton_tempCmd);


        verticalLayout_12->addLayout(horizontalLayout_16);


        verticalLayout_14->addWidget(groupBox_7);

        groupBox_9 = new QGroupBox(tab_2);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setMaximumSize(QSize(16777215, 160));
        horizontalLayout_19 = new QHBoxLayout(groupBox_9);
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_11 = new QLabel(groupBox_9);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font6);
        label_11->setWordWrap(false);

        horizontalLayout_19->addWidget(label_11);

        lineEditd_startID = new QLineEdit(groupBox_9);
        lineEditd_startID->setObjectName(QStringLiteral("lineEditd_startID"));
        lineEditd_startID->setMinimumSize(QSize(0, 30));
        lineEditd_startID->setMaximumSize(QSize(100, 16777215));
        QFont font8;
        font8.setFamily(QStringLiteral("Arial"));
        font8.setPointSize(8);
        lineEditd_startID->setFont(font8);
        lineEditd_startID->setCursor(QCursor(Qt::BlankCursor));
        lineEditd_startID->setMaxLength(3);
        lineEditd_startID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_19->addWidget(lineEditd_startID);

        horizontalSpacer_4 = new QSpacerItem(81, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_4);

        label_12 = new QLabel(groupBox_9);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font6);
        label_12->setWordWrap(false);

        horizontalLayout_19->addWidget(label_12);

        lineEditd_endID = new QLineEdit(groupBox_9);
        lineEditd_endID->setObjectName(QStringLiteral("lineEditd_endID"));
        lineEditd_endID->setMinimumSize(QSize(0, 30));
        lineEditd_endID->setMaximumSize(QSize(100, 16777215));
        lineEditd_endID->setFont(font8);
        lineEditd_endID->setCursor(QCursor(Qt::BlankCursor));
        lineEditd_endID->setMaxLength(3);
        lineEditd_endID->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_19->addWidget(lineEditd_endID);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_2);

        pushButton_query = new QPushButton(groupBox_9);
        pushButton_query->setObjectName(QStringLiteral("pushButton_query"));
        pushButton_query->setFont(font6);

        horizontalLayout_19->addWidget(pushButton_query);


        verticalLayout_14->addWidget(groupBox_9);

        groupBox_8 = new QGroupBox(tab_2);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setFont(font7);
        verticalLayout_13 = new QVBoxLayout(groupBox_8);
        verticalLayout_13->setSpacing(7);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        radioButton_12on5on = new QRadioButton(groupBox_8);
        radioButton_12on5on->setObjectName(QStringLiteral("radioButton_12on5on"));
        radioButton_12on5on->setMinimumSize(QSize(0, 35));
        radioButton_12on5on->setFont(font5);
        radioButton_12on5on->setChecked(true);

        horizontalLayout_17->addWidget(radioButton_12on5on);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_16);

        radioButton_12off5off = new QRadioButton(groupBox_8);
        radioButton_12off5off->setObjectName(QStringLiteral("radioButton_12off5off"));
        radioButton_12off5off->setMinimumSize(QSize(0, 35));
        radioButton_12off5off->setFont(font5);

        horizontalLayout_17->addWidget(radioButton_12off5off);


        verticalLayout_13->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        radioButton_12on5off = new QRadioButton(groupBox_8);
        radioButton_12on5off->setObjectName(QStringLiteral("radioButton_12on5off"));
        radioButton_12on5off->setMinimumSize(QSize(0, 35));
        radioButton_12on5off->setFont(font6);

        horizontalLayout_18->addWidget(radioButton_12on5off);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_17);

        radioButton_12off5on = new QRadioButton(groupBox_8);
        radioButton_12off5on->setObjectName(QStringLiteral("radioButton_12off5on"));
        radioButton_12off5on->setMinimumSize(QSize(0, 35));
        radioButton_12off5on->setFont(font5);
        radioButton_12off5on->setChecked(true);

        horizontalLayout_18->addWidget(radioButton_12off5on);


        verticalLayout_13->addLayout(horizontalLayout_18);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalLayout_21->setContentsMargins(2, 2, 2, 2);
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_20);

        pushButton_relayCmd = new QPushButton(groupBox_8);
        pushButton_relayCmd->setObjectName(QStringLiteral("pushButton_relayCmd"));
        pushButton_relayCmd->setMinimumSize(QSize(0, 30));
        pushButton_relayCmd->setFont(font7);

        horizontalLayout_21->addWidget(pushButton_relayCmd);


        verticalLayout_13->addLayout(horizontalLayout_21);


        verticalLayout_14->addWidget(groupBox_8);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_15->addWidget(tabWidget);

        groupBox_5 = new QGroupBox(Widget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_9 = new QVBoxLayout(groupBox_5);
        verticalLayout_9->setSpacing(7);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(2, 2, 2, 2);
        horizontalSpacer_8 = new QSpacerItem(600, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_8);

        pushButton = new QPushButton(groupBox_5);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));

        horizontalLayout_11->addWidget(pushButton);


        verticalLayout_8->addLayout(horizontalLayout_11);

        listWidget_log = new QListWidget(groupBox_5);
        listWidget_log->setObjectName(QStringLiteral("listWidget_log"));
        listWidget_log->setContextMenuPolicy(Qt::NoContextMenu);

        verticalLayout_8->addWidget(listWidget_log);


        verticalLayout_9->addLayout(verticalLayout_8);


        verticalLayout_15->addWidget(groupBox_5);

        verticalLayout_15->setStretch(2, 1);

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QApplication::translate("Widget", "\347\275\221\347\273\234\351\205\215\347\275\256", nullptr));
        label_2->setText(QApplication::translate("Widget", "\346\234\254\345\234\260IP", nullptr));
        lineEdit_localIP->setText(QApplication::translate("Widget", "127.0.0.1", nullptr));
        label->setText(QApplication::translate("Widget", "\346\216\247\345\210\266\345\231\250IP", nullptr));
        lineEdit_airIP->setText(QApplication::translate("Widget", "127.0.0.1", nullptr));
        label_5->setText(QApplication::translate("Widget", "\346\234\254\345\234\260\347\253\257\345\217\243", nullptr));
        lineEdit_localPort->setText(QApplication::translate("Widget", "5005", nullptr));
        label_6->setText(QApplication::translate("Widget", "\346\216\247\345\210\266\345\231\250\347\253\257\345\217\243", nullptr));
        lineEdit_airPort->setText(QApplication::translate("Widget", "26", nullptr));
        pushButton_open->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\347\275\221\347\273\234", nullptr));
        airConditioner->setTitle(QString());
        groupBox_2->setTitle(QApplication::translate("Widget", "ID\350\256\276\347\275\256", nullptr));
        comboBox_airID->setItemText(0, QApplication::translate("Widget", "90", nullptr));
        comboBox_airID->setItemText(1, QApplication::translate("Widget", "91", nullptr));
        comboBox_airID->setItemText(2, QApplication::translate("Widget", "92", nullptr));

        pushButton_setID->setText(QApplication::translate("Widget", "\350\256\276\347\275\256ID", nullptr));
        pushButton_verifyID->setText(QApplication::translate("Widget", "\350\257\273\345\217\226ID", nullptr));
        groupBox_3->setTitle(QApplication::translate("Widget", "\347\251\272\350\260\203\347\274\226\347\240\201\350\256\276\347\275\256", nullptr));
        comboBox_channelForIndex->setItemText(0, QApplication::translate("Widget", "\347\254\254\344\270\200\350\267\257", nullptr));
        comboBox_channelForIndex->setItemText(1, QApplication::translate("Widget", "\347\254\254\344\272\214\350\267\257", nullptr));
        comboBox_channelForIndex->setItemText(2, QApplication::translate("Widget", "\347\254\254\344\270\211\350\267\257", nullptr));
        comboBox_channelForIndex->setItemText(3, QApplication::translate("Widget", "\347\254\254\345\233\233\350\267\257", nullptr));

        lineEdit_airIndex->setText(QApplication::translate("Widget", "0", nullptr));
        pushButton_airIndex->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\347\274\226\347\240\201", nullptr));
        label_3->setText(QApplication::translate("Widget", "\350\213\245\345\267\262\347\237\245\347\274\226\347\240\201\345\210\231\347\233\264\346\216\245\350\256\276\347\275\256", nullptr));
        pushButton_indexQuery->setText(QApplication::translate("Widget", "\350\275\256\350\257\242", nullptr));
        pushButton_indexStopQuery->setText(QApplication::translate("Widget", "\345\201\234\346\255\242", nullptr));
        label_4->setText(QApplication::translate("Widget", "\350\213\245\344\270\215\347\237\245\347\274\226\347\240\201\345\210\231\350\275\256\350\257\242\350\256\276\347\275\256", nullptr));
        groupBox_4->setTitle(QApplication::translate("Widget", "\345\274\200\345\205\263\346\234\272\346\265\213\350\257\225", nullptr));
        comboBox_channel->setItemText(0, QApplication::translate("Widget", "\347\254\254\344\270\200\350\267\257", nullptr));
        comboBox_channel->setItemText(1, QApplication::translate("Widget", "\347\254\254\344\272\214\350\267\257", nullptr));
        comboBox_channel->setItemText(2, QApplication::translate("Widget", "\347\254\254\344\270\211\350\267\257", nullptr));
        comboBox_channel->setItemText(3, QApplication::translate("Widget", "\347\254\254\345\233\233\350\267\257", nullptr));

        pushButton_openAir->setText(QApplication::translate("Widget", "\345\274\200\346\234\272", nullptr));
        pushButton_closeAir->setText(QApplication::translate("Widget", "\345\205\263\346\234\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\347\251\272\350\260\203", nullptr));
        groupBox_7->setTitle(QApplication::translate("Widget", "\346\270\251\346\271\277\345\272\246\351\207\207\351\233\206", nullptr));
        label_7->setText(QApplication::translate("Widget", "\345\275\223\345\211\215\350\256\276\345\244\207\347\274\226\345\217\267\357\274\232", nullptr));
        lineEditd_curentTempID->setText(QApplication::translate("Widget", "11", nullptr));
        label_8->setText(QApplication::translate("Widget", "\350\256\276\345\244\207\347\274\226\345\217\267\350\256\276\347\275\256\357\274\232", nullptr));
        lineEdit_setTempID->setText(QString());
        label_9->setText(QApplication::translate("Widget", "\346\270\251\345\272\246\345\201\217\347\247\273\350\256\276\347\275\256\357\274\232", nullptr));
        lineEdit_tempBias->setText(QApplication::translate("Widget", "0", nullptr));
        label_10->setText(QApplication::translate("Widget", "\346\271\277\345\272\246\345\201\217\347\247\273\350\256\276\347\275\256\357\274\232", nullptr));
        lineEdit_humidBias->setText(QApplication::translate("Widget", "0", nullptr));
        pushButton_setTemp->setText(QApplication::translate("Widget", "\350\256\276\347\275\256", nullptr));
        pushButton_tempCmd->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        groupBox_9->setTitle(QApplication::translate("Widget", "\350\275\256\350\257\242\351\207\207\351\233\206", nullptr));
        label_11->setText(QApplication::translate("Widget", "\350\265\267\345\247\213\345\234\260\345\235\200\357\274\232", nullptr));
        lineEditd_startID->setText(QString());
        label_12->setText(QApplication::translate("Widget", "\347\273\223\346\235\237\345\234\260\345\235\200\357\274\232", nullptr));
        lineEditd_endID->setText(QString());
        pushButton_query->setText(QApplication::translate("Widget", "\345\274\200\345\247\213", nullptr));
        groupBox_8->setTitle(QApplication::translate("Widget", "\347\273\247\347\224\265\345\231\250\346\216\247\345\210\266", nullptr));
        radioButton_12on5on->setText(QApplication::translate("Widget", "\344\270\244\344\270\252\347\273\247\347\224\265\345\231\250\345\220\214\346\227\266\345\274\200", nullptr));
        radioButton_12off5off->setText(QApplication::translate("Widget", "\344\270\244\344\270\252\347\273\247\347\224\265\345\231\250\345\220\214\346\227\266\345\205\263", nullptr));
        radioButton_12on5off->setText(QApplication::translate("Widget", "\347\273\247\347\224\265\345\231\25012V\345\274\2005V\345\205\263", nullptr));
        radioButton_12off5on->setText(QApplication::translate("Widget", "\347\273\247\347\224\265\345\231\25012V\345\205\2635V\345\274\200", nullptr));
        pushButton_relayCmd->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\345\221\275\344\273\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\347\216\257\345\242\203\344\270\273\346\234\272", nullptr));
        groupBox_5->setTitle(QApplication::translate("Widget", "\346\227\245\345\277\227", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
