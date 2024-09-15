#include <iostream>
#include <fstream>

void	ft_replace(std::string& str, const std::string& from, const std::string& to)
{
	unsigned long long	occur_pos;

	while ((occur_pos = str.find(from, 0)) != std::string::npos) {
		str.erase(occur_pos, from.length());
		str.insert(occur_pos, to);
	}
}

int	main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "Invalid arguments.\nExpected: <filename> <replace_from> <replace_to>" << std::endl;
		return (1);
	}

// file streams
	std::ifstream	inFile;
	std::ofstream	outFile;
// strings
	std::string		from(argv[2]);
	std::string		to(argv[3]);
	std::string		line;

	inFile.open(argv[1], std::ios::out);
	if (inFile.is_open() == false) {
		std::cout << "Error opening " << argv[1] << std::endl;
		return (1);
	}
	outFile.open(std::string(argv[1]) + ".replace", std::ios::out);
	if (outFile.is_open() == false) {
		std::cout << "Error opening outfile" << std::endl;
		return (1);
	}
	while (std::getline(inFile, line)) {
		if (!from.empty())
			ft_replace(line, std::string(argv[2]), std::string(argv[3]));
		outFile << line << std::endl;
	}
	outFile.close();
	inFile.close();
	return 0;
}
