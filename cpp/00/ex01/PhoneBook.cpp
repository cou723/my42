#include <Contact.hpp>
#include <PhoneBook.hpp>
#include <iomanip>
#include <iostream>
#include <string>
PhoneBook::PhoneBook() {
    for(size_t i = 0; i < MAX_CONTACTS_COUNT; i++)
        this->contacts[i] = 0;
}

void PhoneBook::RunAddCommand() {
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
    std::cout << "Enter first name: ";
    std::cin >> first_name;
    std::cout << "Enter last name: ";
    std::cin >> last_name;
    std::cout << "Enter nickname: ";
    std::cin >> nickname;
    std::cout << "Enter phone number: ";
    std::cin >> phone_number;
    std::cout << "Enter darkest secret: ";
    std::cin >> darkest_secret;
    this->AddContact(first_name, last_name, nickname, phone_number, darkest_secret);
}

void PhoneBook::AddContact(std::string first_name, std::string last_name, std::string nickname,
                           std::string phone_number, std::string darkest_secret) {
    if(total_index >= MAX_CONTACTS_COUNT)
        delete this->contacts[total_index % MAX_CONTACTS_COUNT];
    this->contacts[total_index % MAX_CONTACTS_COUNT] =
        new Contact(total_index, first_name, last_name, nickname, phone_number, darkest_secret);
    total_index++;
}

std::string MoldingString(std::string str) {
    if(str.length() > ROW_SIZE)
        return str.substr(0, 9) + ".";
    else
        return str;
}

void PrintHeader() {
    std::cout << "|" << std::right << std::setw(ROW_SIZE) << "Index"
              << "|" << std::right << std::setw(ROW_SIZE) << "First Name"
              << "|" << std::right << std::setw(ROW_SIZE) << "Last Name"
              << "|" << std::right << std::setw(ROW_SIZE) << "Nickname"
              << "|" << std::endl;
}

void PrintContact(Contact *contact) {
    if(contact == NULL) {
        std::cout << "|" << std::right << std::setw(ROW_SIZE) << "Empty"
                  << "|" << std::right << std::setw(ROW_SIZE) << "Empty"
                  << "|" << std::right << std::setw(ROW_SIZE) << "Empty"
                  << "|" << std::right << std::setw(ROW_SIZE) << "Empty"
                  << "|" << std::endl;
        return;
    }
    std::cout << "|" << std::right << std::setw(ROW_SIZE) << contact->GetIndex() << "|" << std::right
              << std::setw(ROW_SIZE) << MoldingString(contact->GetFirstName()) << "|" << std::right
              << std::setw(ROW_SIZE) << MoldingString(contact->GetLastName()) << "|" << std::right
              << std::setw(ROW_SIZE) << MoldingString(contact->GetNickname()) << "|" << std::endl;
}

void PhoneBook::DisplayContacts() {
    PrintHeader();
    for(size_t i = 0; i < MAX_CONTACTS_COUNT; i++) {
        if(this->contacts[i] == 0)
            continue;
        PrintContact(this->contacts[i]);
    }
}

Contact *PhoneBook::SearchContact(std::size_t index) {
    for(size_t i = 0; i < MAX_CONTACTS_COUNT; i++) {
        if(this->contacts[i] != 0 && this->contacts[i]->GetIndex() == index)
            return this->contacts[i];
    }
    return NULL;
}

void PhoneBook::RunSearchCommand() {
    this->DisplayContacts();
    std::size_t index;
    while(1) {
        std::cout << "Enter index: ";
        std::cin >> index;
        if((std::cin.good() != 0))
            break;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cout << "Please enter a number" << std::endl;
    }
    Contact *searched = this->SearchContact(index);
    if(searched != NULL)
        searched->Display();
    else
        std::cout << "index " << index << " is not found" << std::endl;
}

PhoneBook::~PhoneBook() {
    for(size_t i = 0; i < MAX_CONTACTS_COUNT; i++) {
        delete this->contacts[i];
    }
}
