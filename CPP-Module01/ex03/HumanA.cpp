#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
    std::cout << GREEN << "🗡️  HumanA " << name << " is armed and ready with " << weapon.getType() << RESET << std::endl;
}

HumanA::~HumanA() {
    std::cout << RED << "💀 HumanA " << name << " has fallen!" << RESET << std::endl;
}

void HumanA::attack() {
    std::cout << BOLD << name << RESET << " attacks with their " << MAGENTA << weapon.getType() << RESET << std::endl;
}