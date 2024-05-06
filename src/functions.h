#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "opencv2/highgui/highgui.hpp"

#define EPS 0.0000001

using namespace cv;

Mat ComputeDistances(std::array<std::vector<double>, 2>& landmarks);
std::vector<std::vector<double>> ReadFromCSV(const char* filepath);

#endif // FUNCTIONS_H
