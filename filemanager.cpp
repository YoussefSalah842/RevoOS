#include <iostream>
#include <fstream>
#include <string>
#include "filemanager.h"

void fileManager() {
    std::cout << "\n===================================================\n";
    std::cout << "                  File Manager                     \n";
    std::cout << "===================================================\n";

    std::cout << "1. Create a new file\n";
    std::cout << "2. Read from an existing file\n";
    std::cout << "3. Delete a file\n";
    std::cout << "Enter your choice (1-3): ";

    int choice;
    std::cin >> choice;

    std::string filename;
    switch (choice) {
        case 1:
            std::cout << "Enter the filename to create: ";
            std::cin >> filename;

            // Use c_str() to convert std::string to const char*
            {
                std::ofstream file(filename.c_str());
                if (file.is_open()) {
                    std::cout << "File created successfully. You can now write to the file. Type 'exit' to stop.\n";

                    std::string line;
                    std::cin.ignore(); // Clear input buffer
                    while (true) {
                        std::getline(std::cin, line);
                        if (line == "exit")
                            break;
                        file << line << "\n";
                    }

                    file.close();
                    std::cout << "File saved successfully.\n";
                } else {
                    std::cerr << "Error: Unable to create the file.\n";
                }
            }
            break;

        case 2:
            std::cout << "Enter the filename to read: ";
            std::cin >> filename;

            // Use c_str() to convert std::string to const char*
            {
                std::ifstream file(filename.c_str());
                if (file.is_open()) {
                    std::cout << "Contents of the file:\n";
                    std::string line;
                    while (std::getline(file, line)) {
                        std::cout << line << "\n";
                    }

                    file.close();
                } else {
                    std::cerr << "Error: Unable to open the file for reading.\n";
                }
            }
            break;

        case 3:
            std::cout << "Enter the filename to delete: ";
            std::cin >> filename;

            // Use c_str() for compatibility with remove
            if (remove(filename.c_str()) == 0) {
                std::cout << "File deleted successfully.\n";
            } else {
                std::cerr << "Error: Unable to delete the file.\n";
            }
            break;

        default:
            std::cerr << "Invalid choice. Please select 1, 2, or 3.\n";
    }

    std::cout << "Press Enter to return to the menu...\n";
    std::cin.ignore(); // Clear input buffer
    std::cin.get();
}

