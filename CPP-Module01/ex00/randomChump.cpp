#include "Zombie.hpp"
#include <iostream>

void randomChump(std::string name) {
    std::cout << BLUE << "🧠 Creating a stack zombie named " << name << "..." << RESET << std::endl;
    Zombie zombie(name);
    zombie.announce();
    std::cout << BLUE << "Stack zombie scope ending now..." << RESET << std::endl;
}