#include <iostream>
#include <string>

class MicrowaveHomeConnect {
public:
    virtual void connect(const std::string& apiKey) = 0;
    virtual void updateMicrowaveStatus(const std::string& status) = 0;
    virtual ~MicrowaveHomeConnect() = default;
};

class OvenHomeConnect {
public:
    virtual void connect(const std::string& apiKey) = 0;
    virtual void updateOvenStatus(const std::string& status) = 0;
    virtual ~OvenHomeConnect() = default;
};

class HomeAutomation {
public:
    virtual void turnOnHomeLights() = 0;
    virtual void turnOffHomeLights() = 0;
    virtual ~HomeAutomation() = default;
};

class HomeConnect : public MicrowaveHomeConnect, public OvenHomeConnect, public HomeAutomation {
private:
    std::string apiKey;

public:
    void connect(const std::string& key) override {
        apiKey = key;
        std::cout << "Connecting to HomeConnect with API key: " << key << "\n";
        // Simulate connection process
    }

    void updateMicrowaveStatus(const std::string& status) override {
        std::cout << "Updating microwave status on HomeConnect: " << status << "\n";
    }

    void updateOvenStatus(const std::string& status) override {
        std::cout << "Updating oven status on HomeConnect: " << status << "\n";
    }

    void turnOnHomeLights() override {
        std::cout << "Turning on home lights via HomeConnect.\n";
    }

    void turnOffHomeLights() override {
        std::cout << "Turning off home lights via HomeConnect.\n";
    }
};
