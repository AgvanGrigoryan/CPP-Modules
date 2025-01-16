template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {
	std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(0) {
	std::cout << "Array paramether constructor called" << std::endl;
	this->_array = new(std::nothrow) T[n];
	if (!this->_array)
		std::cout << "Memory allocation failed" << std::endl;
	else
		_size = n;
}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(0){
	std::cout << "Copy constructor called" << std::endl;

	this->_array = new(std::nothrow) T[other._size];
	if (!this->_array)
		std::cout << "Memory allocation failed" << std::endl;
	else {
		for (unsigned int i = 0; i < other._size; i++)
			this->_array[i] = other._array[i];
		this->_size = other._size;
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	T* temp;

	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);

	temp = new(std::nothrow) T[other._size];
	if (!temp)
		std::cout << "Memory allocation failed" << std::endl;
	else {
		delete this->_array;
		this->_array = temp;
		this->_size = other._size;
		for (unsigned int i = 0; i < other._size; i++)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index < _size)
		return (_array[index]);
	else
		throw std::exception();
}

template <typename T>
unsigned int Array<T>::size() const {
	return (_size);
}

template <typename T>
Array<T>::~Array() {
	delete[] _array;
}
