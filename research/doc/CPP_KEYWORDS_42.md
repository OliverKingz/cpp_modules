# C++ Keywords for 42 School

This guide focuses specifically on C++ keywords relevant to the 42 School CPP modules curriculum.

## Overview

42 School CPP modules follow a progressive learning path. Here's what keywords you need to master for each stage:

---

## Must Know (Module 00-04)

**Essential for basic C++:**

### Object-Oriented Programming Core

```cpp
class, struct, public, private, protected
```

- **`class`** - Define classes (Module 00: PhoneBook, Module 04: Animal hierarchy)
- **`struct`** - Like class but default public access (rarely used in 42)
- **`public`** - Members accessible from outside the class
- **`private`** - Members only accessible within the class (encapsulation)
- **`protected`** - Members accessible in derived classes (inheritance)

**Why critical:** Every 42 CPP project uses classes. Understanding access specifiers is fundamental to proper encapsulation.

### Memory & Object Lifecycle

```cpp
const, static, virtual
```

- **`const`** - Immutable values/objects, const member functions
  - `const int MAX_SIZE = 8;` (PhoneBook)
  - `std::string getName() const;` (getter methods)
- **`static`** - Class-level members, not instance-level
  - `static const int MAX_CONTACTS = 8;` (shared by all instances)
- **`virtual`** - Enable polymorphism, virtual destructors
  - `virtual ~Animal() {}` (proper cleanup in inheritance)
  - `virtual void makeSound() = 0;` (pure virtual functions)

**Why critical:** `const` ensures data integrity, `static` manages class-wide data, `virtual` enables polymorphism (Module 04).

### Dynamic Memory Management

```cpp
new, delete
```

- **`new`** - Allocate memory on heap: `int* ptr = new int(42);`
- **`delete`** - Free heap memory: `delete ptr;` or `delete[] array;`

**Why critical:** Manual memory management is required in C++98. Every `new` must have matching `delete` to avoid memory leaks.

### Control Flow Fundamentals

```cpp
if, else, for, while, return
```

- **`if/else`** - Conditional execution
- **`for`** - Counting loops: `for(int i = 0; i < 8; i++)`
- **`while`** - Condition-based loops
- **`return`** - Exit function with/without value

**Why critical:** Basic program flow control needed in every project.

### Essential Data Types

```cpp
int, char, bool, float, double, void
```

- **`int`** - Integers for counters, IDs, calculations
- **`char`** - Single characters, C-strings
- **`bool`** - True/false values for flags, conditions
- **`float/double`** - Decimal numbers (prefer `double`)
- **`void`** - No return type for functions

**Why critical:** These are your basic building blocks for all data manipulation.

### Safe Type Conversion

```cpp
static_cast, const_cast, dynamic_cast
```

- **`static_cast`** - Safe compile-time conversions
  - `static_cast<float>(intValue)` (numeric conversion)
  - `static_cast<Derived*>(basePtr)` (safe upcast)
- **`const_cast`** - Remove const qualifier (use sparingly)
  - `const_cast<char*>(constString)` (for legacy C functions)
- **`dynamic_cast`** - Runtime type checking for polymorphism
  - `dynamic_cast<Dog*>(animalPtr)` (safe downcast)

**Why critical:** 42 forbids C-style casts. These provide type safety while allowing necessary conversions.

---

## Important for Later Modules (05-09)

**Advanced concepts:**

### Generic Programming (Module 07-08)

```cpp
template, typename
```

- **`template`** - Create generic classes/functions
  ```cpp
  template<typename T>
  class Array {
      T* data;
      // Works with any type T
  };
  ```
- **`typename`** - Template parameter declaration
  ```cpp
  template<typename T>  // T can be any type
  void function(T value);
  ```

**Why important:** Templates enable code reuse. One template works for `int`, `string`, custom classes, etc.

### Error Handling (Module 05-06)

```cpp
try, catch, throw
```

- **`try`** - Begin exception-handling block
- **`catch`** - Handle specific exception types
- **`throw`** - Raise an exception
  ```cpp
  try {
      if (index >= size)
          throw std::out_of_range("Index too big");
  }
  catch (const std::exception& e) {
      std::cout << "Error: " << e.what() << std::endl;
  }
  ```

**Why important:** Robust error handling instead of return codes. Required for many Module 05+ exercises.

### Code Organization

```cpp
namespace, using
```

