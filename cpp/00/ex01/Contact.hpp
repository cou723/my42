#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cstddef>
#include <string>

class Contact {
    private:
        std::size_t index;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:
        Contact(std::size_t index, std::string first_name, std::string last_name, std::string nickname,
                        std::string phone_number, std::string darkest_secret);
        ~Contact();
        std::size_t GetIndex();
        std::string GetFirstName();
        std::string GetLastName();
        std::string GetNickname();
        void Display();
};

#endif /* CONTACT_HPP */
