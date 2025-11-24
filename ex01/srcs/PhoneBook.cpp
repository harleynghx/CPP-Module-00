#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {}
PhoneBook::~PhoneBook() {}

std::string PhoneBook::truncateString(const std::string &str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::displayContactTableHeader() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
}

void PhoneBook::displayContactTableRow(int index) const {
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << truncateString(contacts[index].getFirstName()) << "|"
              << std::setw(10) << truncateString(contacts[index].getLastName()) << "|"
              << std::setw(10) << truncateString(contacts[index].getNickname()) << std::endl;
}
void PhoneBook::addContact() {
    int targetIndex = (contactCount < 8) ? contactCount++ : oldestContactIndex;
    if (contactCount >= 8) {
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }

    Contact& targetContact = contacts[targetIndex];
    std::string input;

    do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Error: First name cannot be empty!" << std::endl;
        }
    } while (input.empty());
    targetContact.setFirstName(input);

    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Error: Last name cannot be empty!" << std::endl;
        }
    } while (input.empty());
    targetContact.setLastName(input);

    do {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Error: Nickname cannot be empty!" << std::endl;
        }
    } while (input.empty());
    targetContact.setNickname(input);

    do {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Error: Phone number cannot be empty!" << std::endl;
        }
    } while (input.empty());
    targetContact.setPhoneNumber(input);

    do {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Error: Darkest secret cannot be empty!" << std::endl;
        }
    } while (input.empty());
    targetContact.setDarkestSecret(input);

    std::cout << "Contact added successfully!" << std::endl;
}

#include <cstdlib>  // for strtol
#include <cctype>   // for isdigit

void PhoneBook::searchContact() const {
    if (contactCount == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    displayContactTableHeader();
    for (int i = 0; i < contactCount; i++) {
        displayContactTableRow(i);
    }

    int index;
    std::string input;
    
    do {
        std::cout << "Enter index to display (0-" << contactCount - 1 << "): ";
        std::getline(std::cin, input);
        
        if (input.empty()) {
            std::cout << "Empty input! Please enter a number." << std::endl;
            continue;
        }
        
        char* endPtr;
        const char* inputCStr = input.c_str();
        long tempIndex = std::strtol(inputCStr, &endPtr, 10);
        
        if (endPtr == inputCStr) {
            std::cout << "Invalid input! Please enter a valid number." << std::endl;
            continue;
        }
        
        if (*endPtr != '\0') {
            std::cout << "Invalid input! Please enter only a number (no extra characters)." << std::endl;
            continue;
        }
        
        if (tempIndex < INT_MIN || tempIndex > INT_MAX) {
            std::cout << "Number out of range! Please enter a smaller number." << std::endl;
            continue;
        }
        
        index = static_cast<int>(tempIndex);
        
        if (index >= 0 && index < contactCount) {
            break;
        } else {
            std::cout << "Invalid index! Please enter a number between 0 and " 
                      << contactCount - 1 << "." << std::endl;
        }
    } while (true);

    std::cout << "\n--- Contact Details ---" << std::endl;
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}