#include "Fixed.hpp"

// ---- Constructors & Destructor ----
Fixed::Fixed(void) : _fixedPointValue(0){
    std::cout << GREEN << "✓ Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int value){
    std::cout << PURPLE << "🔢 Int constructor called" << RESET << std::endl;
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value){
    std::cout << CYAN << "🌊 Float constructor called" << RESET << std::endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
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

// ---- Conversion Methods ----
float Fixed::toFloat(void) const{
    return (float)_fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const{
    return _fixedPointValue >> _fractionalBits;
}

// ---- Comparison Operators ----
bool Fixed::operator>(const Fixed &rhs) const{
    return this->_fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator<(const Fixed &rhs) const{
    return this->_fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &rhs) const{
    return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &rhs) const{
    return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator==(const Fixed &rhs) const{
    return this->_fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &rhs) const{
    return this->_fixedPointValue != rhs._fixedPointValue;
}

// ---- Arithmetic Operators ----
Fixed Fixed::operator+(const Fixed &rhs) const{
    Fixed result;
    result.setRawBits(this->_fixedPointValue + rhs._fixedPointValue);
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const{
    Fixed result;
    result.setRawBits(this->_fixedPointValue - rhs._fixedPointValue);
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const{
    // Multiply raw values and adjust for fractional bits
    Fixed result;
    result.setRawBits((this->_fixedPointValue * rhs._fixedPointValue) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const{
    // Division: shift left to maintain precision, then divide
    if (rhs._fixedPointValue == 0){
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    Fixed result;
    result.setRawBits((this->_fixedPointValue << _fractionalBits) / rhs._fixedPointValue);
    return result;
}

// ---- Increment/Decrement Operators ----
// Pre-increment: ++a
Fixed &Fixed::operator++(void){
    this->_fixedPointValue += 1;  // Smallest representable epsilon
    return *this;
}

// Post-increment: a++
Fixed Fixed::operator++(int){
    Fixed old = *this;  // Create a copy with the old value
    ++(*this);          // Use pre-increment
    return old;         // Return the copy with the old value
}

// Pre-decrement: --a
Fixed &Fixed::operator--(void){
    this->_fixedPointValue -= 1;  // Smallest representable epsilon
    return *this;
}

// Post-decrement: a--
Fixed Fixed::operator--(int){
    Fixed old = *this;  // Create a copy with the old value
    --(*this);          // Use pre-decrement
    return old;         // Return the copy with the old value
}

// ---- Static Member Functions ----
Fixed &Fixed::min(Fixed &a, Fixed &b){
    if (a < b)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
    if (a < b)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
    if (a > b)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
    if (a > b)
        return a;
    else
        return b;
}

// ---- Member Functions ----
int Fixed::getRawBits(void) const{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw){
    this->_fixedPointValue = raw;
}

// ---- Operator Overloads ----
std::ostream &operator<<(std::ostream &out, const Fixed &fixed){
    out << fixed.toFloat();
    return out;
}