#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main() {
    std::cout << BOLD << CYAN << "===== HI THIS IS BRAIN PROGRAM =====" << RESET << std::endl;
    std::cout << "This program demonstrates pointers vs references" << std::endl << std::endl;
    
    // create a string variable
    std::string string = "HI THIS IS BRAIN";
    
    // create a pointer to the string
    std::string* stringPTR = &string;
    
    // create a reference to the string
    std::string& stringREF = string;
    
    std::cout << BOLD << GREEN << "----- Memory Addresses -----" << RESET << std::endl;
    
    std::cout << YELLOW << "Memory address of string variable: " << RESET << CYAN << &string << RESET << std::endl;
    std::cout << YELLOW << "Memory address held by stringPTR:  " << RESET << CYAN << stringPTR << RESET << std::endl;
    std::cout << YELLOW << "Memory address held by stringREF:  " << RESET << CYAN << &stringREF << RESET << std::endl;
    
    std::cout << std::endl << BOLD << BLUE << "----- Values -----" << RESET << std::endl;
    
    std::cout << YELLOW << "Value of string variable: " << RESET << MAGENTA << string << RESET << std::endl;
    std::cout << YELLOW << "Value pointed to by stringPTR: " << RESET << MAGENTA << *stringPTR << RESET << std::endl;
    std::cout << YELLOW << "Value pointed to by stringREF: " << RESET << MAGENTA << stringREF << RESET << std::endl;
    
    std::cout << std::endl << BOLD << GREEN << "----- Analysis -----" << RESET << std::endl;
    std::cout << "Notice that all memory addresses are the same!" << std::endl;
    std::cout << "References are just another name for the same memory location." << std::endl;
    std::cout << "Pointers and references both allow indirect access to variables." << std::endl;
    
    return 0;
}