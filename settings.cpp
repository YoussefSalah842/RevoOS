#include "settings.h"
#include <iostream>
#include <fstream>

std::string Settings::theme = "Light";   // Default theme
bool Settings::darkMode = false;         // Default dark mode setting

// Function to load settings (from a file or default values)
void Settings::loadSettings() {
    std::ifstream settingsFile("settings.txt");
    if (settingsFile.is_open()) {
        std::getline(settingsFile, theme);
        settingsFile >> darkMode;
        settingsFile.close();
        std::cout << "Settings loaded successfully!" << std::endl;
    } else {
        std::cout << "No settings file found. Using default settings." << std::endl;
    }
}

// Function to save current settings to a file
void Settings::saveSettings() {
    std::ofstream settingsFile("settings.txt");
    if (settingsFile.is_open()) {
        settingsFile << theme << std::endl;
        settingsFile << darkMode << std::endl;
        settingsFile.close();
        std::cout << "Settings saved successfully!" << std::endl;
    } else {
        std::cout << "Unable to save settings." << std::endl;
    }
}

// Function to display current settings
void Settings::displaySettings() {
    std::cout << "Current Settings:" << std::endl;
    std::cout << "Theme: " << theme << std::endl;
    std::cout << "Dark Mode: " << (darkMode ? "Enabled" : "Disabled") << std::endl;
}

