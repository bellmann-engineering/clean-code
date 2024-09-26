#include <iostream>
#include <memory>
#include <string>

class KitchenDevice {
public:
    virtual void turnOn() {
        std::cout << "Kitchen device is turned on.\n";
    }

    virtual void turnOff() {
        std::cout << "Kitchen device is turned off.\n";
    }

    virtual ~KitchenDevice() = default;
};

class PowerAdjustableDevice : public KitchenDevice {
public:
    virtual void setPowerMode(const std::string& mode) = 0;
};

class Toaster : public PowerAdjustableDevice {
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

    void setTemperature(int temperature) {
        std::cout << "Setting refrigerator temperature to " << temperature << " degrees.\n";
    }
};

int main() {
    // Using smart pointers for better memory management
    std::unique_ptr<PowerAdjustableDevice> toaster = std::make_unique<Toaster>();
    std::unique_ptr<Refrigerator> fridge = std::make_unique<Refrigerator>();

    toaster->turnOn();
    toaster->setPowerMode("high");

    fridge->turnOn();
    fridge->setTemperature(4);

    return 0;
}
