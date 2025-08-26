#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {
    std::cout << YELLOW << "👤 HumanB " << name << " is unarmed and looking for a weapon!" << RESET << std::endl;
}

HumanB::~HumanB() {
    std::cout << RED << "💀 HumanB " << name << " has fallen!" << RESET << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
    std::cout << GREEN << "⚔️  " << name << " is now armed with " << weapon.getType() << RESET << std::endl;
}

void HumanB::attack() {
    if (weapon) {
        std::cout << BOLD << name << RESET << " attacks with their " << MAGENTA << weapon->getType() << RESET << std::endl;
    } 
    else {
        std::cout << RED << name << " tries to attack but has no weapon!" << RESET << std::endl;
    }
}