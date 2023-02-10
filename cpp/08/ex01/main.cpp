#include <iostream>
#include <vector>
#include "Span.hpp"
void display_message(std::string s) {
    std::cout << "\e[0;32m--" << s << "--\e[0m" << std::endl;
}

int main() {
    display_message("Subject Test");
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    display_message("Exception Test");
    {
        Span sp = Span(1);
        sp.addNumber(1);
        try {
            sp.addNumber(1);
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << sp.shortestSpan() << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    display_message("Zero Span");
    {
        Span sp = Span(2);
        sp.addNumber(10);
        sp.addNumber(10);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    display_message("N = 0");
    {
        Span sp = Span(0);
        try {
            sp.addNumber(1);
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << sp.shortestSpan() << std::endl;
        } catch (std::exception& e) {
            std::cout << "shortestSpan() exception detected : " << e.what()
                      << std::endl;
        }
        try {
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception& e) {
            std::cout << "longestSpan() exception detected : " << e.what()
                      << std::endl;
        }
    }

    display_message("Empty Span");
    {
        Span sp = Span(10);
        try {
            std::cout << sp.shortestSpan() << std::endl;
        } catch (std::exception& e) {
            std::cout << "shortestSpan() exception detected : " << e.what()
                      << std::endl;
        }
        try {
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception& e) {
            std::cout << "longestSpan() exception detected : " << e.what()
                      << std::endl;
        }
    }

    display_message("100000 Span");
    {
        Span sp = Span(100000);
        for (size_t i = 0; i < 100000; i++)
            sp.addNumber(i);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    display_message("Multi Add Number Test");
    {
        Span sp = Span(5);
        int array[] = {1, 10, 100, 1000, 10000};
        std::vector<int> vec(array, array + 4);
        sp.addNumbers(vec.begin(), vec.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    display_message("Multi Add Number Exception Test");
    {
        Span sp = Span(5);
        std::vector<int> vec(6, 0);
        try {
            sp.addNumbers(vec.begin(), vec.end());
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    display_message("Empty Test");
    {
        Span sp = Span();
        std::vector<int> vec(6, 0);
        try {
            sp.addNumbers(vec.begin(), vec.end());
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}