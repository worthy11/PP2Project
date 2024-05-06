/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
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
    QPushButton *WordGenerator;
    QTextEdit *WordDisplay;
    QFrame *TipFrame;
    QComboBox *CategoryPicker;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(818, 539);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        VideoFrame = new QFrame(centralwidget);
        VideoFrame->setObjectName("VideoFrame");
        VideoFrame->setGeometry(QRect(20, 20, 321, 321));
        VideoFrame->setFrameShape(QFrame::StyledPanel);
        VideoFrame->setFrameShadow(QFrame::Raised);
        WordGenerator = new QPushButton(centralwidget);
        WordGenerator->setObjectName("WordGenerator");
        WordGenerator->setGeometry(QRect(520, 200, 91, 31));
        WordDisplay = new QTextEdit(centralwidget);
        WordDisplay->setObjectName("WordDisplay");
        WordDisplay->setGeometry(QRect(410, 100, 321, 85));
        TipFrame = new QFrame(centralwidget);
        TipFrame->setObjectName("TipFrame");
        TipFrame->setGeometry(QRect(120, 360, 121, 121));
        TipFrame->setFrameShape(QFrame::StyledPanel);
        TipFrame->setFrameShadow(QFrame::Raised);
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
        CategoryPicker->setObjectName("CategoryPicker");
        CategoryPicker->setGeometry(QRect(460, 50, 221, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 818, 25));
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
        WordGenerator->setText(QCoreApplication::translate("MainWindow", "Nowe s\305\202owo", nullptr));
        WordDisplay->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        CategoryPicker->setItemText(0, QCoreApplication::translate("MainWindow", "Imiona", nullptr));
        CategoryPicker->setItemText(1, QCoreApplication::translate("MainWindow", "Przedmioty codziennego u\305\274ytku", nullptr));
        CategoryPicker->setItemText(2, QCoreApplication::translate("MainWindow", "Cechy fizyczne", nullptr));
        CategoryPicker->setItemText(3, QCoreApplication::translate("MainWindow", "Cechy charakteru", nullptr));
        CategoryPicker->setItemText(4, QCoreApplication::translate("MainWindow", "Uczucia", nullptr));
        CategoryPicker->setItemText(5, QCoreApplication::translate("MainWindow", "Jedzenie", nullptr));
        CategoryPicker->setItemText(6, QCoreApplication::translate("MainWindow", "Kolory", nullptr));
        CategoryPicker->setItemText(7, QCoreApplication::translate("MainWindow", "Meble", nullptr));
        CategoryPicker->setItemText(8, QCoreApplication::translate("MainWindow", "Elementy ubioru", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
