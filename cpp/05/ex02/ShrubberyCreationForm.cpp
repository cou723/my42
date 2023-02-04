#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
const std::string ShrubberyCreationForm::_default_name =
    "shrubbery creation form";

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm(_default_name, _default_sign_grade, _default_exec_grade) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(_default_name, _default_sign_grade, _default_exec_grade) {
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rrf)
    : AForm(rrf) {
    *this = rrf;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& scf) {
    if (this != &scf)
        this->_target = scf._target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (executor.getGrade() > this->getExecGrade()) {
        throw AForm::GradeTooLowException();
    }
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    std::ofstream ofs((this->_target + "_shrubbery").c_str());
    ofs << "                                              ." << std::endl
        << "                                   .         ;" << std::endl
        << "      .              .              ;%     ;;" << std::endl
        << "        ,           ,                :;%  %;" << std::endl
        << "         :         ;                   :;%;'     .," << std::endl
        << ",.        %;     %;            ;        %;'    ,;" << std::endl
        << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl
        << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl
        << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl
        << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl
        << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl
        << "         `:%;.  :;bd%;          %;@%;'" << std::endl
        << "           `@%:.  :;%.         ;@@%;'" << std::endl
        << "             `@%.  `;@%.      ;@@%;" << std::endl
        << "               `@%%. `@%%    ;@@%;" << std::endl
        << "                 ;@%. :@%%  %@@%;" << std::endl
        << "                   %@bd%%%bd%%:;" << std::endl
        << "                     #@%%%%%:;;" << std::endl
        << "                     %@@%%%::;" << std::endl
        << "                     %@@@%(o);  . '" << std::endl
        << "                     %@@@o%;:(.,'" << std::endl
        << "                 `.. %@@@o%::;" << std::endl
        << "                    `)@@@o%::;" << std::endl
        << "                     %@@(o)::;" << std::endl
        << "                    .%@@@@%::;" << std::endl
        << "                    ;%@@@@%::;." << std::endl
        << "                   ;%@@@@%%:;;;." << std::endl
        << "               ...;%@@@@@%%:;;;;,..\"" << std::endl;
}
