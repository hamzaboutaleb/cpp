#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstddef>

class PmergeMe
{
public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  void sort(std::vector<int> &vec);
  void sort(std::deque<int> &deq);

private:
  static std::vector<std::size_t> generateInsertionOrder(std::size_t pendSize);

  static void fordJohnsonSort(std::vector<int> &c);
  static void fordJohnsonSort(std::deque<int> &c);
};

#endif
