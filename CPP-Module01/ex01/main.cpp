#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <sstream>

int main() {
    std::cout << BOLD << CYAN << "===== ZOMBIE HORDE CREATOR PROGRAM =====" << RESET << std::endl;
    std::cout << "This program demonstrates creating multiple zombies in a single allocation" << std::endl << std::endl;
    
    std::string baseName;
    int hordeSize;
    
    std::cout << "Enter base name for your zombie horde: ";
    std::getline(std::cin, baseName);
    if (!std::cin) {
        std::cout << RED << "\nInput error or EOF detected. Exiting program." << RESET << std::endl;
        return 1;
    }
    // check if name is empty (just pressed Enter)
    if (baseName.empty()) {
        std::cout << YELLOW << "Empty name not allowed. Using 'DefaultZombie' instead." << RESET << std::endl;
        baseName = "DefaultZombie";
    }
    
    bool validInput = false;
    while (!validInput) {
        std::string input;
        std::cout << "Enter number of zombies to create: ";
        std::getline(std::cin, input);
        
        // try to convert the input to a number
        std::istringstream iss(input);
        if (iss >> hordeSize) {
            validInput = true;
        } 
        else if (std::cin.eof()) {
            std::cout << RED << "EOF detected. Exiting program." << RESET << std::endl;
            return 1;
        } 
        else {
            std::cout << RED << "Invalid input. Please enter a number." << RESET << std::endl;
        }
    }
    
    if (hordeSize <= 0) {
        std::cout << RED << "Invalid horde size! Must be greater than 0." << RESET << std::endl;
        return 1;
    }
    
    std::cout << std::endl << BOLD << GREEN << "----- Creating zombie horde -----" << RESET << std::endl;
    
    Zombie* horde = zombieHorde(hordeSize, baseName);  // create the zombie horde
    
    std::cout << std::endl << BOLD << BLUE << "----- Zombie horde announcing -----" << RESET << std::endl;
    
    // make each zombie announce itself
    for (int i = 0; i < hordeSize; i++) {
        std::cout << CYAN << "Zombie " << (i + 1) << " of " << hordeSize << ": " << RESET;
        horde[i].announce();
    }
    
    std::cout << std::endl << BOLD << RED << "----- Destroying zombie horde -----" << RESET << std::endl;
    
    delete[] horde;
    
    std::cout << std::endl << BOLD << CYAN << "All zombies have returned to their graves. Program ending." << RESET << std::endl;
    return 0;
}