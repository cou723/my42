#ifndef ITER_H
#define ITER_H
#include <cstddef>
template <typename T>
void iter(T* array, std::size_t count, void (*f)(T const &element)) {
    for (size_t i = 0; i < count; i++)
        (*f)(array[i]);
}

#endif /* ITER_H */
