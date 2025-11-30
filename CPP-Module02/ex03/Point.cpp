#include "Point.hpp"

// ---- Constructors & Destructor ----
// Default constructor - initializes coordinates to 0
Point::Point(void) : _x(0), _y(0){
    std::cout << GREEN << "✓ Point default constructor called" << RESET << std::endl;
}

// Float constructor - initializes coordinates with floats
Point::Point(const float x, const float y) : _x(x), _y(y){
    std::cout << CYAN << "✓ Point float constructor called" << RESET << std::endl;
}

// Copy constructor - creates a new point as a copy of the source
Point::Point(const Point &src) : _x(src._x), _y(src._y){
    std::cout << BLUE << "⎘ Point copy constructor called" << RESET << std::endl;
}

// Assignment operator - special case since our attributes are const
Point &Point::operator=(const Point &rhs){
    std::cout << YELLOW << "⟵ Point copy assignment operator called" << RESET << std::endl;
    
    // Cannot modify const attributes, so we do nothing
    // This is just to comply with the Orthodox Canonical Form
    (void)rhs;
    
    return *this;
}

// Destructor
Point::~Point(void){
    std::cout << RED << "✗ Point destructor called" << RESET << std::endl;
}

// ---- Getters ----
Fixed Point::getX(void) const{
    return this->_x;
}

Fixed Point::getY(void) const{
    return this->_y;
}