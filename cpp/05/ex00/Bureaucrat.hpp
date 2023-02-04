#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <string>
class Bureaucrat {
   private:
    const std::string _name;
    unsigned int _grade;
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what(void) const throw();
    };
    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what(void) const throw();
    };

   public:
    Bureaucrat();
    Bureaucrat(std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat& b);
    ~Bureaucrat();
    Bureaucrat* operator=(const Bureaucrat& b);

    std::string getName() const;
    unsigned int getGrade() const;
    void incrementGrade();
    void decrementGrade();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif /* BUREAUCRAT_H */
