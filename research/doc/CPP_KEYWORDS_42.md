# C++ Keywords Reference for 42 School

A comprehensive guide to C++ keywords for 42 School CPP modules, organized by learning progression and practical usage.

## Introduction

The 42 CPP modules use **C++98 standard exclusively**. This reference provides all C++98 keywords with practical examples, usage patterns, and 42-specific guidance. Keywords are organized from basic to advanced to match the module progression.

---

## Foundation Keywords (Modules 00-01)

These are the essential keywords you'll use in every C++ program. Master these first.

### Class Definition & Access Control

| Keyword   | Purpose                                 | Module 00 Example                        |
| --------- | --------------------------------------- | ---------------------------------------- |
| class     | Define a class (OOP foundation)         | `class PhoneBook { };`                   |
| struct    | Define a struct (public by default)     | `struct Contact { std::string name; };`  |
| public    | Public access specifier                 | `public: void addContact();`             |
| private   | Private access specifier                | `private: std::string firstName;`        |
| protected | Protected access specifier              | `protected: std::string type;` (Module 03+) |

### Essential Data Types

| Keyword  | Purpose                         | Common Usage                          |
| -------- | ------------------------------- | ------------------------------------- |
| int      | Integer numbers                 | `int index = 0;`                      |
| char     | Single characters               | `char initial = 'A';`                 |
| bool     | Boolean values                  | `bool isValid = true;`                |
| float    | Single-precision decimals       | `float price = 9.99f;`                |
| double   | Double-precision decimals       | `double pi = 3.14159;`                |
| void     | No type/return value            | `void printMessage();`                |

### Control Flow

| Keyword  | Purpose                            | Essential Usage                       | Notes                                |
| -------- | ---------------------------------- | ------------------------------------- | ------------------------------------ |
| if       | Conditional execution              | `if (index < MAX_SIZE)`               | Basic program logic control         |
| else     | Alternative condition              | `else { handleError(); }`             | Must follow if statement             |
| for      | Counted loops                      | `for (int i = 0; i < 8; i++)`         | When you know iteration count        |
| while    | Conditional loops                  | `while (input != "QUIT")`             | When condition determines when to stop |
| do       | Post-condition loop                | `do { getInput(); } while (invalid);` | Body executes at least once         |
| break    | Exit loop or switch early          | `break;` (in loops/switch)            | Jumps out of current loop/switch     |
| continue | Skip to next iteration             | `continue;` (in loops only)           | Skips rest of loop body              |
| switch   | Multi-way branch                   | `switch (choice) { case 1: ... }`     | Efficient alternative to if-else chain |
| case     | Label in switch statement          | `case 'A': processA(); break;`        | Must end with break (usually)        |
| default  | Default case in switch             | `default: handleUnknown(); break;`    | Handles unmatched cases              |
| return   | Exit function with/without value   | `return getName();`                   | Can return value or just exit        |

### Memory Management (Module 01)

| Keyword | Purpose                   | Critical Usage                        | Memory Rules                          |
| ------- | ------------------------- | ------------------------------------- | ------------------------------------- |
| new     | Allocate heap memory      | `Zombie* z = new Zombie("name");`     | Every `new` needs matching `delete`   |
| delete  | Free heap memory          | `delete z;` or `delete[] array;`      | Use `delete[]` for arrays, `delete` for single objects |

**Critical Memory Management Rules:**
- **Heap vs Stack**: `new` allocates on heap (manual cleanup), local variables on stack (automatic cleanup)
- **Memory Leaks**: Forgetting `delete` causes memory leaks - program keeps using memory
- **Array Allocation**: `new Type[size]` must use `delete[] ptr`, not `delete ptr`
- **Double Delete**: Calling `delete` twice on same pointer = undefined behavior
- **Null Pointers**: Safe to call `delete` on `nullptr`, but not on uninitialized pointers

```cpp
// Module 01 Examples
Zombie* newZombie(std::string name) {
    return new Zombie(name);  // Heap - survives function scope
}

void randomChump(std::string name) {
    Zombie zombie(name);      // Stack - automatic cleanup when function ends
}

// Array management
Zombie* horde = new Zombie[5];  // Array allocation
// ... use horde
delete[] horde;                 // Array deletion - note the []
```

---

## Core Concept Keywords (Modules 02-04)

These keywords enable advanced C++ features like const correctness, operator overloading, and polymorphism.

### The `const` Keyword Family

`const` is fundamental to good C++ design. It has multiple forms with different meanings:

| Usage Pattern             | Syntax                                | Purpose                                       | Why Important                        |
| ------------------------- | ------------------------------------- | --------------------------------------------- | ------------------------------------ |
| **Const Variable**        | `const int MAX_SIZE = 8;`             | Value cannot change after initialization     | Prevents accidental modification     |
| **Const Method**          | `std::string getName() const;`        | Method promises not to modify object         | Enables calling on const objects     |
| **Const Parameter**       | `void func(const std::string& str);`  | Parameter cannot be modified (safe reference) | Efficiency + safety for large objects |
| **Const Return**          | `const std::string& getName() const;` | Returned reference cannot be modified        | Prevents modification of internal data |
| **Const Pointer**         | `int* const ptr = &value;`            | Pointer address cannot change                | Pointer always points to same object |
| **Pointer to Const**      | `const int* ptr = &value;`            | Cannot modify value through pointer          | Read-only access through pointer     |
| **Const Pointer to Const** | `const int* const ptr = &value;`      | Neither pointer address nor value can change | Complete immutability               |

