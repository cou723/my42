#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP
#include <Contact.hpp>
#define ROW_SIZE 10
#define MAX_CONTACTS_COUNT 8

class PhoneBook {
  private:
    Contact *contacts[MAX_CONTACTS_COUNT];
    std::size_t total_index = 0;
    Contact *SearchContact(std::size_t index);
    void DisplayContacts();
    void AddContact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number,
                    std::string darkest_secret);

  public:
    PhoneBook();
    void RunAddCommand();
    void RunSearchCommand();
    ~PhoneBook();
};

#endif /* PHONE_BOOK_HPP */
