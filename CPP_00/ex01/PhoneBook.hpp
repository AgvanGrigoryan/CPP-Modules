#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook {
	public:
		PhoneBook();
		void addContact(const Contact& new_contact);
		void searchContact();
		void show_contacts_demo();
	private:
		void printContactById(const int id);
		Contact contacts[MAX_CONTACTS];
		int	elems;
};

#endif
