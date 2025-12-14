#include "DiamondTrap.hpp"

// ---- Constructors & Destructor ----

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), _name("Default") {
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << GREEN << "✓ DiamondTrap default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << GREEN << "✓ DiamondTrap " << this->_name << " constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), FragTrap(src), ScavTrap(src) {
    std::cout << BLUE << "⎘ DiamondTrap copy constructor called" << RESET << std::endl;
    *this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
    std::cout << YELLOW << "⟵ DiamondTrap copy assignment operator called" << RESET << std::endl;
    if (this != &rhs) {
        ClapTrap::operator=(rhs);
        this->_name = rhs._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << RED << "✗ DiamondTrap " << this->_name << " destructor called" << RESET << std::endl;
}

// ---- Member Functions ----

void DiamondTrap::whoAmI(void) {
    std::cout << MAGENTA << "💎 I am DiamondTrap " << this->_name 
              << " and my ClapTrap name is " << ClapTrap::_name << RESET << std::endl;
}
