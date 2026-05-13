#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

// ANSI color codes
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define BLUE    "\033[34m"

class Bureaucrat; // forward declaration — breaks the circular include with Bureaucrat.hpp

class Form {
private:
    const std::string   _name;           // immutable form name
    bool                _signed;         // starts false; set to true by beSigned()
    const int           _gradeToSign;    // minimum bureaucrat grade to sign (lower number = higher rank)
    const int           _gradeToExecute; // minimum bureaucrat grade to execute

public:
    // Orthodox Canonical Form
    Form();
    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    // Getters
    const std::string&  getName()           const;
    bool                isSigned()          const;
    int                 getGradeToSign()    const;
    int                 getGradeToExecute() const;

    // Attempt to sign: throws GradeTooLowException if the bureaucrat isn't senior enough
    void    beSigned(const Bureaucrat& b);

    // Nested exception classes — no OCF required
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
