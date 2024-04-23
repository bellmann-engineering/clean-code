#include <iostream>

class Alarm {
public:
    void trigger() {
        std::cout << "Alarm triggered: The door is open!\n";
    }
};

class Fridge {
private:
    bool doorOpen;
    Alarm alarm;

public:
    Fridge() : doorOpen(false) {}

    void openDoor() {
        doorOpen = true;
        std::cout << "Fridge door opened.\n";
        checkDoorStatus();
    }

    void closeDoor() {
        doorOpen = false;
        std::cout << "Fridge door closed.\n";
    }

    void checkDoorStatus() {
        if (doorOpen) {
            alarm.trigger();  // Direct dependency on Alarm class
        }
    }
};

int main() {
    Fridge fridge;

    fridge.openDoor();  // This will trigger the alarm
    fridge.closeDoor();  // Fridge door closed
}
