#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& b) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = b;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}
Brain* Brain::operator=(const Brain& b) {
    for (size_t i = 0; i < 100; i++)
        this->idea[i] = b.idea[i];
    return this;
}
