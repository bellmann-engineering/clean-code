#include <stdexcept>

class MathLegacy {
public:
    static int calculate(int a, int b, std::string operation) {
        if (operation == "add") {
            return a + b;
        } else if (operation == "subtract") {
            return a - b;
        } else if (operation == "multiply") {
            return a * b;
        } else if (operation == "divide") {
            return a / b;
        } else if (operation == "factorial") {
            if (a < 0) {
                throw std::invalid_argument("Factorial is not defined for negative numbers.");
            }
            
            int result = 1;
            for (int i = 1; i <= a; i++) {
                result *= i;
            }
            return result;
        } else {
            throw std::invalid_argument("Invalid operation.");
        }
    }
};