**Const Best Practices:**
- **Const Correctness**: Design classes so const objects can do everything read-only
- **Getter Methods**: Always make getters const: `std::string getName() const;`
- **Pass by const reference**: `void func(const LargeObject& obj)` - efficient and safe
- **Const Return**: Return const references to prevent modification: `const std::string& getInternalData() const;`

```cpp
// Module 00 Examples - PhoneBook
class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;  // Class constant - shared by all instances
    Contact contacts[MAX_CONTACTS];
    int contactCount;

public:
    // Const method - doesn't modify object, can be called on const PhoneBook
    int getContactCount() const { return contactCount; }
    
    // Const return - prevents modification of returned reference
    const Contact& getContact(int index) const { 
        return contacts[index]; 
    }
    
    // Non-const method - modifies object state
    void addContact(const Contact& contact) {  // const parameter - efficient, safe
        if (contactCount < MAX_CONTACTS) {
            contacts[contactCount++] = contact;
        }
    }
};
```

### The `static` Keyword Family

`static` controls scope and lifetime in different contexts:

| Usage Context           | Syntax                                 | Purpose                                    | Key Characteristics                  |
| ----------------------- | -------------------------------------- | ------------------------------------------ | ------------------------------------ |
| **Static Class Member** | `static const int MAX_CONTACTS = 8;`  | Shared by all instances of the class       | One copy for entire class            |
| **Static Method**       | `static bool isValid(const std::string&);` | Class method, no `this` pointer      | Called without object instance       |
| **Static Local Var**   | `static int counter = 0;`              | Retains value between function calls       | Initialized only once                |
| **Static Global**       | `static int fileVar = 42;`             | File scope only, not visible externally    | Internal linkage, prevents name conflicts |
| **Static Function**     | `static void helperFunc() { }`         | Function visible only within current file  | File-private function                |

**Static Usage Guidelines:**
- **Class Members**: Use for constants shared by all instances
- **Utility Methods**: Use for functions that don't need object state
- **Function-local**: Use for counters, caches that persist between calls
- **File-scope**: Use to make variables/functions private to a file

```cpp
// Module 00 Examples
class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;  // Shared constant - all PhoneBooks have same limit
    Contact contacts[MAX_CONTACTS];
    int contactCount;                   // Each PhoneBook has its own count

public:
    PhoneBook() : contactCount(0) {}
    
    // Static method - belongs to class, not instance
    static int getMaxContacts() { 
        return MAX_CONTACTS;  // Can access static members
        // return contactCount;  // ERROR! No access to non-static members
    }
    
    // Static utility method
    static bool isValidName(const std::string& name) {
        return !name.empty() && name.length() <= 50;
    }
};

// Usage:
int main() {
    // Call static method without creating object
    std::cout << "Max contacts: " << PhoneBook::getMaxContacts() << std::endl;
    
    if (PhoneBook::isValidName("John")) {
        // Create PhoneBook instance
        PhoneBook pb;
        // pb also has access to static members
    }
}

// Static local variable example
int getNextId() {
    static int nextId = 1;  // Initialized only once, retains value
    return nextId++;        // Each call returns different value
}
```

### Polymorphism Keywords (Module 04)

| Keyword         | Purpose                              | Usage Example                           | Critical Notes                       |
| --------------- | ------------------------------------ | --------------------------------------- | ------------------------------------ |
| virtual         | Enable function overriding          | `virtual void makeSound();`             | Enables runtime polymorphism        |
| virtual (pure)  | Force override, make class abstract  | `virtual void makeSound() = 0;`         | Class cannot be instantiated        |
| virtual (dtor)  | Ensure proper inheritance cleanup    | `virtual ~Animal();`                    | **Always** use in base classes      |

**Virtual Function Deep Dive:**

```cpp
// Module 04 Examples - Animal Hierarchy
class Animal {
protected:
    std::string type;

public:
    Animal() {}
    virtual ~Animal() {}                    // Virtual destructor - CRUCIAL!

    virtual void makeSound() const = 0;     // Pure virtual - must override
    virtual std::string getType() const {   // Virtual - can override
        return type;
    }
    
    // Non-virtual function - cannot be overridden
    void breathe() const {
        std::cout << "Breathing..." << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog() { type = "Dog"; }
    ~Dog() { std::cout << "Dog destructor" << std::endl; }

    // Override pure virtual function - MUST implement
    virtual void makeSound() const {
        std::cout << "Woof!" << std::endl;
    }
    
    // Override virtual function - optional
    virtual std::string getType() const {
        return "Domestic " + type;
    }
};

// Polymorphic usage
int main() {
    Animal* animals[2];
    animals[0] = new Dog();     // Upcasting - always safe
    animals[1] = new Cat();
    
    // Polymorphic calls - correct function called at runtime
    for (int i = 0; i < 2; i++) {
        animals[i]->makeSound();  // Calls Dog::makeSound() or Cat::makeSound()
        animals[i]->breathe();    // Calls Animal::breathe() (not virtual)
    }
    
    // Cleanup - virtual destructor ensures correct destructor called
    for (int i = 0; i < 2; i++) {
        delete animals[i];  // Calls ~Dog() then ~Animal(), or ~Cat() then ~Animal()
    }
}
```

