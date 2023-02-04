#include <iostream>
#include <string>
int main() {
    std::string s = "HI THIS IS BRAIN";
    std::string *s_ptr = &s;
    std::string &s_ref = s;

    std::cout << "s's     memory address: " << std::hex << &s << std::endl;
    std::cout << "s_ptr's memory address: " << std::hex << &s_ptr << std::endl;
    std::cout << "s_ref's memory address: " << std::hex << &s_ref << std::endl;
    std::cout << std::endl;
    std::cout << "s's     value: " << s << std::endl;
    std::cout << "s_ptr's value: " << s_ptr << std::endl;
    std::cout << "s_ref's value: " << s_ref << std::endl;
}
