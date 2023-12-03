1. **Split Temporary Variable:**
   - **Problem:** A temporary variable is used for multiple purposes.

```cpp
#include <iostream>

// Example for Split Temporary Variable
void calculateAreaAndPerimeter(double radius) {
    // Problematic: Using a single variable for both area and perimeter
    double result = 3.14 * radius;  // Represents area temporarily
    std::cout << "Area: " << result << std::endl;

    result = 2 * 3.14 * radius;     // Now represents perimeter
    std::cout << "Perimeter: " << result << std::endl;
}

int main() {
    double circleRadius = 5.0;
    calculateAreaAndPerimeter(circleRadius);

    return 0;
}
```

In the above example, the variable `result` is used for both area and perimeter calculations. 
- **Solution:** Use different variables for different values. Each variable should be responsible for only one particular thing.

```cpp
#include <iostream>

// Applying Split Temporary Variable
void calculateAreaAndPerimeter(double radius) {
    // Use separate variables for area and perimeter
    double area = 3.14 * radius;
    double perimeter = 2 * 3.14 * radius;

    std::cout << "Area: " << area << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;
}

int main() {
    double circleRadius = 5.0;
    calculateAreaAndPerimeter(circleRadius);

    return 0;
}
```

Now, the `calculateAreaAndPerimeter` function uses separate variables (`area` and `perimeter`) for distinct purposes, making the code clearer and less error-prone.

2. **Extract Method:**
   - **Problematic Code:**
     ```cpp
     void complexMethod() {
         // ... (long and complex code)
        int x = 5;
        double y = 8.2;

        // Task 1
        for (int i = 0; i < x; ++i) {
              if (i % 2 == 0) {
                  std::cout << "Even number: " << i << std::endl;
              } else {
                  std::cout << "Odd number: " << i << std::endl;
              }
         }

       // Task 2
       double result = x * y + 10 / (y - 2);

       // Output the result
       std::cout << "Result: " << result << std::endl;

       // Task 3
       int square = calculateSquare(x);
       std::cout << "Square of " << x << ": " << square << std::endl;
   
       // ... (more code)
     }
     ```
   - **Explanation:** The method `complexMethod` is long and performs multiple tasks.
   - **Refactored Code:**
     ```cpp
     void task1() {
         // Task 1
     }

     void task2() {
         // Task 2
     }

     void task3() {
         // Task 3
     }

     void refactoredMethod() {
         task1();
         task2();
         task3();
     }
     ``` 

3. **Inline Method:**
   - **Problematic Code:**
     ```cpp
     int simpleMethod() {
         return 2 + 2;
     }

     int use() {
        int result = simpleMethod();
     }
     ```
   - **Explanation:** The method `simpleMethod` is too simple or short to be useful.
   - **Refactored Code:**
     ```cpp
     int use() {
         result = 2 + 2;
     }
     ```

4. **Rename Method/Variable:**
   - **Problematic Code:**
     ```cpp
     int x = 10;

     void foo() {
         // ... (code using x)
     }
     ```
   - **Explanation:** The variable/method name `x` or `foo` is not descriptive.
   - **Refactored Code:**
     ```cpp
     int playerScore = 10;

     void calculatePlayerScore() {
         // ... (code using playerScore)
     }
     ```

5. **Replace Magic Numbers with Named Constants:**
   - **Problematic Code:**
     ```cpp
     double calculateArea(double radius) {
         return 3.14 * radius * radius;
     }
     ```
   - **Explanation:** The constant `3.14` is a magic number without clear explanation.
   - **Refactored Code:**
     ```cpp
     const double PI = 3.14;

     double calculateArea(double radius) {
         return PI * radius * radius;
     }
     ```

6. **Move Method:**
   - **Problematic Code:**
     ```cpp
     class A {
     public:
         void methodA() {
             // ... (code)
         }
     };

     class B {
     public:
         void methodB() {
             A objA;
             objA.methodA();  // Method belongs to class A
         }
     };
     ```
   - **Explanation:** `methodA` belongs to class A, but it is called from class B.
   - **Refactored Code:**
     ```cpp
     class A {
     public:
         void methodA() {
             // ... (code)
         }
     };

     class B {
     public:
         void methodB() {
             // ... (code)
         }
     };
     ```
7. **Extract Class:**
   - **Problematic Code:**
     ```cpp
     class Employee {
     public:
         std::string name;
         int age;
         // ... (other fields and methods)
     };
     ```
   - **Explanation:** The `Employee` class handles too many responsibilities.
   - **Refactored Code:**
     ```cpp
     class Person {
     public:
         std::string name;
         int age;
         // ... (other fields and methods related to a person)
     };

     class Employee {
     public:
         Person personInfo;
         // ... (other fields and methods related to an employee)
     };
     ```

