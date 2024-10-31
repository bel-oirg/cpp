#include "Array.hpp"

template<typename T>
Array<T>::Array() : arr(NULL), _size(0) {}

template<typename T>
T& Array<T>::operator[](unsigned int size)
{
    if (size >= _size)
        throw std::out_of_range("index is out of range");
    return (arr[size]);
}


template<typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    arr = new T[n];
}


template<typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

template<typename T>
Array<T>::~Array()
{
    delete [] arr;
}

// template<typename T>
// const T& Array<T>::operator[](unsigned int size)
// {
//     if (index >= size) {
//         throw std::out_of_range("Index out of bounds");
//     }
//     return array[index];
// }

void f()
{
    system("leaks arr");
}

int main()
{
    atexit(f);
    Array<int> emp(5);

    std::cout << "Size of emp " << emp.size() << std::endl;
}