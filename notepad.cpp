#include <iostream>
#include <fstream>
#include <string>
#include "notepad.h"

void notepad() {
    std::cout << "\n===================================================\n";
    std::cout << "                     Notepad                       \n";
    std::cout << "===================================================\n";

    std::string filename;
    std::cout << "Enter filename to open or create: ";
    std::cin >> filename;

    // Use c_str() to convert the string to a C-style string (const char*)
    std::ofstream file(filename.c_str(), std::ios::app);
    if (file.is_open()) {
        std::cout << "You can now write to the file. Type 'exit' to stop.\n";

        std::string line;
        std::cin.ignore(); // Clear the input buffer
        while (true) {
            std::getline(std::cin, line);
            if (line == "exit")
                break;
            file << line << "\n";
        }

        file.close();
        std::cout << "File saved successfully.\n";
    } else {
        std::cerr << "Error: Unable to open the file.\n";
    }

    std::cout << "Press Enter to return to the menu...\n";
    std::cin.get();
}

