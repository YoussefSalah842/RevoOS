#include <iostream>
#include <fstream>
#include <string>

void notepad() {
    std::string filename, content, line;

    std::cout << "Notepad: Enter filename to create/edit: ";
    std::cin >> filename;

    
    std::ofstream file(filename.c_str(), std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file.\n";
        return;
    }

    std::cin.ignore(); 
    std::cout << "Type your text (type 'EXIT' on a new line to quit):\n";

    while (true) {
        std::getline(std::cin, line);
        if (line == "EXIT") break;
        file << line << '\n';
    }

    file.close();
    std::cout << "File saved successfully.\n";
}

