#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    brain = new Brain();
    std::cout << GREEN << "✓ Cat default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << BLUE << "⎘ Cat copy constructor called" << RESET << std::endl;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << YELLOW << "⟵ Cat copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << RED << "✗ Cat destructor called" << RESET << std::endl;
    delete brain;
}

void Cat::makeSound() const {
    std::cout << CYAN << "🐱 Meow! Meow!" << RESET << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
}
