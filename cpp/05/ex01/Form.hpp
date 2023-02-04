#ifndef FORM_H
#define FORM_H
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {
   private:
    const std::string _name;
    bool _is_signed;
    const unsigned int _grade;
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what(void) const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what(void) const throw();
    };

   public:
    Form();
    Form(const Form& f);
    Form(const std::string &name, unsigned int grade);
    ~Form();
    Form* operator=(const Form& f);

    void beSigned(const Bureaucrat& b);
    const std::string getName() const;
    bool getIsSigned() const;
    unsigned int getGrade() const;
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif /* FORM_H */
