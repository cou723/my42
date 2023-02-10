#include <cstddef>
#include <cstdlib>
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

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
        std::cerr << "exception detected" << std::endl;
    }
    try {
        (void)a[-10];
    } catch (std::exception& e) {
        std::cerr << "exception detected" << std::endl;
    }

    display_message("Zero Size Test");
    {
        Array<int> a(0);
        try {
            (void)a[0];
        } catch (std::exception& e) {
            std::cerr << "exception detected" << std::endl;
        }
    }

    display_message("Copy constructor Test");
    Array<int> x(a);
    std::cout << "a[0] :" << a[0] << " address :" << &a[0] << std::endl;
    std::cout << "x[0] :" << x[0] << " address :" << &x[0] << std::endl;

    display_message("Assignment operator Test");
    Array<int> y = x;
    std::cout << "x[0] :" << x[0] << " address :" << &x[0] << std::endl;
    std::cout << "y[0] :" << y[0] << " address :" << &y[0] << std::endl;

    display_message("Subject Test");

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try {
        numbers[-2] = 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete[] mirror;  //
    return 0;
}
