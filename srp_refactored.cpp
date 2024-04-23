#include <iostream>
#include <string>

class Microwave {
private:
    int powerLevel;
    int cookingTime;

public:
    Microwave()
        : powerLevel(0), cookingTime(0) {}

    // Set cooking parameters
    void setCookingParameters(int level, int time) {
        powerLevel = level;
        cookingTime = time;
    }

    // Start cooking
    void startCooking() {
        std::cout << "Cooking started at power level " << powerLevel
                  << " for " << cookingTime << " seconds.\n";
        // Simulate cooking process
    }

    // Get microwave status as a string
    std::string getStatus() const {
        return "Microwave power level: " + std::to_string(powerLevel) +
               ", cooking time: " + std::to_string(cookingTime);
    }
};

class HomeConnect {
private:
    std::string apiKey;

public:
    // Connect to HomeConnect with the provided API key
    void connect(const std::string& key) {
        apiKey = key;
        std::cout << "Connecting to HomeConnect with API key: " << key << "\n";
        // Simulate API call to update the microwave status
    }

    // Update the microwave status on HomeConnect
    void updateMicrowaveStatus(const std::string& status) {
        std::cout << "Updating microwave status on HomeConnect: " << status << "\n";
    }

    // Check if connected to HomeConnect
    bool isConnected() const {
        return !apiKey.empty();
    }
};

class MicrowaveController {
private:
    Microwave microwave;
    HomeConnect homeConnect;

public:
    // Constructor initializes the microwave and home connect
    MicrowaveController()
        : microwave(), homeConnect() {}

    // Set cooking parameters
    void setCookingParameters(int level, int time) {
        microwave.setCookingParameters(level, time);
    }

    // Start cooking
    void startCooking() {
        microwave.startCooking();
    }

    // Connect to HomeConnect with the provided API key
    void connectToHomeConnect(const std::string& apiKey) {
        homeConnect.connect(apiKey);
    }

    // Update microwave status on HomeConnect if connected
    void updateMicrowaveStatus() {
        if (homeConnect.isConnected()) {
            homeConnect.updateMicrowaveStatus(microwave.getStatus());
        } else {
            std::cout << "Not connected to HomeConnect.\n";
        }
    }

    // Display the microwave status
    void displayStatus() {
        std::cout << microwave.getStatus() << "\n";
        std::cout << "Connected to HomeConnect: " << (homeConnect.isConnected() ? "Yes" : "No") << "\n";
    }
};

int main() {
    MicrowaveController controller;

    // Set cooking parameters and start cooking
    controller.setCookingParameters(5, 120);
    controller.startCooking();

    // Connect to HomeConnect and update status
    std::string apiKey = "myHomeConnectApiKey";
    controller.connectToHomeConnect(apiKey);
    controller.updateMicrowaveStatus();

    // Display the microwave status
    controller.displayStatus();

    return 0;
}
