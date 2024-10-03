#include <iomanip>

#include "Utilities.hpp"
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	this->elems = 0;
}

void PhoneBook::addContact(const Contact& new_contact)
{
	contacts[elems % MAX_CONTACTS] = new_contact;
	elems++;
}

void PhoneBook::searchContact()
{
	std::string str;
	int id, len;

	id = 0;
	len = (elems < MAX_CONTACTS) ? elems : MAX_CONTACTS;
	if (len == 0)
		std::cout << "There is no one in the Phone Book(try ADD command)" << std::endl;
	while (len != 0)
	{
		std::cout << "Enter Contact ID for more information(Enter for cancel search): ";
		getline(std::cin, str);
		if (std::cin.eof() || str.empty() == true)
		{
			std::cout << std::endl << "Search canceled" << std::endl;
			break;
		}
		else
		{
			if (str.size() != 1 || (str[0] < '0' || str[0] > '9'))
			{
				std::cout << "Input numeric value in range" << std::endl;
				continue;
			}
			id = str[0] - '0';
		}
		if (0 <= id && id < len)
		{
			printContactById(id);
			break;
		}
		else
			std::cout << "Inputed ID is out of range: " << std::endl;
	}
}

void PhoneBook::printContactById(const int id)
{
	Contact tmp;

	if (id < 0 || id >= this->elems) {
		std::cout << "Id is out of range" << std::endl;
		return ;
	}
	tmp = contacts[id];
	std::cout << "ID: " << id << std::endl;
	std::cout << "First Name: " << tmp.get_first_name() << std::endl;
	std::cout << "Last name: " << tmp.get_last_name() << std::endl;
	std::cout << "Nickname: " << tmp.get_nickname() << std::endl;
	std::cout << "Phone number: " << tmp.get_phone_number() << std::endl;
	std::cout << "Secret: " << tmp.get_darkest_secret() << std::endl;
}

void	PhoneBook::show_contacts_demo()
{
	const int end = (elems >= MAX_CONTACTS) ? MAX_CONTACTS : elems;
	std::string str;

	std::cout << std::setw(10) << "ID";
	std::cout << '|' << std::setw(10) << "FirstName";
	std::cout << '|' << std::setw(10) << "lastname";
	std::cout << '|' << std::setw(10) << "nickname";
	std::cout << std::endl;
	for (int i = 0; i < end; i++)
	{
		// index, first name, lastname and nickname
		std::cout << std::setw(10) << i;
		std::cout << '|' << std::setw(10) << ft::truncate_string(contacts[i].get_first_name(), 10);
		std::cout << '|' << std::setw(10) << ft::truncate_string(contacts[i].get_last_name(), 10);
		std::cout << '|' << std::setw(10) << ft::truncate_string(contacts[i].get_nickname(), 10);
		std::cout << std::endl;
	}
}
