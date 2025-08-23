#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name) {
    std::cout << GREEN << "🧠 Creating a heap zombie named " << name << "..." << RESET << std::endl;
    Zombie* zombie = new Zombie(name);
    return zombie;
}