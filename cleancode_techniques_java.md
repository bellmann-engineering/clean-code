Hier sind die Beispiele für die verschiedenen Refactoring-Techniken in Java, strukturiert wie im angegebenen GitHub-Repository:

# Refactoring-Techniken in Java

## Split Temporary Variable
- **Problem:** Eine temporäre Variable wird für mehrere Zwecke verwendet.

### Problematisches Beispiel
```java
public class Example {
    public static void calculateAreaAndPerimeter(double radius) {
        // Problematisch: Verwendung einer einzigen Variablen für Fläche und Umfang
        double result = 3.14 * radius;  // Repräsentiert temporär die Fläche
        System.out.println("Area: " + result);

        result = 2 * 3.14 * radius;     // Repräsentiert jetzt den Umfang
        System.out.println("Perimeter: " + result);
    }

    public static void main(String[] args) {
        double circleRadius = 5.0;
        calculateAreaAndPerimeter(circleRadius);
    }
}
```

### Lösung
- **Lösung:** Verwenden Sie unterschiedliche Variablen für unterschiedliche Werte. Jede Variable sollte nur für eine bestimmte Sache verantwortlich sein.

```java
public class Example {
    public static void calculateAreaAndPerimeter(double radius) {
        // Verwendung separater Variablen für Fläche und Umfang
        double area = 3.14 * radius;
        double perimeter = 2 * 3.14 * radius;

        System.out.println("Area: " + area);
        System.out.println("Perimeter: " + perimeter);
    }

    public static void main(String[] args) {
        double circleRadius = 5.0;
        calculateAreaAndPerimeter(circleRadius);
    }
}
```

## Extract Method
- **Problem:** Eine Methode ist lang und führt mehrere Aufgaben aus.

### Problematisches Beispiel
```java
public class Example {
    public void complexMethod() {
        int x = 5;
        double y = 8.2;

        // Aufgabe 1
        for (int i = 0; i < x; ++i) {
            if (i % 2 == 0) {
                System.out.println("Even number: " + i);
            } else {
                System.out.println("Odd number: " + i);
            }
        }

        // Aufgabe 2
        double result = x * y + 10 / (y - 2);
        System.out.println("Result: " + result);

        // Aufgabe 3
        int square = calculateSquare(x);
        System.out.println("Square of " + x + ": " + square);
    }

    private int calculateSquare(int number) {
        return number * number;
    }
}
```

### Lösung
- **Lösung:** Extrahieren Sie Aufgaben in separate Methoden.

```java
public class Example {
    public void task1(int x) {
        for (int i = 0; i < x; ++i) {
            if (i % 2 == 0) {
                System.out.println("Even number: " + i);
            } else {
                System.out.println("Odd number: " + i);
            }
        }
    }

    public void task2(int x, double y) {
        double result = x * y + 10 / (y - 2);
        System.out.println("Result: " + result);
    }

    public void task3(int x) {
        int square = calculateSquare(x);
        System.out.println("Square of " + x + ": " + square);
    }

    public void refactoredMethod() {
        int x = 5;
        double y = 8.2;
        task1(x);
        task2(x, y);
        task3(x);
    }

    private int calculateSquare(int number) {
        return number * number;
    }
}
```

## Inline Method
- **Problem:** Eine Methode ist zu einfach oder kurz, um nützlich zu sein.

### Problematisches Beispiel
```java
public class Example {
    private int simpleMethod() {
        return 2 + 2;
    }

    public void use() {
        int result = simpleMethod();
        System.out.println("Result: " + result);
    }
}
```

### Lösung
- **Lösung:** Inlinieren Sie die Methode direkt in den Code.

```java
public class Example {
    public void use() {
        int result = 2 + 2;
        System.out.println("Result: " + result);
    }
}
```

## Rename Method/Variable
- **Problem:** Der Name einer Variablen oder Methode ist nicht aussagekräftig.

### Problematisches Beispiel
```java
public class Example {
    private int x = 10;

    public void foo() {
        System.out.println("Value: " + x);
    }
}
```

### Lösung
- **Lösung:** Verwenden Sie aussagekräftige Namen.

```java
public class Example {
    private int playerScore = 10;

    public void displayPlayerScore() {
        System.out.println("Player Score: " + playerScore);
    }
}
```

## Replace Magic Numbers with Named Constants
- **Problem:** Eine Konstante ist eine "magische Zahl", die keine klare Bedeutung hat.

### Problematisches Beispiel
```java
public class Example {
    public double calculateArea(double radius) {
        return 3.14 * radius * radius;
    }
}
```

### Lösung
- **Lösung:** Ersetzen Sie magische Zahlen durch benannte Konstanten.

```java
public class Example {
    private static final double PI = 3.14;

    public double calculateArea(double radius) {
        return PI * radius * radius;
    }
}
```

