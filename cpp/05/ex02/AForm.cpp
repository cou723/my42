#include "AForm.hpp"
#include <iostream>
#include <string>

AForm::AForm()
    : _name("default"), _is_signed(false), _sign_grade(10), _exec_grade(10) {}

AForm::AForm(const std::string& name,
             unsigned int sign_grade,
             unsigned int exec_grade)
    : _name(name),
      _is_signed(false),
      _sign_grade(sign_grade),
      _exec_grade(exec_grade) {
    if (sign_grade < 1 || exec_grade < 1)
        throw AForm::GradeTooLowException();
    if (sign_grade > 150 || exec_grade > 150)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& f)
    : _sign_grade(f._sign_grade), _exec_grade(f._exec_grade) {
    *this = f;
}

AForm::~AForm() {}

AForm* AForm::operator=(const AForm& f) {
    if (this != &f) {
        this->_is_signed = f._is_signed;
    }
    return this;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->_sign_grade)
        throw AForm::GradeTooLowException();
    this->_is_signed = true;
}

const std::string AForm::getName() const {
    return this->_name;
}

bool AForm::getIsSigned() const {
    return this->_is_signed;
}

unsigned int AForm::getSignGrade() const {
    return this->_sign_grade;
}

unsigned int AForm::getExecGrade() const {
    return this->_exec_grade;
}

const std::string AForm::getTarget() const {
    return this->_target;
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << "NAME: " << f.getName() << std::endl
        << "SIGN GRADE: " << f.getSignGrade() << std::endl
        << "EXEC GRADE: " << f.getExecGrade() << std::endl
        << "IS SIGNED: " << (f.getIsSigned() ? "TRUE" : "FALSE");
    return out;
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat's grade is too high for this form.");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat's grade is too low for this form.");
}


const char* AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form is not signed.");
}