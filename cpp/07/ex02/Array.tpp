#ifndef ARRAY_T
#define ARRAY_T
#include <exception>

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
    for (size_t i = 0; i < n; i++)
        _array[i] = 0;
}

template <typename T>
Array<T>::Array(const Array<T>& a) : _array(new T[a._size]), _size(a._size) {
    *this = a;
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}

template <typename T>
Array<T>& ::Array<T>::operator=(const Array<T>& a) {
    if (this != &a)
        for (size_t i = 0; i < a._size; i++)
            this->_array[i] = a._array[i];
    return *this;
}

template <typename T>
T& ::Array<T>::operator[](size_t i) {
    if(_size == 0)
        throw std::exception();
    if (i >= _size)
        throw std::exception();
    return _array[i];
}

template <typename T>
std::size_t Array<T>::size() const {
    return _size;
}

#endif /* ARRAY_T */
