#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class RPN {
private:
	std::string		_expression;
	int				_result;
	bool			_is_result_stale;

	bool	issdigit(const std::string& str);
	bool	is_math_operator(const std::string& str);
	void	process_the_expression();
	void	execute_operation(std::stack<int> &numbers_stack, const char operation);

public:
	RPN();
	RPN(const std::string &expression);
	RPN(const RPN& other);
	~RPN();
	RPN& operator=(const RPN& other);
	void	set_expression(const std::string &expression);
	int		get_result();
};

#endif