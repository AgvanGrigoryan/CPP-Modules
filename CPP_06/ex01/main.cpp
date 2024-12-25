#include <cstdint>
#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {
	Data someData = {42, 'a'};
	uintptr_t	serializedAddress;
	Data*		deserializedAddress;

	serializedAddress = Serializer::serialize(&someData);
	deserializedAddress = Serializer::deserialize(serializedAddress);
	
	std::cout << "&someData=" << &someData << std::endl;
	std::cout << "serializedAddress=" << serializedAddress << std::endl;
	std::cout << "deserializedAddress=" << deserializedAddress << std::endl;
	if (&someData == deserializedAddress) {
		std::cout << "deserializedAddress->" << std::endl;
		std::cout << "\t->count=" << deserializedAddress->count << std::endl;
		std::cout << "\t->type=" << deserializedAddress->type << std::endl;
	}
	else
		std::cout << "Bad Serialization! The Addresses don't match";
}