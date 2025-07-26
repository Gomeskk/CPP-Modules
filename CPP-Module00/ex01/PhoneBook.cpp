#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : totalContacts(0), nextIndex(0) {}

void PhoneBook::addContact() {
    Contact newContact;
    if (!newContact.setInfo()) {
        std::cout << "\033[31m\nInput interrupted. Exiting program.\033[0m" << std::endl;
        exit(0);
    }

    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;

    if (totalContacts < 8)
        totalContacts++;

    std::cout << "Contact added!" << std::endl;
}

void PhoneBook::searchContact() const {
    if (totalContacts == 0) {
        std::cout << "\033[31mNo contacts saved yet.\033[0m" << std::endl;
        return;
    }

    std::cout << "\033[36m" << "\n+----------+----------+----------+----------+\n";
    std::cout << "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |\n";
    std::cout << "+----------+----------+----------+----------+\n" << "\033[0m";

    for (int i = 0; i < totalContacts; i++) {
        contacts[i].displayShort(i);
    }

    std::cout << "\033[36m" << "+----------+----------+----------+----------+\n" << "\033[0m";

    std::string input;
    std::cout << "\033[36mEnter index of contact to view full info: \033[0m";

    if (!std::getline(std::cin, input)) {
        std::cout << "\n\033[31mInput interrupted. Exiting program.\033[0m" << std::endl;
        exit(0);
    }

    if (input.length() != 1) {
        std::cout << "\033[31mInvalid input format.\033[0m" << std::endl;
        return;
    }

    char c = input[0];
    if (c < '0' || c > '7') {
        std::cout << "\033[31mIndex out of valid range (0-7).\033[0m" << std::endl;
        return;
    }

    int index = c - '0';
    if (index >= totalContacts) {
        std::cout << "\033[31mNo contact stored at this index.\033[0m" << std::endl;
        return;
    }

    std::cout << "\n\033[33m[ FULL CONTACT DETAILS ]\033[0m\n";
    contacts[index].displayFull();
}
