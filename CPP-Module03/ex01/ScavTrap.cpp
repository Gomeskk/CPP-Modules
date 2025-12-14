#include "ScavTrap.hpp"

// ---- Constructors & Destructor ----

ScavTrap::ScavTrap(void) : ClapTrap() {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << GREEN << "✓ ScavTrap default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << GREEN << "✓ ScavTrap " << this->_name << " constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src) {
    std::cout << BLUE << "⎘ ScavTrap copy constructor called" << RESET << std::endl;
    *this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
    std::cout << YELLOW << "⟵ ScavTrap copy assignment operator called" << RESET << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
    }
    return *this;
}

ScavTrap::~ScavTrap(void) {
    std::cout << RED << "✗ ScavTrap " << this->_name << " destructor called" << RESET << std::endl;
}

// ---- Member Functions ----

void ScavTrap::attack(const std::string &target) {
    if (_hitPoints == 0) {
        std::cout << RED << "⚠ ScavTrap " << _name << " cannot attack (no hit points left)!" << RESET << std::endl;
        return;
    }
    
    if (_energyPoints == 0) {
        std::cout << RED << "⚠ ScavTrap " << _name << " cannot attack (no energy points left)!" << RESET << std::endl;
        return;
    }
    
    _energyPoints--;
    std::cout << PURPLE << "⚔ ScavTrap " << _name << " fiercely attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
}

void ScavTrap::guardGate(void) {
    std::cout << CYAN << "🛡️  ScavTrap " << this->_name << " is now in Gate keeper mode!" << RESET << std::endl;
}
