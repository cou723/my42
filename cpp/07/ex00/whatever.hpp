#ifndef WHATEVER_H
#define WHATEVER_H

template <typename T>
T const& max(T const& a, T const& b) {
    return (a > b) ? a : b;
}

template <typename T>
T const& min(T const& a, T const& b) {
    return (a < b) ? a : b;
}

template <typename T>
void swap(T & a, T & b) {
    T tmp = a;
    a = b;
    b = tmp;
}

#endif /* WHATEVER_H */
