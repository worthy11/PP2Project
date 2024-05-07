#ifndef CAPTUREWIDGET_H
#define CAPTUREWIDGET_H

#include "model.h"
#include <QTimer>
#include <QLabel>

using namespace cv;

class CaptureWidget : public QLabel
{
    Q_OBJECT
public:
    CaptureWidget(QWidget* parent = 0);
;

public slots:
    void UpdateFrame(Model* model);

private:
    VideoCapture capture;
};

#endif // CAPTUREWIDGET_H
