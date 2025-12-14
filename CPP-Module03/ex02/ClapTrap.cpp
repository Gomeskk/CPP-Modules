#include "ClapTrap.hpp"

// ---- Constructors & Destructor ----

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << GREEN << "✓ ClapTrap default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << GREEN << "✓ ClapTrap " << _name << " constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
    std::cout << BLUE << "⎘ ClapTrap copy constructor called" << RESET << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
    std::cout << YELLOW << "⟵ ClapTrap copy assignment operator called" << RESET << std::endl;
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap(void) {
    std::cout << RED << "✗ ClapTrap " << _name << " destructor called" << RESET << std::endl;
}

// ---- Member Functions ----

void ClapTrap::attack(const std::string &target) {
    if (_hitPoints == 0) {
        std::cout << RED << "⚠ ClapTrap " << _name << " cannot attack (no hit points left)!" << RESET << std::endl;
        return;
    }
    
    if (_energyPoints == 0) {
        std::cout << RED << "⚠ ClapTrap " << _name << " cannot attack (no energy points left)!" << RESET << std::endl;
        return;
    }
    
    _energyPoints--;
    std::cout << CYAN << "⚔ ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << RED << "⚠ ClapTrap " << _name << " is already destroyed!" << RESET << std::endl;
        return;
    }
    
    if (amount >= _hitPoints) {
        _hitPoints = 0;
        std::cout << RED << "💥 ClapTrap " << _name << " takes " << amount 
                  << " points of damage and is destroyed!" << RESET << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout << MAGENTA << "💢 ClapTrap " << _name << " takes " << amount 
                  << " points of damage! (" << _hitPoints << " HP remaining)" << RESET << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout << RED << "⚠ ClapTrap " << _name << " cannot be repaired (destroyed)!" << RESET << std::endl;
        return;
    }
    
    if (_energyPoints == 0) {
        std::cout << RED << "⚠ ClapTrap " << _name << " cannot be repaired (no energy points left)!" << RESET << std::endl;
        return;
    }
    
    _energyPoints--;
    _hitPoints += amount;
    std::cout << GREEN << "🔧 ClapTrap " << _name << " repairs itself for " << amount 
              << " hit points! (" << _hitPoints << " HP total)" << RESET << std::endl;
}

// ---- Getters ----

std::string ClapTrap::getName(void) const {
    return this->_name;
}

unsigned int ClapTrap::getHitPoints(void) const {
    return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const {
    return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const {
    return this->_attackDamage;
}
