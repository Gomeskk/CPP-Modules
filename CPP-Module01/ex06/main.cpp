#include "Harl.hpp"
#include <iostream>
#include <string>

void displayHeader() {
    std::cout << "\n";
    std::cout << CYAN << "╔═══════════════════════════════════════════╗" << RESET << std::endl;
    std::cout << CYAN << "║" << BOLD << "       HARL FILTER COMPLAINT SYSTEM      " << RESET << CYAN << "║" << RESET << std::endl;
    std::cout << CYAN << "╚═══════════════════════════════════════════╝" << RESET << std::endl;
    std::cout << "This program filters Harl's complaints based on the severity level\n" << std::endl;
}

void displayMenu() {
    std::cout << "Select filter level (will show this level and above):" << std::endl;
    std::cout << "  " << GREEN << "[ DEBUG ]" << RESET << " - Show all complaints including debug info" << std::endl;
    std::cout << "  " << BLUE << "[ INFO ]" << RESET << " - Show info, warnings and errors" << std::endl;
    std::cout << "  " << YELLOW << "[ WARNING ]" << RESET << " - Show only warnings and errors" << std::endl;
    std::cout << "  " << RED << "[ ERROR ]" << RESET << " - Show only errors" << std::endl;
    std::cout << "  " << MAGENTA << "[ EXIT ]" << RESET << " - Quit the program" << std::endl;
}

void interactiveMode() {
    displayHeader();
    displayMenu();

    Harl harl;
    std::string level;
    bool running = true;

    while (running) {
        std::cout << std::endl << BOLD << "Enter filter level: " << RESET;
        std::getline(std::cin, level);

        if (level == "EXIT" || level == "exit" || std::cin.eof()) {
            running = false;
            std::cout << std::endl << BOLD << CYAN << "Goodbye! Harl has been silenced." << RESET << std::endl;
        } else {
            std::cout << "----------------------------------------------" << std::endl;
            std::cout << BOLD << "Filtering complaints from \"" << level << "\" and above:" << RESET << std::endl << std::endl;
            harl.filter(level);
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
        
        displayHeader();
        std::cout << BOLD << "Filter Level: " << level << RESET << std::endl << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
        harl.filter(level);
        std::cout << "----------------------------------------------" << std::endl;
        return 0;
    }
    else {
        interactiveMode();
    }
    return 0;
}
