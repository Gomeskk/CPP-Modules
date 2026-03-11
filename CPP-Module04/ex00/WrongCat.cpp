#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << GREEN << "✓ WrongCat default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << BLUE << "⎘ WrongCat copy constructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << YELLOW << "⟵ WrongCat copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << RED << "✗ WrongCat destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << CYAN << "🚫 Wrong Meow! Wrong Meow!" << RESET << std::endl;
}
