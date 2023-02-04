#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
   private:
    static const std::string _default_name;
    static const unsigned int _default_sign_grade = 145;
    static const unsigned int _default_exec_grade = 137;

   public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm& scf);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& scf);

    void execute(Bureaucrat const& executor) const;
};

#endif /* SHRUBBERYCREATIONFORM_H */
