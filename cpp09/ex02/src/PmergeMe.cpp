#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &)
{
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::sort(std::vector<int> &vec)
{
  fordJohnsonSort(vec);
}

void PmergeMe::sort(std::deque<int> &deq)
{
  fordJohnsonSort(deq);
}

void PmergeMe::fordJohnsonSort(std::vector<int> &c)
{
  std::size_t n = c.size();
  if (n <= 1)
    return;

  bool hasStraggler = (n % 2 != 0);
  int straggler = 0;
  if (hasStraggler)
    straggler = c[n - 1];

  std::vector<std::pair<int, int> > pairs;
  for (std::size_t i = 0; i + 1 < n; i += 2)
  {
    if (c[i] > c[i + 1])
      pairs.push_back(std::make_pair(c[i], c[i + 1]));
    else
      pairs.push_back(std::make_pair(c[i + 1], c[i]));
  }

  std::vector<int> largers;
  for (std::size_t i = 0; i < pairs.size(); i++)
    largers.push_back(pairs[i].first);

  fordJohnsonSort(largers);

  std::vector<std::pair<int, int> > sortedPairs;
  std::vector<bool> used(pairs.size(), false);
  for (std::size_t i = 0; i < largers.size(); i++)
  {
    for (std::size_t j = 0; j < pairs.size(); j++)
    {
      if (!used[j] && pairs[j].first == largers[i])
      {
        sortedPairs.push_back(pairs[j]);
        used[j] = true;
        break;
      }
    }
  }

  std::vector<int> mainChain;
  mainChain.push_back(sortedPairs[0].second);
  for (std::size_t i = 0; i < sortedPairs.size(); i++)
    mainChain.push_back(sortedPairs[i].first);

  std::vector<int> pend;
  for (std::size_t i = 1; i < sortedPairs.size(); i++)
    pend.push_back(sortedPairs[i].second);

  if (!pend.empty())
  {
    std::vector<std::size_t> order = generateInsertionOrder(pend.size());
    for (std::size_t i = 0; i < order.size(); i++)
    {
      int val = pend[order[i]];
      std::vector<int>::iterator pos = std::lower_bound(
          mainChain.begin(), mainChain.end(), val);
      mainChain.insert(pos, val);
    }
  }

  if (hasStraggler)
  {
    std::vector<int>::iterator pos = std::lower_bound(
        mainChain.begin(), mainChain.end(), straggler);
    mainChain.insert(pos, straggler);
  }

  c = mainChain;
}

void PmergeMe::fordJohnsonSort(std::deque<int> &c)
{
  std::size_t n = c.size();
  if (n <= 1)
    return;

  bool hasStraggler = (n % 2 != 0);
  int straggler = 0;
  if (hasStraggler)
    straggler = c[n - 1];

  std::vector<std::pair<int, int> > pairs;
  for (std::size_t i = 0; i + 1 < n; i += 2)
  {
    if (c[i] > c[i + 1])
      pairs.push_back(std::make_pair(c[i], c[i + 1]));
    else
      pairs.push_back(std::make_pair(c[i + 1], c[i]));
  }

  std::deque<int> largers;
  for (std::size_t i = 0; i < pairs.size(); i++)
    largers.push_back(pairs[i].first);

  fordJohnsonSort(largers);

  std::vector<std::pair<int, int> > sortedPairs;
  std::vector<bool> used(pairs.size(), false);
  for (std::size_t i = 0; i < largers.size(); i++)
  {
    for (std::size_t j = 0; j < pairs.size(); j++)
    {
      if (!used[j] && pairs[j].first == largers[i])
      {
        sortedPairs.push_back(pairs[j]);
        used[j] = true;
        break;
      }
    }
  }

  std::deque<int> mainChain;
  mainChain.push_back(sortedPairs[0].second);
  for (std::size_t i = 0; i < sortedPairs.size(); i++)
    mainChain.push_back(sortedPairs[i].first);

  std::vector<int> pend;
  for (std::size_t i = 1; i < sortedPairs.size(); i++)
    pend.push_back(sortedPairs[i].second);

  if (!pend.empty())
  {
    std::vector<std::size_t> order = generateInsertionOrder(pend.size());
    for (std::size_t i = 0; i < order.size(); i++)
    {
      int val = pend[order[i]];
      std::deque<int>::iterator pos = std::lower_bound(
          mainChain.begin(), mainChain.end(), val);
      mainChain.insert(pos, val);
    }
  }

  if (hasStraggler)
  {
    std::deque<int>::iterator pos = std::lower_bound(
        mainChain.begin(), mainChain.end(), straggler);
    mainChain.insert(pos, straggler);
  }

  c = mainChain;
}

std::vector<std::size_t> PmergeMe::generateInsertionOrder(std::size_t pendSize)
{
  std::vector<std::size_t> order;
  if (pendSize == 0)
    return order;

  std::size_t totalPairs = pendSize + 1;

  std::vector<std::size_t> jacobsthal;
  jacobsthal.push_back(0);
  jacobsthal.push_back(1);
  while (jacobsthal.back() < totalPairs)
  {
    std::size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
    jacobsthal.push_back(next);
  }

  for (std::size_t k = 3; k < jacobsthal.size(); k++)
  {
    std::size_t jk = jacobsthal[k];
    std::size_t jk_prev = jacobsthal[k - 1];
    std::size_t upper = (jk > totalPairs) ? totalPairs : jk;

    for (std::size_t bIdx = upper; bIdx > jk_prev && bIdx >= 2; bIdx--)
      order.push_back(bIdx - 2);

    if (jk >= totalPairs)
      break;
  }

  return order;
}
