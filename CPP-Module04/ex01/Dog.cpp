#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    brain = new Brain();
    std::cout << GREEN << "✓ Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << BLUE << "⎘ Dog copy constructor called" << RESET << std::endl;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << YELLOW << "⟵ Dog copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << RED << "✗ Dog destructor called" << RESET << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << CYAN << "🐶 Woof! Woof!" << RESET << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}
