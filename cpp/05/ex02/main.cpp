#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
void display_message(std::string s) {
    std::cout << "\e[0;32m-- " << s << " --\e[0m" << std::endl;
}

void bureaucrat_tests() {
    display_message("<Bureaucrat Test>");
    {
        display_message("Bureaucrat Constructor Test");
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
    } catch (std::exception& e) {
        std::cout << "catch: " << e.what() << std::endl;
    }
    try {
        Bureaucrat b3("Bob3", 0);
    } catch (std::exception& e) {
        std::cout << "catch: " << e.what() << std::endl;
    }
}

void sign_test(unsigned int grade, AForm& form) {
    Bureaucrat b("test", grade);
    std::cout << b << std::endl;
    b.signForm(form);
    display_message("");
}

void exec_test(unsigned int grade, AForm& form) {
    Bureaucrat b("test", grade);
    std::cout << b << std::endl;
    b.executeForm(form);
    display_message("");
}

void shrubbery_creation_form_tests() {
    display_message("< ShrubberyCreationForm Test >");
    {
        display_message("ShrubberyCreationForm Constructor Test");
        ShrubberyCreationForm scf1;
        ShrubberyCreationForm scf2("test target");
        ShrubberyCreationForm scf3(scf2);
        std::cout << scf3.getTarget() << std::endl;
    }
    ShrubberyCreationForm scf("home");
    display_message("form information");
    std::cout << scf << std::endl;
    display_message("Unsigned Exec Test");
    exec_test(1, scf);

    display_message("Sign Test");
    sign_test(136, scf);
    sign_test(137, scf);
    sign_test(145, scf);
    sign_test(146, scf);
    sign_test(150, scf);

    display_message("Exec Test");
    exec_test(136, scf);
    exec_test(137, scf);
    exec_test(145, scf);
    exec_test(146, scf);
    exec_test(150, scf);

    display_message("");
}

void robotomy_request_form_tests() {
    display_message("<RobotomyRequestForm Test>");
    {
        display_message("RobotomyRequestForm Constructor Test");
        RobotomyRequestForm rrf1;
        RobotomyRequestForm rrf2("test target");
        RobotomyRequestForm rrf3(rrf2);
        std::cout << rrf3.getTarget() << std::endl;
    }
    RobotomyRequestForm rrf("bob");
    display_message("form information");
    std::cout << rrf << std::endl;
    display_message("Unsigned Exec Test");
    exec_test(1, rrf);

    display_message("Sign Test");
    sign_test(44, rrf);
    sign_test(45, rrf);
    sign_test(72, rrf);
    sign_test(73, rrf);

    display_message("Exec Test");
    exec_test(44, rrf);
    exec_test(45, rrf);
    exec_test(72, rrf);
    exec_test(73, rrf);
}

void presidential_pardon_form_tests() {
    display_message("< PresidentialPardonForm Test >");
    {
        display_message("PresidentialPardonForm Constructor Test");
        PresidentialPardonForm ppf1;
        PresidentialPardonForm ppf2("test target");
        PresidentialPardonForm ppf3(ppf2);
        std::cout << ppf3.getTarget() << std::endl;
    }
    PresidentialPardonForm ppf("break town");
    display_message("form information");
    std::cout << ppf << std::endl;
    display_message("Unsigned Exec Test");
    exec_test(1, ppf);

    display_message("Sign Test");
    sign_test(5, ppf);
    sign_test(25, ppf);
    sign_test(30, ppf);
    sign_test(150, ppf);

    display_message("Exec Test");
    exec_test(5, ppf);
    exec_test(25, ppf);
    exec_test(30, ppf);
    exec_test(150, ppf);
}

int main() {
    // bureaucrat_tests();
    shrubbery_creation_form_tests();
    robotomy_request_form_tests();
    presidential_pardon_form_tests();
    return 0;
}
