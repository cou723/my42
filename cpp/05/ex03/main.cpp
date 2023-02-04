#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
        Bureaucrat bureaucrat(a);
        Bureaucrat c;
        a = c;
    }

    display_message("getName() getGrade() Test");
    Bureaucrat bureaucrat1("Bob", 2);
    std::cout << "getName(): " << bureaucrat1.getName() << std::endl;
    std::cout << "getGrade(): " << bureaucrat1.getGrade() << std::endl;

    display_message("Increment Decrement Test");
    bureaucrat1.incrementGrade();
    std::cout << "getGrade(): " << bureaucrat1.getGrade() << std::endl;
    bureaucrat1.decrementGrade();
    std::cout << "getGrade(): " << bureaucrat1.getGrade() << std::endl;

    display_message("Grade Overflow Test");
    Bureaucrat bureaucrat2("Bob2", 149);
    bureaucrat2.incrementGrade();
    bureaucrat2.incrementGrade();
    std::cout << "getGrade(): " << bureaucrat1.getGrade() << std::endl;

    display_message("Grade Underflow Test");
    bureaucrat1.decrementGrade();
    bureaucrat1.decrementGrade();
    std::cout << "getGrade(): " << bureaucrat1.getGrade() << std::endl;

    display_message("Insert operator operand Test");
    std::cout << bureaucrat1 << std::endl;
    std::cout << bureaucrat2 << std::endl;

    display_message("Constructor exception Test");
    try {
        Bureaucrat bureaucrat3("Bob3", 160);
    } catch (std::exception& e) {
        std::cout << "catch: " << e.what() << std::endl;
    }
    try {
        Bureaucrat bureaucrat3("Bob3", 0);
    } catch (std::exception& e) {
        std::cout << "catch: " << e.what() << std::endl;
    }
}

void sign_test(unsigned int grade, AForm& form) {
    Bureaucrat bureaucrat("test", grade);
    std::cout << bureaucrat << std::endl;
    bureaucrat.signForm(form);
    display_message("");
}

void exec_test(unsigned int grade, AForm& form) {
    Bureaucrat bureaucrat("test", grade);
    std::cout << bureaucrat << std::endl;
    bureaucrat.executeForm(form);
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

void intern_tests() {
    display_message(" < Intern Test > ");
    {
        display_message("normal makeForm() Test");
        Intern intern;
        AForm* scf = intern.makeForm("shrubbery creation", "one");
        AForm* rrf = intern.makeForm("robotomy request", "two");
        AForm* ppf = intern.makeForm("presidential pardon", "three");
        std::cout << *scf << std::endl;
        std::cout << *rrf << std::endl;
        std::cout << *ppf << std::endl;
        display_message("exception makeForm() Test");
        try {
            intern.makeForm("invalid form name", "test");
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        delete scf;
        delete rrf;
        delete ppf;
    }
    {
        display_message("Returned Form Check");
        Intern intern;
        Bureaucrat bureaucrat("master", 1);
        AForm* scf = intern.makeForm("shrubbery creation", "target1");
        AForm* rrf = intern.makeForm("robotomy request", "target2");
        AForm* ppf = intern.makeForm("presidential pardon", "target3");
        std::cout << *scf << std::endl;
        std::cout << *rrf << std::endl;
        std::cout << *ppf << std::endl;
        bureaucrat.signForm(*scf);
        bureaucrat.signForm(*rrf);
        bureaucrat.signForm(*ppf);
        bureaucrat.executeForm(*scf);
        bureaucrat.executeForm(*rrf);
        bureaucrat.executeForm(*ppf);
        delete scf;
        delete rrf;
        delete ppf;
    }
}

int main() {
    bureaucrat_tests();
    shrubbery_creation_form_tests();
    robotomy_request_form_tests();
    presidential_pardon_form_tests();
    intern_tests();
    return 0;
}
