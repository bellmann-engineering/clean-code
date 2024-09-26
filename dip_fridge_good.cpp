#include <iostream>

class IAlarm {
public:
    virtual void trigger() = 0;
    virtual ~IAlarm() = default;
};

class Alarm : public IAlarm {
public:
    void trigger() override {
        std::cout << "Alarm triggered: The door is open!\n";
    }
};

class Fridge {
private:
    bool doorOpen;
    IAlarm& alarm;

public:
    // Constructor takes a reference to an IAlarm instance
    Fridge(IAlarm& alarmSystem) : doorOpen(false), alarm(alarmSystem) {}

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
            alarm.trigger();  // Uses the alarm interface
        }
    }
};

int main() {
    Alarm alarm;  // Create an instance of the Alarm class
    Fridge fridge(alarm);  // Pass the alarm instance to the fridge

    fridge.openDoor();  // This will trigger the alarm
    fridge.closeDoor();  // Fridge door closed
}
