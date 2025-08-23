#include "Zombie.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << BOLD << CYAN << "===== ZOMBIE CREATOR PROGRAM =====" << RESET << std::endl;
    std::cout << "This program demonstrates heap vs stack allocation" << std::endl << std::endl;
    
    // Get user input for zombie names
    std::string heapName, stackName;
    
    std::cout << "Enter a name for heap zombie: ";
    std::getline(std::cin, heapName);
    
    std::cout << "Enter a name for stack zombie: ";
    std::getline(std::cin, stackName);
    
    std::cout << std::endl << BOLD << GREEN << "----- Creating heap zombie -----" << RESET << std::endl;
    std::cout << GREEN << "(This zombie will persist until manually deleted)" << RESET << std::endl;
    Zombie* heapZombie = newZombie(heapName);
    
    std::cout << std::endl << BOLD << BLUE << "----- Creating stack zombie -----" << RESET << std::endl;
    std::cout << BLUE << "(This zombie will be automatically destroyed when out of scope)" << RESET << std::endl;
    randomChump(stackName);
    
    std::cout << std::endl << BOLD << YELLOW << "----- Back in main function -----" << RESET << std::endl;
    std::cout << "Notice that " << BLUE << stackName << RESET << " is already destroyed!" << std::endl;
    std::cout << "But " << GREEN << heapName << RESET << " still exists and can announce again:" << std::endl;
    heapZombie->announce();
    
    std::cout << std::endl << BOLD << RED << "----- Manually deleting heap zombie -----" << RESET << std::endl;
    delete heapZombie;
    
    std::cout << std::endl << BOLD << CYAN << "All zombies have returned to their graves. Program ending." << RESET << std::endl;
    return 0;
}