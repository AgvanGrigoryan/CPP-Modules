#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:

	MutantStack();
	MutantStack(unsigned int N);
	MutantStack(const MutantStack& other);
	~MutantStack();
	MutantStack&	operator=(const MutantStack& other);

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	reverse_iterator rbegin();
	reverse_iterator rend();
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;

};

template <typename T, typename Container>
MutantStack<T,Container>::MutantStack() {
	std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T, typename Container>
MutantStack<T,Container>::MutantStack(const MutantStack& ) {
	std::cout << "MutantStack copy constructor called" << std::endl;
}

template <typename T, typename Container>
MutantStack<T,Container>::~MutantStack() {
	std::cout << "MutantStack destructor called" << std::endl;
}

template <typename T, typename Container>
MutantStack<T,Container>&	MutantStack<T,Container>::operator=(const MutantStack& ) {
	std::cout << "MutantStack assignment operator called" << std::endl;
}

#include "MutantStack.tpp"

#endif