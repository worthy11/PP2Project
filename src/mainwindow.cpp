#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLayout>
#include <iostream>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
    this->setFixedSize(size());
    this->setStyleSheet(QString("background-color: rgb(40, 40, 40);"
                                "font-family: 'Trebuchet MS';"
                                "font-weight: 300;"
                                "font-size: 15px;"
                                "color: white"));

    model = new Model;
    capture = new CaptureWidget;
    tip = new QLabel;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateWidgets()));
    timer->start(60);

    ui->VideoLayout->addWidget(capture); // DISPLAY WEBCAM
    ui->CategoryPicker->setCurrentIndex(8); // SET CATEGORY TO FOODS

    // ADJUST LAYOUT FOR WORD DISPLAY
    QHBoxLayout* layout = new QHBoxLayout(ui->WordDisplay);
    layout->setAlignment(Qt::AlignCenter);
    layout->setSpacing(10);
    ui->WordDisplay->setLayout(layout);

    ui->WordGenerator->setStyleSheet(QString("background-color: rgb(60, 60, 60);"
                                             "border-radius: 5px;"
                                             "text-align: center;"
                                             "border-width: 2px;"
                                             "border-color: rgb(80, 80, 80);"
                                             "border-style: solid"));

    ui->CategoryPicker->setStyleSheet(QString("background-color: rgb(60, 60, 60);"
                                             "border-radius: 5px;"
                                             "text-align: center;"
                                             "border-width: 2px;"
                                             "border-color: rgb(80, 80, 80);"
                                             "border-style: solid"));

    // ADJUST LAYOUT FOR TIP DISPLAY
    tip->setStyleSheet(QString("background-color: white;"));
    ui->TipLayout->addWidget(tip); // DISPLAY TIP
    ui->TipLayout->setAlignment(Qt::AlignCenter);
    ui->TipFrame->setStyleSheet(QString(".QFrame { border: 2px solid red;"
                                        "background-color: white; }"));

    generator = new GeneratorWidget(ui->WordDisplay);
}

MainWindow::~MainWindow()
{
    // disconnect(timer, nullptr, nullptr, nullptr);
    delete ui;
    // delete model;
    // delete capture;
    // delete tip;
    // delete timer;
    // delete generator;
}

void MainWindow::on_WordGenerator_clicked(){
    generator->SetWord();
}

void MainWindow::UpdateWidgets(){
    capture->UpdateFrame(model);
    LoadTip(generator->GetLetter());
    generator->SetCategory(this->ui->CategoryPicker->currentIndex());
    if (generator->CheckLetter(model->GetPredictions()))
        model->ResetPredictions();
}

void MainWindow::LoadTip(const QChar& letter){
    QString filepath("../../../data/img/");
    filepath.push_back(letter);
    filepath += ".png";
    tip->setPixmap(QPixmap::fromImage(QImage(QString(filepath))));
}
