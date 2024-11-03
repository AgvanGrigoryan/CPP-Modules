#include <fstream>
#include "ShrubberyCreationForm.hpp"

const std::string treeArt = 
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠴⠒⠋⠉⠁⠀⠀⠈⠉⠉⠓⠦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⢀⡴⠖⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⣠⠖⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⢀⡞⠁⠀⠀⠀⠀⠀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⣰⠏⠀⠀⠀⠀⣠⠖⠋⠉⠀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⡀⠠⠀⢰\n"
"⢠⠏⠀⠀⠀⢀⡞⠁⢀⡤⠖⠋⠁⠀⠀⣀⣠⡤⠤⠄⠀⠀⠀⠀⠀⠀⠀⢰⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡴⠖⠛⠉⠉⠀⠀⠀⠀⠀⠀⢸\n"
"⣼⠀⠀⠀⠀⠈⢀⡴⠋⠀⢀⣠⠔⠚⠉⣁⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠋\n"
"⣿⠀⠀⠀⠀⠀⠞⠀⣀⠔⠋⠀⠀⢠⠞⠁⠀⠈⠙⢦⡀⠀⠀⠀⠀⢀⡾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⡞⠁⠀⠀⠀⠀⠀⠀⠀⠀⣀⡴⠚⠁⠀\n"
"⢹⡄⠀⠀⠀⠀⠀⣴⠋⠀⢀⠀⠀⣿⠀⠀⠀⡀⠀⠀⠹⣄⠀⠀⣦⠞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠖⠋⠀⠁⠀⠀⠀⠀⠀⢀⣠⠴⠚⠁⠀⠀⠀⠀\n"
"⠈⢧⠀⠀⠀⠀⢸⠃⠀⡾⠋⠉⠉⠻⣧⠀⢸⣿⡄⠀⠀⠹⡆⠀⢈⣷⠤⠒⠒⠒⠦⣄⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠋⠁⠀⠀⣀⡤⠖⠋⠉⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠈⢧⡀⠀⠀⠀⠀⢸⡇⠀⠀⡀⠀⠙⣆⠀⢻⣿⣦⣄⡀⢹⠀⠈⢀⣠⠴⠒⠒⠒⠾⢦⣀⣀⡀⢀⡠⠖⠋⠁⠀⣀⡤⠒⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠙⠶⣄⣀⣀⣈⣧⡀⢺⣿⣦⠀⢸⡷⣄⡙⠟⢁⣴⠏⣠⠶⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⡇⣀⡤⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⡀⠹⢿⣷⣿⠀⠈⠉⠻⣍⣱⠞⠁⢠⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠞⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣲⠤⣭⣿⠀⠀⢀⡴⠋⠁⢀⣴⣯⣹⠦⠤⠤⠤⠤⠴⠒⣏⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⠁⠀⢀⣿⣀⡾⠋⠀⠀⣠⠞⠻⣄⠹⣆⠀⠀⠀⠀⣠⡴⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⢀⠔⢉⡼⠋⠀⠀⢀⡴⠋⠀⠀⠹⡮⣿⠛⢦⡖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣄⣁⣴⠋⠀⠀⠀⣠⠏⠀⠀⠀⠀⢀⡗⠈⠀⠀⠙⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡽⠁⠀⠀⠀⣰⣧⣀⠀⠀⢀⣠⠿⠁⠀⠀⠀⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⠀⠀⣠⠾⠁⠀⣉⠽⠛⠉⢳⡀⠀⠀⠀⠀⠀⠀⠨⢷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠷⠶⠯⠥⠔⠒⠉⠁⠀⠀⠀⠈⡇⠀⠀⠀⠀⠀⠀⠀⠈⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠁⠀⠀⠀⠀⠀⠀⠀⠀⠘⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠇⠀⢀⣀⣀⣤⣤⣀⣀⡀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⠖⠊⠉⠀⠀⠀⠀⠀⠀⠉⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";


// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", SHRUBBERY_TOSIGN_GRADE, SHRUBBERY_TOEXEC_GRADE), _target("_NO_TARGET_") {
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", SHRUBBERY_TOSIGN_GRADE, SHRUBBERY_TOEXEC_GRADE), _target(target) {
	std::cout << "ShrubberyCreationForm parameter constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// member functions
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "ShrubberyCreationForm copy assignment operator called(it doesn't do anything)" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	validateExecutionRequirements(executor); // Check the conditions, throw exceptions if necessary

	// Do actions of form if the checks are passed
	std::ofstream shrubberyFile(_target + "_shrubbery");
	if (!shrubberyFile) {
		std::cerr << "File could not be opened" << std::endl;
		return;
	}
	shrubberyFile << treeArt;
	shrubberyFile.close();
}