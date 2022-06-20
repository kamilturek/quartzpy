#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include <CoreGraphics/CGDisplayConfiguration.h>

/* Display type */
typedef struct {
  PyObject_HEAD
} DisplayObject;

static PyTypeObject DisplayType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "quartz.Display",
    .tp_doc = PyDoc_STR("Display objects"),
    .tp_basicsize = sizeof(DisplayObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
};

/* quartz module */

static PyObject *quartz_count_displays(PyObject *self, PyObject *args) {
    uint32_t count;
    CGGetOnlineDisplayList(UINT32_MAX, NULL, &count);
    return PyLong_FromLong(count);
}

static PyObject *quartz_list_displays(PyObject *self, PyObject *args) {
    return PyLong_FromLong(55);
}

static PyMethodDef QuartzMethods[] = {
    {
        "count_displays",
        quartz_count_displays,
        METH_VARARGS,
        "Provides a count of displays that are online (active, mirrored, or "
        "sleeping)."
    },
    {
        "list_displays",
        quartz_list_displays,
        METH_VARARGS,
        "Provides a list of displays that are online (active, mirrored, or "
        "sleeping)."
    },
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef quartzmodule = {
    PyModuleDef_HEAD_INIT,
    .m_name = "quartz",
    .m_doc = NULL,
    .m_size = -1,
    .m_methods = QuartzMethods,
};

PyMODINIT_FUNC PyInit_quartz(void) { 
    PyObject *m;

    if (PyType_Ready(&DisplayType) < 0)
        return NULL;

    m = PyModule_Create(&quartzmodule);
    if (m == NULL)
        return NULL;

    Py_INCREF(&DisplayType);
    if (PyModule_AddObject(m, "Display", (PyObject *) &DisplayType) < 0) {
        Py_DECREF(&DisplayType);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