- **`namespace`** - Organize code, prevent name conflicts
  ```cpp
  namespace ft {
      class vector { /* custom implementation */ };
  }
  ```
- **`using`** - Bring namespace items into scope
  ```cpp
  using std::cout;  // Now can use 'cout' instead of 'std::cout'
  using namespace std;  // Bring entire namespace (avoid in headers!)
  ```

**Why important:** Large projects need organization. Standard library is in `std` namespace.

### Performance & Design

```cpp
inline, explicit, operator
```

- **`inline`** - Suggest function inlining for performance
  ```cpp
  inline int getSize() const { return size; }  // Small, frequently called
  ```
- **`explicit`** - Prevent implicit conversions
  ```cpp
  explicit MyClass(int value);  // Prevents: MyClass obj = 42;
  ```
- **`operator`** - Overload operators for custom classes
  ```cpp
  MyClass operator+(const MyClass& other) const;  // Enable: obj1 + obj2
  ```

**Why important:** Fine-tune performance, prevent bugs, make classes behave like built-in types.

---

## Avoid in 42

**Forbidden or discouraged:**

### Strictly Forbidden

```cpp
goto          // Bad practice, jumps anywhere
asm           // Assembly not allowed in 42
```

### Discouraged/Restricted

```cpp
register      // Deprecated since C++11
reinterpret_cast  // Usually forbidden (unsafe)
```

### Use with Caution

```cpp
const_cast    // Only when absolutely necessary
mutable       // Rare use cases
volatile      // Usually not needed in 42 projects
```

---

## Quick Reference by Module

### Module 00 - First Steps

**Keywords needed:**

- `class`, `public`, `private`
- `const`, `static`
- `int`, `string`, `bool`, `void`
- `if`, `for`, `while`, `return`

**Example - PhoneBook:**

```cpp
class PhoneBook {
private:              // keyword: access specifier
    static const int MAX_CONTACTS = 8;  // keywords: static, const, int
public:               // keyword: access specifier
    void addContact();    // keywords: void
    bool searchContact(); // keywords: bool
};
```

### Module 01 - Memory, References, Pointers

**New keywords:**

- `new`, `delete`

**Example:**

```cpp
class Zombie {
private:
    std::string name;
public:
    Zombie(const std::string& name);  // const reference
    ~Zombie();                        // destructor
};

// Dynamic allocation
Zombie* zombie = new Zombie("Foo");
delete zombie;  // Don't forget!
```

### Module 02 - Ad-hoc Polymorphism, Operators

**New keywords:**

- `operator`
- `static_cast`

**Example:**

```cpp
class Fixed {
public:
    Fixed operator+(const Fixed& other) const;  // operator overloading
    operator float() const;                     // conversion operator
};
```

### Module 03 - Inheritance

**New keywords:**

- `protected` (now becomes important)

**Example:**

```cpp
class ClapTrap {
protected:             // accessible to derived classes
    std::string name;
public:
    virtual ~ClapTrap(); // virtual destructor
};

class ScavTrap : public ClapTrap {  // public inheritance
public:
    void guardGate();
};
```

### Module 04 - Subtype Polymorphism

**New keywords:**

- `virtual` (pure virtual functions)
- `dynamic_cast`

**Example:**

```cpp
class Animal {
public:
    virtual void makeSound() const = 0;  // pure virtual
    virtual ~Animal() {}                 // virtual destructor
};

class Dog : public Animal {
public:
    void makeSound() const {             // override
        std::cout << "Woof!" << std::endl;
    }
};

// Safe downcasting
Animal* animal = new Dog();
Dog* dog = dynamic_cast<Dog*>(animal);   // runtime check
```

### Module 05 - Exceptions

**New keywords:**

- `try`, `catch`, `throw`

**Example:**

```cpp
class Form {
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high!";
        }
    };

    void setGrade(int grade) {
        if (grade < 1)
            throw GradeTooHighException();  // throw keyword
    }
};

// Usage
try {                                    // try keyword
    form.setGrade(0);
}
catch (const std::exception& e) {        // catch keyword
    std::cout << e.what() << std::endl;
}
```

### Module 06-09 - Advanced Topics

**New keywords:**

- `template`, `typename` (Module 07-08)
- `namespace`, `using`
- `inline`, `explicit`

---

## Common 42 Mistakes to Avoid

### ❌ Forbidden Casts

