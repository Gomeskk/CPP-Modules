#include "Harl.hpp"
#include <iostream>
#include <string>

void displayHeader() {
    std::cout << "\n";
    std::cout << CYAN << "╔═══════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << CYAN << "║" << BOLD << "       HARL 2.0 COMPLAINT SIMULATOR       " << RESET << CYAN << "║" << RESET << std::endl;
    std::cout << CYAN << "╚═══════════════════════════════════════════╝" << RESET << std::endl;
    std::cout << "This program demonstrates Harl's different levels of complaints\n" << std::endl;
}

void displayMenu() {
    std::cout << "Select complaint level:" << std::endl;
    std::cout << "  " << GREEN << "[ DEBUG ]" << RESET << " - Contextual information for diagnosis" << std::endl;
    std::cout << "  " << BLUE << "[ INFO ]" << RESET << " - Extensive information about program execution" << std::endl;
    std::cout << "  " << YELLOW << "[ WARNING ]" << RESET << " - Potential issue that can be handled or ignored" << std::endl;
    std::cout << "  " << RED << "[ ERROR ]" << RESET << " - Unrecoverable error requiring intervention" << std::endl;
    std::cout << "  " << MAGENTA << "[ EXIT ]" << RESET << " - Quit the program" << std::endl;
}

void interactiveMode() {
    displayHeader();
    displayMenu();

    Harl harl;
    std::string level;
    bool running = true;

    while (running) {
        std::cout << std::endl << BOLD << "Enter complaint level: " << RESET;
        std::getline(std::cin, level);

        if (level == "EXIT" || level == "exit" || std::cin.eof()) {
            running = false;
            std::cout << std::endl << BOLD << CYAN << "Goodbye! Harl will be back..." << RESET << std::endl;
        }
        else {
            std::cout << "----------------------------------------------" << std::endl;
            harl.complain(level);
            std::cout << "----------------------------------------------" << std::endl;
            std::cout << YELLOW << "Press ENTER to continue..." << RESET;
            std::cin.get();
            displayMenu();
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        Harl harl;
        std::string level = argv[1];
        
        std::cout << "----------------------------------------------" << std::endl;
        harl.complain(level);
        std::cout << "----------------------------------------------" << std::endl;
        return 0;
    }
    else {
        interactiveMode();
    }
    return 0;
}