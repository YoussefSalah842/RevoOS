#include <iostream>
using namespace std;


void notepad();
void calculator();

int main() {
    int choice;

    do {
        cout << "\n=== Revo Simple OS Menu ===\n";
        cout << "1. Notepad\n";
        cout << "2. Calculator\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                notepad();
                break;
            case 2:
                calculator();
                break;
            case 3:
                cout << "Exiting... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