```cpp
// NEVER do this in 42:
int* ptr = (int*)somePointer;        // C-style cast - FORBIDDEN
void* raw = reinterpret_cast<void*>(ptr);  // Usually forbidden

// Do this instead:
int* ptr = static_cast<int*>(somePointer);  // Safe cast
```

### ❌ Missing Virtual Destructors

```cpp
// BAD - memory leaks in polymorphism:
class Base {
public:
    ~Base() {}  // NOT virtual!
};

// GOOD - proper cleanup:
class Base {
public:
    virtual ~Base() {}  // Virtual destructor
};
```

### ❌ Memory Leaks

```cpp
// BAD - no matching delete:
int* arr = new int[10];
// ... forgot delete[]

// GOOD - proper cleanup:
int* arr = new int[10];
// ... use array
delete[] arr;  // Don't forget!
```

### ❌ Using Keywords as Names

```cpp
// ERROR - keywords can't be variable names:
int class = 5;     // 'class' is a keyword
int new = 10;      // 'new' is a keyword

// OK - case matters:
int Class = 5;     // Capital C, not the keyword
```

---

## 42 Best Practices

1. **Always use proper access specifiers** - `private` by default, `public` when needed
2. **Every `new` needs a `delete`** - manual memory management
3. **Virtual destructors in base classes** - prevents memory leaks
4. **Prefer `static_cast` over C-style casts** - type safety
5. **Use `const` everywhere possible** - data integrity
6. **Initialize everything** - avoid undefined behavior

---

## Progression Timeline

| Module | New Keywords                                    | Focus                |
| ------ | ----------------------------------------------- | -------------------- |
| 00     | `class`, `public`, `private`, `const`, `static` | Basic OOP            |
| 01     | `new`, `delete`                                 | Memory management    |
| 02     | `operator`, `static_cast`                       | Operator overloading |
| 03     | `protected` (important now)                     | Inheritance          |
| 04     | `virtual`, `dynamic_cast`                       | Polymorphism         |
| 05     | `try`, `catch`, `throw`                         | Exception handling   |
| 06     | Advanced casting                                | Type conversion      |
| 07-08  | `template`, `typename`                          | Generic programming  |
| 09     | STL containers                                  | Standard library     |

This progression ensures you learn keywords when you actually need them, building complexity gradually.

---

## Detailed Examples by Module Progression

### Module 00 Examples

#### `class` - Basic Class Definition

```cpp
// PhoneBook.hpp
class PhoneBook {
    // Class defines a new type
};
```

#### `public`, `private` - Access Specifiers

```cpp
class Contact {
private:                    // Only Contact can access these
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;

public:                     // Anyone can access these
    void setFirstName(const std::string& name);
    std::string getFirstName() const;
};
```

#### `const` - Constants and Const Methods

- When applied to a variable, `const` means its value cannot be changed after initialization.
- When combined with `static`, it creates a class-level constant.

```cpp
class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;  // Constant value

public:
    // Const method - doesn't modify object
    std::string getContact(int index) const;

    // Non-const method - can modify object
    void addContact(const Contact& contact);
};
```

#### `static` - Class-Level Members

- When applied to a class member variable or function, `static` means that the member belongs to the class itself, not to any particular instance.
- All instances of the class share the same static member.
- Example: `static int totalCreated;` counts the total number of `PhoneBook` objects created, shared across all instances.

```cpp
class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;  // Shared by all instances
    Contact contacts[MAX_CONTACTS];
    static int totalCreated;            // Count all PhoneBooks created

public:
    static int getTotalCreated() { return totalCreated; }
};

// In .cpp file
int PhoneBook::totalCreated = 0;
```

- Why is `totalCreated` static?
  - `totalCreated` is declared as `static` so that it keeps track of the total number of `PhoneBook` objects created, regardless of how many instances exist.
  - If it were not static, each `PhoneBook` instance would have its own separate `totalCreated` variable, which would not allow for a global count.

#### Basic Data Types: `int`, `bool`, `void`, `size_t`

- **`int`** - Represents integer values (whole numbers without decimals)
- **`bool`** - Represents boolean values (`true` or `false`)
- **`void`** - Represents "no type" or "no return value"
- **`size_t`** - Represents an unsigned integer type, typically used for sizes and counts

```cpp
class Utils {
public:
    // int - integer values for calculations, indices, counts
    static int stringToInt(const std::string& str);

    // bool - true/false return for validation functions
    static bool isValidName(const std::string& name);

    // void - no return value for action functions
    static void printError(const std::string& message);
};
```

