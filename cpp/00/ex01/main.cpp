#include <PhoneBook.hpp>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int main() {
    PhoneBook *phone_book;
    try {
        phone_book = new PhoneBook();
    } catch(std::bad_alloc &e) {
        std::cout << "Memory allocation failed" << std::endl;
        return 1;
    }
    while(1) {
        std::string command;
        std::cout << "Enter command: ";
        std::cin >> command;

        std::transform(command.begin(), command.end(), command.begin(), ::toupper);
        if(command == "EXIT")
            break;
        else if(command == "ADD") {
            try {
                phone_book->RunAddCommand();
            } catch(std::bad_alloc &e) {
                std::cout << "ADD failed: Memory allocation failed" << std::endl;
            }
        } else if(command == "SEARCH")
            phone_book->RunSearchCommand();
        else
            std::cout << "Invalid command" << std::endl;
    }
    delete phone_book;
    return 0;
}