**Why Virtual Destructors Matter:**
```cpp
// WITHOUT virtual destructor - MEMORY LEAK!
class Base {
public:
    ~Base() { /* cleanup Base */ }  // NOT virtual!
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() : data(new int[100]) {}
    ~Derived() { delete[] data; }   // This won't be called!
};

Base* ptr = new Derived();
delete ptr;  // Only calls ~Base(), NOT ~Derived() - MEMORY LEAK!

// WITH virtual destructor - CORRECT
class Base {
public:
    virtual ~Base() { /* cleanup Base */ }  // Virtual!
};
// Now delete ptr calls ~Derived() then ~Base() - no leak!
```

### Operator Overloading (Module 02)

| Keyword  | Purpose                     | Usage Example                          | Design Guidelines                    |
| -------- | --------------------------- | -------------------------------------- | ------------------------------------ |
| operator | Define custom operators     | `Fixed operator+(const Fixed& other);` | Make classes behave like built-in types |

**Operator Overloading Deep Dive:**

```cpp
// Module 02 Examples - Fixed Point Class
class Fixed {
private:
    int rawValue;
    static const int fractionalBits = 8;

public:
    Fixed() : rawValue(0) {}
    Fixed(const int value) : rawValue(value << fractionalBits) {}
    Fixed(const float value) : rawValue(static_cast<int>(roundf(value * (1 << fractionalBits)))) {}

    // Arithmetic operators - return new objects
    Fixed operator+(const Fixed& other) const {
        Fixed result;
        result.rawValue = this->rawValue + other.rawValue;
        return result;
    }

    Fixed operator-(const Fixed& other) const {
        Fixed result;
        result.rawValue = this->rawValue - other.rawValue;
        return result;
    }

    Fixed operator*(const Fixed& other) const {
        Fixed result;
        result.rawValue = (this->rawValue * other.rawValue) >> fractionalBits;
        return result;
    }

    Fixed operator/(const Fixed& other) const {
        Fixed result;
        result.rawValue = (this->rawValue << fractionalBits) / other.rawValue;
        return result;
    }

    // Comparison operators - return bool
    bool operator>(const Fixed& other) const {
        return this->rawValue > other.rawValue;
    }

    bool operator<(const Fixed& other) const {
        return this->rawValue < other.rawValue;
    }

    bool operator>=(const Fixed& other) const {
        return this->rawValue >= other.rawValue;
    }

    bool operator<=(const Fixed& other) const {
        return this->rawValue <= other.rawValue;
    }

    bool operator==(const Fixed& other) const {
        return this->rawValue == other.rawValue;
    }

    bool operator!=(const Fixed& other) const {
        return this->rawValue != other.rawValue;
    }

    // Increment/decrement operators
    Fixed& operator++() {        // Pre-increment: ++obj
        rawValue++;
        return *this;            // Return reference to modified object
    }

    Fixed operator++(int) {      // Post-increment: obj++
        Fixed temp(*this);       // Save current state
        rawValue++;              // Modify current object
        return temp;             // Return old state
    }

    Fixed& operator--() {        // Pre-decrement: --obj
        rawValue--;
        return *this;
    }

    Fixed operator--(int) {      // Post-decrement: obj--
        Fixed temp(*this);
        rawValue--;
        return temp;
    }

    // Assignment operator
    Fixed& operator=(const Fixed& other) {
        if (this != &other) {    // Self-assignment check
            this->rawValue = other.rawValue;
        }
        return *this;            // Return reference for chaining
    }

    // Conversion operators
    operator float() const {     // Implicit conversion to float
        return static_cast<float>(rawValue) / (1 << fractionalBits);
    }

    operator int() const {       // Implicit conversion to int
        return rawValue >> fractionalBits;
    }
};

// External operators (for symmetry)
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << static_cast<float>(fixed);  // Use conversion operator
    return out;
}

// Usage examples
int main() {
    Fixed a(5.05f);
    Fixed b(2);
    
    Fixed c = a + b;             // Calls a.operator+(b)
    Fixed d = a * b;             // Calls a.operator*(b)
    
    bool greater = a > b;        // Calls a.operator>(b)
    
    ++a;                         // Calls a.operator++()
    Fixed old = b++;             // Calls b.operator++(0)
    
    std::cout << a << std::endl; // Calls operator<<(cout, a)
    
    return 0;
}
```

