#include "Harl.hpp"
#include <iostream>
int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./harlFilter <output_level>" << std::endl;
        return 1;
    }
    Harl h;
    h.complain(argv[1]);
    return 0;
}
