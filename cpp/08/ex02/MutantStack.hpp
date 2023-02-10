#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H
#include <iterator>
#include <stack>
template <class T>
class MutantStack : public std::stack<T> {
   public:
    typedef typename std::stack<T>::container_type container_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;
    typedef typename container_type::reverse_iterator reverse_iterator;
    typedef
        typename container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin() { return static_cast<iterator>(this->c.begin()); }
    iterator end() { return static_cast<iterator>(this->c.end()); }

    const_iterator begin(void) const { return (this->c.begin()); }
    const_iterator end(void) const { return (this->c.end()); }

    reverse_iterator rbegin(void) { return (this->c.rbegin()); }
    reverse_iterator rend(void) { return (this->c.rend()); }

    const_reverse_iterator rbegin(void) const { return (this->c.rbegin()); }
    const_reverse_iterator rend(void) const { return (this->c.rend()); }
};

#endif /* MUTANTSTACK_H */
