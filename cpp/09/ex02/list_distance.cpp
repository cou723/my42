#include "list_distance.hpp"

#include <iostream>
#include <list>

#ifdef UNIT_TEST
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#endif

int list_distance(std::list<unsigned int>& lst,
                  std::list<unsigned int>::iterator a,
                  std::list<unsigned int>::iterator b) {
    std::list<unsigned int>::iterator start = lst.begin();
    while (start != lst.end()) {
        if (start == a) return std::distance(a, b);
        if (start == b) return (lst.size() - std::distance(a, b) + 1) * -1;
        start++;
    }
    return 0;
}

#ifdef UNIT_TEST
TEST_CASE("uni test") {
    std::list<unsigned int> x{1, 2, 3, 4, 5};
    std::list<unsigned int>::iterator it1 = x.begin();
    std::list<unsigned int>::iterator it2 = x.end();
    REQUIRE(list_distance(x, it1, it2) == std::distance(it1, it2));
    REQUIRE(list_distance(x, it2, it1) == -5);
    REQUIRE(list_distance(x, it1, it1) == 0);
    ++it1;
    REQUIRE(list_distance(x, it1, it2) == std::distance(it1, it2));
    REQUIRE(list_distance(x, it2, it1) == -4);
    REQUIRE(list_distance(x, it1, it1) == 0);
    --it1;
    --it2;
    REQUIRE(list_distance(x, it1, it2) == std::distance(it1, it2));
    REQUIRE(list_distance(x, it2, it1) == -4);
    REQUIRE(list_distance(x, it1, it1) == 0);
    --it2;
    REQUIRE(list_distance(x, it1, it2) == std::distance(it1, it2));
    REQUIRE(list_distance(x, it2, it1) == -3);
    REQUIRE(list_distance(x, it1, it1) == 0);
}
#endif