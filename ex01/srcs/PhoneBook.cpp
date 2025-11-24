#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

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

    // First Name
    do {
        std::cout << "Enter first name: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Error: First name cannot be empty!" << std::endl;
        }
    } while (input.empty());
    targetContact.setFirstName(input);

    // Last Name
    do {
        std::cout << "Enter last name: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Error: Last name cannot be empty!" << std::endl;
        }
    } while (input.empty());
    targetContact.setLastName(input);

    // Nickname
    do {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Error: Nickname cannot be empty!" << std::endl;
        }
    } while (input.empty());
    targetContact.setNickname(input);

    // Phone Number
    do {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Error: Phone number cannot be empty!" << std::endl;
        }
    } while (input.empty());
    targetContact.setPhoneNumber(input);

    // Darkest Secret
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

void PhoneBook::searchContact() const {
    if (contactCount == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }
    std::cout << contactCount << std::endl;

    displayContactTableHeader();
    for (int i = 0; i < contactCount; i++) {
        displayContactTableRow(i);
    }

    std::cout << "Enter index to display: ";
    int index;
    std::cin >> index;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (std::cin.fail() || index < 0 || index >= contactCount) {
        std::cout << "Invalid index!" << std::endl;
        std::cin.clear();
        return;
    }

    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}