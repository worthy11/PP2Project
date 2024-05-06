#pragma once
#ifndef MODEL_H
#define MODEL_H

#define OPENCV_TRAITS_ENABLE_DEPRECATED
#include <opencv2/dnn.hpp>
#include "pylandmarkrecognizer.h"

using namespace cv;

class Model {
    PyLandmarkRecognizer recognizer;
    dnn::Net net = dnn::readNetFromONNX("../../../data/net/pjmrecognizer.onnx");
    std::string predictions;
    double confidence;

public:
    Model();

    void Forward(const Mat& img);
    std::string GetPredictions() const { return predictions; }
    void ResetPredictions() { predictions = ""; }
    void SetConfidence(double (&output)[]);
    double GetConfidence() const { return confidence; }
};

#endif // MODEL_H
