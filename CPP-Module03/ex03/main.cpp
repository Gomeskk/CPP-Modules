#include "DiamondTrap.hpp"
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

    std::cout << BOLD << "\n===== DIAMONDTRAP MULTIPLE INHERITANCE DEMONSTRATION =====" << RESET << std::endl;
    
    // Test 1: Diamond inheritance construction
    separator();
    std::cout << BOLD << "TEST 1: DiamondTrap construction (Diamond Problem)" << RESET << std::endl;
    std::cout << "\nCreating DiamondTrap (note the construction order):" << std::endl;
    std::cout << "Expected: ClapTrap -> FragTrap -> ScavTrap -> DiamondTrap" << std::endl;
    DiamondTrap diamond1("Diamond");
    
    std::cout << "\nDiamondTrap initial status:" << std::endl;
    printStatus(diamond1, "DiamondTrap");
    
    // Test 2: whoAmI function
    separator();
    std::cout << BOLD << "TEST 2: DiamondTrap identity - whoAmI()" << RESET << std::endl;
    std::cout << "\nDiamondTrap has two names:" << std::endl;
    diamond1.whoAmI();
    
    // Test 3: Attribute inheritance
    separator();
    std::cout << BOLD << "TEST 3: Attribute inheritance from FragTrap and ScavTrap" << RESET << std::endl;
    std::cout << "\nComparing attributes:" << std::endl;
    FragTrap frag("Fraggy");
    ScavTrap scav("Scavvy");
    DiamondTrap diamond2("Hybrid");
    
    std::cout << "\nFragTrap attributes (HP: 100, Energy: 100, Attack: 30):" << std::endl;
    printStatus(frag, "FragTrap");
    
    std::cout << "\nScavTrap attributes (HP: 100, Energy: 50, Attack: 20):" << std::endl;
    printStatus(scav, "ScavTrap");
    
    std::cout << "\nDiamondTrap attributes (HP from FragTrap, Energy from ScavTrap, Attack from FragTrap):" << std::endl;
    printStatus(diamond2, "DiamondTrap");
    
    // Test 4: Attack method from ScavTrap
    separator();
    std::cout << BOLD << "TEST 4: Attack method inherited from ScavTrap" << RESET << std::endl;
    DiamondTrap diamond3("Attacker");
    
    std::cout << "\nDiamondTrap uses ScavTrap's attack:" << std::endl;
    diamond3.attack("Enemy");
    
    std::cout << "\nCompare with ScavTrap's attack:" << std::endl;
    scav.attack("Enemy");
    
    std::cout << "\nAnd ClapTrap's attack:" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Enemy");
    
    // Test 5: Special abilities from both parents
    separator();
    std::cout << BOLD << "TEST 5: DiamondTrap has abilities from both parents" << RESET << std::endl;
    DiamondTrap diamond4("Versatile");
    
    std::cout << "\nFrom FragTrap - highFivesGuys():" << std::endl;
    diamond4.highFivesGuys();
    
    std::cout << "\nFrom ScavTrap - guardGate():" << std::endl;
    diamond4.guardGate();
    
    std::cout << "\nDiamondTrap's own ability - whoAmI():" << std::endl;
    diamond4.whoAmI();
    
    // Test 6: Full combat test
    separator();
    std::cout << BOLD << "TEST 6: DiamondTrap in combat" << RESET << std::endl;
    DiamondTrap diamond5("Warrior");
    
    std::cout << "\nInitial status:" << std::endl;
    printStatus(diamond5, "DiamondTrap");
    
    std::cout << "\nPerforming various actions:" << std::endl;
    diamond5.attack("Target");
    printStatus(diamond5, "DiamondTrap");
    
    diamond5.takeDamage(40);
    printStatus(diamond5, "DiamondTrap");
    
    diamond5.beRepaired(20);
    printStatus(diamond5, "DiamondTrap");
    
    diamond5.guardGate();
    diamond5.highFivesGuys();
    diamond5.whoAmI();
    
    // Test 7: Energy management
    separator();
    std::cout << BOLD << "TEST 7: Energy points from ScavTrap (50)" << RESET << std::endl;
    DiamondTrap diamond6("Energetic");
    
    std::cout << "\nUsing energy with multiple attacks:" << std::endl;
    for (int i = 0; i < 10; i++) {
        diamond6.attack("Target");
    }
    printStatus(diamond6, "DiamondTrap");
    
    std::cout << "\nNote: Has 50 energy (from ScavTrap), not 100 (from FragTrap)" << std::endl;
    
    // Test 8: Copy operations
    separator();
    std::cout << BOLD << "TEST 8: DiamondTrap copy operations" << RESET << std::endl;
    DiamondTrap diamond7("Original");
    diamond7.takeDamage(30);
    diamond7.attack("Someone");
    
    std::cout << "\nOriginal status:" << std::endl;
    printStatus(diamond7, "DiamondTrap");
    diamond7.whoAmI();
    
    std::cout << "\nCreating copy:" << std::endl;
    DiamondTrap diamond8(diamond7);
    std::cout << "Copy status:" << std::endl;
    printStatus(diamond8, "DiamondTrap");
    diamond8.whoAmI();
    
    // Test 9: All robots together
    separator();
    std::cout << BOLD << "TEST 9: Complete inheritance hierarchy" << RESET << std::endl;
    ClapTrap clap2("Basic");
    ScavTrap scav2("Guardian");
    FragTrap frag2("Destroyer");
    DiamondTrap diamond9("Ultimate");
    
    std::cout << "\nAll robot types:" << std::endl;
    printStatus(clap2, "ClapTrap");
    printStatus(scav2, "ScavTrap");
    printStatus(frag2, "FragTrap");
    printStatus(diamond9, "DiamondTrap");
    
    std::cout << "\nDiamondTrap demonstrating all abilities:" << std::endl;
    diamond9.attack("Enemy");
    diamond9.guardGate();
    diamond9.highFivesGuys();
    diamond9.whoAmI();
    
    separator();
    std::cout << BOLD << "Objects going out of scope (note destruction order)..." << RESET << std::endl;
    std::cout << "Expected: DiamondTrap -> ScavTrap -> FragTrap -> ClapTrap" << std::endl;
    
    return 0;
}
