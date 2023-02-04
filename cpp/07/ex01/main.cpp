#include <cstddef>
#include <iostream>
#include <string>
#include "iter.hpp"
void display_message(std::string s) {
    std::cout << "\e[0;32m--" << s << "--\e[0m" << std::endl;
}

template<typename T>
void increment(T& x) {
    x++;
}

void add_a(std::string& x) {
    x = x + "_a";
}

template <typename T>
void print_array(T* array, std::size_t array_size) {
    for (size_t i = 0; i < array_size; i++) {
        std::cout << array[i];
        if (i + 1 != array_size)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

int main(void) {
    display_message("Multi Type Test");
    {
        display_message("int");
        int array[] = {1, 2, 3};
        iter(array, 3, increment);
        print_array(array, 3);
    }
    {
        display_message("char");
        char array[] = {'a', 'b', 'c'};
        iter(array, 3, increment);
        print_array(array, 3);
    }
    {
        display_message("double");
        double array[] = {1.1, 2.2, 3.3};
        iter(array, 3, increment);
        print_array(array, 3);
    }
    {
        display_message("string");
        std::string array[] = {"one", "two", "three"};
        iter(array, 3, add_a);
        print_array(array, 3);
    }

    display_message("Many Elements Test");
    const std::size_t array_size = 100;
    int array[array_size];
    for (size_t i = 0; i < array_size; i++)
        array[i] = i;
    iter(array, array_size, increment);
    print_array(array, array_size);
}