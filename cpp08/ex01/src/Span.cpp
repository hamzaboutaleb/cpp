#include "Span.hpp"
#include <climits>

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
  if (this != &other)
  {
    _maxSize = other._maxSize;
    _numbers = other._numbers;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
  if (_numbers.size() >= _maxSize)
    throw std::overflow_error("Span is full: cannot add more numbers");
  _numbers.push_back(number);
}

int Span::shortestSpan() const
{
  if (_numbers.size() < 2)
    throw std::logic_error("Span: not enough elements to find a span");
  std::vector<int> sorted(_numbers);
  std::sort(sorted.begin(), sorted.end());
  int minSpan = INT_MAX;
  for (std::size_t i = 1; i < sorted.size(); i++)
  {
    int diff = sorted[i] - sorted[i - 1];
    if (diff < minSpan)
      minSpan = diff;
  }
  return minSpan;
}

int Span::longestSpan() const
{
  if (_numbers.size() < 2)
    throw std::logic_error("Span: not enough elements to find a span");
  int min = *std::min_element(_numbers.begin(), _numbers.end());
  int max = *std::max_element(_numbers.begin(), _numbers.end());
  return max - min;
}