- **Why use specific data types?**
  - `int` for numeric operations where you need whole numbers (array indices, counts, IDs)
  - `bool` for functions that need to return yes/no, valid/invalid, success/failure
  - `void` for functions that perform actions but don't need to return data

- **Key `size_t` Rules:**
  - **Use for**: Array indices, container sizes, loop counters with containers
  - **Don't use for**: Values that can be negative, small flags/enums, general arithmetic
  - **Be careful with**: Reverse loops (underflow), mixing with signed integers
  - **42 Context**: Good for contact counts, array indices, string lengths

#### Control Flow: `if`, `for`, `while`, `return`

- **`if`** - Conditional execution: runs code only when a condition is true
- **`for`** - Counting loops: repeats code a specific number of times
- **`while`** - Condition-based loops: repeats code while a condition remains true
- **`return`** - Exits a function, optionally returning a value

```cpp
bool PhoneBook::addContact(const Contact& contact) {
    // if - conditional execution
    if (contactCount >= MAX_CONTACTS) {
        return false;  // return - exit with value (failure)
    }

    // for - counting loop (when you know how many iterations)
    for (int i = 0; i < MAX_CONTACTS; i++) {
        if (contacts[i].isEmpty()) {
            contacts[i] = contact;
            return true;  // return - exit with value (success)
        }
    }

    // while - condition-based loop (when condition determines when to stop)
    int index = 0;
    while (index < MAX_CONTACTS && !contacts[index].isEmpty()) {
        index++;
    }

    return false;  // return - default exit value
}
```

- **When to use each:**
  - Use `for` when you know exactly how many times to loop
  - Use `while` when you need to loop until a condition changes
  - Use `if` for single conditional checks
  - Use `return` to exit functions early or provide results

---

### Module 01 Examples

#### `new`, `delete` - Dynamic Memory Management

- **`new`** - Allocates memory on the heap at runtime
- **`delete`** - Frees memory that was allocated with `new`
- **Heap vs Stack**: Stack memory is automatic (cleaned up when scope ends), heap memory is manual (you must clean it up)

```cpp
// Zombie.cpp
class Zombie {
private:
    std::string name;

public:
    Zombie(std::string name) : name(name) {}
    ~Zombie() { std::cout << name << " destroyed" << std::endl; }
    void announce();
};

// Creating zombies
Zombie* newZombie(std::string name) {
    return new Zombie(name);  // Allocate on heap - survives function scope
}

void randomChump(std::string name) {
    Zombie zombie(name);      // Allocate on stack - automatic cleanup
}

int main() {
    // Heap allocation - manual cleanup required
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;        // Must delete manually or memory leak!

    // Stack allocation - automatic cleanup
    randomChump("StackZombie");  // Zombie destroyed when function ends

    // Array allocation
    Zombie* horde = new Zombie[5];  // Allocate array on heap
    // ... use horde
    delete[] horde;           // Array delete - note the []

    return 0;
}
```

- **Critical Rules:**
  - Every `new` must have exactly one matching `delete`
  - Every `new[]` must have exactly one matching `delete[]`
  - Don't mix `new`/`delete[]` or `new[]`/`delete` - undefined behavior!
  - Memory allocated with `new` persists until you `delete` it

---

### Module 02 Examples

#### `operator` - Operator Overloading

- **`operator`** - Allows you to define how operators (+, -, ==, etc.) work with your custom classes
- **Why overload operators?** - Makes your classes behave like built-in types, improving readability
- **Common operators to overload**: arithmetic (+, -, *, /), comparison (==, !=, <, >), assignment (=), increment/decrement (++, --)

```cpp
// Fixed.hpp
class Fixed {
private:
    int rawValue;
    static const int fractionalBits = 8;

public:
    Fixed() : rawValue(0) {}
    Fixed(const int value) : rawValue(value << fractionalBits) {}

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

    // Comparison operators - return bool
    bool operator>(const Fixed& other) const {
        return this->rawValue > other.rawValue;
    }

    bool operator<(const Fixed& other) const {
        return this->rawValue < other.rawValue;
    }

    // Increment/decrement - two versions each
    Fixed& operator++() {        // Pre-increment: ++obj
        rawValue++;
        return *this;            // Return reference to modified object
    }

    Fixed operator++(int) {      // Post-increment: obj++
        Fixed temp(*this);       // Save current state
        rawValue++;              // Modify current object
        return temp;             // Return old state
    }
};

// Usage
int main() {
    Fixed a(5);
    Fixed b(3);

    Fixed sum = a + b;          // Calls a.operator+(b)
    bool greater = a > b;       // Calls a.operator>(b)
    ++a;                        // Calls a.operator++()
    b++;                        // Calls b.operator++(0)

    return 0;
}
```

