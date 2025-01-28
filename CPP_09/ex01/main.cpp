#include "RPN.hpp"
#include <iostream>
// #include <cassert>

// void test_empty_expression() {
//     try {
//         RPN calculator("");
//         calculator.get_result();
//         std::cerr << "Test failed: empty expression did not throw exception" << std::endl;
//     } catch (const std::runtime_error& e) {
//         assert(std::string(e.what()) == "RPN: Expression is empty");
//     }
// }

// void test_not_enough_operands() {
//     try {
//         RPN calculator("1 +");
//         calculator.get_result();
//         std::cerr << "Test failed: not enough operands did not throw exception" << std::endl;
//     } catch (const std::runtime_error& e) {
//         assert(std::string(e.what()) == "RPN: Invalid expression");
//     }
// }

// void test_too_many_operands() {
//     try {
//         RPN calculator("1 2 3 +");
//         calculator.get_result();
//         std::cerr << "Test failed: too many operands did not throw exception" << std::endl;
//     } catch (const std::runtime_error& e) {
//         assert(std::string(e.what()) == "RPN: Invalid expression");
//     }
// }

// void test_invalid_expression_extra_symbols() {
//     try {
//         RPN calculator("1 2 $ +");
//         calculator.get_result();
//         std::cerr << "Test failed: invalid token ($) did not throw exception" << std::endl;
//     } catch (const std::runtime_error& e) {
//         assert(std::string(e.what()) == "RPN: Invalid token found: $");
//     }
// }

// void test_invalid_expression_non_digit_operand() {
//     try {
//         RPN calculator("a b *");
//         calculator.get_result();
//         std::cerr << "Test failed: non-digit operand did not throw exception" << std::endl;
//     } catch (const std::runtime_error& e) {
//         assert(std::string(e.what()) == "RPN: Invalid token found: a");
//     }
// }

// void test_normal_case_1() {
//     try {
//         RPN calculator("2 3 +");
//         int result = calculator.get_result();
//         assert(result == 5);
//     } catch (const std::runtime_error& e) {
//         std::cerr << "Test failed: normal case 1 " << e.what() << std::endl;
//     }
// }

// void test_normal_case_2() {
//     try {
//         RPN calculator("3 4 * 2 +");
//         int result = calculator.get_result();
//         assert(result == 14);
//     } catch (const std::runtime_error& e) {
//         std::cerr << "Test failed: normal case 2 " << e.what() << std::endl;
//     }
// }

// void test_copy_constructor() {
//     try {
//         RPN original("5 2 +");
//         RPN copied = original;  // Use copy constructor
//         int result = copied.get_result();
//         assert(result == 7);
//     } catch (const std::runtime_error& e) {
//         std::cerr << "Test failed: copy constructor " << e.what() << std::endl;
//     }
// }

// void test_copy_assignment() {
//     try {
//         RPN original("8 3 +");
//         RPN assigned("10 2 +");
//         assigned = original;  // Use copy assignment operator
//         int result = assigned.get_result();
//         assert(result == 11);
//     } catch (const std::runtime_error& e) {
//         std::cerr << "Test failed: copy assignment " << e.what() << std::endl;
//     }
// }

// void test_expression_with_numbers() {
//     try {
//         RPN calculator("1 200 + 50 *");
//         calculator.get_result();
//     } catch (const std::runtime_error& e) {
// 		assert(std::string(e.what()) == "RPN: Invalid token found: 200");
//     }
// }

// void test_single_operand() {
//     try {
//         RPN calculator("5");
//         int result = calculator.get_result();
//         assert(result == 5);
//     } catch (const std::runtime_error& e) {
//         std::cerr << "Test failed: single operand " << e.what() << std::endl;
//     }
// }

// void test_division_by_zero() {
//     try {
//         RPN calculator("7 0 /");
//         calculator.get_result();
//         std::cerr << "Test failed: division by zero did not throw exception" << std::endl;
//     } catch (const std::runtime_error& e) {
//         assert(std::string(e.what()) == "RPN: Division by zero");
//     }
// }

// void test_only_operators() {
//     try {
//         RPN calculator("+");
//         calculator.get_result();
//         std::cerr << "Test failed: only operators did not throw exception" << std::endl;
//     } catch (const std::runtime_error& e) {
//         assert(std::string(e.what()) == "RPN: Invalid expression");
//     }
// }

// void test_leading_trailing_spaces() {
//     try {
//         RPN calculator(" 2 3 + ");
//         int result = calculator.get_result();
//         assert(result == 5);  // Spaces are expected to be ignored
//     } catch (const std::runtime_error& e) {
//         std::cerr << "Test failed: leading or trailing spaces " << e.what() << std::endl;
//     }
// }

// void test_multiple_spaces_between_tokens() {
//     try {
//         RPN calculator("2    3    +");
//         int result = calculator.get_result();
//         assert(result == 5);  // Multiple spaces are expected to be ignored
//     } catch (const std::runtime_error& e) {
//         std::cerr << "Test failed: multiple spaces between tokens " << e.what() << std::endl;
//     }
// }

// void test_only_spaces() {
//     try {
//         RPN calculator("     ");
//         calculator.get_result();
//         std::cerr << "Test failed: only spaces did not throw exception" << std::endl;
//     } catch (const std::runtime_error& e) {
//         assert(std::string(e.what()) == "RPN: Invalid expression");
//     }
// }

// int main() {
//     test_empty_expression();
//     test_not_enough_operands();
//     test_too_many_operands();
//     test_invalid_expression_extra_symbols();
//     test_invalid_expression_non_digit_operand();
//     test_normal_case_1();
//     test_normal_case_2();
//     test_copy_constructor();
//     test_copy_assignment();
//     test_expression_with_numbers();
//     test_single_operand();
//     test_division_by_zero();
// 	test_only_operators();
// 	test_leading_trailing_spaces();
// 	test_multiple_spaces_between_tokens();
// 	test_only_spaces();

//     std::cout << "\033[0;32m" << "All tests passed!" << "\033[0m" << std::endl;
//     return 0;
// }

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] << " expected one argument" << std::endl;
		return (-1);
	}
	try {
		RPN calculator2(argv[1]);
		std::cout << calculator2.get_result() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}