#ifndef EASYFIND_H
#define EASYFIND_H
#include <algorithm>
#include <iterator>

class NotFound : std::exception {
   public:
    const char* what() const throw() { return "Target not found"; }
};

template <typename T>
typename T::iterator easyfind(T& iter, int target) {
    typename T::iterator found = find(iter.begin(), iter.end(), target);
    if (found == iter.end() && *found != target)
        throw NotFound();
    return found;
}

#endif /* EASYFIND_H */
