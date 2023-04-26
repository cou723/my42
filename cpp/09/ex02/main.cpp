#include <algorithm>
#include <ctime>
#include <iostream>
#include <list>
#include <vector>

#include "PmergeMe.hpp"
#include "list_distance.hpp"
#include "utils.hpp"

#ifdef TEST
#define IS_DEBUG false
#else
#define IS_DEBUG false
#endif

template <typename Iterator>
bool my_is_sorted(Iterator first, Iterator last) {
    if (first == last) {
        return true;
    }
    Iterator next = first;
    ++next;
    while (next != last) {
        if (*next < *first) {
            return false;
        }
        ++first;
        ++next;
    }
    return true;
}

int main(int argc, const char** argv) {
    if (argc == 1) return 1;

    const char** number_list = &argv[1];
    PmergeMe<std::vector<unsigned int> > vec;
    PmergeMe<std::list<unsigned int> > lst;
    try {
        vec = PmergeMe<std::vector<unsigned int> >(number_list);
        lst = PmergeMe<std::list<unsigned int> >(number_list);
    } catch (std::invalid_argument const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
#ifndef TEST
    std::cout << "Before: " << vec << std::endl;
#endif
    vec.sort();
    lst.sort();
    std::cout
#ifndef TEST
        << "After: "
#endif
        << vec << std::endl;
#ifndef TEST
    vec.outputResult();
    lst.outputResult();
#endif
    return 0;
}
