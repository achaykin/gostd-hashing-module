#include <Python.h>

#include "gosthash.h"

static PyObject *gost_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    gost_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    gost_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef GostMethods[] = {
    { "getPoWHash", gost_getpowhash, METH_VARARGS, "Returns the proof of work hash using gost hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef GostModule = {
    PyModuleDef_HEAD_INIT,
    "gost_hash",
    "...",
    -1,
    gostMethods
};

PyMODINIT_FUNC PyInit_gost_hash(void) {
    return PyModule_Create(&GostModule);
}

#else

PyMODINIT_FUNC initgost_hash(void) {
    (void) Py_InitModule("gost_hash", GostMethods);
}
#endif
