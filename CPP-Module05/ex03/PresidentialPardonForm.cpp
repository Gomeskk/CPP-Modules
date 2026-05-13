#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("default") {
    std::cout << GREEN << "✓ PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << GREEN << "✓ PresidentialPardonForm parameterized constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {
    std::cout << BLUE << "⎘ PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << YELLOW << "⟵ PresidentialPardonForm copy assignment operator called" << RESET << std::endl;
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << RED << "✗ PresidentialPardonForm destructor called" << RESET << std::endl;
}

void PresidentialPardonForm::executeAction() const {
    std::cout << MAGENTA << _target << " has been pardoned by Zaphod Beeblebrox. 🏛️" << RESET << std::endl;
}
