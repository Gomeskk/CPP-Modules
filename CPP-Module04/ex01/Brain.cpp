#include "Brain.hpp"

Brain::Brain() {
    std::cout << GREEN << "✓ Brain default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << BLUE << "⎘ Brain copy constructor called" << RESET << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << YELLOW << "⟵ Brain copy assignment operator called" << RESET << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << RED << "✗ Brain destructor called" << RESET << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return ideas[index];
    }
    return "";
}
