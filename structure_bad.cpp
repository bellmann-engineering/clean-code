#include <iostream>
#include <vector>

class BankSystem {
private:
    std::vector<double> accountBalances_;

public:
    void transaction(double amount) {
        accountBalances_.push_back(amount);
    }

    void showBalance() {
        double totalBalance = 0;
        for (double balance : accountBalances_) {
            totalBalance += balance;
        }
        std::cout << "Total balance across all accounts: " << totalBalance << std::endl;
    }
};

int main() {
    BankSystem bs;

    // Account transactions
    bs.transaction(1000); // Deposit 1000 €
    bs.transaction(500);  // Deposit 500 €
    bs.transaction(-200); // Withdraw 200 €

    // Display total balance
    bs.showBalance();

    return 0;
}
