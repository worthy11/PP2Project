#include "capturewidget.h"
#include "opencv2/imgproc.hpp"
#include <QPixmap>

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
    cv::resize(img, img, Size(300, 300), INTER_LINEAR);
    setPixmap(QPixmap::fromImage(QImage((uchar*) img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
}
