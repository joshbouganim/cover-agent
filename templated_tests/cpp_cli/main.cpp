#include "calculator.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: ./calculator <operation> <operand1> <operand2>\n";
        return EXIT_FAILURE;
    }

    double op1 = std::stod(argv[2]);
    double op2 = std::stod(argv[3]);
    std::string operation(argv[1]);

    try {
        double result = calculate(op1, op2, operation);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
