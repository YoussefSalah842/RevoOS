#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

// Declare a Settings class or configuration variables
class Settings {
public:
    static void loadSettings();    // Load settings from a file or default settings
    static void saveSettings();    // Save current settings to a file
    static void displaySettings(); // Display current settings

    // Add any other necessary settings like screen resolution, theme, etc.
    static std::string theme;
    static bool darkMode;
};

#endif // SETTINGS_H

