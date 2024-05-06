#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLayout>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
    this->setFixedSize(800, 500);
    this->setStyleSheet(QString("background-color: rgb(40, 40, 40);"
                                "font-family: 'Trebuchet MS';"
                                "font-weight: 300;"
                                "font-size: 15px;"
                                "color: white"));

    model = new Model;
    // capture = new CaptureWidget;
    tip = new QLabel;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(UpdateWidgets()));
    timer->start(60);

    // ui->VideoLayout->addWidget(capture);
    ui->TipLayout->addWidget(tip);
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
    // capture->UpdateFrame(model);
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
