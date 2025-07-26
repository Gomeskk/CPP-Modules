#include "PhoneBook.hpp"
#include <iostream>

void printWelcome() {
    std::cout << "\033[35m"; // Magenta color for the whole box
    std::cout << "===============================" << std::endl;
    std::cout << "|        \033[1mRETRO PHONEBOOK\033[0;35m      |" << std::endl;  // Bold magenta for title
    std::cout << "|   Type ADD, SEARCH, or EXIT |" << std::endl;
    std::cout << "===============================\033[0m" << std::endl; // Reset color after box
}

int main() {
    PhoneBook phonebook;
    std::string command;

    printWelcome();

    while (true) {
        std::cout << "\n\033[36m> Command: \033[0m"; // Cyan prompt, reset after input

        if (!std::getline(std::cin, command)) {
            std::cout << "\n\033[31mInput interrupted. Exiting program.\033[0m" << std::endl;
            exit(0);
        }

        if (command == "ADD") {
            std::cout << "\n\033[32m[ ADDING A NEW CONTACT ]\033[0m\n";  // Green message
            phonebook.addContact();
        } else if (command == "SEARCH") {
            std::cout << "\n\033[33m[ SEARCHING CONTACTS ]\033[0m\n";  // Yellow message
            phonebook.searchContact();
        } else if (command == "EXIT") {
            std::cout << "\n\033[31mExiting... All contacts will be lost.\033[0m\n"; // Red message
            break;
        } else {
            std::cout << "\033[31mInvalid command. Try ADD, SEARCH, or EXIT.\033[0m\n"; // Red error
        }
    }

    std::cout << "\033[35mGoodbye!\033[0m" << std::endl; // Magenta goodbye
    return 0;
}

