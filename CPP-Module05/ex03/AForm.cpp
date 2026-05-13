#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ── Constructors / Destructor ──────────────────────────────────────────────────

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << GREEN << "✓ AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << GREEN << "✓ AForm parameterized constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm& other)
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << BLUE << "⎘ AForm copy constructor called" << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    std::cout << YELLOW << "⟵ AForm copy assignment operator called" << RESET << std::endl;
    if (this != &other)
        _signed = other._signed;
    return *this;
}

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

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

// ── execute ───────────────────────────────────────────────────────────────────

void AForm::execute(const Bureaucrat& executor) const {
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    executeAction();
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
