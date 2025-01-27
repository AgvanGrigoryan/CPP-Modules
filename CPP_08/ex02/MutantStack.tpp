
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
	std::cout << "MutantStack copy assignment operator called" << std::endl;
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
	return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
	return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const {
	return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const {
	return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin() {
	return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend() {
	return this->c.rend();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const {
	return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const {
	return this->c.rend();
}
