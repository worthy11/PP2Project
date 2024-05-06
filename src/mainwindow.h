#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model.h"
#include "capturewidget.h"
#include "generatorwidget.h"
#include <QMainWindow>
#include <QLayout>
#include <QRect>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_WordGenerator_clicked();
    void UpdateWidgets();

private:
    Ui::MainWindow *ui;
    Model* model;
    CaptureWidget* capture;
    GeneratorWidget* generator;
    QLabel* tip;
    QTimer* timer;

    void LoadTip(const QChar& letter);
};
#endif // MAINWINDOW_H
