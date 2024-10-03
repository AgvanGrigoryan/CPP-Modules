#include <iostream>
#include "Utilities.hpp"
#include "Contact.hpp"

Contact::Contact()
{
	first_name.clear();
	last_name.clear();
	nickname.clear();
	phone_number.clear();
	darkest_secret.clear();
}

// Setters
void Contact::set_first_name()
{
	std::cout << "Enter First Name: ";
	while (getline(std::cin, first_name)) {
		if (first_name.empty() == false &&
			ft::isAllLetters(first_name) == true)
			break;
		std::cout << "First Name must consist of only letters (at least one)." << std::endl;
		std::cout << "Enter First Name: ";
	}
}

void Contact::set_last_name()
{
	std::cout << "Enter Last Name: ";
	while (getline(std::cin, last_name)) {
		if (last_name.empty() == false &&
			ft::isAllLetters(last_name) == true)
			break;
		std::cout << "Last name must consist of only letters (at least one)." << std::endl;
		std::cout << "Enter Last Name: ";
	}
}

void Contact::set_phone_number()
{
	std::cout << "Enter Phone number: ";
	while (getline(std::cin, phone_number)) {
		if (phone_number.empty() == false &&
			ft::isAllDigits(phone_number) == true)
			break;
		std::cout << "Phone number must consist of only digits (at least one)." << std::endl;
		std::cout << "Enter Phone number: ";
	}
}

void Contact::set_nickname()
{
	std::string trimmed;

	std::cout << "Enter Nickname: ";
	while (getline(std::cin, nickname))
	{
		trimmed = ft::trim(nickname);
		if (trimmed.empty() == false)
		{
			nickname = trimmed;
			break;
		}
		std::cout << "Nickname can't be empty" << std::endl;
		std::cout << "Enter Nickname: ";
	}
}

void Contact::set_darkest_secret()
{
	std::string trimmed;

	std::cout << "Enter your darkest secret: ";
	while (getline(std::cin, darkest_secret))
	{
		trimmed = ft::trim(darkest_secret);
		if (trimmed.empty() == false)
		{
			darkest_secret = trimmed;
			break;
		}
		std::cout << "Darkest secret can't be empty" << std::endl;
		std::cout << "Enter your darkest secret: ";
	}
}

void Contact::setAllValues()
{
	if (std::cin.eof() == false)
		set_first_name();
	if (std::cin.eof() == false)
		set_last_name();
	if (std::cin.eof() == false)
		set_nickname();
	if (std::cin.eof() == false)
		set_phone_number();
	if (std::cin.eof() == false)
		set_darkest_secret();
}

// Getters
std::string Contact::get_first_name()
{
	return (first_name);
}
std::string Contact::get_last_name()
{
	return (last_name);
}
std::string Contact::get_phone_number()
{
	return (phone_number);
}
std::string Contact::get_nickname()
{
	return (nickname);
}
std::string Contact::get_darkest_secret()
{
	return (darkest_secret);
}
