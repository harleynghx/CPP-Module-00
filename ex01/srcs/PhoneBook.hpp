#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook(); // Constructor
    ~PhoneBook(); // Destructor

    void addContact();
    void searchContact() const;

private:
    Contact contacts[0];
    int contactCount;
    int oldestContactIndex;

    std::string truncateString(const std::string &str) const;
    void displayContactTableHeader() const;
    void displayContactTableRow(int index) const;
};

#endif