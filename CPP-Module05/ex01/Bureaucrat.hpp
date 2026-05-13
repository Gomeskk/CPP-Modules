#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

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

class Form; // forward declaration — avoids a circular include between the two headers

class Bureaucrat {
private:
    const std::string   _name;  // immutable: set once at construction
    int                 _grade; // 1 = highest, 150 = lowest

public:
    // Orthodox Canonical Form
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters
    const std::string&  getName()  const;
    int                 getGrade() const;

    // Grade modifiers — throw if result would leave [1, 150]
    void    incrementGrade(); // lowers the number (more senior)
    void    decrementGrade(); // raises the number (less senior)

    // Form signing — delegates to Form::beSigned(), catches & reports errors
    void    signForm(Form& form);

    // Nested exception classes — no OCF needed per the subject
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
