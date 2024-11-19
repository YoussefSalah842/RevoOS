#include <iostream>
#include <string>
#include <vector>
#include "notepad.h"

std::vector<std::string> notes;

void notepad() {
    int choice;
    do {
        std::cout << "\n--- Notepad ---\n";
        std::cout << "1. Write a new note\n";
        std::cout << "2. View all notes\n";
        std::cout << "0. Return to main menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1: {
                std::cout << "Enter your note: ";
                std::string note;
                std::getline(std::cin, note);
                notes.push_back(note);
                std::cout << "Note saved!\n";
                break;
            }
            case 2:
                std::cout << "\n--- Notes ---\n";
                if (notes.empty()) {
                    std::cout << "No notes available.\n";
                } else {
                    for (size_t i = 0; i < notes.size(); ++i) {
                        std::cout << i + 1 << ". " << notes[i] << "\n";
                    }
                }
                break;
            case 0:
                std::cout << "Returning to main menu...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

