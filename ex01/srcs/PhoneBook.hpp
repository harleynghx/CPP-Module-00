#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;
    int oldestContactIndex;

    std::string truncateString(const std::string &str) const;
    void displayContactTableHeader() const;
    void displayContactTableRow(int index) const;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContact() const;
};

#endif