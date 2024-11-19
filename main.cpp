#include <iostream>
#include <iomanip> // For better alignment and styling
#include "calculator.h"
#include "notepad.h"
#include "settings.h"  // Include settings header
#include "filemanager.h"  // Include file manager header

// Function to display the welcome banner
void displayBanner() {
    std::cout << "=== Welcome to RevoOS ===\n";
    std::cout << "===================================================\n";
    std::cout << "1. Calculator \n";
    std::cout << "2. Notepad\n";
    std::cout << "3. File Manager\n";  // Add file manager option
    std::cout << "4. Settings\n";  // Add settings option
    std::cout << "5. About RevoOS\n";
    std::cout << "0. Exit \n";
    std::cout << "---------------------------------------\n";
    std::cout << "Enter your choice: ";
}

// Function to display the About section
void displayAbout() {
    std::cout << "\n===================================================\n";
    std::cout << "About RevoOS \n";
    std::cout << "===================================================\n";
    std::cout << "RevoOS is a lightweight command-line\n";
    std::cout << "interface program designed for quick\n";
    std::cout << "access to essential tools like \n";
    std::cout << "Calculator and Notepad. \n";
    std::cout << "---------------------------------------\n";
    std::cout << "Developed by: Youssef \n";
    std::cout << "Version: 1.0 \n";
    std::cout << "---------------------------------------\n";
    std::cout << "Press Enter to return to the menu...\n";
    std::cin.ignore(); // Wait for user input
    std::cin.get();
}

// Function to display and modify settings
void settingsMenu() {
    int settingsChoice;
    do {
        std::cout << "\n===== Settings =====\n";
        std::cout << "1. Display Current Settings\n";
        std::cout << "2. Change Theme (Current: " << Settings::theme << ")\n"; // Show current theme
        std::cout << "3. Toggle Dark Mode (Current: " << (Settings::darkMode ? "Enabled" : "Disabled") << ")\n"; // Show current dark mode state
        std::cout << "0. Return to Main Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> settingsChoice;

        switch (settingsChoice) {
            case 1:
                Settings::displaySettings();
                break;
            case 2:
                std::cout << "Enter new theme (Light/Dark): ";
                std::cin >> Settings::theme;
                std::cout << "Theme changed to " << Settings::theme << "!\n";
                break;
            case 3:
                Settings::darkMode = !Settings::darkMode;
                std::cout << "Dark Mode " << (Settings::darkMode ? "Enabled" : "Disabled") << "!\n";
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (settingsChoice != 0);
}

int main() {
    int choice;

    // Load settings at the start
    Settings::loadSettings();

    // Display the banner once at startup
    displayBanner();

    do {
        std::cin >> choice;

        switch (choice) {
            case 1:
                calculator();
                break;
            case 2:
                notepad();
                break;
            case 3:
                fileManager();  // Open file manager
                break;
            case 4:
                settingsMenu();  // Open settings menu
                break;
            case 5:
                displayAbout();
                break;
            case 0:
                std::cout << "\nThank you for using RevoOS. Goodbye!\n";
                break;
            default:
                std::cout << "\nInvalid choice. Please enter a number between 0 and 5.\n";
        }
    } while (choice != 0);

    // Save settings before exiting
    Settings::saveSettings();

    return 0;
}

