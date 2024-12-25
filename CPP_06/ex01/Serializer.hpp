#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

class Serializer {
private:
	Serializer();
	// other methods for orthodox form
public:
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
}

#endif