- **Key Concepts:**
  - **const correctness**: Operators that don't modify the object should be `const`
  - **Return types**: Arithmetic operators return new objects, comparison returns `bool`
  - **Pre vs Post increment**: Pre-increment is more efficient (no temporary object)
  - **this pointer**: Refers to the current object in member functions

#### `static_cast` - Safe Type Conversion

- **`static_cast`** - Performs compile-time type conversions with safety checks
- **Why use it?** - Replaces dangerous C-style casts with explicit, safer alternatives
- **When to use**: Numeric conversions, inheritance upcasting, explicit conversions

```cpp
class Fixed {
public:
    Fixed(const float value) {
        // Convert float to fixed-point representation
        // static_cast ensures explicit conversion from float to int
        rawValue = static_cast<int>(roundf(value * (1 << fractionalBits)));
    }

    float toFloat() const {
        // Convert fixed-point back to float
        // static_cast makes the conversion explicit and safe
        return static_cast<float>(rawValue) / (1 << fractionalBits);
    }

    int toInt() const {
        // Convert fixed-point to integer (truncates fractional part)
        return rawValue >> fractionalBits;
    }
};
```

- **Advantages over C-style casts:**
  - **Explicit intent**: Shows exactly what conversion you're doing
  - **Compile-time checking**: Catches many conversion errors at compile time
  - **Searchable**: Easy to find all casts in code with grep
  - **42 compliant**: C-style casts `(int)value` are forbidden in 42

---

### Module 03 Examples

#### `protected` - Inheritance Access

- **`protected`** - Access level between `private` and `public`
- **Accessibility**: Only the class itself and its derived classes can access protected members
- **Why use protected?** - Allows inheritance while maintaining encapsulation from outside users

```cpp
// ClapTrap.hpp
class ClapTrap {
protected:                    // Accessible to derived classes but not outside users
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:
    ClapTrap(const std::string& name);
    virtual ~ClapTrap();      // Virtual destructor for proper inheritance cleanup

    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

// ScavTrap.hpp - Inherits from ClapTrap
class ScavTrap : public ClapTrap {
public:
    ScavTrap(const std::string& name);
    ~ScavTrap();

    void attack(const std::string& target);  // Override base class method
    void guardGate();                        // ScavTrap-specific function
};

// ScavTrap.cpp
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    // Can access protected members from base class
    this->hitPoints = 100;     // protected member - accessible here
    this->energyPoints = 50;   // protected member - accessible here
    this->attackDamage = 20;   // protected member - accessible here
}

void ScavTrap::attack(const std::string& target) {
    // Can use protected members directly (no getter functions needed)
    if (energyPoints > 0) {
        std::cout << "ScavTrap " << name << " attacks " << target;
        std::cout << " causing " << attackDamage << " damage!" << std::endl;
        energyPoints--;
    }
}
```

- **Access Comparison:**
  - **`private`**: Only the class itself can access
  - **`protected`**: The class and its derived classes can access
  - **`public`**: Everyone can access
- **Design principle**: Use `protected` for data that derived classes need but outside code shouldn't touch

---

### Module 04 Examples

#### `virtual` - Polymorphism and Pure Virtual Functions

- **`virtual`** - Enables polymorphism by allowing function overriding in derived classes
- **Pure virtual** (`= 0`) - Makes a class abstract (cannot be instantiated)
- **Virtual destructor** - Ensures proper cleanup in inheritance hierarchies

