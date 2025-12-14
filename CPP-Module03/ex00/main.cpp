#include "ClapTrap.hpp"
#include <iostream>

void printStatus(const ClapTrap &clap) {
    std::cout << "  [" << clap.getName() << "] HP: " << clap.getHitPoints() 
              << " | Energy: " << clap.getEnergyPoints() 
              << " | Attack: " << clap.getAttackDamage() << std::endl;
}

void separator(void) {
    std::cout << BOLD << "\n----------------------------------------\n" << RESET << std::endl;
}

int main(int argc, char *argv[]) {
    // Check if command line arguments were provided
    if (argc > 1) {
        std::cerr << RED << "⚠ ERROR: This program does not accept command line arguments" << RESET << std::endl;
        std::cerr << YELLOW << "Usage: " << argv[0] << RESET << std::endl;
        return 1;
    }

    std::cout << BOLD << "\n===== CLAPTRAP CLASS DEMONSTRATION =====" << RESET << std::endl;
    
    // Test 1: Basic construction and attacks
    separator();
    std::cout << BOLD << "TEST 1: Creating ClapTraps and basic attacks" << RESET << std::endl;
    ClapTrap clap1("Clappy");
    ClapTrap clap2("Trappy");
    
    std::cout << "\nInitial status:" << std::endl;
    printStatus(clap1);
    printStatus(clap2);
    
    std::cout << "\nClappy attacks Trappy:" << std::endl;
    clap1.attack("Trappy");
    printStatus(clap1);
    
    // Test 2: Taking damage
    separator();
    std::cout << BOLD << "TEST 2: Taking damage" << RESET << std::endl;
    clap2.takeDamage(3);
    printStatus(clap2);
    
    clap2.takeDamage(5);
    printStatus(clap2);
    
    clap2.takeDamage(10);
    printStatus(clap2);
    
    std::cout << "\nTrying to attack while destroyed:" << std::endl;
    clap2.attack("Clappy");
    
    // Test 3: Repairing
    separator();
    std::cout << BOLD << "TEST 3: Repairing" << RESET << std::endl;
    ClapTrap clap3("Fixy");
    printStatus(clap3);
    
    clap3.takeDamage(7);
    printStatus(clap3);
    
    std::cout << "\nRepairing:" << std::endl;
    clap3.beRepaired(5);
    printStatus(clap3);
    
    clap3.beRepaired(3);
    printStatus(clap3);
    
    // Test 4: Energy depletion
    separator();
    std::cout << BOLD << "TEST 4: Energy point depletion" << RESET << std::endl;
    ClapTrap clap4("Energetic");
    printStatus(clap4);
    
    std::cout << "\nPerforming multiple actions:" << std::endl;
    for (int i = 0; i < 5; i++) {
        clap4.attack("Target");
    }
    printStatus(clap4);
    
    for (int i = 0; i < 5; i++) {
        clap4.beRepaired(1);
    }
    printStatus(clap4);
    
    std::cout << "\nNo energy left:" << std::endl;
    clap4.attack("Target");
    clap4.beRepaired(5);
    
    // Test 5: Copy operations
    separator();
    std::cout << BOLD << "TEST 5: Copy constructor and assignment operator" << RESET << std::endl;
    ClapTrap clap5("Original");
    clap5.takeDamage(3);
    clap5.attack("Someone");
    
    std::cout << "\nOriginal status:" << std::endl;
    printStatus(clap5);
    
    std::cout << "\nCreating copy:" << std::endl;
    ClapTrap clap6(clap5);
    std::cout << "Copy status:" << std::endl;
    printStatus(clap6);
    
    std::cout << "\nUsing assignment operator:" << std::endl;
    ClapTrap clap7("Different");
    clap7 = clap5;
    std::cout << "Assigned status:" << std::endl;
    printStatus(clap7);
    
    // Test 6: Edge cases
    separator();
    std::cout << BOLD << "TEST 6: Edge cases" << RESET << std::endl;
    ClapTrap clap8("EdgeCase");
    
    std::cout << "\nRepairing when destroyed:" << std::endl;
    clap8.takeDamage(10);
    clap8.beRepaired(5);
    
    separator();
    std::cout << BOLD << "Objects going out of scope..." << RESET << std::endl;
    
    return 0;
}