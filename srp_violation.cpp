#include <iostream>
#include <string>

class Microwave {
private:
    int powerLevel;
    int cookingTime;
    std::string homeConnectApiKey;

public:
    Microwave()
        : powerLevel(0), cookingTime(0), homeConnectApiKey("") {}

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

    // Connect to HomeConnect and update status
    void connectToHomeConnect(const std::string& apiKey) {
        homeConnectApiKey = apiKey;
        std::cout << "Connecting to HomeConnect with API key: " << apiKey << "\n";
        // Simulate API call to update the microwave status
        std::cout << "Microwave status updated on HomeConnect.\n";
    }

    // Display the microwave status
    void displayStatus() {
        std::cout << "Microwave power level: " << powerLevel << "\n";
        std::cout << "Microwave cooking time: " << cookingTime << "\n";
        std::cout << "Connected to HomeConnect: " << (homeConnectApiKey.empty() ? "No" : "Yes") << "\n";
    }
};

int main() {
    Microwave microwave;

    // Set cooking parameters and start cooking
    microwave.setCookingParameters(5, 120);
    microwave.startCooking();

    // Connect to HomeConnect and update status
    std::string apiKey = "myHomeConnectApiKey";
    microwave.connectToHomeConnect(apiKey);

    // Display the microwave status
    microwave.displayStatus();

    return 0;
}
