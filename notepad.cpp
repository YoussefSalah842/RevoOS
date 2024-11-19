#include <iostream>
#include <fstream>
#include <string>
#include <limits>  // For numeric limits (to clear input buffer)
using namespace std;

void notepad() {
    string text;
    string filename = "notepad.txt";
    int option;

    do {
        system("cls"); // Clear screen for a fresh interface
        cout << "====================\n";
        cout << "     Notepad        \n";
        cout << "====================\n";
        cout << "1. Write to file\n";
        cout << "2. Read from file\n";
        cout << "3. Clear Text\n";
        cout << "4. Return to menu\n";
        cout << "====================\n";
        cout << "Enter your option: ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        switch (option) {
            case 1:
                cout << "Enter text (press Enter twice to save):\n";
                getline(cin, text);
                {
                    ofstream file(filename.c_str());  // Use c_str() to pass the file name
                    file << text;
                    file.close();
                    cout << "Text saved to file!\n";
                }
                break;
            case 2:
                {
                    ifstream file(filename.c_str());  // Use c_str() to pass the file name
                    if (file.is_open()) {
                        cout << "Contents of notepad.txt:\n";
                        string line;
                        while (getline(file, line)) {
                            cout << line << endl;
                        }
                        file.close();
                    } else {
                        cout << "Error: File not found!\n";
                    }
                }
                break;
            case 3:
                text.clear();  // Clear the text buffer
                cout << "Text cleared.\n";
                break;
            case 4:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid option, try again.\n";
        }

        if (option != 4) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    } while (option != 4);
}