**Operator Overloading Rules:**
- **Const correctness**: Operators that don't modify should be const
- **Return types**: Arithmetic returns new objects, comparison returns bool
- **Pre vs Post increment**: Pre-increment more efficient (no temporary)
- **Self-assignment**: Always check in assignment operator
- **Symmetry**: Some operators better as external functions

### Type Safety & Conversions

| Keyword          | Purpose                           | When to Use                         | Safety Level                        |
| ---------------- | --------------------------------- | ----------------------------------- | ----------------------------------- |
| static_cast      | Safe compile-time conversions     | Numeric conversions, inheritance    | ✅ Safe - compile-time checks       |
| dynamic_cast     | Runtime-checked conversions       | Safe downcasting in polymorphism    | ✅ Safe - runtime checks            |
| const_cast       | Remove const qualifier            | Rarely (legacy C function calls)   | ⚠️ Use sparingly - breaks const correctness |
| reinterpret_cast | Unsafe bit-level conversions      | ❌ Usually forbidden in 42          | ❌ Dangerous - no safety checks     |

**Type Conversion Deep Dive:**

```cpp
// static_cast - Safe conversions
void staticCastExamples() {
    // Numeric conversions
    int intValue = 42;
    double doubleValue = static_cast<double>(intValue);  // int to double - safe
    float floatValue = static_cast<float>(doubleValue);  // double to float - safe
    
    // Truncation warning - but explicit
    int truncated = static_cast<int>(3.14159);  // Becomes 3 - explicit truncation
    
    // Inheritance upcasting (always safe)
    Dog dog;
    Animal* animalPtr = static_cast<Animal*>(&dog);  // Upcast - safe
    
    // Inheritance downcasting (compile-time, no runtime check)
    Animal* basePtr = &dog;
    Dog* dogPtr = static_cast<Dog*>(basePtr);  // Downcast - assumes basePtr points to Dog
    // This is NOT checked at runtime - dangerous if basePtr doesn't point to Dog!
}

// dynamic_cast - Runtime-checked conversions
void dynamicCastExamples() {
    Dog dog;
    Cat cat;
    Animal* animals[] = { &dog, &cat };
    
    for (int i = 0; i < 2; i++) {
        // Safe downcasting with runtime check
        Dog* dogPtr = dynamic_cast<Dog*>(animals[i]);
        if (dogPtr != nullptr) {  // Cast succeeded - animals[i] is actually a Dog
            std::cout << "Found a dog!" << std::endl;
            dogPtr->wagTail();  // Safe to call Dog-specific methods
        }
        
        Cat* catPtr = dynamic_cast<Cat*>(animals[i]);
        if (catPtr != nullptr) {  // Cast succeeded - animals[i] is actually a Cat
            std::cout << "Found a cat!" << std::endl;
            catPtr->purr();     // Safe to call Cat-specific methods
        }
    }
}

// const_cast - Remove const (use rarely!)
void constCastExamples() {
    const std::string message = "Hello";
    
    // Need to call legacy C function that takes non-const char*
    void legacyFunction(char* str);  // Old C function signature
    
    // const_cast to interface with legacy code
    char* mutableStr = const_cast<char*>(message.c_str());
    legacyFunction(mutableStr);  // DANGEROUS - if legacyFunction modifies string!
    
    // Better approach - copy to non-const
    std::string copy = message;
    legacyFunction(const_cast<char*>(copy.c_str()));  // Safer - modify copy
}

// Why reinterpret_cast is forbidden
void dangerousReinterpretCast() {
    int number = 42;
    
    // FORBIDDEN in 42 - treats int bits as char* - UNDEFINED BEHAVIOR!
    char* badPtr = reinterpret_cast<char*>(&number);
    // Using badPtr is almost certainly going to crash or corrupt memory
}
```

**Cast Safety Guidelines:**
1. **Prefer static_cast** for most conversions - explicit and compile-time checked
2. **Use dynamic_cast** for safe downcasting in polymorphic hierarchies
3. **Avoid const_cast** unless interfacing with legacy C code
4. **Never use reinterpret_cast** in 42 - breaks type safety
5. **C-style casts forbidden** - `(int)value` hides what type of cast is happening

---

## Advanced Keywords (Modules 05-09)

For sophisticated C++ features like exceptions, templates, and namespaces.

### Exception Handling (Module 05)

| Keyword | Purpose                      | Example Usage                        | Exception Flow                       |
| ------- | ---------------------------- | ------------------------------------ | ------------------------------------ |
| try     | Begin exception monitoring   | `try { risky_operation(); }`         | Monitors code for thrown exceptions  |
| catch   | Handle specific exceptions   | `catch (const std::exception& e)`    | Handles exceptions by type           |
| throw   | Raise an exception           | `throw GradeTooHighException();`     | Transfers control to nearest catch   |

**Exception Handling Deep Dive:**

