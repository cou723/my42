#ifndef CE392BF5_E690_48CF_87C9_D876EB934AA5_H
#define CE392BF5_E690_48CF_87C9_D876EB934AA5_H

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

#endif /* CE392BF5_E690_48CF_87C9_D876EB934AA5_H */
