#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
    std::cout << "Bureaucrat name,grade constructor" << std::endl;

    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& b) {
    std::cout << "Bureaucrat copy constructor" << std::endl;
    *this = b;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat* Bureaucrat::operator=(const Bureaucrat& b) {
    std::cout << "Bureaucrat assignment operator" << std::endl;
    if (this != &b) {
        this->_grade = b._grade;
    }
    return this;
}

std::string Bureaucrat::getName() const {
    return this->_name;
}

unsigned int Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::incrementGrade() {
    this->_grade -= 1;
}

void Bureaucrat::decrementGrade() {
    this->_grade += 1;
}

void Bureaucrat::signForm(Form& f) const {
    try {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << this->getName() << " couldn't sign " << f.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Bureaucrat's grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
    return ("Bureaucrat's grade is too low.");
}