```cpp
// Module 05 Examples - Bureaucrat Class
class Bureaucrat {
private:
    const std::string name;
    int grade;  // 1 (highest) to 150 (lowest)

public:
    Bureaucrat(const std::string& name, int grade) : name(name) {
        if (grade < 1) {
            throw GradeTooHighException();    // throw - signal error condition
        }
        if (grade > 150) {
            throw GradeTooLowException();     // throw - signal error condition
        }
        this->grade = grade;
    }

    // Custom exception classes - inherit from std::exception
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high! (minimum is 1)";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too low! (maximum is 150)";
        }
    };

    void incrementGrade() {
        if (grade <= 1) {
            throw GradeTooHighException();    // throw - signal error condition
        }
        grade--;  // Lower number = higher grade
    }

    void decrementGrade() {
        if (grade >= 150) {
            throw GradeTooLowException();     // throw - signal error condition
        }
        grade++;  // Higher number = lower grade
    }

    int getGrade() const { return grade; }
    const std::string& getName() const { return name; }
};

// Exception handling in action
int main() {
    try {                                      // try - monitor for exceptions
        Bureaucrat bob("Bob", 2);
        std::cout << bob.getName() << ", grade " << bob.getGrade() << std::endl;

        bob.incrementGrade();  // This works (grade becomes 1)
        std::cout << "After increment: " << bob.getGrade() << std::endl;

        bob.incrementGrade();  // This throws exception (can't go below 1)
        std::cout << "This line won't execute" << std::endl;  // Skipped due to exception
    }
    catch (const Bureaucrat::GradeTooHighException& e) {  // catch - handle specific exception
        std::cout << "Caught high grade exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {   // catch - handle specific exception
        std::cout << "Caught low grade exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {                     // catch - handle any std::exception
        std::cout << "Caught general exception: " << e.what() << std::endl;
    }
    // Execution continues here after exception is handled

    // Multiple try-catch blocks
    try {                                      // try - separate exception handling block
        Bureaucrat alice("Alice", 200);  // This will throw (grade too low)
        alice.incrementGrade();          // This won't execute
    }
    catch (const std::exception& e) {          // catch - handle any exception
        std::cout << "Failed to create Alice: " << e.what() << std::endl;
    }

    std::cout << "Program continues normally" << std::endl;
    return 0;
}
```

**Exception Handling Principles:**
- **RAII (Resource Acquisition Is Initialization)**: Local objects automatically destroyed when exception thrown
- **Stack unwinding**: Function call stack unwound until catch block found
- **Exception safety**: Write code that handles exceptions gracefully
- **what() method**: Standard way to get error message from exceptions
- **Catch order**: More specific exceptions before general ones
- **Exception specifications**: `throw()` means function doesn't throw (C++98 syntax)

**Exception vs Return Codes:**
```cpp
// Old C-style error handling
int divide(int a, int b, int* result) {
    if (b == 0) return -1;  // Error code
    *result = a / b;
    return 0;  // Success
}

// Modern C++ exception handling
int divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;  // Clean, simple interface
}
```

### Template Programming (Modules 07-08)

| Keyword  | Purpose                        | Example Usage                       | Key Concepts                        |
| -------- | ------------------------------ | ----------------------------------- | ----------------------------------- |
| template | Define generic code            | `template<typename T>`              | Code generation at compile time     |
| typename | Declare template type parameter | `template<typename T> class Array;` | T is placeholder for any type       |

**Template Programming Deep Dive:**

```cpp
// Module 07-08 Examples - Generic Array Class
template<typename T>  // template and typename keywords - T is placeholder for any type
class Array {
private:
    T* data;          // T will be replaced with actual type (int, string, etc.)
    unsigned int size;

public:
    // Default constructor
    Array() : data(nullptr), size(0) {}

    // Parameterized constructor
    Array(unsigned int n) : size(n) {
        if (n > 0) {
            data = new T[n];           // Create array of type T
            for (unsigned int i = 0; i < n; i++) {
                data[i] = T();         // Call default constructor of type T
            }
        } else {
            data = nullptr;
        }
    }

    // Copy constructor - deep copy
    Array(const Array& other) : size(other.size) {
        if (size > 0) {
            data = new T[size];
            for (unsigned int i = 0; i < size; i++) {
                data[i] = other.data[i];  // Copy elements of type T
            }
        } else {
            data = nullptr;
        }
    }

    // Assignment operator - deep copy with self-assignment check
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            if (size > 0) {
                data = new T[size];
                for (unsigned int i = 0; i < size; i++) {
                    data[i] = other.data[i];
                }
            } else {
                data = nullptr;
            }
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] data;
    }

    // Subscript operator with bounds checking
    T& operator[](unsigned int index) {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    unsigned int getSize() const { return size; }
};

// Template function example
template<typename T>  // template and typename keywords
void swap(T& a, T& b) {  // Works with any type T that supports copying
    T temp = a;
    a = b;
    b = temp;
}

// Template function with multiple parameters
template<typename T, typename U>
void printPair(const T& first, const U& second) {
    std::cout << "(" << first << ", " << second << ")" << std::endl;
}

// Usage of templates
int main() {
    try {
        // Array of integers - compiler generates Array<int> class
        Array<int> intArray(5);  // T becomes int
        for (unsigned int i = 0; i < intArray.getSize(); i++) {
            intArray[i] = i * 10;
        }

        // Array of strings - compiler generates Array<std::string> class
        Array<std::string> stringArray(3);  // T becomes std::string
        stringArray[0] = "Hello";
        stringArray[1] = "World";
        stringArray[2] = "!";

        // Template function usage
        int x = 10, y = 20;
        swap<int>(x, y);  // Explicit template parameter specification
        swap(x, y);       // Template parameter deduction - compiler figures out T = int

        std::string str1 = "first", str2 = "second";
        swap(str1, str2); // Template parameter deduction - compiler figures out T = std::string

        // Multiple template parameters
        printPair(42, "Answer");     // T = int, U = const char*
        printPair(3.14, true);       // T = double, U = bool

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
```

