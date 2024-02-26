#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Order class representing an order in an e-commerce system
class Order {
private:
    int orderId;
    vector<string> products;
    string customerName;
    string address;
    double totalAmount;

public:
    Order(int orderId, const vector<string>& products, const string& customerName, const string& address, double totalAmount)
        : orderId(orderId), products(products), customerName(customerName), address(address), totalAmount(totalAmount) {}

    void saveOrder() {
        ofstream file("orders.txt", ios::app);
        if (file.is_open()) {
            file << orderId << "," << customerName << "," << address << "," << totalAmount << "\n";
            file.close();
        } else {
            cout << "Unable to open file";
        }
    }

    void printInvoice() {
        cout << "Invoice for Order #" << orderId << ":\n";
        cout << "Customer: " << customerName << "\n";
        cout << "Address: " << address << "\n";
        cout << "Products:\n";
        for (const auto& product : products) {
            cout << "- " << product << "\n";
        }
        cout << "Total Amount: $" << totalAmount << "\n";
    }
};

int main() {
    vector<string> products = {"Laptop", "Mouse", "Keyboard"};
    Order order1(1001, products, "John Doe", "123 Main St", 2500.0);
    order1.saveOrder();
    order1.printInvoice();
    return 0;
}
