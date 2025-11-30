#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) : _fixedPointValue(0){
    std::cout << GREEN << "✓ Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &src){
    std::cout << BLUE << "⎘ Copy constructor called" << RESET << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs){
    std::cout << YELLOW << "⟵ Copy assignment operator called" << RESET << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed(void){
    std::cout << RED << "✗ Destructor called" << RESET << std::endl;
}

int Fixed::getRawBits(void) const{
    std::cout << CYAN << "getRawBits member function called" << RESET << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw){
    std::cout << MAGENTA << "⚙ setRawBits member function called" << RESET << std::endl;
    this->_fixedPointValue = raw;
}