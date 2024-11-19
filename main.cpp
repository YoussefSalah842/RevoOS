#include <iostream>
#include "calculator.h"
#include "notepad.h"

void displayMenu() {
    std::cout << "\n--- RevoOS Menu ---\n";
    std::cout << "1. Calculator\n";
    std::cout << "2. Notepad\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                calculator();
                break;
            case 2:
                notepad();
                break;
            case 0:
                std::cout << "Exiting RevoOS. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

