#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void printStatus(const ClapTrap &trap, const std::string &type) {
    std::cout << "  [" << type << " " << trap.getName() << "] HP: " << trap.getHitPoints() 
              << " | Energy: " << trap.getEnergyPoints() 
              << " | Attack: " << trap.getAttackDamage() << std::endl;
}

void separator(void) {
    std::cout << BOLD << "\n========================================\n" << RESET << std::endl;
}

int main(int argc, char *argv[]) {
    // Check if command line arguments were provided
    if (argc > 1) {
        std::cerr << RED << "⚠ ERROR: This program does not accept command line arguments" << RESET << std::endl;
        std::cerr << YELLOW << "Usage: " << argv[0] << RESET << std::endl;
        return 1;
    }

    std::cout << BOLD << "\n===== FRAGTRAP INHERITANCE DEMONSTRATION =====" << RESET << std::endl;
    
    // Test 1: Construction/Destruction chaining
    separator();
    std::cout << BOLD << "TEST 1: FragTrap Construction and Destruction chaining" << RESET << std::endl;
    std::cout << "\nCreating FragTrap (note: ClapTrap constructor called first):" << std::endl;
    FragTrap frag1("Fraggy");
    
    std::cout << "\nFragTrap initial status:" << std::endl;
    printStatus(frag1, "FragTrap");
    
    std::cout << "\nDestruction order (FragTrap destructor, then ClapTrap destructor):" << std::endl;
    
    // Test 2: Comparing all three types
    separator();
    std::cout << BOLD << "TEST 2: Comparing ClapTrap, ScavTrap, and FragTrap" << RESET << std::endl;
    ClapTrap clap("Clappy");
    ScavTrap scav("Scavvy");
    FragTrap frag2("Destroyer");
    
    std::cout << "\nAttribute comparison:" << std::endl;
    printStatus(clap, "ClapTrap");
    printStatus(scav, "ScavTrap");
    printStatus(frag2, "FragTrap");
    
    std::cout << "\nNote the differences in HP, Energy, and Attack damage!" << std::endl;
    
    // Test 3: High Five special ability
    separator();
    std::cout << BOLD << "TEST 3: FragTrap special ability - High Five" << RESET << std::endl;
    FragTrap frag3("Friendly");
    
    std::cout << "\nFragTrap requesting high fives:" << std::endl;
    frag3.highFivesGuys();
    frag3.highFivesGuys();
    
    std::cout << "\nFragTrap can still perform regular actions:" << std::endl;
    frag3.attack("Enemy");
    frag3.beRepaired(10);
    printStatus(frag3, "FragTrap");
    
    // Test 4: Maximum energy points
    separator();
    std::cout << BOLD << "TEST 4: FragTrap maximum energy points" << RESET << std::endl;
    FragTrap frag4("Energizer");
    
    std::cout << "\nFragTrap has 100 energy points - performing many actions:" << std::endl;
    for (int i = 0; i < 15; i++) {
        frag4.attack("Target");
    }
    printStatus(frag4, "FragTrap");
    
    std::cout << "\nStill has plenty of energy for repairs:" << std::endl;
    for (int i = 0; i < 10; i++) {
        frag4.beRepaired(1);
    }
    printStatus(frag4, "FragTrap");
    
    // Test 5: Maximum attack damage
    separator();
    std::cout << BOLD << "TEST 5: FragTrap devastating attack power" << RESET << std::endl;
    FragTrap frag5("Devastator");
    ClapTrap clap2("Victim");
    
    std::cout << "\nFragTrap attacks with 30 damage:" << std::endl;
    frag5.attack("Victim");
    
    std::cout << "\nClapTrap takes the damage:" << std::endl;
    clap2.takeDamage(30);
    printStatus(clap2, "ClapTrap");
    
    // Test 6: Durability test
    separator();
    std::cout << BOLD << "TEST 6: FragTrap durability (100 HP)" << RESET << std::endl;
    FragTrap frag6("Tank");
    
    std::cout << "\nTaking multiple hits:" << std::endl;
    frag6.takeDamage(25);
    printStatus(frag6, "FragTrap");
    
    frag6.takeDamage(30);
    printStatus(frag6, "FragTrap");
    
    frag6.takeDamage(20);
    printStatus(frag6, "FragTrap");
    
    std::cout << "\nStill standing! Repairing:" << std::endl;
    frag6.beRepaired(30);
    printStatus(frag6, "FragTrap");
    
    std::cout << "\nCelebrating survival with high fives:" << std::endl;
    frag6.highFivesGuys();
    
    // Test 7: Copy operations
    separator();
    std::cout << BOLD << "TEST 7: FragTrap copy operations" << RESET << std::endl;
    FragTrap frag7("Original");
    frag7.takeDamage(40);
    frag7.attack("Someone");
    
    std::cout << "\nOriginal status:" << std::endl;
    printStatus(frag7, "FragTrap");
    
    std::cout << "\nCreating copy:" << std::endl;
    FragTrap frag8(frag7);
    std::cout << "Copy status:" << std::endl;
    printStatus(frag8, "FragTrap");
    
    std::cout << "\nUsing assignment operator:" << std::endl;
    FragTrap frag9("Different");
    frag9 = frag7;
    std::cout << "Assigned status:" << std::endl;
    printStatus(frag9, "FragTrap");
    
    // Test 8: All robots together
    separator();
    std::cout << BOLD << "TEST 8: Battle royale - ClapTrap vs ScavTrap vs FragTrap" << RESET << std::endl;
    ClapTrap clap3("Fighter");
    ScavTrap scav2("Guardian");
    FragTrap frag10("Champion");
    
    std::cout << "\nInitial lineup:" << std::endl;
    printStatus(clap3, "ClapTrap");
    printStatus(scav2, "ScavTrap");
    printStatus(frag10, "FragTrap");
    
    std::cout << "\nClapTrap attacks:" << std::endl;
    clap3.attack("Enemy");
    
    std::cout << "\nScavTrap enters guard mode and attacks:" << std::endl;
    scav2.guardGate();
    scav2.attack("Enemy");
    
    std::cout << "\nFragTrap attacks and celebrates:" << std::endl;
    frag10.attack("Enemy");
    frag10.highFivesGuys();
    
    std::cout << "\nFinal status:" << std::endl;
    printStatus(clap3, "ClapTrap");
    printStatus(scav2, "ScavTrap");
    printStatus(frag10, "FragTrap");
    
    separator();
    std::cout << BOLD << "Objects going out of scope (note destruction order)..." << RESET << std::endl;
    
    return 0;
}
