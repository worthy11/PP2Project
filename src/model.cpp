#include "model.h"
#include "functions.h"

std::string labels = "ABCDEFGHIKLMNOPRSUWYZ";

Model::Model(): predictions(""), confidence(0) {
    net.setPreferableBackend(dnn::DNN_BACKEND_OPENCV);
    net.setPreferableTarget(dnn::DNN_TARGET_CPU);
}

void Model::Forward(const Mat& img) {
    double output[21];
    int prediction = -1;

    std::array<std::vector<double>, 2> landmarks = recognizer.PyGetLandmarks(img);
    if (!landmarks[0].empty()) {
        Mat input_mat = ComputeDistances(landmarks);
        _InputArray input(input_mat);
        net.setInput(input);
        Mat output_mat = net.forward();

        for (int i = 0; i < 21; i++) output[i] = *(output_mat.ptr<int>(0, i));
        prediction = std::distance(output, std::max_element(output, output+21));
    }

    if (prediction != -1) predictions += labels[prediction];
    else predictions += " ";
    if (predictions.size() == 20) predictions.erase(0, 1);
}
