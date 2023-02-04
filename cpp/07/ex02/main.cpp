#include <cstddef>
#include <iostream>
#include "Array.hpp"

void display_message(std::string s) {
    std::cout << "\e[0;32m--" << s << "--\e[0m" << std::endl;
}

int main() {
    // "Constructor Test"
    Array<int> a(10);
    // Index Assignment Test"
    a[0] = 100;
    display_message("Index Access Test");
    std::cout << "a[0]: " << a[0] << std::endl;

    display_message("size() Test");
    std::cout << "a.size(): " << a.size() << std::endl;

    display_message("Out of index exception tests");
    try {
        (void)a[1000];
    } catch (std::exception& e) {
        std::cout << "exception detected" << std::endl;
    }
    try {
        (void)a[-10];
    } catch (std::exception& e) {
        std::cout << "exception detected" << std::endl;
    }

    display_message("Copy constructor Test");
    Array<int> x(a);
    std::cout << "a[0] :" << a[0] << " address :" << &a[0] << std::endl;
    std::cout << "x[0] :" << x[0] << " address :" << &x[0] << std::endl;

    display_message("Assignment operator Test");
    Array<int> y = x;
    std::cout << "x[0] :" << x[0] << " address :" << &x[0] << std::endl;
    std::cout << "y[0] :" << y[0] << " address :" << &y[0] << std::endl;

    return 0;
}
