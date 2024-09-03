#include <stdexcept>
#include <string>

class MathLegacy {
public:
    static int calculate(int a, int b, const std::string& operation) {
        if (operation == "add") {
            return add(a, b);
        } else if (operation == "subtract") {
            return subtract(a, b);
        } else if (operation == "multiply") {
            return multiply(a, b);
        } else if (operation == "divide") {
            return divide(a, b);
        } else if (operation == "factorial") {
            return factorial(a);
        } else {
            throw std::invalid_argument("Invalid operation.");
        }
    }

private:
    static int add(int a, int b) {
        return a + b;
    }

    static int subtract(int a, int b) {
        return a - b;
    }

    static int multiply(int a, int b) {
        return a * b;
    }

    static int divide(int a, int b) {
        if (b == 0) {
            throw std::runtime_error("Division by zero is undefined.");
        }
        return a / b;
    }

    static int factorial(int a) {
        if (a < 0) {
            throw std::invalid_argument("Factorial is not defined for negative numbers.");
        }
        int result = 1;
        for (int i = 1; i <= a; ++i) {
            result *= i;
        }
        return result;
    }
};


#include <gtest/gtest.h>
#include "MathLegacy.h"

TEST(MathLegacyTest, AddOperation) {
    EXPECT_EQ(MathLegacy::calculate(3, 2, "add"), 5);
    EXPECT_EQ(MathLegacy::calculate(-3, -2, "add"), -5);
}

TEST(MathLegacyTest, SubtractOperation) {
    EXPECT_EQ(MathLegacy::calculate(3, 2, "subtract"), 1);
    EXPECT_EQ(MathLegacy::calculate(-3, -2, "subtract"), -1);
}

TEST(MathLegacyTest, MultiplyOperation) {
    EXPECT_EQ(MathLegacy::calculate(3, 2, "multiply"), 6);
    EXPECT_EQ(MathLegacy::calculate(-3, -2, "multiply"), 6);
}

TEST(MathLegacyTest, DivideOperation) {
    EXPECT_EQ(MathLegacy::calculate(4, 2, "divide"), 2);
    EXPECT_EQ(MathLegacy::calculate(5, 2, "divide"), 2);
    EXPECT_THROW(MathLegacy::calculate(5, 0, "divide"), std::runtime_error);
}

TEST(MathLegacyTest, FactorialOperation) {
    EXPECT_EQ(MathLegacy::calculate(5, 0, "factorial"), 120);
    EXPECT_EQ(MathLegacy::calculate(0, 0, "factorial"), 1);
    EXPECT_THROW(MathLegacy::calculate(-5, 0, "factorial"), std::invalid_argument);
}

TEST(MathLegacyTest, InvalidOperation) {
    EXPECT_THROW(MathLegacy::calculate(5, 2, "modulus"), std::invalid_argument);
}

