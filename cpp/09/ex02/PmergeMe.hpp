#ifndef PMERGE_ME_H
#define PMERGE_ME_H
#include <sys/types.h>

#include <list>
#include <ostream>
#include <stdexcept>
#include <vector>

template <typename T>
class PmergeMe {
   private:
    clock_t _elapsed_start;
    clock_t _elapsed_end;
    T* _container;
    void insertSort(std::vector<unsigned int>::iterator start,
                    std::vector<unsigned int>::iterator end);
    void insertSort(std::list<unsigned int>::iterator start,
                    std::list<unsigned int>::iterator end);
    void mergeInsertSort(typename T::iterator start, typename T::iterator end);

   public:
    PmergeMe<T>();
    PmergeMe<T>(char const** list) throw(std::invalid_argument);
    PmergeMe<T>(const PmergeMe<T>& pm);
    ~PmergeMe<T>();
    void sort();
    bool isSorted() const;
    unsigned long long int getElapsedTime() const;
    PmergeMe& operator=(const PmergeMe&);
    void outputResult() const { outputResultImpl((T*)0); };
    template <typename U>
    void outputResultImpl(const U*) const;
    void outputResultImpl(std::vector<unsigned int>*) const;
    void outputResultImpl(std::list<unsigned int>*) const;

    typename T::const_iterator getBegin() const;

    typename T::const_iterator getEnd() const;
};
template <typename T>
std::ostream& operator<<(std::ostream& out, const PmergeMe<T>& pm);

#include "PmergeMe.tpp"

#endif /* PMERGE_ME_H */
