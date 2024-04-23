#include <iostream>

int mode = 0;

void startOven(int m) {
    if (m == 1) {
        std::cout << "Baking mode started.\n";
    } else if (m == 2) {
        std::cout << "Broiling mode started.\n";
    } else if (m == 3) {
        std::cout << "Toasting mode started.\n";
    } else {
        std::cout << "Off mode started.\n";
    }
}

int main() {
    std::cout << "Choose oven mode (1 for baking, 2 for broiling, 3 for toasting, 0 to turn off): ";
    std::cin >> mode;
    startOven(mode);
    return 0;
}
