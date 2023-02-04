#ifndef INTERN_H
#define INTERN_H
#include "AForm.hpp"
class Intern {
   public:
    Intern();
    Intern(const Intern& i);
    ~Intern();
    Intern* operator=(const Intern& i);

    AForm* makeForm(const std::string& form_name,
                    const std::string& form_target);
    class RequestFormNotDefined : public std::exception {
       public:
        virtual const char* what(void) const throw();
    };
};

#endif /* INTERN_H */
