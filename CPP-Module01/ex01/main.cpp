#include "Zombie.hpp"

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
    
    std::cout << "Enter number of zombies to create: ";
    std::cin >> hordeSize;
    if (!std::cin) {
        std::cout << RED << "\nInput error or EOF detected. Exiting program." << RESET << std::endl;
        return 1;
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
        std::ostringstream oss;
        oss << "Zombie " << (i + 1) << " of " << hordeSize << ": ";
        std::cout << CYAN << oss.str() << RESET;
        horde[i].announce();
    }
    
    std::cout << std::endl << BOLD << RED << "----- Destroying zombie horde -----" << RESET << std::endl;
    
    delete[] horde;
    
    std::cout << std::endl << BOLD << CYAN << "All zombies have returned to their graves. Program ending." << RESET << std::endl;
    return 0;
}