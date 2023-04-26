#include <exception>
#include <iomanip>
#include <iostream>
#include <stack>
#include <string>

#include "RPN.hpp"
#include "TreeNode.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try {
        RPN rpn(argv[1]);
        std::cout << rpn.calc() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
        return 1;
    }
    return 0;
}