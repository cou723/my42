#ifndef AFORM_H
#define AFORM_H
#include <string>
#include "Bureaucrat.hpp"
#include <exception>
class Bureaucrat;

class AForm {
   private:
    const std::string _name;
    bool _is_signed;
    const unsigned int _sign_grade;
    const unsigned int _exec_grade;

   protected:
    std::string _target;
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what(void) const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what(void) const throw();
    };
    class FormNotSignedException : public std::exception {
       public:
        virtual const char* what(void) const throw();
    };

   public:
    AForm();
    AForm(const AForm& f);
    AForm(const std::string& name,
          unsigned int sign_grade,
          unsigned int exec_grade);
    virtual ~AForm();
    AForm* operator=(const AForm& f);

    void beSigned(const Bureaucrat& b);
    const std::string getName() const;
    bool getIsSigned() const;
    unsigned int getSignGrade() const;
    unsigned int getExecGrade() const;
    const std::string getTarget() const;
    virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif /* AFORM_H */