8. **Introduce Parameter Object:**
   - **Problematic Code:**
     ```cpp
     double calculateTotalPrice(double itemPrice, int quantity, double discountRate) {
         // ... (calculation using individual parameters)
     }
     ```
   - **Explanation:** Too many parameters in the method signature.
   - **Refactored Code:**
     ```cpp
     struct PurchaseInfo {
         double itemPrice;
         int quantity;
         double discountRate;
     };

     double calculateTotalPrice(const PurchaseInfo& purchaseInfo) {
         // ... (calculation using purchaseInfo)
     }
     ```

9. **Remove Duplication:**
   - **Problematic Code:**
     ```cpp
     void processData1() {
         // ... (common code)
     }

     void processData2() {
         // ... (common code)
     }
     ```
   - **Explanation:** Duplicate code segments in different methods.
   - **Refactored Code:**
     ```cpp
     void commonProcessing() {
         // ... (common code)
     }

     void processData1() {
         commonProcessing();
         // ... (unique code for processData1)
     }

     void processData2() {
         commonProcessing();
         // ... (unique code for processData2)
     }
     ```

10. **Replace Conditional with Polymorphism:**
   - **Problematic Code:**
     ```cpp
     class Animal {
     public:
         void makeSound(int type) {
             if (type == 1)
                 std::cout << "Woof!" << std::endl;
             else if (type == 2)
                 std::cout << "Meow!" << std::endl;
             // ... (more conditions)
         }
     };
     ```
   - **Explanation:** Excessive use of conditional statements.
   - **Refactored Code:**
     ```cpp
     class Animal {
     public:
         virtual void makeSound() const = 0;
     };

     class Dog : public Animal {
     public:
         void makeSound() const override {
             std::cout << "Woof!" << std::endl;
         }
     };

     class Cat : public Animal {
     public:
         void makeSound() const override {
             std::cout << "Meow!" << std::endl;
         }
     };
     ```

11. **Introduce Null Object:**
   - **Problematic Code:**
      ```cpp
      User* getUserById(int userId) {
          // ... (return user or nullptr if not found)
      }
      ```
   - **Explanation:** Frequent checks for null references.
   - **Refactored Code:**
      ```cpp
      class NullUser : public User {
          // ... (implement default behavior or do nothing)
      };

      User* getUserById(int userId) {
          // ... (return user or a NullUser object if not found)
      }
      ```

12. **Encapsulate Fields:**
   - **Problematic Code:**
     ```cpp
     class Student {
     public:
         int age;
         // ... (other fields and methods)
     };
     ```
   - **Explanation:** Direct access to class fields.
   - **Refactored Code:**
     ```cpp
     class Student {
     private:
         int age;

     public:
         int getAge() const {
             return age;
         }

         void setAge(int newAge) {
             age = newAge;
         }
         // ... (other fields and methods)
     };
     ```

13. **Consolidate Conditional Expression:**
   - **Problematic Code:**
     ```cpp
     bool isEligibleForDiscount(int age, int purchaseAmount) {
       if (age >= 18) {
           if (purchaseAmount > 100) {
               return true;
           } else {
               return false;
           }
       } else {
        return false;
       }
     }
     ```
   - **Explanation:** Multiple conditions that can be simplified.
   - **Refactored Code:**
     ```cpp
     bool isEligibleForDiscount(int age, int purchaseAmount) {
         return age >= 18 && purchaseAmount > 100;
     }
     ```

14. **Introduce Guard Clauses:**
   - **Problematic Code:**
     ```cpp
     double calculateDiscountedPrice(double price, bool isMember) {
         if (isMember) {
             // ... (calculate discounted price)
         } else {
             // ... (calculate regular price)
         }
     }
     ```
   - **Explanation:** Long methods with nested conditional statements.
   - **Refactored Code:**
     ```cpp
     double calculateDiscountedPrice(double price, bool isMember) {
         if (isMember) {
             // ... (calculate discounted price)
             return discountedPrice;
         }

         // ... (calculate regular price)
         return regularPrice;
     }
     ```

15. **Replace Method with Method Object:**
   - **Problematic Code:**
     ```cpp
     class ComplexCalculator {
     public:
         double complexCalculation(double a, double b) {
             // ... (complex calculation using a and b)
         }
     };
     ```
   - **Explanation:** A method is too complex and hard to understand.
   - **Refactored Code:**
     ```cpp
     class ComplexCalculator {
     private:
         double a;
         double b;

     public:
         ComplexCalculator(double a, double b) : a(a), b(b) {}

         double calculate() {
             // ... (complex calculation using a and b)
         }
     };
     ```

16. **Breaking Dependencies:**
   - **Problematic Code:**
     ```cpp
     class DatabaseManager {
     public:
         void saveData(const Data& data) {
             // ... (code that interacts with the database)
         }
     };
     ```
   - **Explanation:** Tight coupling between classes.
   - **Refactored Code:**
     ```cpp
     class DatabaseManager {
     public:
         virtual void saveData(const Data& data) = 0;
     };

     class ConcreteDatabaseManager : public DatabaseManager {
     public:
         void saveData(const Data& data) override {
             // ... (code that interacts with the database)
         }
     };
     ```

