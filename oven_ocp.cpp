#include <iostream>
#include <memory>

class OvenMode {
public:
    virtual void start() const {
        std::cout << "Oven is turned off.\n";
    }
};

class BakingMode : public OvenMode {
public:
    void start() const override {
        std::cout << "Baking mode started.\n";
    }
};

class BroilingMode : public OvenMode {
public:
    void start() const override {
        std::cout << "Broiling mode started.\n";
    }
};

class ToastingMode : public OvenMode {
public:
    void start() const override {
        std::cout << "Toasting mode started.\n";
    }
};

class Oven {
private:
    std::unique_ptr<OvenMode> mode; // Use unique_ptr to manage memory

public:
    Oven() : mode(std::make_unique<OvenMode>()) {}

    void setMode(std::unique_ptr<OvenMode> newMode) {
        mode = std::move(newMode);
    }

    void start() const {
        mode->start();
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
            oven.setMode(std::make_unique<BakingMode>());
            break;
        case 2:
            oven.setMode(std::make_unique<BroilingMode>());
            break;
        case 3:
            oven.setMode(std::make_unique<ToastingMode>());
            break;
        case 0:
        default:
            oven.setMode(std::make_unique<OvenMode>());
    }
}
