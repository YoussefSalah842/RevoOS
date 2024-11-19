#include <iostream>
#include <limits> // For numeric limits (to clear input buffer)
using namespace std;

void calculator() {
    double num1, num2;
    char op;
    char continueCalc;
    
    do {
        system("cls"); // Clear the screen for a fresh interface
        cout << "====================\n";
        cout << "     Calculator     \n";
        cout << "====================\n";
        
        // Input for the first number
        cout << "Enter first number: ";
        while (!(cin >> num1)) {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input! Please enter a valid number: ";
        }

        // Input for the operator
        cout << "Enter operator (+, -, *, /): ";
        cin >> op;

        // Input for the second number
        cout << "Enter second number: ";
        while (!(cin >> num2)) {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input! Please enter a valid number: ";
        }

        // Perform calculation
        switch (op) {
            case '+':
                cout << "Result: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Result: " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Result: " << num1 * num2 << endl;
                break;
            case '/':
                if (num2 != 0)
                    cout << "Result: " << num1 / num2 << endl;
                else
                    cout << "Error: Division by zero!\n";
                break;
            default:
                cout << "Invalid operator!\n";
        }

        // Ask if the user wants to continue
        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> continueCalc;
    } while (continueCalc == 'y' || continueCalc == 'Y');

    cout << "Returning to main menu...\n";
}
