#include <iostream>
#include <string>

class Fridge {
public:
    Fridge(int temp) : temperature(temp) {}

    void adjustTemperature(int idealTemp) {
        if (temperature > idealTemp) {
            temperature = idealTemp;
            std::cout << "Fridge temperature adjusted to " << temperature << " degrees.\n";
        } else {
            std::cout << "Fridge temperature is already optimal.\n";
        }
    }

private:
    int temperature;
};

class User {
public:
    void adjustFridgeTemperature(Fridge& fridge) {
        fridge.adjustTemperature(5); // Tell the fridge to adjust itself
    }
};

int main() {
    Fridge myFridge(10);
    User user;
    user.adjustFridgeTemperature(myFridge);
    return 0;
}
