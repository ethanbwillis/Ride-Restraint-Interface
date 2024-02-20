/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *seatImage;
    QPushButton *pushButton;
    QLabel *info;
    QPlainTextEdit *timeMarker;
    QPlainTextEdit *elapsedTime;
    QPlainTextEdit *trainMarker;
    QPlainTextEdit *trainNumber;
    QLabel *backInfo;
    QLabel *middleInfo;
    QLabel *frontInfo;
    QPlainTextEdit *backMarker;
    QPlainTextEdit *midMarker;
    QPlainTextEdit *frontMarker;
    QLabel *backStatus;
    QLabel *midStatus;
    QLabel *frontStatus;
    QPlainTextEdit *overTimeLabel;
    QLabel *logo;
    QPushButton *rmvTrainButton;
    QPlainTextEdit *timeMarker_2;
    QPlainTextEdit *averageTime;
    QPushButton *resetButton;
    QPushButton *addTrainButton;
    QPlainTextEdit *totalTrainsMarker;
    QPlainTextEdit *overTimeLabel_2;
    QPlainTextEdit *totalTrains;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        seatImage = new QLabel(centralwidget);
        seatImage->setObjectName("seatImage");
        seatImage->setGeometry(QRect(270, 160, 271, 221));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(590, 240, 111, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("OCR A Extended")});
        font.setPointSize(15);
        font.setBold(true);
        pushButton->setFont(font);
        info = new QLabel(centralwidget);
        info->setObjectName("info");
        info->setGeometry(QRect(0, 0, 231, 201));
        timeMarker = new QPlainTextEdit(centralwidget);
        timeMarker->setObjectName("timeMarker");
        timeMarker->setGeometry(QRect(60, 50, 101, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("OCR A Extended")});
        font1.setBold(true);
        timeMarker->setFont(font1);
        timeMarker->setFrameShape(QFrame::NoFrame);
        timeMarker->setFrameShadow(QFrame::Plain);
        timeMarker->setLineWidth(0);
        timeMarker->setReadOnly(true);
        elapsedTime = new QPlainTextEdit(centralwidget);
        elapsedTime->setObjectName("elapsedTime");
        elapsedTime->setGeometry(QRect(160, 50, 81, 31));
        elapsedTime->setFont(font1);
        elapsedTime->setFrameShape(QFrame::NoFrame);
        elapsedTime->setFrameShadow(QFrame::Plain);
        elapsedTime->setLineWidth(0);
        elapsedTime->setReadOnly(true);
        elapsedTime->setCenterOnScroll(true);
        trainMarker = new QPlainTextEdit(centralwidget);
        trainMarker->setObjectName("trainMarker");
        trainMarker->setGeometry(QRect(60, 110, 111, 31));
        trainMarker->setFont(font1);
        trainMarker->setFrameShape(QFrame::NoFrame);
        trainMarker->setFrameShadow(QFrame::Plain);
        trainMarker->setLineWidth(0);
        trainMarker->setReadOnly(true);
        trainNumber = new QPlainTextEdit(centralwidget);
        trainNumber->setObjectName("trainNumber");
        trainNumber->setGeometry(QRect(170, 110, 101, 31));
        trainNumber->setFont(font1);
        trainNumber->setFrameShape(QFrame::NoFrame);
        trainNumber->setFrameShadow(QFrame::Plain);
        trainNumber->setLineWidth(0);
        trainNumber->setReadOnly(true);
        backInfo = new QLabel(centralwidget);
        backInfo->setObjectName("backInfo");
        backInfo->setGeometry(QRect(0, 420, 191, 161));
        middleInfo = new QLabel(centralwidget);
        middleInfo->setObjectName("middleInfo");
        middleInfo->setGeometry(QRect(300, 420, 201, 161));
        frontInfo = new QLabel(centralwidget);
        frontInfo->setObjectName("frontInfo");
        frontInfo->setGeometry(QRect(600, 420, 201, 161));
        backMarker = new QPlainTextEdit(centralwidget);
        backMarker->setObjectName("backMarker");
        backMarker->setGeometry(QRect(40, 390, 131, 31));
        backMarker->setFont(font1);
        backMarker->setFrameShape(QFrame::NoFrame);
        backMarker->setFrameShadow(QFrame::Plain);
        backMarker->setLineWidth(0);
        backMarker->setReadOnly(true);
        midMarker = new QPlainTextEdit(centralwidget);
        midMarker->setObjectName("midMarker");
        midMarker->setGeometry(QRect(340, 390, 151, 31));
        midMarker->setFont(font1);
        midMarker->setFrameShape(QFrame::NoFrame);
        midMarker->setFrameShadow(QFrame::Plain);
        midMarker->setLineWidth(0);
        midMarker->setReadOnly(true);
        frontMarker = new QPlainTextEdit(centralwidget);
        frontMarker->setObjectName("frontMarker");
        frontMarker->setGeometry(QRect(640, 390, 151, 31));
        frontMarker->setFont(font1);
        frontMarker->setFrameShape(QFrame::NoFrame);
        frontMarker->setFrameShadow(QFrame::Plain);
        frontMarker->setLineWidth(0);
        frontMarker->setReadOnly(true);
        backStatus = new QLabel(centralwidget);
        backStatus->setObjectName("backStatus");
        backStatus->setGeometry(QRect(-10, 440, 211, 121));
        midStatus = new QLabel(centralwidget);
        midStatus->setObjectName("midStatus");
        midStatus->setGeometry(QRect(290, 440, 211, 121));
        frontStatus = new QLabel(centralwidget);
        frontStatus->setObjectName("frontStatus");
        frontStatus->setGeometry(QRect(590, 440, 211, 121));
        overTimeLabel = new QPlainTextEdit(centralwidget);
        overTimeLabel->setObjectName("overTimeLabel");
        overTimeLabel->setGeometry(QRect(310, 70, 61, 31));
        overTimeLabel->setFont(font1);
        overTimeLabel->setFrameShape(QFrame::NoFrame);
        overTimeLabel->setFrameShadow(QFrame::Plain);
        overTimeLabel->setLineWidth(0);
        overTimeLabel->setReadOnly(true);
        logo = new QLabel(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(570, 0, 231, 201));
        rmvTrainButton = new QPushButton(centralwidget);
        rmvTrainButton->setObjectName("rmvTrainButton");
        rmvTrainButton->setGeometry(QRect(610, 310, 80, 24));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("OCR A Extended")});
        font2.setPointSize(6);
        rmvTrainButton->setFont(font2);
        timeMarker_2 = new QPlainTextEdit(centralwidget);
        timeMarker_2->setObjectName("timeMarker_2");
        timeMarker_2->setGeometry(QRect(60, 80, 111, 31));
        timeMarker_2->setFont(font1);
        timeMarker_2->setFrameShape(QFrame::NoFrame);
        timeMarker_2->setFrameShadow(QFrame::Plain);
        timeMarker_2->setLineWidth(0);
        timeMarker_2->setReadOnly(true);
        averageTime = new QPlainTextEdit(centralwidget);
        averageTime->setObjectName("averageTime");
        averageTime->setGeometry(QRect(150, 80, 141, 31));
        averageTime->setFont(font1);
        averageTime->setFrameShape(QFrame::NoFrame);
        averageTime->setFrameShadow(QFrame::Plain);
        averageTime->setLineWidth(0);
        averageTime->setReadOnly(true);
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(40, 353, 131, 21));
        resetButton->setFont(font2);
        resetButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        addTrainButton = new QPushButton(centralwidget);
        addTrainButton->setObjectName("addTrainButton");
        addTrainButton->setGeometry(QRect(610, 290, 80, 24));
        addTrainButton->setFont(font2);
        totalTrainsMarker = new QPlainTextEdit(centralwidget);
        totalTrainsMarker->setObjectName("totalTrainsMarker");
        totalTrainsMarker->setGeometry(QRect(60, 140, 101, 31));
        totalTrainsMarker->setFont(font1);
        totalTrainsMarker->setFrameShape(QFrame::NoFrame);
        totalTrainsMarker->setFrameShadow(QFrame::Plain);
        totalTrainsMarker->setLineWidth(0);
        totalTrainsMarker->setReadOnly(true);
        overTimeLabel_2 = new QPlainTextEdit(centralwidget);
        overTimeLabel_2->setObjectName("overTimeLabel_2");
        overTimeLabel_2->setGeometry(QRect(470, 360, 61, 31));
        overTimeLabel_2->setFont(font1);
        overTimeLabel_2->setFrameShape(QFrame::NoFrame);
        overTimeLabel_2->setFrameShadow(QFrame::Plain);
        overTimeLabel_2->setLineWidth(0);
        overTimeLabel_2->setReadOnly(true);
        totalTrains = new QPlainTextEdit(centralwidget);
        totalTrains->setObjectName("totalTrains");
        totalTrains->setGeometry(QRect(160, 140, 81, 31));
        totalTrains->setFont(font1);
        totalTrains->setFrameShape(QFrame::NoFrame);
        totalTrains->setFrameShadow(QFrame::Plain);
        totalTrains->setLineWidth(0);
        totalTrains->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        seatImage->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "DISPATCH", nullptr));
        info->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        timeMarker->setPlainText(QCoreApplication::translate("MainWindow", "Elapsed Time:", nullptr));
        elapsedTime->setPlainText(QString());
        trainMarker->setPlainText(QCoreApplication::translate("MainWindow", "Train Number:", nullptr));
        trainNumber->setPlainText(QString());
        backInfo->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        middleInfo->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        frontInfo->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        backMarker->setPlainText(QCoreApplication::translate("MainWindow", "Back of Train:", nullptr));
        midMarker->setPlainText(QCoreApplication::translate("MainWindow", "Middle of Train:", nullptr));
        frontMarker->setPlainText(QCoreApplication::translate("MainWindow", "Front of Train:", nullptr));
        backStatus->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        midStatus->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        frontStatus->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        overTimeLabel->setPlainText(QString());
        logo->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        rmvTrainButton->setText(QCoreApplication::translate("MainWindow", "Remove Train", nullptr));
        timeMarker_2->setPlainText(QCoreApplication::translate("MainWindow", "Avg Time:", nullptr));
        averageTime->setPlainText(QString());
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset Everything", nullptr));
        addTrainButton->setText(QCoreApplication::translate("MainWindow", "Add Train", nullptr));
        totalTrainsMarker->setPlainText(QCoreApplication::translate("MainWindow", "Total Trains:", nullptr));
        overTimeLabel_2->setPlainText(QString());
        totalTrains->setPlainText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
