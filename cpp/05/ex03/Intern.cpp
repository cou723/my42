#include "Intern.hpp"
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
Intern::Intern() {}
Intern::Intern(const Intern& i) {
    (void)i;
}
Intern::~Intern() {}
Intern* Intern::operator=(const Intern& i) {
    (void)i;
    return this;
}

AForm* _create_ppf(std::string const& target) {
    return (new PresidentialPardonForm(target));
}

AForm* _create_rrf(std::string const& target) {
    return (new RobotomyRequestForm(target));
}

AForm* _create_scf(std::string const& target) {
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(const std::string& form_name,
                        const std::string& form_target) {
    std::size_t const form_count = 3;
    std::string const form_names[form_count] = {
        "presidential pardon", "robotomy request", "shrubbery creation"};
    AForm* (*form_creators[form_count])(std::string const&) = {
        &_create_ppf, &_create_rrf, &_create_scf};
    for (size_t i = 0; i < form_count; i++) {
        if (form_name == form_names[i]) {
            AForm* new_form = (*form_creators[i])(form_target);
            std::cout << "Intern creates " << form_names[i] << std::endl;
            return new_form;
        }
    }
    throw Intern::RequestFormNotDefined();
    return NULL;
}

const char* Intern::RequestFormNotDefined::what(void) const throw()
{
	return ("The given form name does not exist.");
}