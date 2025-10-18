#include "Fixed.hpp"
#include <iostream>

int main(int argc, char *argv[]){
    if (argc > 1){
        std::cerr << RED << "⚠ ERROR: This program does not accept command line arguments" << RESET << std::endl;
        std::cerr << YELLOW << "Usage: " << argv[0] << RESET << std::endl;
        return 1;
    }

    std::cout << BOLD << "\n===== FIXED-POINT NUMBER CLASS DEMONSTRATION =====" << RESET << std::endl;
    
    std::cout << BOLD << "\n1. Creating objects:" << RESET << std::endl;
    std::cout << "→ Creating object a with default constructor" << std::endl;
    Fixed a; // Default constructor
    
    std::cout << "\n→ Creating object b as a copy of a" << std::endl;
    Fixed b(a); // Copy constructor
    
    std::cout << "\n→ Creating object c with default constructor" << std::endl;
    Fixed c;
    
    std::cout << "\n→ Assigning b to c" << std::endl;
    c = b; // Copy assignment operator

    std::cout << BOLD << "\n2. Reading raw values:" << RESET << std::endl;
    std::cout << "a: " << a.getRawBits() << std::endl;
    std::cout << "b: " << b.getRawBits() << std::endl;
    std::cout << "c: " << c.getRawBits() << std::endl;

    std::cout << BOLD << "\n3. Modifying and reading again:" << RESET << std::endl;
    std::cout << "→ Setting a's raw bits to 42" << std::endl;
    a.setRawBits(42);
    std::cout << "a: " << a.getRawBits() << std::endl;
    std::cout << "b: " << b.getRawBits() << " (unchanged)" << std::endl;
    std::cout << "c: " << c.getRawBits() << " (unchanged)" << std::endl;

    std::cout << BOLD << "\n4. Objects going out of scope:" << RESET << std::endl;
    return 0;
}