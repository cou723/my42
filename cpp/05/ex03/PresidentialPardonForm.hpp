#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   private:
    static const std::string _default_name;
    static const unsigned int _default_sign_grade = 25;
    static const unsigned int _default_exec_grade = 5;

   public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& ppf);
    ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& ppf);

    void execute(Bureaucrat const& executor) const;
};

#endif /* PRESIDENTIALPARDONFORM_H */
