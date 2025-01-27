#include <iostream>
#include <sstream>
#include <stdexcept>

std::time_t	stringToDate(const std::string& str) {
	std::tm dateTm = {0};
	std::stringstream ss(str);
	char	delimiter;

	ss >> dateTm.tm_year >> delimiter >> dateTm.tm_mon >> delimiter >> dateTm.tm_mday;
	dateTm.tm_year -= 1900;
	dateTm.tm_mon -= 1;

	return (std::mktime(&dateTm));
}

int main(int argc, char *argv[]) {
	std::string str("2010-12-17");

	std::time_t date = stringToDate(str);
	std::time_t date2 = stringToDate("2010-12-18");

	if (date < date2) {
		std::cout << "Date" << std::endl;
	}
	else {
		std::cout << "Date2" << std::endl;
	}
}