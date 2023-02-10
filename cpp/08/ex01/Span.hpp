#ifndef SPAN_H
#define SPAN_H
#include <iostream>
#include <iterator>
#include <vector>
class Span {
   private:
    unsigned int _N;
    std::vector<int> _array;

   public:
    Span();
    Span(unsigned int n);
    Span(const Span& s);
    ~Span();
    Span& operator=(const Span& s);

    void addNumber(int n);
    void addNumbers(std::vector<int>::iterator start,
                    std::vector<int>::iterator end);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
};

#endif /* SPAN_H */
