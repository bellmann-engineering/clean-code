#include <iostream>
#include <vector>

class BankingSystem {
private:
    std::vector<double> accountBalances_;

public:
    void Deposit(double amount) {
        accountBalances_.push_back(amount);
    }

    void Withdraw(double amount) {
        accountBalances_.push_back(-amount);
    }

    void ShowTotalBalance() const {
        double totalBalance = 0;
        for (double balance : accountBalances_) {
            totalBalance += balance;
        }
        std::cout << "Total balance across all accounts: " << totalBalance << std::endl;
    }
};

int main() {
    BankingSystem bankingSystem;

    // Account transactions
    bankingSystem.Deposit(1000); // Deposit 1000 €
    bankingSystem.Deposit(500);  // Deposit 500 €
    bankingSystem.Withdraw(200); // Withdraw 200 €

    // Display total balance
    bankingSystem.ShowTotalBalance();

    return 0;
}
