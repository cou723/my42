#include "Form.hpp"
#include <iostream>
#include <string>
Form::Form() : _name("default"), _is_signed(false), _grade(10) {
    std::cout << "Form default constructor" << std::endl;
}

Form::Form(const std::string& name, unsigned int grade)
    : _name(name), _is_signed(false), _grade(grade) {
    std::cout << "Form name,grade constructor" << std::endl;
    if (grade < 1)
        throw Form::GradeTooLowException();
    if (grade > 150)
        throw Form::GradeTooHighException();
}

Form::Form(const Form& f) : _grade(f._grade) {
    std::cout << "Form copy constructor" << std::endl;
    *this = f;
}

Form::~Form() {
    std::cout << "Form destructor" << std::endl;
}

Form* Form::operator=(const Form& f) {
    std::cout << "Form assignment operator" << std::endl;

    if (this != &f) {
        this->_is_signed = f._is_signed;
    }
    return this;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->_grade)
        throw Form::GradeTooLowException();
    this->_is_signed = true;
}

const std::string Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_is_signed;
}

unsigned int Form::getGrade() const {
    return this->_grade;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat's grade is too high for this form.");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat's grade is too low for this form.");
}

std::ostream& operator<<(std::ostream& out, const Form& f) {
    out << "NAME: " << f.getName() << std::endl
        << "GRADE: " << f.getGrade() << std::endl
        << "IS SIGNED: " << (f.getIsSigned() ? "TRUE" : "FALSE");
    return out;
}
