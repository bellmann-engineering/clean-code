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

    // Define a new method to set the temperature in a safe range
    virtual void setTemperature(int temperature) {
        // Default implementation does nothing
        std::cout << "Setting temperature is not supported for this kitchen device.\n";
    }

    virtual ~KitchenDevice() = default;
};

class Toaster : public KitchenDevice {
private:
    int temperature;

public:
    Toaster() : temperature(0) {}

    void turnOn() override {
        std::cout << "Toaster is heating up.\n";
    }

    void turnOff() override {
        std::cout << "Toaster is cooling down.\n";
    }

    // Override the setTemperature method to set the toaster temperature
    void setTemperature(int temp) override {
        temperature = temp;
        std::cout << "Setting toaster temperature to " << temperature << " degrees.\n";
    }
};

class Refrigerator : public KitchenDevice {
private:
    int temperature;

public:
    Refrigerator() : temperature(0) {}

    void turnOn() override {
        std::cout << "Refrigerator is cooling.\n";
    }

    void turnOff() override {
        std::cout << "Refrigerator is not cooling.\n";
    }

    // Override the setTemperature method to set the refrigerator temperature
    void setTemperature(int temp) override {
        // Check if the temperature is within a safe range
        if (temp >= -20 && temp <= 10) {
            temperature = temp;
            std::cout << "Setting refrigerator temperature to " << temperature << " degrees.\n";
        } else {
            std::cout << "Temperature " << temp << " degrees is outside the safe range.\n";
        }
    }
};

int main() {
    // Using std::unique_ptr to manage memory of KitchenDevice objects
    std::unique_ptr<KitchenDevice> device1 = std::make_unique<Toaster>();
    std::unique_ptr<KitchenDevice> device2 = std::make_unique<Refrigerator>();

    // Using KitchenDevice pointers to refer to different types of kitchen devices
    device1->turnOn();  // Toaster is heating up
    device2->turnOn();  // Refrigerator is cooling

    // Using the setTemperature method on both devices
    device1->setTemperature(200);  // Setting toaster temperature
    device2->setTemperature(5);  // Setting refrigerator temperature

    // Unique pointers automatically manage memory, so no explicit delete needed
}
