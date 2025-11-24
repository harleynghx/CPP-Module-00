#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>  // for strtol
#include <cctype>   // for isdigit
#include <climits>  // for Int_max int_min

class PhoneBook {
public:
    PhoneBook(); // Constructor
    ~PhoneBook(); // Destructor

    void addContact();
    void searchContact() const;
    
private:
    Contact contacts[8];
    int contactCount;
    int oldestContactIndex;

    std::string truncateString(const std::string &str) const;
    void displayContactTableHeader() const;
    void displayContactTableRow(int index) const;
};

#endif