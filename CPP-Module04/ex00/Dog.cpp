#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << GREEN << "✓ Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << BLUE << "⎘ Dog copy constructor called" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << YELLOW << "⟵ Dog copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << RED << "✗ Dog destructor called" << RESET << std::endl;
}

void Dog::makeSound() const {
    std::cout << CYAN << "🐶 Woof! Woof!" << RESET << std::endl;
}
