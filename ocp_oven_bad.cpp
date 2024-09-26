#include <iostream>

class Oven {
public:
    enum Mode {
        OFF,
        BAKING,
        BROILING,
        TOASTING
    };

private:
    Mode currentMode;

public:
    Oven() : currentMode(OFF) {}

    void setMode(Mode mode) {
        currentMode = mode;
    }

    void start() const {
        switch (currentMode) {
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
};

void displayMenu() {
    std::cout << "Choose oven mode:\n";
    std::cout << "1 - Baking\n";
    std::cout << "2 - Broiling\n";
    std::cout << "3 - Toasting\n";
    std::cout << "0 - Turn off\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Oven oven;
    int choice;

    displayMenu();
    std::cin >> choice;

    switch (choice) {
        case 1:
            oven.setMode(Oven::BAKING);
            break;
        case 2:
            oven.setMode(Oven::BROILING);
            break;
        case 3:
            oven.setMode(Oven::TOASTING);
            break;
        case 0:
        default:
            oven.setMode(Oven::OFF);
            break;
    }

    oven.start();

    return 0;
}
