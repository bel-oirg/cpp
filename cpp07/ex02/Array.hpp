#pragma once

#include <iostream>
#include <string.h>

template <typename T>
class Array
{
    private:
        T               *arr;
        unsigned int    _size;

    public:
    Array();
    Array(unsigned int n);
    Array(const Array &cpy);
    ~Array();
    T &operator[](unsigned int size);
    class out_of_range : public std::exception
    {
        public:
            virtual const char* what() const throw();
    }
    // T& operator[](int size) const;

    unsigned int size() const;
};
