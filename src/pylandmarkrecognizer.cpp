#include <iostream>
#include "pylandmarkrecognizer.h"

PyLandmarkRecognizer::PyLandmarkRecognizer() {
    Py_Initialize();

    PyRun_SimpleString("import sys\nsys.path.append('../../../data/net')");
    pModule = PyImport_ImportModule("landmark_recognizer");
    if (pModule == nullptr) {
        PyErr_Print();
        std::cerr << "Failed to import Python module" << std::endl;
    }
    ImportRecognizer();
}

PyLandmarkRecognizer::~PyLandmarkRecognizer() { Py_Finalize(); }

void PyLandmarkRecognizer::ImportRecognizer() {
    pFunc = PyObject_GetAttrString(pModule, "GetLandmarks");
    if (!pFunc || !PyCallable_Check(pFunc)) {
        std::cerr << "ERROR: Could not import function GetLandmarks()\n";
    }
}

std::array<std::vector<double>, 2> PyLandmarkRecognizer::PyGetLandmarks(const Mat& img) {
    std::array<std::vector<double>, 2> landmarks;

    PyObjectPtr pData = PyBytes_FromStringAndSize(reinterpret_cast<const char*>(img.data), img.cols * img.rows * img.channels());
    PyObjectPtr pResult = PyObject_CallFunction(pFunc, "Oii", pData, img.cols, img.rows);

    for (Py_ssize_t i = 0; i < PyList_Size(pResult); ++i) {
        PyObjectPtr next = PyList_GetItem(pResult, i);
        landmarks[0].push_back(PyFloat_AsDouble(PyList_GetItem(next, 0)));
        landmarks[1].push_back(PyFloat_AsDouble(PyList_GetItem(next, 1)));
    }

    return landmarks;
}
