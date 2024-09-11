#include <iostream>

#include "PhoneBook.hpp"
#include "Contact.hpp"



int main()
{
	PhoneBook phonebook;
	std::string line;
	std::cout << "Enter command (ADD/SEARCH/EXIT): ";
	while (getline(std::cin, line))
	{
		if (line == "ADD")
		{
			Contact new_contact;
			new_contact.setAllValues();
			phonebook.addContact(new_contact);
		}
		else if (line == "SEARCH")
		{
			phonebook.show_contacts_demo();
			phonebook.searchContact();
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
