#include <iostream>
#include "calculator.h"

void calculator() {
    double num1, num2;
    char op;
    std::cout << "\n--- Calculator ---\n";
    std::cout << "Enter an expression (e.g., 5 + 3): ";
    std::cin >> num1 >> op >> num2;

    switch (op) {
        case '+':
            std::cout << "Result: " << num1 + num2 << "\n";
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << "\n";
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << "\n";
            break;
        case '/':
            if (num2 != 0)
                std::cout << "Result: " << num1 / num2 << "\n";
            else
                std::cout << "Error: Division by zero is not allowed.\n";
            break;
        default:
            std::cout << "Invalid operator. Use +, -, *, or /.\n";
    }
}