```cpp
// Animal.hpp - Abstract base class
class Animal {
protected:
    std::string type;

public:
    Animal();
    virtual ~Animal();                    // Virtual destructor - CRUCIAL for inheritance!

    virtual void makeSound() const = 0;   // Pure virtual - must be overridden
    virtual std::string getType() const; // Virtual - can be overridden
};

// Dog.hpp
class Dog : public Animal {
private:
    Brain* brain;  // Dog has a brain (composition)

public:
    Dog();
    Dog(const Dog& other);               // Copy constructor
    Dog& operator=(const Dog& other);    // Assignment operator
    virtual ~Dog();                      // Virtual destructor

    virtual void makeSound() const;      // Override pure virtual function
    Brain* getBrain() const;
};

// Dog.cpp
Dog::Dog() : Animal() {
    type = "Dog";
    brain = new Brain();  // Dynamic allocation
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
    delete brain;  // Clean up dynamic memory
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

// Usage demonstrating polymorphism
int main() {
    const int arraySize = 4;
    Animal* animals[arraySize];

    // Fill array with different animals
    for (int i = 0; i < arraySize / 2; i++) {
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; i++) {
        animals[i] = new Cat();
    }

    // Polymorphic behavior - calls the correct makeSound() for each animal type
    for (int i = 0; i < arraySize; i++) {
        animals[i]->makeSound();  // Virtual function call - runtime dispatch
    }

    // Proper cleanup - virtual destructors ensure correct destructor is called
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];  // Calls Dog::~Dog() or Cat::~Cat(), then Animal::~Animal()
    }

    return 0;
}
```

- **Key Concepts:**
  - **Runtime polymorphism**: Function called depends on actual object type, not pointer type
  - **Virtual table (vtable)**: Compiler creates table of virtual functions for each class
  - **Abstract classes**: Classes with pure virtual functions cannot be instantiated
  - **Virtual destructor rule**: Always make base class destructors virtual in inheritance hierarchies

#### `dynamic_cast` - Safe Downcasting

- **`dynamic_cast`** - Runtime type checking for safe downcasting in inheritance hierarchies
- **When to use**: Converting from base class pointer to derived class pointer
- **Safety**: Returns `nullptr` if the cast is invalid (unlike `static_cast`)

```cpp
// Safe downcasting in polymorphic hierarchy
void identifyAnimal(Animal* animal) {
    // Try to cast to Dog - runtime type checking
    Dog* dog = dynamic_cast<Dog*>(animal);
    if (dog != nullptr) {  // Cast succeeded - animal is actually a Dog
        std::cout << "This is a dog with brain!" << std::endl;
        dog->getBrain();  // Can safely call Dog-specific methods
        return;
    }

    // Try to cast to Cat - runtime type checking
    Cat* cat = dynamic_cast<Cat*>(animal);
    if (cat != nullptr) {  // Cast succeeded - animal is actually a Cat
        std::cout << "This is a cat with brain!" << std::endl;
        cat->getBrain();  // Can safely call Cat-specific methods
        return;
    }

    std::cout << "Unknown animal type" << std::endl;
}
```

- **How it works:**
  - **Runtime Type Information (RTTI)**: Compiler stores type information in objects
  - **Polymorphic classes only**: Works only with classes that have virtual functions
  - **Safe failure**: Returns `nullptr` for pointers, throws `std::bad_cast` for references
- **vs static_cast**: `static_cast` trusts you, `dynamic_cast` verifies at runtime

---

### Module 05 Examples

#### `try`, `catch`, `throw` - Exception Handling

- **`try`** - Defines a block where exceptions might occur
- **`catch`** - Handles specific types of exceptions
- **`throw`** - Raises an exception to signal an error condition
- **Why use exceptions?** - Better error handling than return codes, automatic stack unwinding

```cpp
// Bureaucrat.hpp
class Bureaucrat {
private:
    const std::string name;
    int grade;  // 1 (highest) to 150 (lowest)

public:
    Bureaucrat(const std::string& name, int grade);

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

    void incrementGrade();
    void decrementGrade();
    int getGrade() const { return grade; }
    const std::string& getName() const { return name; }
};

// Bureaucrat.cpp
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (grade < 1) {
        throw GradeTooHighException();    // throw - raise exception
    }
    if (grade > 150) {
        throw GradeTooLowException();     // throw - raise exception
    }
    this->grade = grade;
}

void Bureaucrat::incrementGrade() {
    if (grade <= 1) {
        throw GradeTooHighException();    // throw - signal error condition
    }
    grade--;  // Lower number = higher grade
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150) {
        throw GradeTooLowException();     // throw - signal error condition
    }
    grade++;  // Higher number = lower grade
}

// Usage with exception handling
int main() {
    try {                                      // try - monitor for exceptions
        Bureaucrat bob("Bob", 2);
        std::cout << bob.getName() << ", grade " << bob.getGrade() << std::endl;

        bob.incrementGrade();  // This works (grade becomes 1)
        std::cout << "After increment: " << bob.getGrade() << std::endl;

        bob.incrementGrade();  // This throws exception (can't go below 1)
    }
    catch (const Bureaucrat::GradeTooHighException& e) {  // catch - handle specific exception
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {   // catch - handle specific exception
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {                     // catch - handle any std::exception
        std::cout << "Caught general exception: " << e.what() << std::endl;
    }

    // Multiple try-catch blocks
    try {                                      // try - separate exception handling block
        Bureaucrat alice("Alice", 200);  // This will throw (grade too high)
    }
    catch (const std::exception& e) {          // catch - handle any exception
        std::cout << "Failed to create Alice: " << e.what() << std::endl;
    }

    return 0;
}
```

