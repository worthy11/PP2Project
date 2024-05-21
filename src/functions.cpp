#include <cmath>
#include "functions.h"

Mat ComputeDistances(std::array<std::vector<double>, 2>& landmarks) {
    Mat mat(441, 1, CV_64FC1);
    double width = *std::max_element(landmarks[0].begin(), landmarks[0].end()) - *std::min_element(landmarks[0].begin(), landmarks[0].end());
    double height = *std::max_element(landmarks[1].begin(), landmarks[1].end()) - *std::min_element(landmarks[1].begin(), landmarks[1].end());
    double dx, dy;

    for (auto i = 0; i < 21; ++i) {
        for (auto j = 0; j < 21; ++j) {
            dx = (landmarks[0][j] - landmarks[0][i]) / (width + EPS); // HORIZONTAL DISTANCE BETWEEN Ith AND Jth LANDMARK
            dy = (landmarks[1][j] - landmarks[1][i]) / (height + EPS);  // VERTICAL DISTANCE BETWEEN Ith AND Jth LANDMARK
            mat.at<double>(i*21 + j, 0) = sqrt(pow(dx, 2) + pow(dy, 2)); // EUCLIDEAN DISTANCE
        }
    }
    return mat;
}
