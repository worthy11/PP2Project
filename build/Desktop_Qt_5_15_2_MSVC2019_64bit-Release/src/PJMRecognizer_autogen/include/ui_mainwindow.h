/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *VideoFrame;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *VideoLayout;
    QPushButton *WordGenerator;
    QFrame *TipFrame;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *TipLayout;
    QComboBox *CategoryPicker;
    QWidget *WordDisplay;
    QTextEdit *CategoryText;
    QTextEdit *SpellText;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(475, 654);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        VideoFrame = new QFrame(centralwidget);
        VideoFrame->setObjectName(QString::fromUtf8("VideoFrame"));
        VideoFrame->setGeometry(QRect(140, 280, 321, 321));
        VideoFrame->setFrameShape(QFrame::StyledPanel);
        VideoFrame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget_2 = new QWidget(VideoFrame);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(9, 9, 301, 301));
        VideoLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        VideoLayout->setObjectName(QString::fromUtf8("VideoLayout"));
        VideoLayout->setContentsMargins(0, 0, 0, 0);
        WordGenerator = new QPushButton(centralwidget);
        WordGenerator->setObjectName(QString::fromUtf8("WordGenerator"));
        WordGenerator->setGeometry(QRect(160, 210, 151, 41));
        TipFrame = new QFrame(centralwidget);
        TipFrame->setObjectName(QString::fromUtf8("TipFrame"));
        TipFrame->setGeometry(QRect(10, 390, 121, 121));
        TipFrame->setFrameShape(QFrame::StyledPanel);
        TipFrame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget_3 = new QWidget(TipFrame);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 10, 101, 101));
        TipLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        TipLayout->setObjectName(QString::fromUtf8("TipLayout"));
        TipLayout->setContentsMargins(0, 0, 0, 0);
        CategoryPicker = new QComboBox(centralwidget);
        CategoryPicker->addItem(QString());
        CategoryPicker->addItem(QString());
        CategoryPicker->addItem(QString());
        CategoryPicker->addItem(QString());
        CategoryPicker->addItem(QString());
        CategoryPicker->addItem(QString());
        CategoryPicker->addItem(QString());
        CategoryPicker->addItem(QString());
        CategoryPicker->addItem(QString());
        CategoryPicker->addItem(QString());
        CategoryPicker->addItem(QString());
        CategoryPicker->addItem(QString());
        CategoryPicker->setObjectName(QString::fromUtf8("CategoryPicker"));
        CategoryPicker->setGeometry(QRect(130, 40, 221, 28));
        WordDisplay = new QWidget(centralwidget);
        WordDisplay->setObjectName(QString::fromUtf8("WordDisplay"));
        WordDisplay->setGeometry(QRect(50, 120, 371, 80));
        CategoryText = new QTextEdit(centralwidget);
        CategoryText->setObjectName(QString::fromUtf8("CategoryText"));
        CategoryText->setEnabled(true);
        CategoryText->setGeometry(QRect(200, 10, 81, 31));
        CategoryText->setReadOnly(true);
        SpellText = new QTextEdit(centralwidget);
        SpellText->setObjectName(QString::fromUtf8("SpellText"));
        SpellText->setGeometry(QRect(180, 100, 121, 31));
        SpellText->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        CategoryPicker->raise();
        VideoFrame->raise();
        WordGenerator->raise();
        TipFrame->raise();
        WordDisplay->raise();
        CategoryText->raise();
        SpellText->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 475, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        WordGenerator->setText(QCoreApplication::translate("MainWindow", "Nowe s\305\202owo", nullptr));
        CategoryPicker->setItemText(0, QCoreApplication::translate("MainWindow", "Cechy charakteru", nullptr));
        CategoryPicker->setItemText(1, QCoreApplication::translate("MainWindow", "Cechy fizyczne", nullptr));
        CategoryPicker->setItemText(2, QCoreApplication::translate("MainWindow", "Dodatkowe", nullptr));
        CategoryPicker->setItemText(3, QCoreApplication::translate("MainWindow", "Elementy ubioru", nullptr));
        CategoryPicker->setItemText(4, QCoreApplication::translate("MainWindow", "Emocje", nullptr));
        CategoryPicker->setItemText(5, QCoreApplication::translate("MainWindow", "Geografia Polski", nullptr));
        CategoryPicker->setItemText(6, QCoreApplication::translate("MainWindow", "Geografia \305\233wiata", nullptr));
        CategoryPicker->setItemText(7, QCoreApplication::translate("MainWindow", "Imiona", nullptr));
        CategoryPicker->setItemText(8, QCoreApplication::translate("MainWindow", "Jedzenie", nullptr));
        CategoryPicker->setItemText(9, QCoreApplication::translate("MainWindow", "Kolory", nullptr));
        CategoryPicker->setItemText(10, QCoreApplication::translate("MainWindow", "Meble", nullptr));
        CategoryPicker->setItemText(11, QCoreApplication::translate("MainWindow", "Przedmioty codziennego u\305\274ytku", nullptr));

        CategoryText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:7pt;\">Kategoria:</span></p></body></html>", nullptr));
        SpellText->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Przeliteruj s\305\202owo:</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
