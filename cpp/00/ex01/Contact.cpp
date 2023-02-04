#include "Contact.hpp"
#include <iostream>
Contact::Contact(std::size_t index, std::string first_name, std::string last_name, std::string nickname,
                 std::string phone_number, std::string darkest_secret) {
    this->index = index;
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}

Contact::~Contact() {
}

std::size_t Contact::GetIndex() {
    return this->index;
}
std::string Contact::GetFirstName() {
    return this->first_name;
}
std::string Contact::GetLastName() {
    return this->last_name;
}
std::string Contact::GetNickname() {
    return this->nickname;
}

void Contact::Display() {
    std::cout << "First Name: " << this->first_name << std::endl;
    std::cout << "Last Name: " << this->last_name << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "Phone Number: " << this->phone_number << std::endl;
    std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
}