## Move Method
- **Problem:** Eine Methode gehört zu einer anderen Klasse, wird aber von einer anderen Klasse verwendet.

### Problematisches Beispiel
```java
public class A {
    public void methodA() {
        System.out.println("Method A");
    }
}

public class B {
    public void methodB() {
        A objA = new A();
        objA.methodA();
    }
}
```

### Lösung
- **Lösung:** Verschieben Sie die Methode in die richtige Klasse.

```java
public class A {
    public void methodA() {
        System.out.println("Method A");
    }
}

public class B {
    public void methodB() {
        System.out.println("Method B");
    }
}
```

## Extract Class
- **Problem:** Eine Klasse hat zu viele Verantwortlichkeiten.

### Problematisches Beispiel
```java
public class Employee {
    private String name;
    private int age;
    private double salary;
    private String department;

    // ... (andere Felder und Methoden)
}
```

### Lösung
- **Lösung:** Extrahieren Sie eine neue Klasse.

```java
public class Person {
    private String name;
    private int age;

    // ... (andere Felder und Methoden, die zu einer Person gehören)
}

public class Employee {
    private Person personInfo;
    private double salary;
    private String department;

    // ... (andere Felder und Methoden, die zu einem Mitarbeiter gehören)
}
```

## Introduce Parameter Object
- **Problem:** Zu viele Parameter in der Methodensignatur.

### Problematisches Beispiel
```java
public class Example {
    public double calculateTotalPrice(double itemPrice, int quantity, double discountRate) {
        return itemPrice * quantity * (1 - discountRate);
    }
}
```

### Lösung
- **Lösung:** Führen Sie ein Parameterobjekt ein.

```java
public class PurchaseInfo {
    private double itemPrice;
    private int quantity;
    private double discountRate;

    public PurchaseInfo(double itemPrice, int quantity, double discountRate) {
        this.itemPrice = itemPrice;
        this.quantity = quantity;
        this.discountRate = discountRate;
    }

    public double getItemPrice() {
        return itemPrice;
    }

    public int getQuantity() {
        return quantity;
    }

    public double getDiscountRate() {
        return discountRate;
    }
}

public class Example {
    public double calculateTotalPrice(PurchaseInfo purchaseInfo) {
        return purchaseInfo.getItemPrice() * purchaseInfo.getQuantity() * (1 - purchaseInfo.getDiscountRate());
    }
}
```

## Remove Duplication
- **Problem:** Duplizierte Code-Segmente in verschiedenen Methoden.

### Problematisches Beispiel
```java
public class Example {
    public void processData1() {
        // ... (gemeinsamer Code)
        System.out.println("Processing Data 1");
    }

    public void processData2() {
        // ... (gemeinsamer Code)
        System.out.println("Processing Data 2");
    }
}
```

### Lösung
- **Lösung:** Extrahieren Sie den gemeinsamen Code in eine eigene Methode.

```java
public class Example {
    private void commonProcessing() {
        // ... (gemeinsamer Code)
    }

    public void processData1() {
        commonProcessing();
        System.out.println("Processing Data 1");
    }

    public void processData2() {
        commonProcessing();
        System.out.println("Processing Data 2");
    }
}
```

## Replace Conditional with Polymorphism
- **Problem:** Übermäßige Verwendung von bedingten Anweisungen.

### Problematisches Beispiel
```java
public class Animal {
    public void makeSound(int type) {
        if (type == 1) {
            System.out.println("Woof!");
        } else if (type == 2) {
            System.out.println("Meow!");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Animal animal = new Animal();
        animal.makeSound(1);  // Output: Woof!
        animal.makeSound(2);  // Output: Meow!
    }
}
```

### Lösung
- **Lösung:** Verwenden Sie Polymorphismus.

```java
// Basisklasse Animal
public abstract class Animal {
    public abstract void makeSound();
}

// Unterklasse Dog
public class Dog extends Animal {
    @Override
    public void makeSound() {
        System.out.println("Woof!");
    }
}

// Unterklasse Cat
public class Cat extends Animal {
    @Override
    public void makeSound() {
        System.out.println("Meow!");
    }
}

// Hauptklasse Main zum Testen
public class Main {
    public static void main(String[] args) {
        Animal dog = new Dog();
        dog.makeSound();  // Output: Woof!

        Animal cat = new Cat();
        cat.makeSound();  // Output: Meow!
    }
}
```

Hier sind die Java-Beispiele für die Refactoring-Techniken mit dem Einsatz von `Optional<>` anstelle von Null-Objekten.

# Refactoring-Techniken in Java

## Introduce Null Object / Use Optional
- **Problem:** Häufige Überprüfungen auf null-Referenzen.

