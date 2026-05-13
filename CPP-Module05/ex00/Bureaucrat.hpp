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

class Bureaucrat {
private:
    const std::string   _name;  // name is const: cannot change after construction
    int                 _grade; // 1 = highest rank, 150 = lowest rank

public:
    // Orthodox Canonical Form — required by the subject for every non-exception class
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters — return by const ref / value to protect internal state
    const std::string&  getName() const;
    int                 getGrade() const;

    // Grade modifiers — throw if the new grade would go out of [1, 150]
    // Note: increment lowers the number (grade 3 → 2 = more senior)
    void    incrementGrade();
    void    decrementGrade();

    // Nested exception classes — inherit std::exception so they can be caught
    // with 'catch (std::exception& e)'. They do NOT need OCF per the subject.
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw(); // throw() = no-throw specifier (C++98)
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
