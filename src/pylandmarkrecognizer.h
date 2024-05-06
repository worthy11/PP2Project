#pragma once
#ifndef PYTHONLANDMARKRECOGNIZER_H
#define PYTHONLANDMARKRECOGNIZER_H

#include <Python.h>
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

struct PyObjectPtr {
    PyObject* obj;
public:
    PyObjectPtr() : obj(NULL) {}
    PyObjectPtr(PyObject* _obj) : obj(_obj) {}
    ~PyObjectPtr() { Release(); }

    PyObject* getObject() { return obj; }
    PyObject* setObject(PyObject* _p) { return (obj = _p); }
    PyObject* AddRef() {
        if (obj) Py_INCREF(obj);
        return obj;
    }

    void Release() {
        if (obj) Py_DECREF(obj);
        obj = NULL;
    }

    PyObject* operator ->() { return obj; }
    bool is() { return obj ? true : false; }
    operator PyObject* () { return obj; }
    PyObject* operator = (PyObject* obj1) { obj = obj1; return obj; }
    operator bool() { return obj ? true : false; }
};

class PyLandmarkRecognizer{
    PyObjectPtr pName;
    PyObjectPtr pModule;
    PyObjectPtr pFunc;
public:
    PyLandmarkRecognizer();
    ~PyLandmarkRecognizer();
    void ImportRecognizer();
    std::array<std::vector<double>, 2> PyGetLandmarks(const Mat& img);
};

#endif // PYTHONLANDMARKRECOGNIZER_H
