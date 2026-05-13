#ifndef AFORM_HPP
#define AFORM_HPP

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

class Bureaucrat; // forward declaration

class AForm {
private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeToSign;
    const int           _gradeToExecute;

public:
    // Orthodox Canonical Form
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Getters
    const std::string&  getName()           const;
    bool                isSigned()          const;
    int                 getGradeToSign()    const;
    int                 getGradeToExecute() const;

    // Sign
    void    beSigned(const Bureaucrat& b);

    // Execute — checks preconditions then calls the protected action
    void    execute(const Bureaucrat& executor) const;

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };

protected:
    // Pure virtual: each concrete form implements its own action
    virtual void    executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
