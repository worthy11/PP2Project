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

    // WORD DISPLAY STYLE
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
    ui->CategoryText->setStyleSheet(QString("border-style: none;"
                                            "background-color: transparent"));
    ui->SpellText->setStyleSheet(QString("border-style: none;"
                                         "background-color: transparent"));

    // TIP DISPLAY STYLE
    tip->setStyleSheet(QString("background-color: white;"));
    ui->TipLayout->addWidget(tip); // DISPLAY TIP
    ui->TipLayout->setAlignment(Qt::AlignCenter);
    ui->TipFrame->setStyleSheet(QString("background-color: white;"
                                        "border-radius: 5px"));

    // CAPTURE DISPLAY STYLE
    ui->VideoFrame->setStyleSheet(QString("background-color: rgb(60, 60, 60);"
                                          "border-radius: 5px;"
                                          "border-width: 2px;"
                                          "border-color: rgb(80, 80, 80);"
                                          "border-style: solid"));
    ui->VideoLayout->setAlignment(Qt::AlignCenter);

    ui->InstructionsText->setStyleSheet(QString("background-color: rgb(60, 60, 60);"
                                                "border-radius: 5px;"
                                                "border-width: 2px;"
                                                "border-color: rgb(80, 80, 80);"
                                                "border-style: solid"));

    generator = new GeneratorWidget(ui->WordDisplay);
}

MainWindow::~MainWindow()
{
    delete ui;
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
    tip->setPixmap(QPixmap::fromImage(QImage(QString(filepath)).scaled(150, 150, Qt::KeepAspectRatio)));
}
