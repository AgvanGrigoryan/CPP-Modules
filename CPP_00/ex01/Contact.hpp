#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
	public:
		Contact();

		void setAllValues();
		//setters
		void set_first_name();
		void set_last_name();
		void set_nickname();
		void set_phone_number();
		void set_darkest_secret();
		//getters
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
		std::string get_phone_number();
		std::string get_darkest_secret();
	private:
		std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};

#endif