#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

const std::string RobotomyRequestForm::_default_name = "robotomy request form";

RobotomyRequestForm::RobotomyRequestForm()
    : AForm(_default_name, _default_sign_grade, _default_exec_grade) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm(_default_name, _default_sign_grade, _default_exec_grade) {
    this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rrf)
    : AForm(rrf) {
    *this = rrf;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& rrf) {
    if (this != &rrf)
        this->_target = rrf._target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    if (executor.getGrade() > this->getExecGrade()) {
        throw AForm::GradeTooLowException();
    }
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    std::cout << "Guiiiiiiiin" << std::endl;
    if (rand() % 2)
        std::cout << this->_target << " has been successfully robotized!"
                  << std::endl;
    else
        std::cout << this->_target << " failed to robotize..." << std::endl;
}