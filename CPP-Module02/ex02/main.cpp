#include "Fixed.hpp"
#include <iostream>

int main(int argc, char *argv[]){
    if (argc > 1){
        std::cerr << RED << "⚠ ERROR: This program does not accept command line arguments" << RESET << std::endl;
        std::cerr << YELLOW << "Usage: " << argv[0] << RESET << std::endl;
        return 1;
    }

    std::cout << BOLD << "\n===== FIXED-POINT NUMBER CLASS DEMONSTRATION =====" << RESET << std::endl;
    
    std::cout << BOLD << "\n1. Testing increment/decrement operators:" << RESET << std::endl;
    Fixed a;
    std::cout << "Initial a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    
    std::cout << BOLD << "\n2. Testing arithmetic operators:" << RESET << std::endl;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << "b (5.05 * 2): " << b << std::endl;
    
    Fixed c(3.14f);
    Fixed d(2);
    std::cout << "c (3.14): " << c << std::endl;
    std::cout << "d (2): " << d << std::endl;
    std::cout << "c + d: " << c + d << std::endl;
    std::cout << "c - d: " << c - d << std::endl;
    std::cout << "c * d: " << c * d << std::endl;
    std::cout << "c / d: " << c / d << std::endl;
    
    std::cout << BOLD << "\n3. Testing comparison operators:" << RESET << std::endl;
    std::cout << "c > d: " << (c > d) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "c >= d: " << (c >= d) << std::endl;
    std::cout << "c <= d: " << (c <= d) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;
    
    std::cout << BOLD << "\n4. Testing min/max functions:" << RESET << std::endl;
    std::cout << "min(a, c): " << Fixed::min(a, c) << std::endl;
    std::cout << "max(a, c): " << Fixed::max(a, c) << std::endl;
    std::cout << "min(b, d) [const]: " << Fixed::min(b, d) << std::endl;
    std::cout << "max(b, d) [const]: " << Fixed::max(b, d) << std::endl;

    std::cout << BOLD << "\n5. Required test from the exercise:" << RESET << std::endl;
    a = Fixed(0);  // Reset a
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}