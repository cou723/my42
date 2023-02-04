#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

const std::string PresidentialPardonForm::_default_name =
    "presidential pardon form";

PresidentialPardonForm::PresidentialPardonForm()
    : AForm(_default_name, _default_sign_grade, _default_exec_grade) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(_default_name, _default_sign_grade, _default_exec_grade) {
    this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& ppf)
    : AForm(ppf) {
    *this = ppf;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& ppf) {
    if (this != &ppf)
        this->_target = ppf._target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (executor.getGrade() > this->getExecGrade()) {
        throw AForm::GradeTooLowException();
    }
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}
