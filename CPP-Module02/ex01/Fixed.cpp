#include "Fixed.hpp"

// ---- Constructors & Destructor ----
Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << GREEN << "✓ Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << PURPLE << "🔢 Int constructor called" << RESET << std::endl;
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << CYAN << "🌊 Float constructor called" << RESET << std::endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &src) {
    std::cout << BLUE << "⎘ Copy constructor called" << RESET << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
    std::cout << YELLOW << "⟵ Copy assignment operator called" << RESET << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << RED << "✗ Destructor called" << RESET << std::endl;
}

// ---- Conversion Methods ----
float Fixed::toFloat(void) const {
    return (float)_fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

// ---- Member functions ----
int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// ---- Stream Overload ----
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}