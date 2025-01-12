#ifndef ARRAY_HPP
#define ARRAY_HPP

template<class T>
class Array {
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
};

#endif