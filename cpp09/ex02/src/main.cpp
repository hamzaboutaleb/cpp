#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <sys/time.h>

static bool parsePositiveInt(const std::string &s, int &result)
{
  if (s.empty() || s.size() > 10)
    return false;
  for (std::size_t i = 0; i < s.size(); i++)
  {
    if (s[i] < '0' || s[i] > '9')
      return false;
  }
  char *end;
  long val = std::strtol(s.c_str(), &end, 10);
  if (*end != '\0' || val <= 0 || val > 2147483647)
    return false;
  result = static_cast<int>(val);
  return true;
}

static double getTimeUs()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  std::vector<int> numbers;
  for (int i = 1; i < argc; i++)
  {
    int val;
    if (!parsePositiveInt(argv[i], val))
    {
      std::cerr << "Error" << std::endl;
      return 1;
    }
    numbers.push_back(val);
  }

  std::cout << "Unsorted sequence:";
  for (std::size_t i = 0; i < numbers.size(); i++)
    std::cout << " " << numbers[i];
  std::cout << std::endl;

  std::vector<int> vec(numbers.begin(), numbers.end());
  double startTime = getTimeUs();
  PmergeMe pmerge;
  pmerge.sort(vec);
  double vecTime = getTimeUs() - startTime;

  std::deque<int> deq(numbers.begin(), numbers.end());
  startTime = getTimeUs();
  pmerge.sort(deq);
  double deqTime = getTimeUs() - startTime;

  std::cout << "Sorted sequence:";
  for (std::size_t i = 0; i < vec.size(); i++)
    std::cout << " " << vec[i];
  std::cout << std::endl;

  std::cout << "Time taken by algorithm using std::vector for " << numbers.size()
            << " elements: " << vecTime << " us" << std::endl;
  std::cout << "Time taken by algorithm using std::deque for " << numbers.size()
            << " elements: " << deqTime << " us" << std::endl;

  return 0;
}
