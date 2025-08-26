#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {
    std::cout << BLUE << "⚔️  Weapon '" << type << "' has been forged!" << RESET << std::endl;
}

Weapon::~Weapon() {
    std::cout << RED << "💥 Weapon '" << type << "' has been destroyed!" << RESET << std::endl;
}

const std::string& Weapon::getType() const {
    return type;
}

void Weapon::setType(std::string type) {
    std::cout << YELLOW << "🔧 Weapon type changed from '" << this->type << "' to '" << type << "'" << RESET << std::endl;
    this->type = type;
}