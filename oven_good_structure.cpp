#include <iostream>

enum OvenMode {
    OFF = 0,
    BAKING = 1,
    BROILING = 2,
    TOASTING = 3
};

void startOven(OvenMode mode) {
    switch (mode) {
        case BAKING:
            std::cout << "Baking mode started.\n";
            break;
        case BROILING:
            std::cout << "Broiling mode started.\n";
            break;
        case TOASTING:
            std::cout << "Toasting mode started.\n";
            break;
        case OFF:
        default:
            std::cout << "Oven is turned off.\n";
            break;
    }
}

void displayMenu() {
    std::cout << "Choose oven mode:\n";
    std::cout << "1 - Baking\n";
    std::cout << "2 - Broiling\n";
    std::cout << "3 - Toasting\n";
    std::cout << "0 - Turn off\n";
    std::cout << "Enter your choice: ";
}

int main() {
    OvenMode selectedMode = OFF;
    
    displayMenu();
    int choice;
    std::cin >> choice;
    
    // Validate user input
    if (choice >= OFF && choice <= TOASTING) {
        selectedMode = static_cast<OvenMode>(choice);
    } else {
        std::cout << "Invalid choice. Please enter a valid option (0-3).\n";
        return 1; // Return an error code
    }
    
    startOven(selectedMode);
    return 0;
}
