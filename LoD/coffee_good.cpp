#include <iostream>
#include <string>

class CoffeeGrounds {
public:
    int getAmount() const { return amount; }
    void consume(int amt) { amount -= amt; }

private:
    int amount = 100; // Initial amount of coffee grounds
};

class CoffeeContainer {
public:
    bool hasEnoughGrounds(int requiredAmount) const {
        return coffeeGrounds.getAmount() >= requiredAmount;
    }

    void useGrounds(int amount) {
        coffeeGrounds.consume(amount);
    }

private:
    CoffeeGrounds coffeeGrounds;
};

class CoffeeMachine {
public:
    bool canBrew(int requiredAmount) const {
        return coffeeContainer.hasEnoughGrounds(requiredAmount);
    }

    void brew(int amount) {
        if (canBrew(amount)) {
            coffeeContainer.useGrounds(amount);
            std::cout << "Brewing coffee...\n";
        } else {
            std::cout << "Not enough coffee grounds!\n";
        }
    }

private:
    CoffeeContainer coffeeContainer;
};

class User {
public:
    void brewCoffee(CoffeeMachine& machine) {
        machine.brew(10); // The user interacts only with the CoffeeMachine
    }
};

int main() {
    CoffeeMachine myMachine;
    User user;
    user.brewCoffee(myMachine);
    return 0;
}