**Template Concepts:**
- **Code generation**: Compiler creates separate code for each type used with template
- **Type requirements**: Template code must work with the types you instantiate it with
- **Compile-time errors**: Template errors show up when you instantiate with incompatible types
- **No runtime overhead**: Templates are resolved at compile time, not runtime
- **Type deduction**: Compiler can often figure out template parameters automatically

**Template Specialization:**
```cpp
// General template
template<typename T>
class Container {
public:
    void process() {
        std::cout << "Processing generic type" << std::endl;
    }
};

// Specialization for bool
template<>  // Empty template parameter list for specialization
class Container<bool> {
public:
    void process() {
        std::cout << "Processing bool type specially" << std::endl;
    }
};

// Usage
Container<int> intContainer;
intContainer.process();      // "Processing generic type"

Container<bool> boolContainer;
boolContainer.process();     // "Processing bool type specially"
```

### Code Organization

| Keyword   | Purpose                         | Example Usage                      | Best Practices                      |
| --------- | ------------------------------- | ---------------------------------- | ----------------------------------- |
| namespace | Create named scopes             | `namespace ft { /* code */ }`      | Organize code, prevent name conflicts |
| using     | Import namespace elements       | `using std::cout;`                 | Use sparingly, avoid in headers    |

**Namespace and Using Deep Dive:**

```cpp
// Creating custom namespace
namespace MyLibrary {                    // namespace - create named scope
    namespace Math {                     // nested namespace
        const double PI = 3.14159;

        double square(double x) {
            return x * x;
        }

        class Calculator {
        public:
            double add(double a, double b) { return a + b; }
            double multiply(double a, double b) { return a * b; }
        };
    }

    namespace String {                   // separate nested namespace
        std::string toUpper(const std::string& str) {
            std::string result = str;
            for (size_t i = 0; i < result.length(); i++) {
                result[i] = std::toupper(result[i]);
            }
            return result;
        }

        bool isValidEmail(const std::string& email) {
            return email.find('@') != std::string::npos;
        }
    }
}

// Usage examples
int main() {
    // Full namespace qualification - most explicit and safe
    double result1 = MyLibrary::Math::square(5.0);
    std::cout << "Square: " << result1 << std::endl;

    // Using declaration for specific items
    using MyLibrary::Math::PI;           // using - bring specific symbol into scope
    using MyLibrary::Math::Calculator;   // using - bring specific class into scope

    std::cout << "PI = " << PI << std::endl;  // No namespace qualifier needed
    Calculator calc;                     // No namespace qualifier needed
    double sum = calc.add(10, 20);

    // Using directive for entire namespace (use carefully!)
    {
        using namespace MyLibrary::String;   // using namespace - bring all symbols into scope
        std::string upper = toUpper("hello world");  // No namespace qualifier needed
        bool valid = isValidEmail("test@example.com");
    }  // using namespace scope ends here

    // Namespace alias for long namespace names
    namespace ML = MyLibrary::Math;      // namespace alias - create shortcut
    double result2 = ML::square(3.0);    // Use alias instead of full name

    return 0;
}

// Namespace best practices for 42
namespace ft {  // Common to use 'ft' namespace in 42 for custom implementations
    template<typename T>
    class vector {
        // Custom vector implementation
    private:
        T* data;
        size_t size;
        size_t capacity;
    public:
        // Implementation...
    };

    template<typename T>
    class stack {
        // Custom stack implementation
    };
}

// In header file (.hpp) - AVOID this:
using namespace std;  // BAD in headers - pollutes global namespace for all includers

// In source file (.cpp) - OK but use sparingly:
int main() {
    using std::cout;     // GOOD - specific declaration
    using std::endl;     // GOOD - specific declaration
    // using namespace std;  // ACCEPTABLE in .cpp, but not recommended
    
    cout << "Hello World" << endl;  // Can use without std::
    return 0;
}
```

**Namespace Guidelines:**
- **Organization**: Group related functionality together
- **Name conflicts**: Prevent clashes between different libraries
- **Header files**: Never use `using namespace` in headers
- **Specific using**: Prefer `using std::cout;` over `using namespace std;`
- **Custom namespace**: Use `ft` namespace for 42 implementations
- **Nested namespaces**: Organize complex libraries hierarchically

