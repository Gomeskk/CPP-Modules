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

class Bureaucrat; // forward declaration — breaks the circular include

// AForm is an abstract base class — it cannot be instantiated directly.
// The pure virtual executeAction() forces every subclass to implement
// its own specific action, while keeping shared logic (grades, signing,
// execution checks) here in the base.
class AForm {
private:
    // All attributes are private — subclasses access them only through getters.
    const std::string   _name;
    bool                _signed;         // false at construction; set true by beSigned()
    const int           _gradeToSign;    // minimum seniority required to sign
    const int           _gradeToExecute; // minimum seniority required to execute

public:
    // Orthodox Canonical Form
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm(); // virtual destructor — ensures the right destructor is called
                      // when deleting a subclass through an AForm* pointer

    // Getters
    const std::string&  getName()           const;
    bool                isSigned()          const;
    int                 getGradeToSign()    const;
    int                 getGradeToExecute() const;

    // Sign: throws if the bureaucrat isn't senior enough
    void    beSigned(const Bureaucrat& b);

    // Execute: validates preconditions (signed + grade), then calls executeAction().
    // Centralising checks here avoids duplicating them in every subclass.
    void    execute(const Bureaucrat& executor) const;

    // Exception classes — no OCF required
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
    // Pure virtual — makes AForm abstract and forces each concrete subclass
    // to define what actually happens when the form is executed.
    virtual void    executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
