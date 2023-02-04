#include <iostream>
#include "Bureaucrat.hpp"

void display_message(std::string s) {
    std::cout << "\e[0;32m--" << s << "--\e[0m" << std::endl;
}

int main() {
    {
        display_message("Constructor Test");
        Bureaucrat a;
        Bureaucrat b(a);
        Bureaucrat c;
        a = c;
    }

    display_message("getName() getGrade() Test");
    Bureaucrat b1("Bob", 2);
    std::cout << "getName(): " << b1.getName() << std::endl;
    std::cout << "getGrade(): " << b1.getGrade() << std::endl;

    display_message("Increment Decrement Test");
    b1.incrementGrade();
    std::cout << "getGrade(): " << b1.getGrade() << std::endl;
    b1.decrementGrade();
    std::cout << "getGrade(): " << b1.getGrade() << std::endl;

    display_message("Grade Overflow Test");
    Bureaucrat b2("Bob2", 149);
    b2.incrementGrade();
    b2.incrementGrade();
    std::cout << "getGrade(): " << b1.getGrade() << std::endl;

    display_message("Grade Underflow Test");
    b1.decrementGrade();
    b1.decrementGrade();
    std::cout << "getGrade(): " << b1.getGrade() << std::endl;

    display_message("Insert operator operand Test");
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    display_message("Constructor exception Test");
    try {
        Bureaucrat b3("Bob3", 160);
    } catch (std::exception &e) {
        std::cout << "catch: " << e.what() << std::endl;
    }
    try {
        Bureaucrat b3("Bob3", 0);
    } catch (std::exception &e) {
        std::cout << "catch: " << e.what() << std::endl;
    }
    return 0;
}