### Performance & Safety Hints

| Keyword  | Purpose                       | Usage Guidelines                    | When to Use                         |
| -------- | ----------------------------- | ----------------------------------- | ----------------------------------- |
| inline   | Suggest function inlining     | `inline int getSize() const;`       | Small, frequently called functions  |
| explicit | Prevent implicit conversions  | `explicit MyClass(int value);`      | Single-argument constructors        |
| mutable  | Allow modification in const   | `mutable int cacheValue;`           | Caching, lazy evaluation           |

**Performance & Safety Deep Dive:**

```cpp
// inline keyword - performance optimization
class Vector3D {
private:
    double x, y, z;

public:
    // Inline functions - suggest compiler to inline for performance
    inline double getX() const { return x; }    // Small, frequently called
    inline double getY() const { return y; }    // Good candidates for inlining
    inline double getZ() const { return z; }

    // Inline member function (implicitly inline when defined in class)
    double magnitude() const {                  // Functions defined in class are inline
        return std::sqrt(x*x + y*y + z*z);
    }

    // Non-inline function for complex operations
    Vector3D crossProduct(const Vector3D& other) const;  // Declared but not defined here
};

// Inline function defined outside class
inline Vector3D Vector3D::crossProduct(const Vector3D& other) const {
    return Vector3D(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

// explicit keyword - prevent implicit conversions
class MyString {
private:
    char* data;
    size_t length;

public:
    // Explicit constructor prevents implicit conversions
    explicit MyString(size_t size) : length(size) {
        data = new char[size + 1];
        data[0] = '\0';
    }

    // Multi-parameter constructor - no need for explicit
    MyString(const char* str, size_t len) : length(len) {
        data = new char[len + 1];
        strncpy(data, str, len);
        data[len] = '\0';
    }

    ~MyString() { delete[] data; }
};

// Usage showing explicit keyword effect
void demonstrateExplicit() {
    MyString str1(10);                   // OK - direct initialization
    MyString str2 = MyString(20);        // OK - explicit constructor call

    // MyString str3 = 30;               // ERROR! explicit prevents implicit conversion
    // processString(40);                // ERROR! explicit prevents implicit conversion

    MyString str4(50);                   // OK - direct initialization
    processString(MyString(60));         // OK - explicit constructor call
}

void processString(const MyString& str) {
    // Function that takes MyString
}

// mutable keyword - logical const vs bitwise const
class ExpensiveCalculation {
private:
    int input;
    mutable int cachedResult;           // Can be modified even in const methods
    mutable bool resultCached;          // Can be modified even in const methods

public:
    ExpensiveCalculation(int value) : input(value), cachedResult(0), resultCached(false) {}

    // Const method that can modify mutable members
    int getExpensiveResult() const {
        if (!resultCached) {            // Check if we need to calculate
            // Simulate expensive calculation
            cachedResult = input * input * input;  // Can modify mutable member
            resultCached = true;                    // Can modify mutable member
            std::cout << "Expensive calculation performed" << std::endl;
        }
        return cachedResult;            // Return cached result
    }

    // Truly const method
    int getInput() const {
        return input;  // Cannot modify input or any non-mutable members
    }
};

// mutable usage example
int main() {
    const ExpensiveCalculation calc(5);  // const object

    // First call - calculation performed
    int result1 = calc.getExpensiveResult();  // "Expensive calculation performed"

    // Second call - cached result returned
    int result2 = calc.getExpensiveResult();  // No output - uses cache

    return 0;
}
```

**Performance & Safety Guidelines:**

**inline Rules:**
- **Use for**: Small functions (1-3 lines), getters/setters, frequently called functions
- **Avoid for**: Large functions, recursive functions, functions with loops
- **Compiler decision**: `inline` is a suggestion, compiler may ignore it
- **Header files**: Inline functions must be defined in headers (ODR - One Definition Rule)