- **Exception Handling Principles:**
  - **RAII (Resource Acquisition Is Initialization)**: Exceptions trigger automatic cleanup
  - **Stack unwinding**: Local objects are destroyed automatically when exception is thrown
  - **Exception hierarchy**: Catch more specific exceptions before general ones
  - **what() method**: Standard way to get error message from exceptions

---

### Module 06 Examples

#### Advanced Casting Examples

```cpp
// Using const_cast to work with legacy C functions
void legacyCFunction(char* str) {
    // Some old C function that needs non-const char*
    std::cout << "Processing: " << str << std::endl;
}

void modernCppFunction(const std::string& str) {
    // Need to call legacy function with const string
    char* mutableStr = const_cast<char*>(str.c_str());
    legacyCFunction(mutableStr);  // Use const_cast sparingly!
}

// More static_cast examples
class Base {
public:
    virtual ~Base() {}
    virtual void baseMethod() { std::cout << "Base method" << std::endl; }
};

class Derived : public Base {
public:
    void baseMethod() override { std::cout << "Derived method" << std::endl; }
    void derivedOnlyMethod() { std::cout << "Derived only" << std::endl; }
};

void castingExamples() {
    // Numeric conversions
    int intValue = 42;
    double doubleValue = static_cast<double>(intValue);  // int to double
    float floatValue = static_cast<float>(doubleValue);  // double to float

    // Pointer conversions in inheritance
    Derived derivedObj;
    Base* basePtr = &derivedObj;  // Implicit upcast (safe)

    // Downcast using static_cast (compile-time, no safety check)
    Derived* derivedPtr = static_cast<Derived*>(basePtr);
    derivedPtr->derivedOnlyMethod();  // This works if basePtr really points to Derived

    // Safer downcast using dynamic_cast (runtime check)
    Derived* safeDerivedPtr = dynamic_cast<Derived*>(basePtr);
    if (safeDerivedPtr != nullptr) {
        safeDerivedPtr->derivedOnlyMethod();  // Safe to call
    }
}
```

---

### Module 07-08 Examples

#### `template`, `typename` - Generic Programming

- **`template`** - Defines generic code that works with multiple types
- **`typename`** - Declares template type parameters
- **Generic programming** - Write code once, use with many different types
- **Compile-time polymorphism** - Different from runtime polymorphism (virtual functions)

```cpp
// Array.hpp - Template class
template<typename T>  // template and typename keywords - T is a placeholder for any type
class Array {
private:
    T* data;          // T will be replaced with actual type (int, string, etc.)
    unsigned int size;

public:
    // Template constructor
    Array() : data(nullptr), size(0) {}

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

    // Copy constructor
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

    // Assignment operator
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

// Usage of templates
int main() {
    try {
        // Array of integers - T becomes int
        Array<int> intArray(5);  // Compiler generates Array<int> class
        for (unsigned int i = 0; i < intArray.getSize(); i++) {
            intArray[i] = i * 10;
        }

        // Array of strings - T becomes std::string
        Array<std::string> stringArray(3);  // Compiler generates Array<std::string> class
        stringArray[0] = "Hello";
        stringArray[1] = "World";
        stringArray[2] = "!";

        // Template function usage
        int x = 10, y = 20;
        swap<int>(x, y);  // Explicit template parameter specification
        swap(x, y);       // Template parameter deduction - compiler figures out T = int

        std::string str1 = "first", str2 = "second";
        swap(str1, str2); // Template parameter deduction - compiler figures out T = std::string

    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
```

- **Key Template Concepts:**
  - **Code generation**: Compiler creates separate code for each type used
  - **Type requirements**: Template code must work with the types you use it with
  - **Compile-time errors**: Template errors show up when you try to use incompatible types
  - **No runtime overhead**: Templates are resolved at compile time, not runtime

