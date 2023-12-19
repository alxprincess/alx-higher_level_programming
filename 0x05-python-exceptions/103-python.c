#include <Python.h>

/**
 * print_python_list - to print some basic info about Python lists
 * @p: PyObject (Python list)
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t i, size;
    PyObject *item;

    if (!PyList_Check(p))
    {
        fprintf(stderr, "[ERROR] Invalid List Object\n");
        return;
    }

    size = PyList_Size(p);
    printf("[*] Python list info\n[*] Size of the Python List = %ld\n[*] Allocated = %ld\n", size, ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++)
    {
        item = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
        if (PyBytes_Check(item))
            print_python_bytes(item);
        else if (PyFloat_Check(item))
            print_python_float(item);
    }
}

/**
 * print_python_bytes - to print some basic info about Python bytes
 * @p: PyObject (Python bytes)
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t i, size;
    char *str;

    if (!PyBytes_Check(p))
    {
        fprintf(stderr, "[ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    printf("[.] bytes object info\n  size: %ld\n  trying string: %s\n  first 10 bytes: ", size, PyBytes_AsString(p));

    str = PyBytes_AsString(p);
    for (i = 0; i < size && i < 10; i++)
    {
        printf("%02x", str[i] & 0xff);
        if (i < size - 1)
            printf(" ");
    }
    printf("\n");
}
