#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
  // --- Test with std::vector ---
  std::cout << "=== std::vector ===" << std::endl;
  std::vector<int> vec;
  for (int i = 0; i < 10; i++)
    vec.push_back(i * 3);

  try
  {
    std::vector<int>::iterator it = easyfind(vec, 9);
    std::cout << "Found " << *it << " at index " << std::distance(vec.begin(), it) << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  try
  {
    std::vector<int>::iterator it = easyfind(vec, 42);
    std::cout << "Found " << *it << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "42: " << e.what() << std::endl;
  }

  // --- Test with std::list ---
  std::cout << "\n=== std::list ===" << std::endl;
  std::list<int> lst;
  for (int i = 0; i < 5; i++)
    lst.push_back(i + 10);

  try
  {
    std::list<int>::iterator it = easyfind(lst, 12);
    std::cout << "Found " << *it << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  try
  {
    std::list<int>::iterator it = easyfind(lst, 99);
    std::cout << "Found " << *it << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "99: " << e.what() << std::endl;
  }

  // --- Test with std::deque ---
  std::cout << "\n=== std::deque ===" << std::endl;
  std::deque<int> deq;
  deq.push_back(100);
  deq.push_back(200);
  deq.push_back(300);

  try
  {
    std::deque<int>::iterator it = easyfind(deq, 200);
    std::cout << "Found " << *it << " at index " << std::distance(deq.begin(), it) << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

  try
  {
    std::deque<int>::iterator it = easyfind(deq, 0);
    std::cout << "Found " << *it << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "0: " << e.what() << std::endl;
  }

  // --- Edge case: empty container ---
  std::cout << "\n=== empty container ===" << std::endl;
  std::vector<int> empty;
  try
  {
    easyfind(empty, 1);
  }
  catch (std::exception &e)
  {
    std::cout << "empty: " << e.what() << std::endl;
  }

  return 0;
}
