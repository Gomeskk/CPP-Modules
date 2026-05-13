#include "Form.hpp"
#include "Bureaucrat.hpp"

// ── Constructors / Destructor ──────────────────────────────────────────────────

// Default constructor — all grades set to 150 (lowest valid value)
Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << GREEN << "✓ Form default constructor called" << RESET << std::endl;
}

// Parameterized constructor — validates both grades before the object is used.
// Both const members must be initialised here (they cannot be assigned later).
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();  // either grade is above the valid ceiling
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();   // either grade is below the valid floor
    std::cout << GREEN << "✓ Form parameterized constructor called" << RESET << std::endl;
}

// Copy constructor — const members (_name, _gradeToSign, _gradeToExecute) must
// be set in the initialiser list because they cannot be assigned in the body.
Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << BLUE << "⎘ Form copy constructor called" << RESET << std::endl;
}

// Copy assignment operator — const members cannot change, so only _signed copies.
Form& Form::operator=(const Form& other) {
    std::cout << YELLOW << "⟵ Form copy assignment operator called" << RESET << std::endl;
    if (this != &other)
        _signed = other._signed;
    return *this;
}

Form::~Form() {
    std::cout << RED << "✗ Form destructor called" << RESET << std::endl;
}

// ── Getters ────────────────────────────────────────────────────────────────────

const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

// ── beSigned ──────────────────────────────────────────────────────────────────
// Grade comparison: lower number means higher rank.
// b.getGrade() > _gradeToSign means the bureaucrat is LESS senior than required.

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

// ── Exception messages ─────────────────────────────────────────────────────────

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high (minimum is 1)";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Bureaucrat's grade is too low to sign this form";
}

// ── Insertion operator ─────────────────────────────────────────────────────────
// Prints all four attributes so the evaluator can see the form's full state.

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << CYAN
       << "Form: "          << f.getName()
       << " | Signed: "     << (f.isSigned() ? "yes" : "no")
       << " | Sign grade: " << f.getGradeToSign()
       << " | Exec grade: " << f.getGradeToExecute()
       << RESET;
    return os;
}
