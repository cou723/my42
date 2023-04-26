#ifndef PMERGE_ME_T
#define PMERGE_ME_T

#include <iostream>
#include <list>
#include <vector>

#include "PmergeMe.hpp"
#include "list_distance.hpp"
#include "utils.hpp"

// private

template <typename T>
void PmergeMe<T>::insertSort(std::list<unsigned int>::iterator start,
                             std::list<unsigned int>::iterator end) {
    for (std::list<unsigned int>::iterator target = start; target != end;
         ++target) {
        unsigned int value = *target;
        --target;
        if (target == (*this->_container).end()) {
            ++target;
            continue;
        }
        std::list<unsigned int>::iterator comparison = target;
        ++target;
        while (list_distance((*this->_container), comparison, start) <= 0 &&
               *comparison > value) {
            unsigned int tmp = *comparison;
            ++comparison;
            *(comparison--) = tmp;
            --comparison;
            if (comparison == (*this->_container).end()) break;
        }
        ++comparison;
        *(comparison) = static_cast<unsigned int>(value);
    }
}

template <typename T>
void PmergeMe<T>::insertSort(std::vector<unsigned int>::iterator start,
                             std::vector<unsigned int>::iterator end) {
    for (std::vector<unsigned int>::iterator target = start; target != end;
         ++target) {
        unsigned int value = *target;
        std::vector<unsigned int>::iterator comparison = target - 1;
        while (std::distance(comparison, start) <= 0 && *comparison > value) {
            *(comparison + 1) = *comparison;
            --comparison;
        }
        *(comparison + 1) = static_cast<unsigned int>(value);
    }
}

template <typename T>
void PmergeMe<T>::mergeInsertSort(typename T::iterator start,
                                  typename T::iterator end) {
    if (std::distance(start, end) <= 5) {
        insertSort(start, end);
        return;
    }

    typename T::iterator mid = start;
    std::advance(mid, std::distance(start, end) / 2);
    mergeInsertSort(start, mid);
    mergeInsertSort(mid, end);

    T tmp;
    typename T::iterator i = start, j = mid;
    while (i != mid && j != end) {
        if (*i <= *j)
            tmp.push_back(*i++);
        else
            tmp.push_back(*j++);
    }
    while (i != mid) tmp.push_back(*i++);
    while (j != end) tmp.push_back(*j++);
    std::copy(tmp.begin(), tmp.end(), start);
}

// public
template <typename T>
PmergeMe<T>::PmergeMe() {}

template <typename T>
PmergeMe<T>::PmergeMe(char const** list) throw(std::invalid_argument)
    : _elapsed_start(0), _elapsed_end(0) {
    this->_container = new T();
    while (*list != 0) {
        (*this->_container).push_back(myStoi(*list));
        ++list;
    }
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe<T>& pm)
    : _elapsed_start(0), _elapsed_end(0), _container(pm._container) {}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
void PmergeMe<T>::sort() {
    this->_elapsed_start = clock();
    this->mergeInsertSort((*this->_container).begin(),
                          (*this->_container).end());
    this->_elapsed_end = clock();
}

template <typename T>
bool PmergeMe<T>::isSorted() const {
    return my_is_sorted(_container->begin(), _container->end());
}

template <typename T>
unsigned long long int PmergeMe<T>::getElapsedTime() const {
    return (_elapsed_end - _elapsed_start) * 1000 * 1000 / CLOCKS_PER_SEC;
}

template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe<T>& pm) {
    if (this != &pm) this->_container = pm._container;
    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const PmergeMe<T>& pm) {
    typename T::const_iterator it = pm.getBegin();
    while (it != pm.getEnd()) {
        out << *it;
        ++it;
        if (it != pm.getEnd()) out << " ";
    }
    return out;
}

template <typename T>
template <typename U>
void PmergeMe<T>::outputResultImpl(const U*) const {
    std::cout << "Time to process a range of " << (*this->_container).size()
              << " elements with std::unknown : " << getElapsedTime() << " us"
              << std::endl;
}

template <typename T>
void PmergeMe<T>::outputResultImpl(std::vector<unsigned int>*) const {
    std::cout << "Time to process a range of " << (*this->_container).size()
              << " elements with std::vector : " << getElapsedTime() << " us"
              << std::endl;
}

template <typename T>
void PmergeMe<T>::outputResultImpl(std::list<unsigned int>*) const {
    std::cout << "Time to process a range of " << (*this->_container).size()
              << " elements with std::list : " << getElapsedTime() << " us"
              << std::endl;
}

template <typename T>
typename T::const_iterator PmergeMe<T>::getBegin() const {
    return (const_cast<const T&>((*this->_container)).begin());
}

template <typename T>
typename T::const_iterator PmergeMe<T>::getEnd() const {
    return (const_cast<const T&>((*this->_container)).end());
}

#endif /* PMERGE_ME_T */
