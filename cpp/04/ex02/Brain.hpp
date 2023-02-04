#ifndef BRAIN_H
#define BRAIN_H
#include <string>
class Brain {
   private:
    std::string idea[100];

   public:
    Brain();
    Brain(const Brain& b);
    ~Brain();
    Brain* operator=(const Brain& b);
};

#endif /* BRAIN_H */
