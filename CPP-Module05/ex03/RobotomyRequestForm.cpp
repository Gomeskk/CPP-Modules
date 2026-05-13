#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default") {
    std::cout << GREEN << "✓ RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << GREEN << "✓ RobotomyRequestForm parameterized constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {
    std::cout << BLUE << "⎘ RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << YELLOW << "⟵ RobotomyRequestForm copy assignment operator called" << RESET << std::endl;
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << RED << "✗ RobotomyRequestForm destructor called" << RESET << std::endl;
}

void RobotomyRequestForm::executeAction() const {
    std::cout << BOLD << "DRRRRRR... BZZZT... WHIRRRR... 🔩" << RESET << std::endl;
    std::srand(std::time(NULL));
    if (std::rand() % 2 == 0)
        std::cout << GREEN << _target << " has been robotomized successfully! 🤖" << RESET << std::endl;
    else
        std::cout << RED << "Robotomy of " << _target << " failed. 💀" << RESET << std::endl;
}
