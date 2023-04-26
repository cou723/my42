#include "utils.hpp"

#include <sstream>
#include <string>
unsigned int myStoi(std::string s) throw(std::invalid_argument) {
    if (s.find('-') != std::string::npos)
        throw std::invalid_argument("Negative number found");
    std::stringstream ss(s);
    unsigned int n;
    ss >> n;
    if (ss.fail() || !ss.eof()) throw std::invalid_argument("Invalid argument");
    return n;
}
