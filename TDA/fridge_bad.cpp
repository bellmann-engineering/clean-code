#include <iostream>
#include <string>

class Fridge {
public:
    Fridge(int temp) : temperature(temp) {}

    int getTemperature() const {
        return temperature;
    }

    void setTemperature(int newTemp) {
        temperature = newTemp;
    }

private:
    int temperature;
};

class User {
public:
    void adjustFridgeTemperature(Fridge& fridge) {
        int currentTemp = fridge.getTemperature(); // Asking for data
        if (currentTemp > 5) {
            fridge.setTemperature(5); // Acting on it externally
            std::cout << "Fridge temperature adjusted to 5 degrees.\n";
        }
    }
};

int main() {
    Fridge myFridge(10);
    User user;
    user.adjustFridgeTemperature(myFridge);
    return 0;
}
