#include "Zombie.hpp"

// default constructor
Zombie::Zombie() : name("unnamed") {
    std::cout << YELLOW << "🧟 An unnamed zombie has risen from the grave!" << RESET << std::endl;
}

// constructor with name
Zombie::Zombie(std::string name) : name(name) {
    std::cout << YELLOW << "🧟 Zombie " << name << " has risen from the grave!" << RESET << std::endl;
}

// destructor
Zombie::~Zombie() {
    std::cout << RED << "💀 Zombie " << name << " has returned to the grave." << RESET << std::endl;
}

void Zombie::announce() {
    std::cout << BOLD << name << RESET << ": " << MAGENTA << "BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
    std::cout << BLUE << "🧠 Zombie has been named " << name << RESET << std::endl;
}