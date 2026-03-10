#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &x)
{
  std::cout << x << std::endl;
}

template <typename T>
void increment(T &x)
{
  x += 1;
}

int main(void)
{
  std::cout << "=== int array ===" << std::endl;
  int intArr[] = {1, 2, 3, 4, 5};
  ::iter(intArr, 5, print<int>);

  std::cout << "=== increment int array ===" << std::endl;
  ::iter(intArr, 5, increment<int>);
  ::iter(intArr, 5, print<int>);

  std::cout << "=== double array ===" << std::endl;
  double dblArr[] = {1.1, 2.2, 3.3};
  ::iter(dblArr, 3, print<double>);

  std::cout << "=== string array ===" << std::endl;
  std::string strArr[] = {"hello", "world", "42"};
  ::iter(strArr, 3, print<std::string>);

  std::cout << "=== const int array ===" << std::endl;
  int const constArr[] = {10, 20, 30};
  ::iter(constArr, 3, print<int>);

  return 0;
}