**explicit Rules:**
- **Always use** for single-argument constructors (unless conversion is intended)
- **Prevents surprises**: No accidental type conversions
- **Better error messages**: Compilation fails instead of silent conversion
- **Not needed** for multi-parameter constructors (can't be used for implicit conversion)

**mutable Rules:**
- **Use sparingly**: Only for implementation details that don't affect logical state
- **Good for**: Caching, reference counting, mutex locks, lazy evaluation
- **Bad for**: Actual object state that users care about
- **Logical const**: Object appears unchanged to users, but implementation may cache data

---

## Type System & Utilities

### Additional Data Types

| Keyword  | Purpose                    | Usage Notes                          |
| -------- | -------------------------- | ------------------------------------ |
| long     | Long integer type          | `long timestamp = 1234567890L;`      |
| short    | Short integer type         | `short port = 8080;`                 |
| unsigned | Unsigned integer modifier  | `unsigned int count = 0u;`           |
| signed   | Signed integer modifier    | `signed char value = -128;`          |
| wchar_t  | Wide character type        | For internationalization             |

### Type Information & Manipulation

| Keyword | Purpose                      | Example Usage                        |
| ------- | ---------------------------- | ------------------------------------ |
| sizeof  | Get size of type/variable    | `sizeof(int)`, `sizeof(array)`       |
| typedef | Create type aliases          | `typedef std::string String;`       |
| typeid  | Runtime type information     | `typeid(obj).name()`                |
| enum    | Define enumerated type       | `enum Color { RED, GREEN, BLUE };`   |
| union   | Define union type            | `union Data { int i; float f; };`    |

### Special Keywords

| Keyword | Purpose                         | Usage Context                       |
| ------- | ------------------------------- | ----------------------------------- |
| friend  | Grant access to private members | `friend class MyFriend;`            |
| this    | Pointer to current object       | `this->member` or `return *this;`   |
| true    | Boolean true literal            | `bool flag = true;`                 |
| false   | Boolean false literal           | `bool flag = false;`                |

---

## Forbidden & Restricted Keywords in 42

### ❌ Strictly Forbidden

| Keyword | Reason                           | Alternative                        |
| ------- | -------------------------------- | ---------------------------------- |
| goto    | Poor programming practice        | Use proper control structures      |
| asm     | Assembly not allowed in 42       | Use C++ language features          |

### ⚠️ Use with Extreme Caution

| Keyword          | Issues                          | When Acceptable                    |
| ---------------- | ------------------------------- | ---------------------------------- |
| reinterpret_cast | Unsafe, breaks type system     | Almost never in 42 projects       |
| const_cast       | Breaks const correctness        | Only for legacy C function calls  |
| volatile         | Rarely needed                   | Hardware programming (not in 42)  |
| register         | Deprecated since C++11          | Let compiler optimize              |
| export           | Not supported by most compilers | Avoid completely                   |

---

## Modern C++ Keywords (NOT Available in 42)

These keywords exist in C++11 and later but **cannot be used** in 42 CPP modules:

| Keyword       | C++ Version | Purpose                             |
| ------------- | ----------- | ----------------------------------- |
| nullptr       | C++11       | Type-safe null pointer              |
| auto          | C++11       | Type inference                      |
| override      | C++11       | Explicit virtual function override  |
| final         | C++11       | Prevent inheritance/overriding      |
| constexpr     | C++11       | Compile-time constant expressions   |
| decltype      | C++11       | Type deduction from expressions     |
| static_assert | C++11       | Compile-time assertions             |
| noexcept      | C++11       | Exception specification             |
| thread_local  | C++11       | Thread-local storage                |
| alignas       | C++11       | Alignment specification             |
| alignof       | C++11       | Alignment query                     |
| char16_t      | C++11       | 16-bit Unicode character            |
| char32_t      | C++11       | 32-bit Unicode character            |

---

## Module-by-Module Keyword Introduction

### Module 00: Basic OOP
**New Keywords:** `class`, `public`, `private`, `const`, `static`
**Focus:** Class definition, access control, basic encapsulation

### Module 01: Memory Management
**New Keywords:** `new`, `delete`
**Focus:** Dynamic memory allocation, pointers vs references

### Module 02: Operator Overloading
**New Keywords:** `operator`, `static_cast`, `explicit`
**Focus:** Making classes behave like built-in types

### Module 03: Inheritance
**New Keywords:** `protected`, advanced `virtual` usage
**Focus:** Code reuse through inheritance

### Module 04: Polymorphism
**New Keywords:** `dynamic_cast`, pure virtual functions
**Focus:** Runtime polymorphism, abstract classes

### Module 05: Exceptions
**New Keywords:** `try`, `catch`, `throw`
**Focus:** Error handling mechanisms

### Module 06: Type Conversions
**New Keywords:** Advanced casting techniques
**Focus:** Safe and explicit type conversions

### Module 07-08: Templates
**New Keywords:** `template`, `typename`
**Focus:** Generic programming, code reuse

### Module 09: Containers
**New Keywords:** `namespace`, `using`, STL integration
**Focus:** Standard library usage, algorithms

---

## Best Practices Summary

### ✅ Always Do
1. **Use `const` everywhere possible** - methods, parameters, return values
2. **Make single-argument constructors `explicit`** - prevent accidental conversions
3. **Use `virtual` destructors** - in any class that might be inherited
4. **Prefer `static_cast`** - over C-style casts for safety
5. **Match every `new` with `delete`** - avoid memory leaks

### ⚠️ Be Careful With
1. **`static` members** - ensure proper initialization order
2. **`const_cast`** - only when interfacing with legacy C code
3. **`mutable`** - use only for truly implementation-specific details
4. **Multiple inheritance** - can lead to diamond problem

### ❌ Never Do
1. **Use `goto`** - forbidden in 42 style guidelines
2. **Use C-style casts** - `(type)value` is dangerous
3. **Forget virtual destructors** - causes memory leaks in inheritance
4. **Use raw pointers without ownership** - always know who deletes what

This reference covers all keywords you'll encounter in 42 CPP modules. Focus on understanding each keyword's purpose and proper usage patterns rather than memorizing syntax.
