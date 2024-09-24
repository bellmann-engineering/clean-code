#include <iostream>
#include <string>

class CoffeeGrounds {
public:
    int getAmount() const { return amount; }
    void setAmount(int amt) { amount = amt; }

private:
    int amount = 100; // Initial amount of coffee grounds
};

class CoffeeContainer {
public:
    CoffeeGrounds& getCoffeeGrounds() { return coffeeGrounds; }

private:
    CoffeeGrounds coffeeGrounds;
};

class CoffeeMachine {
public:
    CoffeeContainer& getCoffeeContainer() { return coffeeContainer; }

private:
    CoffeeContainer coffeeContainer;
};

class User {
public:
    void brewCoffee(CoffeeMachine& machine) {
        // Violating the Law of Demeter: User navigates multiple objects to access the coffee grounds
        CoffeeGrounds& grounds = machine.getCoffeeContainer().getCoffeeGrounds();
        if (grounds.getAmount() > 10) {
            grounds.setAmount(grounds.getAmount() - 10);
            std::cout << "Brewing coffee...\n";
        } else {
            std::cout << "Not enough coffee grounds!\n";
        }
    }
};

int main() {
    CoffeeMachine myMachine;
    User user;
    user.brewCoffee(myMachine);
    return 0;
}
