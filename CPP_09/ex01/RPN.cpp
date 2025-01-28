#include "RPN.hpp"
#include <cctype>
#include <stdexcept>

RPN::RPN() : _expression(), _is_result_stale(true) {
	std::cout << "Default constructor called" << std::endl;
}

RPN::RPN(const std::string &expression) : _expression(expression), _is_result_stale(true) {
	std::cout << "Parameter constructor called" << std::endl;
}

RPN::RPN(const RPN& other) : _expression(other._expression), _is_result_stale(true) {
	std::cout << "Copy constructor called" << std::endl;
}

RPN::~RPN() {
	std::cout << "Destructor called" << std::endl;
}

RPN& RPN::operator=(const RPN& other) {
	if (this == &other)
		return (*this);
	this->_expression = other._expression;
	_is_result_stale = true;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

// Main Logic

void	RPN::execute_operation(std::stack<int> &numbers_stack, const char operation) {
	if (numbers_stack.size() < 2)
		throw std::runtime_error("RPN: Invalid expression");
	int operand1;
	int operand2;
	int result;

	operand2 = numbers_stack.top();
	numbers_stack.pop();
	operand1 = numbers_stack.top();
	numbers_stack.pop();
	switch (operation) {
		case '+':
			result = operand1 + operand2;
			break;
		case '-':
			result = operand1 - operand2;
			break;
		case '*':
			result = operand1 * operand2;
			break;
		case '/':
			if (operand2 == 0)
				throw std::runtime_error("RPN: Division by zero");
			result = operand1 / operand2;
			break;
	}
	numbers_stack.push(result);
}

void	RPN::process_the_expression() {
	if (_expression.empty())
		throw std::runtime_error("RPN: Expression is empty");
	std::stringstream ss(_expression);
	std::string	token;
	std::stack<int>	numbers_stack;

	while (ss >> token) {
		if (issdigit(token))
			numbers_stack.push(token[0] - 48);
		else if (is_math_operator(token))
			execute_operation(numbers_stack, token[0]);
		else
			throw std::runtime_error("RPN: Invalid token found: " + token);
	}
	if (numbers_stack.size() != 1)
		throw std::runtime_error("RPN: Invalid expression");
	_result = numbers_stack.top();
	_is_result_stale = false;
}

// Getters & Setters

int	RPN::get_result() {
	if (_is_result_stale)
		process_the_expression();
	return (_result);
}

void	RPN::set_expression(const std::string &expression) {
	_expression = expression;
	_is_result_stale = true;
}

// Helper functions

bool	RPN::is_math_operator(const std::string& str) {
	return (str.size() == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/'));
}

bool	RPN::issdigit(const std::string& str) {
	return (str.size() == 1 && std::isdigit(str[0]));
}