#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ── Constructors / Destructor ──────────────────────────────────────────────────

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << GREEN << "✓ AForm default constructor called" << RESET << std::endl;
}

// Both grade values are validated immediately — a form with invalid grades must
// never exist. Throwing in the constructor is the only clean way to enforce this.
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << GREEN << "✓ AForm parameterized constructor called" << RESET << std::endl;
}

// All const members must be set in the initialiser list (cannot be assigned in body)
AForm::AForm(const AForm& other)
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << BLUE << "⎘ AForm copy constructor called" << RESET << std::endl;
}

// Only _signed can change — the three const members cannot be reassigned.
AForm& AForm::operator=(const AForm& other) {
    std::cout << YELLOW << "⟵ AForm copy assignment operator called" << RESET << std::endl;
    if (this != &other)
        _signed = other._signed;
    return *this;
}

// Virtual destructor — guarantees subclass destructors run when deleting via AForm*
AForm::~AForm() {
    std::cout << RED << "✗ AForm destructor called" << RESET << std::endl;
}

// ── Getters ────────────────────────────────────────────────────────────────────

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _signed;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

// ── beSigned ──────────────────────────────────────────────────────────────────
// b.getGrade() > _gradeToSign means the bureaucrat's number is larger,
// i.e. they are LESS senior than the form requires → throw.

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

// ── execute ───────────────────────────────────────────────────────────────────
// Two preconditions checked here once, in the base class:
//   1. The form must be signed.
//   2. The executor's grade must be sufficient.
// Only then is executeAction() called — the subclass-specific logic.
// This is the "elegant" approach the subject hints at: no duplicated checks.

void AForm::execute(const Bureaucrat& executor) const {
    if (!_signed)
        throw FormNotSignedException();  // cannot run an unsigned form
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();    // executor isn't senior enough
    executeAction();                     // delegate to the concrete subclass
}

// ── Exception messages ─────────────────────────────────────────────────────────

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high (minimum is 1)";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Bureaucrat's grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

// ── Insertion operator ─────────────────────────────────────────────────────────

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << CYAN
       << "AForm: "         << f.getName()
       << " | Signed: "     << (f.isSigned() ? "yes" : "no")
       << " | Sign grade: " << f.getGradeToSign()
       << " | Exec grade: " << f.getGradeToExecute()
       << RESET;
    return os;
}