### Problematisches Beispiel
```java
public class User {
    private String name;

    public User(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

public class UserService {
    public User getUserById(int userId) {
        // ... (return user or null if not found)
        return null; // Beispielrückgabe
    }
}

public class Main {
    public static void main(String[] args) {
        UserService userService = new UserService();
        User user = userService.getUserById(1);

        if (user != null) {
            System.out.println("User name: " + user.getName());
        } else {
            System.out.println("User not found");
        }
    }
}
```

### Lösung mit Null-Objekt
- **Lösung:** Verwenden Sie ein Null-Objekt, um null-Referenzen zu vermeiden.

```java
public class User {
    private String name;

    public User(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

public class NullUser extends User {
    public NullUser() {
        super("Unknown");
    }
}

public class UserService {
    public User getUserById(int userId) {
        // ... (return user or a NullUser object if not found)
        return new NullUser(); // Beispielrückgabe
    }
}

public class Main {
    public static void main(String[] args) {
        UserService userService = new UserService();
        User user = userService.getUserById(1);
        System.out.println("User name: " + user.getName());
    }
}
```

### Lösung mit Optional
- **Lösung:** Verwenden Sie `Optional<>`, um null-Referenzen zu vermeiden.

```java
import java.util.Optional;

public class User {
    private String name;

    public User(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

public class UserService {
    public Optional<User> getUserById(int userId) {
        // ... (return Optional.of(user) or Optional.empty() if not found)
        return Optional.empty(); // Beispielrückgabe
    }
}

public class Main {
    public static void main(String[] args) {
        UserService userService = new UserService();
        Optional<User> userOptional = userService.getUserById(1);

        userOptional.ifPresentOrElse(
            user -> System.out.println("User name: " + user.getName()),
            () -> System.out.println("User not found")
        );
    }
}
```

## Encapsulate Fields
- **Problem:** Direkter Zugriff auf Klassenfelder.

### Problematisches Beispiel
```java
public class Student {
    public int age;

    // ... (andere Felder und Methoden)
}
```

### Lösung
- **Lösung:** Kapseln Sie die Felder ein.

```java
public class Student {
    private int age;

    public int getAge() {
        return age;
    }

    public void setAge(int newAge) {
        this.age = newAge;
    }

    // ... (andere Felder und Methoden)
}
```

## Consolidate Conditional Expression
- **Problem:** Mehrere Bedingungen, die vereinfacht werden können.

### Problematisches Beispiel
```java
public class Example {
    public boolean isEligibleForDiscount(int age, int purchaseAmount) {
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
}
```

### Lösung
- **Lösung:** Konsolidieren Sie die Bedingungen.

```java
public class Example {
    public boolean isEligibleForDiscount(int age, int purchaseAmount) {
        return age >= 18 && purchaseAmount > 100;
    }
}
```

## Introduce Guard Clauses
- **Problem:** Lange Methoden mit verschachtelten Bedingungsanweisungen.

### Problematisches Beispiel
```java
public class Example {
    public double calculateDiscountedPrice(double price, boolean isMember) {
        if (isMember) {
            // ... (berechne Rabattpreis)
        } else {
            // ... (berechne regulären Preis)
        }
    }
}
```

### Lösung
- **Lösung:** Verwenden Sie Guard Clauses.

```java
public class Example {
    public double calculateDiscountedPrice(double price, boolean isMember) {
        if (isMember) {
            // ... (berechne Rabattpreis)
            return discountedPrice;
        }

        // ... (berechne regulären Preis)
        return regularPrice;
    }
}
```

## Replace Method with Method Object
- **Problem:** Eine Methode ist zu komplex und schwer zu verstehen.

### Problematisches Beispiel
```java
public class ComplexCalculator {
    public double complexCalculation(double a, double b) {
        // ... (komplexe Berechnung mit a und b)
    }
}
```

### Lösung
- **Lösung:** Verwenden Sie ein Methodenobjekt.

```java
public class ComplexCalculator {
    private double a;
    private double b;

    public ComplexCalculator(double a, double b) {
        this.a = a;
        this.b = b;
    }

    public double calculate() {
        // ... (komplexe Berechnung mit a und b)
    }
}
```

## Breaking Dependencies
- **Problem:** Enge Kopplung zwischen Klassen.

### Problematisches Beispiel
```java
public class DatabaseManager {
    public void saveData(Data data) {
        // ... (code, der mit der Datenbank interagiert)
    }
}
```

### Lösung
- **Lösung:** Lösen Sie die Abhängigkeiten.

```java
public abstract class DatabaseManager {
    public abstract void saveData(Data data);
}

public class ConcreteDatabaseManager extends DatabaseManager {
    @Override
    public void saveData(Data data) {
        // ... (code, der mit der Datenbank interagiert)
    }
}
```
