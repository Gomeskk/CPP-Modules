#include "Fixed.hpp"
#include <iostream>

int main(int argc, char *argv[]){
    if (argc > 1) {
        std::cerr << RED << "⚠ ERROR: This program does not accept command line arguments" << RESET << std::endl;
        std::cerr << YELLOW << "Usage: " << argv[0] << RESET << std::endl;
        return 1;
    }

    std::cout << BOLD << "\n===== FIXED-POINT NUMBER CLASS DEMONSTRATION =====" << RESET << std::endl;
    
    std::cout << BOLD << "\n1. Creating objects with different constructors:" << RESET << std::endl;
    std::cout << "→ Creating object a with default constructor" << std::endl;
    Fixed a;
    
    std::cout << "\n→ Creating const object b with int constructor (10)" << std::endl;
    Fixed const b(10);
    
    std::cout << "\n→ Creating const object c with float constructor (42.42f)" << std::endl;
    Fixed const c(42.42f);
    
    std::cout << "\n→ Creating const object d as a copy of b" << std::endl;
    Fixed const d(b);
    
    std::cout << "\n→ Assigning float value to a" << std::endl;
    a = Fixed(1234.4321f);
    
    std::cout << BOLD << "\n2. Displaying as floating-point (using << operator):" << RESET << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    
    std::cout << BOLD << "\n3. Displaying as integers (using toInt()):" << RESET << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    
    std::cout << BOLD << "\n4. Objects going out of scope:" << RESET << std::endl;
    return 0;
}