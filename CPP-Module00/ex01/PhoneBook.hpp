#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>

class PhoneBook {
private:
    Contact contacts[8];
    int totalContacts;
    int nextIndex;

public:
    PhoneBook();
    void addContact();
    void searchContact() const;
};

#endif
