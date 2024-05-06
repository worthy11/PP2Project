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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
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
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *WordDisplay;
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
        horizontalLayoutWidget_2 = new QWidget(VideoFrame);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(9, 9, 301, 301));
        VideoLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        VideoLayout->setObjectName("VideoLayout");
        VideoLayout->setContentsMargins(0, 0, 0, 0);
        WordGenerator = new QPushButton(centralwidget);
        WordGenerator->setObjectName("WordGenerator");
        WordGenerator->setGeometry(QRect(520, 350, 91, 31));
        TipFrame = new QFrame(centralwidget);
        TipFrame->setObjectName("TipFrame");
        TipFrame->setGeometry(QRect(120, 360, 121, 121));
        TipFrame->setFrameShape(QFrame::StyledPanel);
        TipFrame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget_3 = new QWidget(TipFrame);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(10, 10, 101, 101));
        TipLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        TipLayout->setObjectName("TipLayout");
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
        CategoryPicker->setObjectName("CategoryPicker");
        CategoryPicker->setGeometry(QRect(460, 50, 221, 28));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(420, 100, 291, 80));
        WordDisplay = new QHBoxLayout(horizontalLayoutWidget);
        WordDisplay->setObjectName("WordDisplay");
        WordDisplay->setContentsMargins(0, 0, 0, 0);
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

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
