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

    void saveOrder(const string& filename) const {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << orderId << "," << customerName << "," << address << "," << totalAmount << "\n";
            file.close();
        } else {
            cout << "Unable to open file";
        }
    }
};

// OrderPrinter class to handle printing of order invoices
class OrderPrinter {
public:
    static void printInvoice(const Order& order) {
        cout << "Invoice for Order #" << order.getOrderId() << ":\n";
        cout << "Customer: " << order.getCustomerName() << "\n";
        cout << "Address: " << order.getAddress() << "\n";
        cout << "Products:\n";
        for (const auto& product : order.getProducts()) {
            cout << "- " << product << "\n";
        }
        cout << "Total Amount: $" << order.getTotalAmount() << "\n";
    }
};

int main() {
    vector<string> products = {"Laptop", "Mouse", "Keyboard"};
    Order order1(1001, products, "John Doe", "123 Main St", 2500.0);
    order1.saveOrder("orders.txt");
    OrderPrinter::printInvoice(order1);
    return 0;
}
