#include <iostream>

int main(int argc, char *argv[]) {
    if(argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for(size_t i = 1; i < (size_t)argc; i++) {
        std::string input = argv[i];
        for(size_t i = 0; i < input.length(); i++)
            input[i] = std::toupper(input[i]);
        std::cout << input;
    }
    std::cout << '\n';

    return 0;
}
