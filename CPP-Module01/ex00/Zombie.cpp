#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name(name) {
    std::cout << YELLOW << "🧟 Zombie " << name << " has risen from the grave!" << RESET << std::endl;
}

Zombie::~Zombie() {
    std::cout << RED << "💀 Zombie " << name << " has returned to the grave." << RESET << std::endl;
}

void Zombie::announce() {
    std::cout << BOLD << name << RESET << ": " << MAGENTA << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}