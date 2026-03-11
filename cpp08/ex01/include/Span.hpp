#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
public:
  Span(unsigned int n);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber(int number);

  template <typename Iterator>
  void addRange(Iterator begin, Iterator end)
  {
    if (std::distance(begin, end) + _numbers.size() > _maxSize)
      throw std::overflow_error("Span: not enough space to add range");
    _numbers.insert(_numbers.end(), begin, end);
  }

  int shortestSpan() const;
  int longestSpan() const;

private:
  unsigned int _maxSize;
  std::vector<int> _numbers;
};

#endif
