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

    void setTemperature(int temperature) {
        std::cout << "Setting toaster temperature to " << temperature << " degrees.\n";
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
    
    // Violating LSP: Refrigerator turns off when a low temperature is set
    void setTemperatureToLow() {
        std::cout << "Setting temperature to very low. Refrigerator is turning off to prevent freezing.\n";
        turnOff();
    }
};

int main() {
    KitchenDevice* device1 = new Toaster();
    KitchenDevice* device2 = new Refrigerator();

    // Using KitchenDevice pointers to refer to different types of kitchen devices
    device1->turnOn();  // Toaster is heating up
    device2->turnOn();  // Refrigerator is cooling

    // LSP violation: setting temperature on Refrigerator can turn it off unexpectedly
    Refrigerator* fridge = dynamic_cast<Refrigerator*>(device2);
    if (fridge) {
        fridge->setTemperatureToLow();  // Refrigerator turns off
    }

    // Clean up
    delete device
