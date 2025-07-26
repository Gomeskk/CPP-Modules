#include "Contact.hpp"

bool Contact::setInfo() {
    while (true) {
        std::cout << "First name: ";
        if (!std::getline(std::cin, firstName))
            return false;
        if (!firstName.empty())
            break;
        std::cout << "\033[31mFirst name can't be empty.\033[0m" << std::endl;
    }
    while (true) {
        std::cout << "Last name: ";
        if (!std::getline(std::cin, lastName))
            return false;
        if (!lastName.empty())
            break;
        std::cout << "\033[31mLast name can't be empty.\033[0m" << std::endl;
    }
    while (true) {
        std::cout << "Nickname: ";
        if (!std::getline(std::cin, nickname))
            return false;
        if (!nickname.empty())
            break;
        std::cout << "\033[31mNickname can't be empty.\033[0m" << std::endl;
    }
    while (true) {
        std::cout << "Phone number: ";
        if (!std::getline(std::cin, phoneNumber))
            return false;
        bool isValid = !phoneNumber.empty();
        for (size_t i = 0; i < phoneNumber.length() && isValid; ++i) {
            if (!isdigit(static_cast<unsigned char>(phoneNumber[i])))
                isValid = false;
        }
        if (isValid)
            break;
        std::cout << "\033[31mPhone number must contain digits only.\033[0m" << std::endl;
    }
    while (true) {
        std::cout << "Darkest secret: ";
        if (!std::getline(std::cin, darkestSecret))
            return false;
        if (!darkestSecret.empty())
            break;
        std::cout << "\033[31mDarkest secret can't be empty.\033[0m" << std::endl;
    }
    return true;
}

bool Contact::isValid() const {
    return !firstName.empty() && !lastName.empty()
        && !nickname.empty() && !phoneNumber.empty()
        && !darkestSecret.empty();
}

std::string truncateField(const std::string& field) {
    if (field.length() > 10) {
        return field.substr(0, 9) + ".";
    }
    return field;
}

void Contact::displayShort(int index) const {
    std::cout << "\033[33m" << "|" << std::setw(10) << index << "|";  // Yellow index

    std::string out = truncateField(firstName);
    std::cout << "\033[32m" << std::setw(10) << out << "|"; // Green text

    out = truncateField(lastName);
    std::cout << std::setw(10) << out << "|";

    out = truncateField(nickname);
    std::cout << std::setw(10) << out << "|" << "\033[0m" << std::endl; // Reset color after nickname
}

void Contact::displayFull() const {
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
