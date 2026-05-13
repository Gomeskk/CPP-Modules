#include "Bureaucrat.hpp"

// ── Constructors / Destructor ──────────────────────────────────────────────────

// Default constructor — creates a safe lowest-rank bureaucrat
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
    std::cout << GREEN << "✓ Bureaucrat default constructor called" << RESET << std::endl;
}

// Parameterized constructor — validates grade AFTER member initialisation.
// We must throw here because constructors have no return value; this is the
// only clean way to signal that the object cannot be validly created.
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException(); // grade 0 or negative is above the top rank
    if (grade > 150)
        throw GradeTooLowException();  // grade 151+ is below the bottom rank
    std::cout << GREEN << "✓ Bureaucrat parameterized constructor called" << RESET << std::endl;
}

// Copy constructor — _name is const so it must be set in the initialiser list
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << BLUE << "⎘ Bureaucrat copy constructor called" << RESET << std::endl;
}

// Copy assignment operator — cannot reassign _name because it is const;
// only _grade can change. Self-assignment guard prevents _grade = _grade.
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

// incrementGrade: lowers the grade NUMBER (higher seniority).
// Grade 1 is already the top — going higher would be invalid.
void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--; // e.g. grade 3 → 2
}

// decrementGrade: raises the grade NUMBER (lower seniority).
// Grade 150 is already the bottom — going lower would be invalid.
void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++; // e.g. grade 3 → 4
}

// ── Exception messages ─────────────────────────────────────────────────────────
// what() returns a C-string describing the error, used by catch blocks.
// 'throw()' is the C++98 no-throw specifier required to match std::exception.

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high (minimum is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low (maximum is 150)";
}

// ── Insertion operator ─────────────────────────────────────────────────────────
// Overloads << so a Bureaucrat can be printed with std::cout directly.
// Returns os by reference to allow chaining (e.g. cout << a << b).

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << CYAN << b.getName() << ", bureaucrat grade " << b.getGrade() << RESET;
    return os;
}
