#include "Harl.hpp"
#include <iostream>
Harl::Harl() {}
Harl::~Harl() {}

void Harl::_debug() {
    std::cout << "[DEBUG]" << std::endl
              << "I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special-ketchup burger. I "
                 "really do!"
              << std::endl;
}

void Harl::_info() {
    std::cout << "[INFO]" << std::endl
              << "I cannot believe adding extra bacon costs more money. You "
                 "didn’t putenough bacon in my burger! If you did, I wouldn’t "
                 "be asking for more!"
              << std::endl;
}

void Harl::_warning() {
    std::cout
        << "[WARNING]" << std::endl
        << "I think I deserve to have some extra bacon for free. I’ve been "
           "coming foryears whereas you started working here since last month."
        << std::endl;
}

void Harl::_error() {
    std::cout << "[ERROR]" << std::endl
              << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}
void Harl::complain(std::string level_str) {
    if (level_str != "DEBUG" && level_str != "INFO" && level_str != "WARNING" &&
        level_str != "ERROR") {
        std::cerr << "[ Probably complaining about insignificant problems ]"
                  << std::endl;
        return;
    }
    std::string level_str_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[])(void) = {&Harl::_debug, &Harl::_info,
                                       &Harl::_warning, &Harl::_error};
    int level = 0;
    while (level_str != level_str_list[level])
        level++;
    for (int j = 3; j >= level; j--)
        (this->*functions[j])();
}