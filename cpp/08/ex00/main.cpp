#include <iostream>
#include <vector>
#include "easyfind.hpp"
int main() {
    std::vector<int> data(10, 5);
    std::cout << *easyfind(data, 5) << std::endl;
    if(easyfind(data, 5) == data.begin())

    try {
        std::cout << *easyfind(data, 4) << std::endl;
    } catch (const NotFound& e) {
        std::cout << "error detected" << std::endl;
    }
    int array[] = {1, 2, 3};
    std::vector<int> data2(array, array + 3);
    std::cout << *easyfind(data, 3) << std::endl;

    return 0;
}
