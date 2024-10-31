#pragma once

#include <iostream>
#include <string.h>

template <typename T>
void iter(T *a, size_t len, void (*itered)(T &))
{
    for (size_t index = 0; index < len; index++)
        itered(a[index]);
}