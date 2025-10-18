#include "Fixed.hpp"
#include <iostream>

// Default constructor
Fixed::Fixed(void) : _fixedPointValue(0){
    std::cout << GREEN << "✓ Default constructor called" << RESET << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &src){
    std::cout << BLUE << "⎘ Copy constructor called" << RESET << std::endl;
    *this = src;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &rhs){
    std::cout << YELLOW << "⟵ Copy assignment operator called" << RESET << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

// Destructor
Fixed::~Fixed(void){
    std::cout << RED << "✗ Destructor called" << RESET << std::endl;
}

// Get raw bits
int Fixed::getRawBits(void) const{
    std::cout << CYAN << "getRawBits member function called" << RESET << std::endl;
    return this->_fixedPointValue;
}

// Set raw bits
void Fixed::setRawBits(int const raw){
    std::cout << MAGENTA << "⚙ setRawBits member function called" << RESET << std::endl;
    this->_fixedPointValue = raw;
}