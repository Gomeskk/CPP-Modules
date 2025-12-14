#include "FragTrap.hpp"

// ---- Constructors & Destructor ----

FragTrap::FragTrap(void) : ClapTrap() {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << GREEN << "✓ FragTrap default constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << GREEN << "✓ FragTrap " << this->_name << " constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src) {
    std::cout << BLUE << "⎘ FragTrap copy constructor called" << RESET << std::endl;
    *this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
    std::cout << YELLOW << "⟵ FragTrap copy assignment operator called" << RESET << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

FragTrap::~FragTrap(void) {
    std::cout << RED << "✗ FragTrap " << this->_name << " destructor called" << RESET << std::endl;
}

// ---- Member Functions ----

void FragTrap::highFivesGuys(void) {
    std::cout << YELLOW << "🙌 FragTrap " << this->_name << " requests a positive high five! ✋" << RESET << std::endl;
}
