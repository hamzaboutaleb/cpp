#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	// --- Subject test ---
	std::cout << "=== Subject test ===" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	// --- Same test with std::list for comparison ---
	std::cout << "\n=== std::list comparison ===" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Back: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Size: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	while (lit != lite) {
		std::cout << *lit << std::endl;
		++lit;
	}

	// --- Reverse iterator ---
	std::cout << "\n=== Reverse iteration ===" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite) {
		std::cout << *rit << std::endl;
		++rit;
	}

	// --- Const iterator ---
	std::cout << "\n=== Const iteration ===" << std::endl;
	const MutantStack<int> cstack(mstack);
	MutantStack<int>::const_iterator cit = cstack.begin();
	MutantStack<int>::const_iterator cite = cstack.end();
	while (cit != cite) {
		std::cout << *cit << std::endl;
		++cit;
	}

	// --- Copy & assignment ---
	std::cout << "\n=== Copy & assignment ===" << std::endl;
	MutantStack<int> copy(mstack);
	MutantStack<int> assigned;
	assigned = mstack;
	std::cout << "Copy top:     " << copy.top() << std::endl;
	std::cout << "Assigned top: " << assigned.top() << std::endl;
	std::cout << "Copy size:     " << copy.size() << std::endl;
	std::cout << "Assigned size: " << assigned.size() << std::endl;

	// --- Modify through iterator ---
	std::cout << "\n=== Modify through iterator ===" << std::endl;
	MutantStack<int>::iterator mit = mstack.begin();
	*mit = 999;
	std::cout << "Bottom after modification: " << *mstack.begin() << std::endl;

	// --- Empty check ---
	std::cout << "\n=== Empty stack ===" << std::endl;
	MutantStack<int> emptyStack;
	std::cout << "Empty: " << emptyStack.empty() << std::endl;
	std::cout << "begin == end: " << (emptyStack.begin() == emptyStack.end()) << std::endl;

	return 0;
}
