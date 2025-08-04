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
    Contact newContact;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    newContact.setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    newContact.setLastName(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    newContact.setNickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);
    std::cout << contactCount << std::endl;

    if (contactCount < 8) {
        contacts[contactCount] = newContact;
        contactCount++;
    } else {
        contacts[oldestContactIndex] = newContact;
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
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