#### Advanced Template Features

```cpp
// Template specialization
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

// Function templates with multiple parameters
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {  // C++11 trailing return type
    return a + b;
}

// Template with non-type parameters
template<typename T, int SIZE>
class FixedArray {
private:
    T data[SIZE];

public:
    T& operator[](int index) { return data[index]; }
    const T& operator[](int index) const { return data[index]; }
    int size() const { return SIZE; }
};

// Usage
int main() {
    Container<int> intContainer;
    intContainer.process();      // "Processing generic type"

    Container<bool> boolContainer;
    boolContainer.process();     // "Processing bool type specially"

    auto result = add(3.14, 42); // Mix double and int

    FixedArray<int, 10> fixedArray;  // Array of 10 integers
    fixedArray[0] = 100;

    return 0;
}
```

---

### Advanced Keywords Examples

#### `namespace`, `using` - Code Organization

- **`namespace`** - Creates named scopes to organize code and prevent name conflicts
- **`using`** - Brings namespace elements into current scope
- **Why use namespaces?** - Avoid naming conflicts in large projects, organize related code

```cpp
// MyLibrary namespace
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
            for (char& c : result) {
                c = std::toupper(c);
            }
            return result;
        }
    }
}

// Usage examples
int main() {
    // Full namespace qualification - most explicit
    double result1 = MyLibrary::Math::square(5.0);
    std::cout << "Square: " << result1 << std::endl;

    // Using declaration for specific items
    using MyLibrary::Math::PI;           // using - bring specific symbol into scope
    using MyLibrary::Math::Calculator;   // using - bring specific class into scope

    std::cout << "PI = " << PI << std::endl;  // No namespace qualifier needed
    Calculator calc;                     // No namespace qualifier needed
    double sum = calc.add(10, 20);

    // Using directive for entire namespace
    using namespace MyLibrary::String;   // using namespace - bring all symbols into scope
    std::string upper = toUpper("hello world");  // No namespace qualifier needed

    // Alias for long namespace names
    namespace ML = MyLibrary::Math;      // namespace alias - create shortcut
    double result2 = ML::square(3.0);    // Use alias instead of full name

    return 0;
}
```

- **Namespace Best Practices:**
  - **Avoid `using namespace std;` in headers** - pollutes global namespace for all includers
  - **Use specific `using` declarations** - bring only what you need into scope
  - **Organize related functionality** - group related classes and functions together
  - **Prevent name conflicts** - especially important when using multiple libraries

#### `inline`, `explicit` - Performance and Safety

- **`inline`** - Suggests to compiler to replace function calls with function body (optimization)
- **`explicit`** - Prevents implicit type conversions and constructor calls
- **Performance vs Safety** - `inline` for speed, `explicit` for preventing bugs

```cpp
class Vector3D {
private:
    double x, y, z;

public:
    // Explicit constructor prevents implicit conversions
    explicit Vector3D(double value) : x(value), y(value), z(value) {}

    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

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

// Usage showing explicit keyword effect
void demonstrateExplicit() {
    Vector3D v1(1.0, 2.0, 3.0);     // OK - multi-parameter constructor
    Vector3D v2 = Vector3D(5.0);     // OK - explicit constructor call

    // Vector3D v3 = 5.0;            // ERROR! explicit prevents implicit conversion
    // doSomething(5.0);             // ERROR! explicit prevents implicit conversion

    Vector3D v4(5.0);                // OK - direct initialization
    doSomething(Vector3D(5.0));      // OK - explicit constructor call
}

void doSomething(const Vector3D& v) {
    std::cout << "Processing vector" << std::endl;
}
```

- **`inline` Benefits and Considerations:**
  - **Performance**: Eliminates function call overhead for small functions
  - **Compiler decision**: `inline` is a suggestion, compiler may ignore it
  - **Code bloat**: Inlining large functions can increase executable size
  - **Best for**: Small, frequently called functions (getters, simple calculations)

- **`explicit` Benefits:**
  - **Prevents surprises**: No accidental type conversions
  - **Clear intent**: Forces explicit constructor calls
  - **Safer code**: Reduces hard-to-find bugs from implicit conversions
  - **42 Best Practice**: Use `explicit` for single-parameter constructors

These examples show the progressive complexity and real-world usage of each keyword as you advance through the 42 CPP modules. Each example builds on previous knowledge while introducing new concepts appropriately.
