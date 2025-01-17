#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &left, T &right) {
	T tmp = left;
	left = right;
	right = tmp;
}

template <typename T>
T& min(T &left, T &right) {
	if (left < right)
		return (left);
	else
		return (right);
}

template <typename T>
T& max(T &left, T &right) {
	if (left > right)
		return (left);
	else
		return (right);
}

#endif
