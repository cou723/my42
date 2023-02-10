#include "Span.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
Span::Span() : _N(0), _array(std::vector<int>()) {}

Span::Span(unsigned int n) : _N(n), _array(std::vector<int>()) {}

Span::Span(const Span& s) : _N(s._N), _array(std::vector<int>()) {}

Span::~Span() {}

Span& Span::operator=(const Span& s) {
    if (this != &s) {
        this->_array = s._array;
        this->_N = s._N;
    }
    return *this;
}

void Span::addNumber(int n) {
    if (this->_array.size() == this->_N)
        throw std::out_of_range("out of range");
    this->_array.push_back(n);
}
void Span::addNumbers(std::vector<int>::iterator start,
                      std::vector<int>::iterator end) {
    do {
        addNumber(*start);
        start++;
    } while (start != end);
}

unsigned int Span::shortestSpan() const {
    int shortest_span = std::numeric_limits<int>::max();
    if (this->_array.size() <= 1)
        throw std::logic_error("Too few elements to find Span");
    for (size_t i = 0; i < this->_array.size() - 1; i++) {
        if (shortest_span > std::abs(_array[i] - _array[i + 1]))
            shortest_span = std::abs(_array[i] - _array[i + 1]);
    }
    return shortest_span;
}

unsigned int Span::longestSpan() const {
    if (this->_array.size() <= 1)
        throw std::logic_error("Too few elements to find Span");
    return (*max_element(this->_array.begin(), this->_array.end()) -
            *min_element(this->_array.begin(), this->_array.end()));
}
