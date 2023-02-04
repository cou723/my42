#include <fstream>
#include <iostream>
#include <string>

bool argsCheck(int argc, char const *argv[]) {
    if (argc != 4) {
        std::cout << "Usage: " << argv[0]
                  << " <input file> <output file> <number of threads>"
                  << std::endl;
        return false;
    }
    std::ifstream ifs(argv[1]);
    if (ifs.fail()) {
        std::cerr << argv[1] << ": Failed to open input file." << std::endl;
        return false;
    }
    return true;
}

void replaceToNewFile(std::fstream &outfile, const char *str, std::string a,
                      std::string b) {
    while (*str != '\0') {
        if (std::string(str).substr(0, a.length()) == a) {
            outfile << b;
            str += a.length();
        } else {
            outfile << str[0];
            str++;
        }
    }
    outfile << "\n";
}

int main(int argc, char const *argv[]) {
    if (!argsCheck(argc, argv))
        return 1;
    std::ifstream ifs(argv[1]);
    std::string file_text;
    std::fstream outfile;
    try {
        outfile.open((std::string(argv[1]) + ".replace").c_str(),
                     std::ios_base::out);
    } catch (const std::exception &e) {
        std::cerr << argv[1] << ": Failed to open output file." << std::endl;
    }
    while (getline(ifs, file_text))
        replaceToNewFile(outfile, file_text.c_str(), argv[2], argv[3]);
    return 0;
}
