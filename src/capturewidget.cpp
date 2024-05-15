#include "capturewidget.h"
#include "opencv2/imgproc.hpp"
#include <QPixmap>

CaptureWidget::CaptureWidget(QWidget* parent): QLabel(parent), capture(0) {
    this->setStyleSheet(QString("border-radius: 5px"));
}

void CaptureWidget::UpdateFrame(Model* model){
    Mat img;

    if (!capture.isOpened()){
        img = imread("../../../data/img/nocamera.jpg");
    } else {
        capture >> img;
        if (!img.empty()){
            model->Forward(img);
            cvtColor(img, img, COLOR_BGR2RGB);
        } else img = imread("../../../data/img/nocamera.jpg");
    }

    img = img(Rect(floor((img.cols - img.rows) / 2), 0, img.rows, img.rows));
    cv::resize(img, img, Size(360, 360), INTER_LINEAR);
    setPixmap(QPixmap::fromImage(QImage((uchar*) img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
}
