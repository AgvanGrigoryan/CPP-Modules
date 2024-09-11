#include <iostream>

#include "PhoneBook.hpp"
#include "Contact.hpp"



int main()
{
	PhoneBook phone_book;
	std::string line;
	std::cout << "Enter command (ADD/SEARCH/EXIT): ";
	while (getline(std::cin, line))
	{
		if (line == "ADD")
		{
			Contact new_contact;
			new_contact.setAllValues();
			phone_book.addContact(new_contact);
		}
		else if (line == "SEARCH")
		{
			phone_book.show_contacts_demo();
			phone_book.searchContact();
		}
		else if (line == "EXIT")
			break;
		else
			std::cout << "Unknown command. Accepted: ADD/SEARCH/EXIT" << std::endl;
		if (std::cin.eof() == false)
			std::cout << "Enter command: ";
	}
	return (0);
}
