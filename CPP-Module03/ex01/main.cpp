#include "ScavTrap.hpp"
#include <iostream>

void printStatus(const ClapTrap &trap, const std::string &type) {
    std::cout << "  [" << type << " " << trap.getName() << "] HP: " << trap.getHitPoints() 
              << " | Energy: " << trap.getEnergyPoints() 
              << " | Attack: " << trap.getAttackDamage() << std::endl;
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

    std::cout << BOLD << "\n===== SCAVTRAP INHERITANCE DEMONSTRATION =====" << RESET << std::endl;
    
    // Test 1: Construction/Destruction chaining
    separator();
    std::cout << BOLD << "TEST 1: Construction and Destruction chaining" << RESET << std::endl;
    std::cout << "\nCreating ScavTrap (note: ClapTrap constructor called first):" << std::endl;
    ScavTrap scav1("Scavvy");
    
    std::cout << "\nCreating ClapTrap for comparison:" << std::endl;
    ClapTrap clap1("Clappy");
    
    std::cout << "\nInitial status comparison:" << std::endl;
    printStatus(scav1, "ScavTrap");
    printStatus(clap1, "ClapTrap");
    
    std::cout << "\nDestruction order (ScavTrap destructor, then ClapTrap destructor):" << std::endl;
    
    // Test 2: Different attack behavior
    separator();
    std::cout << BOLD << "TEST 2: Attack behavior differences" << RESET << std::endl;
    ScavTrap scav2("Attacker");
    ClapTrap clap2("Defender");
    
    std::cout << "\nScavTrap attack:" << std::endl;
    scav2.attack("Enemy");
    
    std::cout << "\nClapTrap attack:" << std::endl;
    clap2.attack("Enemy");
    
    std::cout << "\nNote the different messages and damage values!" << std::endl;
    printStatus(scav2, "ScavTrap");
    printStatus(clap2, "ClapTrap");
    
    // Test 3: Guard Gate special ability
    separator();
    std::cout << BOLD << "TEST 3: ScavTrap special ability - Guard Gate" << RESET << std::endl;
    ScavTrap scav3("Guardian");
    
    std::cout << "\nActivating Gate keeper mode:" << std::endl;
    scav3.guardGate();
    
    std::cout << "\nGuardian can still perform other actions:" << std::endl;
    scav3.attack("Intruder");
    scav3.beRepaired(10);
    printStatus(scav3, "ScavTrap");
    
    // Test 4: Enhanced durability
    separator();
    std::cout << BOLD << "TEST 4: ScavTrap enhanced durability" << RESET << std::endl;
    ScavTrap scav4("Tank");
    
    std::cout << "\nScavTrap taking heavy damage:" << std::endl;
    scav4.takeDamage(30);
    printStatus(scav4, "ScavTrap");
    
    scav4.takeDamage(40);
    printStatus(scav4, "ScavTrap");
    
    std::cout << "\nStill alive! Repairing:" << std::endl;
    scav4.beRepaired(20);
    printStatus(scav4, "ScavTrap");
    
    // Test 5: Energy management
    separator();
    std::cout << BOLD << "TEST 5: Energy points management" << RESET << std::endl;
    ScavTrap scav5("Energetic");
    
    std::cout << "\nPerforming multiple attacks (ScavTrap has 50 energy):" << std::endl;
    for (int i = 0; i < 10; i++) {
        scav5.attack("Target");
    }
    printStatus(scav5, "ScavTrap");
    
    std::cout << "\nCompare with ClapTrap (only 10 energy):" << std::endl;
    ClapTrap clap3("Limited");
    for (int i = 0; i < 10; i++) {
        clap3.attack("Target");
    }
    printStatus(clap3, "ClapTrap");
    
    // Test 6: Copy operations
    separator();
    std::cout << BOLD << "TEST 6: Copy constructor and assignment operator" << RESET << std::endl;
    ScavTrap scav6("Original");
    scav6.takeDamage(20);
    scav6.attack("Someone");
    
    std::cout << "\nOriginal status:" << std::endl;
    printStatus(scav6, "ScavTrap");
    
    std::cout << "\nCreating copy:" << std::endl;
    ScavTrap scav7(scav6);
    std::cout << "Copy status:" << std::endl;
    printStatus(scav7, "ScavTrap");
    
    std::cout << "\nUsing assignment operator:" << std::endl;
    ScavTrap scav8("Different");
    scav8 = scav6;
    std::cout << "Assigned status:" << std::endl;
    printStatus(scav8, "ScavTrap");
    
    // Test 7: Mixed interactions
    separator();
    std::cout << BOLD << "TEST 7: ScavTrap and ClapTrap interaction" << RESET << std::endl;
    ScavTrap scav9("Warrior");
    ClapTrap clap4("Soldier");
    
    std::cout << "\nBattle simulation:" << std::endl;
    scav9.attack("Soldier");
    clap4.takeDamage(20);
    printStatus(clap4, "ClapTrap");
    
    clap4.attack("Warrior");
    scav9.takeDamage(0);
    printStatus(scav9, "ScavTrap");
    
    std::cout << "\nScavTrap activates Gate keeper mode for defense:" << std::endl;
    scav9.guardGate();
    
    separator();
    std::cout << BOLD << "Objects going out of scope (note destruction order)..." << RESET << std::endl;
    
    return 0;
}
