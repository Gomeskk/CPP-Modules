#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << GREEN << "✓ Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << BLUE << "⎘ Animal copy constructor called" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << YELLOW << "⟵ Animal copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << RED << "✗ Animal destructor called" << RESET << std::endl;
}

void Animal::makeSound() const {
    std::cout << MAGENTA << "🔊 Generic animal sound" << RESET << std::endl;
}

std::string Animal::getType() const {
    return type;
}
