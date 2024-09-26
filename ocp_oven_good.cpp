#include <iostream>
#include <memory>
#include <map>
#include <functional>

class OvenMode {
public:
    virtual void start() const = 0;  // pure virtual function
    virtual ~OvenMode() = default;   // virtual destructor
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
    std::unique_ptr<OvenMode> mode;

public:
    void setMode(std::unique_ptr<OvenMode> newMode) {
        mode = std::move(newMode);
    }

    void start() const {
        if (mode) {
            mode->start();
        } else {
            std::cout << "Oven is turned off.\n";
        }
    }
};

class OvenModeFactory {
private:
    std::map<int, std::function<std::unique_ptr<OvenMode>()>> modeMap;

public:
    OvenModeFactory() {
        modeMap[1] = []() { return std::make_unique<BakingMode>(); };
        modeMap[2] = []() { return std::make_unique<BroilingMode>(); };
        modeMap[3] = []() { return std::make_unique<ToastingMode>(); };
        modeMap[0] = []() { return nullptr; };  // nullptr represents "Oven is off"
    }

    std::unique_ptr<OvenMode> createMode(int choice) const {
        auto it = modeMap.find(choice);
        if (it != modeMap.end()) {
            return it->second();
        }
        return nullptr;
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
    OvenModeFactory factory;
    int choice;

    displayMenu();
    std::cin >> choice;

    oven.setMode(factory.createMode(choice));
    oven.start();

    return 0;
}
