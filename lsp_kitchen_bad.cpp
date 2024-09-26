#include <iostream>
#include <string>

class KitchenDevice {
public:
    virtual void turnOn() {
        std::cout << "Kitchen device is turned on.\n";
    }

    virtual void turnOff() {
        std::cout << "Kitchen device is turned off.\n";
    }

    virtual void setPowerMode(const std::string& mode) {
        std::cout << "Setting power mode to " << mode << ".\n";
    }

    virtual ~KitchenDevice() = default;
};

class Toaster : public KitchenDevice {
public:
    void turnOn() override {
        std::cout << "Toaster is heating up.\n";
    }

    void turnOff() override {
        std::cout << "Toaster is cooling down.\n";
    }

    void setPowerMode(const std::string& mode) override {
        if (mode == "low" || mode == "medium" || mode == "high") {
            std::cout << "Toaster set to " << mode << " power mode.\n";
        } else {
            std::cout << "Invalid mode for toaster. Defaulting to medium.\n";
        }
    }
};

class Refrigerator : public KitchenDevice {
public:
    void turnOn() override {
        std::cout << "Refrigerator is cooling.\n";
    }

    void turnOff() override {
        std::cout << "Refrigerator is not cooling.\n";
    }

    // Violating LSP: Refrigerator overrides setPowerMode() with unexpected behavior
    void setPowerMode(const std::string& mode) override {
        if (mode == "low") {
            std::cout << "Refrigerator set to energy-saving mode.\n";
        } else if (mode == "medium") {
            std::cout << "Refrigerator set to normal mode.\n";
        } else if (mode == "high") {
            std::cout << "Error: High power mode triggers defrost and stops cooling!\n";
            turnOff();  // Unexpected behavior: turns off the refrigerator
        } else {
            std::cout << "Invalid mode for refrigerator. Remaining in current mode.\n";
        }
    }
};

int main() {
    KitchenDevice* device1 = new Toaster();
    KitchenDevice* device2 = new Refrigerator();

    // Using KitchenDevice pointers to refer to different types of kitchen devices
    device1->turnOn();  // Toaster is heating up
    device2->turnOn();  // Refrigerator is cooling

    // LSP violation: Setting high power mode on Refrigerator unexpectedly turns it off
    device1->setPowerMode("high");  // Toaster set to high power mode
    device2->setPowerMode("high");  // Refrigerator turns off unexpectedly

    delete device1;
    delete device2;

    return 0;
}
