#ifndef ARRAY_H
#define ARRAY_H
#include <cstddef>

template <typename T>
class Array {
   private:
    T* _array;
    const unsigned int _size;

   public:
    Array<T>();
    Array<T>(unsigned int n);
    Array<T>(const Array<T>& a);
    ~Array<T>();

    Array<T>& operator=(const Array<T>& a);
    T& operator[](std::size_t i);
    std::size_t size() const;
};

#include "Array.tpp"

#endif /* ARRAY_H */
