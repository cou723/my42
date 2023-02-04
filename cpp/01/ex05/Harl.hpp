#ifndef DBE957EE_A2A6_471B_BB51_83845D19E1EF_H
#define DBE957EE_A2A6_471B_BB51_83845D19E1EF_H

#include <string>
class Harl {
  private:
    void _debug();
    void _info();
    void _warning();
    void _error();

  public:
    Harl();
    ~Harl();
    void complain(std::string level);
};

#endif /* DBE957EE_A2A6_471B_BB51_83845D19E1EF_H */
