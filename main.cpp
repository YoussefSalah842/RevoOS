#include <iostream>
#include <iomanip> // For text alignment
#include <string>  // For decorative strings
using namespace std;

// Function prototypes
void notepad();
void calculator();

void printHeader(const string& title) {
    cout << "\n=====================================\n";
    cout << setw(20) << right << title << "\n";
    cout << "=====================================\n";
}

void printMenu() {
    printHeader("RevoOS Alpha Test 1.0 Menu");
    cout << "| 1 | Open Notepad                 |\n";
    cout << "| 2 | Open Calculator              |\n";
    cout << "| 3 | Exit                         |\n";
    cout << "=====================================\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;

    do {
        system("cls"); // Clear the screen for a fresh look (Windows-only)
        printMenu();

        cin >> choice;

        switch (choice) {
            case 1:
                notepad();
                break;
            case 2:
                calculator();
                break;
            case 3:
                cout << "Thank you for using Simple OS. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        if (choice != 3) {
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
        }
    } while (choice != 3);

    return 0;
}

