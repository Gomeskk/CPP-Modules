#include "Bureaucrat.hpp"
#include "AForm.hpp"

// ── Constructors / Destructor ──────────────────────────────────────────────────

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    std::cout << GREEN << "✓ Bureaucrat default constructor called" << RESET << std::endl;
}

// Grade validated after initialisation — throwing here prevents a bad object
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << GREEN << "✓ Bureaucrat parameterized constructor called" << RESET << std::endl;
}

// _name is const — must be copied via the initialiser list
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << BLUE << "⎘ Bureaucrat copy constructor called" << RESET << std::endl;
}

// Only _grade can be reassigned; _name is const
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << YELLOW << "⟵ Bureaucrat copy assignment operator called" << RESET << std::endl;
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << RED << "✗ Bureaucrat destructor called" << RESET << std::endl;
}

// ── Getters ────────────────────────────────────────────────────────────────────

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// ── Grade modifiers ────────────────────────────────────────────────────────────

void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--; // lower number = higher rank
}

void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++; // higher number = lower rank
}

// ── signForm ──────────────────────────────────────────────────────────────────

void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);  // pass ourselves by const ref
        std::cout << GREEN << _name << " signed " << form.getName() << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << RED << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << RESET << std::endl;
    }
}

// ── executeForm ───────────────────────────────────────────────────────────────
// AForm::execute() checks that the form is signed and that our grade is high
// enough, then calls the concrete executeAction(). Any failure throws — caught
// and reported here.

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);  // execute() is non-virtual; it calls virtual executeAction()
        std::cout << GREEN << _name << " executed " << form.getName() << RESET << std::endl;
    }
    catch (std::exception& e) {
        std::cout << RED << _name << " couldn't execute " << form.getName()
                  << " because " << e.what() << RESET << std::endl;
    }
}

// ── Exception messages ─────────────────────────────────────────────────────────

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high (minimum is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low (maximum is 150)";
}

// ── Insertion operator ─────────────────────────────────────────────────────────

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << CYAN << b.getName() << ", bureaucrat grade " << b.getGrade() << RESET;
    return os;
}
