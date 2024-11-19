#include <iostream>
#include "calculator.h"

void calculator() {
    std::cout << "\n===================================================\n";
    std::cout << "                    Calculator                     \n";
    std::cout << "===================================================\n";

    double num1, num2;
    char operation;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> operation;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    switch (operation) {
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
                std::cerr << "Error: Division by zero is not allowed.\n";
            break;
        default:
            std::cerr << "Error: Invalid operator.\n";
    }

    std::cout << "Press Enter to return to the menu...\n";
    std::cin.ignore();
    std::cin.get();
}

