#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
    std::cout << YELLOW << "Harl has entered the restaurant!" << RESET << std::endl;
}

Harl::~Harl() {
    std::cout << YELLOW << "Harl has left the restaurant (for now)..." << RESET << std::endl;
}

void Harl::debug() {
    std::cout << GREEN << "[ DEBUG ]" << RESET << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl << std::endl;
}

void Harl::info() {
    std::cout << BLUE << "[ INFO ]" << RESET << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void Harl::warning() {
    std::cout << YELLOW << "[ WARNING ]" << RESET << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void Harl::error() {
    std::cout << RED << "[ ERROR ]" << RESET << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level) {
    // Array of pointers to member functions
    void (Harl::*complaints[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    // Find the matching level and call the corresponding function
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*complaints[i])();
            return;
        }
    }

    std::cout << MAGENTA << "[ UNKNOWN ]" << RESET << std::endl;
    std::cout << "Harl doesn't know how to complain at level \"" << level << "\"" << std::endl << std::endl;
}

int Harl::getLevelIndex(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++) {
        if (level == levels[i])
            return i;
    }
    return -1;
}

void Harl::filter(std::string level) {
    int levelIndex = getLevelIndex(level);
    
    switch (levelIndex) {
        case 0: // DEBUG
            debug();
            // Fall through to show all levels below
        case 1: // INFO
            info();
            // Fall through
        case 2: // WARNING
            warning();
            // Fall through
        case 3: // ERROR
            error();
            break;
        default:
            std::cout << MAGENTA << "[ Probably complaining about insignificant problems ]" << RESET << std::endl << std::endl;
    }
}
