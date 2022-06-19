#define PY_SSIZE_T_CLEAN
#include <CoreGraphics/CGDisplayConfiguration.h>
#include "Python.h"

static PyObject *
quartz_list_displays(PyObject *self, PyObject *args)
{
    return PyLong_FromLong(55);
}

static PyMethodDef QuartzMethods[] = {
    {"list_displays", quartz_list_displays, METH_VARARGS,
     "Provides a list of displays that are online (active, mirrored, or "
     "sleeping)."},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef quartzmodule = {PyModuleDef_HEAD_INIT, "quartz", /* name of module */
                                          NULL,                            /* module documentation, may be NULL */
                                          -1,                              /* size of per-interpreter state of the module,
                                                                              or -1 if the module keeps state in global variables. */
                                          QuartzMethods};

PyMODINIT_FUNC PyInit_quartz(void)
{
    return PyModule_Create(&quartzmodule);
}
