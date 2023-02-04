#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
   private:
    static const std::string _default_name;
    static const unsigned int _default_sign_grade = 72;
    static const unsigned int _default_exec_grade = 45;

   public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& rrf);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& rrf);

    void execute(Bureaucrat const& executor) const;
};

#endif /* ROBOTOMYREQUESTFORM_H */
