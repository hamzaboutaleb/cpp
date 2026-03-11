#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
  // --- Subject example ---
  std::cout << "=== Subject test ===" << std::endl;
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest:  " << sp.longestSpan() << std::endl;

  // --- Overflow test ---
  std::cout << "\n=== Overflow test ===" << std::endl;
  try
  {
    sp.addNumber(42);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  // --- Not enough elements ---
  std::cout << "\n=== Too few elements ===" << std::endl;
  Span empty(0);
  try
  {
    empty.shortestSpan();
  }
  catch (std::exception &e)
  {
    std::cout << "empty shortestSpan: " << e.what() << std::endl;
  }
  Span one(1);
  one.addNumber(42);
  try
  {
    one.longestSpan();
  }
  catch (std::exception &e)
  {
    std::cout << "one longestSpan:    " << e.what() << std::endl;
  }

  // --- 10,000 numbers ---
  std::cout << "\n=== 10,000 numbers ===" << std::endl;
  Span big(10000);
  std::srand(std::time(NULL));
  for (int i = 0; i < 10000; i++)
    big.addNumber(std::rand());
  std::cout << "Shortest: " << big.shortestSpan() << std::endl;
  std::cout << "Longest:  " << big.longestSpan() << std::endl;

  // --- 100,000 numbers with addRange ---
  std::cout << "\n=== 100,000 numbers (addRange) ===" << std::endl;
  Span huge(100000);
  std::vector<int> vec;
  for (int i = 0; i < 100000; i++)
    vec.push_back(std::rand());
  huge.addRange(vec.begin(), vec.end());
  std::cout << "Shortest: " << huge.shortestSpan() << std::endl;
  std::cout << "Longest:  " << huge.longestSpan() << std::endl;

  // --- addRange overflow ---
  std::cout << "\n=== addRange overflow ===" << std::endl;
  Span small(3);
  small.addNumber(1);
  std::vector<int> extra;
  extra.push_back(2);
  extra.push_back(3);
  extra.push_back(4);
  try
  {
    small.addRange(extra.begin(), extra.end());
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  // --- Copy / assignment ---
  std::cout << "\n=== Copy & assignment ===" << std::endl;
  Span original(5);
  original.addNumber(1);
  original.addNumber(100);
  Span copy(original);
  Span assigned(1);
  assigned = original;
  std::cout << "Copy shortest:     " << copy.shortestSpan() << std::endl;
  std::cout << "Assigned longest:  " << assigned.longestSpan() << std::endl;

  return 0;
}
