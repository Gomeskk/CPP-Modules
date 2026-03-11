#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << GREEN << "✓ WrongAnimal default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << BLUE << "⎘ WrongAnimal copy constructor called" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << YELLOW << "⟵ WrongAnimal copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << RED << "✗ WrongAnimal destructor called" << RESET << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << MAGENTA << "🚫 Generic wrong animal sound" << RESET << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}
