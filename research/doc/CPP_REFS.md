# References in C++

A **reference** is an **alias** (alternative name) for an existing variable. Think of it as a "nickname" for a variable—it's the same variable, just accessed through a different name.

## Key Characteristics

- **Must be initialized** when declared
- **Cannot be reassigned** to refer to another variable
- **No null references** (unlike pointers)
- **No arithmetic operations** (unlike pointers)
- **Same memory address** as the original variable

## Syntax

```cpp
int x = 42;
int &ref = x;    // ref is now an alias for x
```

## References vs. Pointers

| Aspect         | Reference       | Pointer                          |
| -------------- | --------------- | -------------------------------- |
| Initialization | Must initialize | Can declare without initializing |
| Reassignment   | Cannot reassign | Can point to different variables |
| Null values    | Cannot be null  | Can be null                      |
| Arithmetic     | No arithmetic   | Pointer arithmetic allowed       |
| Syntax         | Direct access   | Requires dereferencing (`*`)     |
| Memory         | No extra memory | Takes memory for address         |

## Examples

### Basic Usage

```cpp
int original = 10;
int &alias = original;    // alias refers to original

alias = 20;               // Changes original to 20
cout << original;         // Prints: 20
cout << &original;        // Same address
cout << &alias;           // Same address as original
```

### Function Parameters (Pass by Reference)

```cpp
// Without reference (pass by value)
void badSwap(int a, int b) {
		int temp = a;
		a = b;
		b = temp;           // Only swaps local copies!
}

// With reference (pass by reference)
void goodSwap(int &a, int &b) {
		int temp = a;
		a = b;
		b = temp;           // Swaps original variables!
}

// With pointers
void pointerSwap(int *a, int *b) {
		int temp = *a;
		*a = *b;
		*b = temp;          // Swaps original variables via pointers!
}

int main() {
		int x = 1, y = 2;

		badSwap(x, y);      // x and y unchanged
		cout << x << y;     // Prints: 12

		goodSwap(x, y);     // x and y are swapped
		cout << x << y;     // Prints: 21

		pointerSwap(&x, &y); // x and y are swapped again
		cout << x << y;     // Prints: 12
}
```

### Function Return References

```cpp
int& getArrayElement(int arr[], int index) {
		return arr[index];  // Returns reference to array element
}

int main() {
		int numbers[3] = {10, 20, 30};

		getArrayElement(numbers, 1) = 99;  // Can assign directly!
		cout << numbers[1];                // Prints: 99
}
```

### Const References (Very Common)

```cpp
void printString(const std::string &str) {  // Efficient: no copy
		cout << str;                            // Cannot modify str
}

int main() {
		string message = "Hello World";
		printString(message);  // No copy made, efficient!
}
```

## Common Use Cases

### 1. Efficient Parameter Passing

```cpp
// Bad: Makes a copy (expensive for large objects)
void processContact(Contact contact) { /* ... */ }

// Good: No copy, can modify original
void processContact(Contact &contact) { /* ... */ }

// Best: No copy, cannot modify (read-only)
void processContact(const Contact &contact) { /* ... */ }
```

### 2. Avoiding Copies

```cpp
// Expensive: Creates copy
string getName() {
		static string name = "John";
		return name;  // Copy returned
}

// Efficient: Returns reference
const string& getName() {
		static string name = "John";
		return name;  // No copy
}
```

## Reference Rules

### ✅ Valid

```cpp
int x = 5;
int &ref = x;           // OK: Initialized with variable
const int &cref = 10;   // OK: Const reference to literal
```

### ❌ Invalid

```cpp
int &ref;               // ERROR: Must initialize
int &ref = 5;           // ERROR: Cannot bind to literal (unless const)
int &ref = x;
ref = y;                // ERROR: Cannot reassign reference
```

## Memory Visualization

```cpp
int x = 42;
int &ref = x;
int *ptr = &x;
```

**Memory Layout:**

```
Variable x:    [42] at address 0x1000
Reference ref: [alias to 0x1000] (no extra memory)
Pointer ptr:   [0x1000] at address 0x2000
```

## Why Use References?

1. **Cleaner syntax** — no `*` or `->` needed
2. **Safety** — cannot be null, cannot be reassigned
3. **Efficiency** — no extra memory overhead
4. **Intent** — clearly shows you want to work with the original

---

# References vs Pointers vs Pass by Value: C++ Best Practices

Coming from C, you're used to pointers for everything. C++ gives you three ways to pass data to functions, each with specific use cases and benefits.

## The Three Ways to Pass Parameters

### 1. Pass by Value (Copy)

```cpp
void processContact(Contact contact) {  // Creates a copy
    contact.setName("Modified");        // Only modifies the copy
    // Original contact unchanged
}
```

### 2. Pass by Pointer (C-style)

```cpp
void processContact(Contact* contact) { // Passes address
    if (contact != nullptr) {           // Must check for null
        contact->setName("Modified");   // Modifies original via pointer
    }
}
```

### 3. Pass by Reference (C++ style)

```cpp
void processContact(Contact& contact) { // Passes reference (alias)
    contact.setName("Modified");        // Modifies original directly
    // No null check needed - references can't be null
}
```

## Decision Tree: When to Use What

### Use **Pass by Value** when:

- ✅ Parameter is a **small, primitive type** (`int`, `char`, `bool`, `float`)
- ✅ You want to **modify a copy** without affecting the original
- ✅ Function is **pure** (no side effects)

```cpp
// ✅ Good: Small types, no side effects
int add(int a, int b) {             // Pass by value for primitives
    return a + b;                   // Pure function
}

bool isValidGrade(int grade) {      // Pass by value for small types
    return grade >= 1 && grade <= 150;
}

// ✅ Good: Intentionally working with a copy
Contact createContactCopy(Contact original) {
    original.setName("Copy of " + original.getName());
    return original;                // Return modified copy
}
```

### Use **Pass by Reference** when:

- ✅ Parameter is a **large object** (classes, structs, containers)
- ✅ You want to **modify the original** object
- ✅ You **know the object exists** (not null)
- ✅ You want **clean, safe syntax**

```cpp
// ✅ Good: Large objects, modify original
void updateContact(Contact& contact) {          // No copy, modifies original
    std::string name = inputName("Enter name: ");
    contact.setName(name);                      // Clean syntax
}

// ✅ Good: Large objects, read-only (const reference)
void printContact(const Contact& contact) {    // No copy, cannot modify
    std::cout << contact.getName() << std::endl;
}

// ✅ Good: Efficient return of large objects
const std::string& Contact::getName() const {  // Return reference, no copy
    return firstName;
}
```

### Use **Pass by Pointer** when:

- ✅ Parameter **might be null** (optional parameter)
- ✅ You need **pointer arithmetic** (arrays, iteration)
- ✅ Working with **C-style APIs** or **legacy code**
- ✅ **Dynamic memory management** scenarios

```cpp
// ✅ Good: Optional parameter (might be null)
void processContact(Contact* contact = nullptr) {
    if (contact != nullptr) {               // Must check for null
        contact->setName("Processed");
    } else {
        std::cout << "No contact provided" << std::endl;
    }
}

// ✅ Good: C-style array processing
void processArray(int* arr, size_t size) { // Pointer for array access
    for (size_t i = 0; i < size; i++) {
        arr[i] *= 2;                        // Pointer arithmetic
    }
}

// ✅ Good: Dynamic memory management
Contact* createContact() {
    return new Contact();                   // Return pointer to heap object
}
```

## Comparison Table for C Programmers

| Aspect           | Pass by Value             | Pass by Reference    | Pass by Pointer        |
| ---------------- | ------------------------- | -------------------- | ---------------------- |
| **C Equivalent** | `func(int x)`             | _No equivalent_      | `func(int* x)`         |
| **Memory**       | Creates copy              | No copy (alias)      | No copy (address)      |
| **Null Safety**  | N/A                       | ✅ Cannot be null    | ❌ Can be null         |
| **Syntax**       | `obj.method()`            | `obj.method()`       | `obj->method()`        |
| **Reassignment** | ✅ Can change copy        | ❌ Cannot reassign   | ✅ Can point elsewhere |
| **Performance**  | ❌ Slow for large objects | ✅ Fast              | ✅ Fast                |
| **Intent**       | "Work with copy"          | "Work with original" | "Might be null/array"  |

## Best Practices for C++ (Coming from C)

### 1. **Prefer References over Pointers**

```cpp
// ❌ C-style (works but not idiomatic C++)
void cStyleFunction(Contact* contact) {
    if (contact != nullptr) {
        contact->setName("New Name");
    }
}

// ✅ C++ style (preferred)
void cppStyleFunction(Contact& contact) {
    contact.setName("New Name");        // Cleaner, safer
}
```

### 2. **Use const References for Read-Only Access**

```cpp
// ❌ Inefficient (creates copy)
void printContactBad(Contact contact) {         // Copy made
    std::cout << contact.getName() << std::endl;
}

// ✅ Efficient and safe
void printContactGood(const Contact& contact) { // No copy, cannot modify
    std::cout << contact.getName() << std::endl;
}
```

### 3. **Use References for Member Functions**

```cpp
class PhoneBook {
public:
    // ✅ Good: Reference for input, no copy
    void addContact(const Contact& newContact) {
        contactList[contactCount] = newContact;
        contactCount++;
    }

    // ✅ Good: Reference return for chain operations
    Contact& getContact(size_t index) {
        return contactList[index];
    }

    // ✅ Good: const reference return for getters
    const Contact& getContact(size_t index) const {
        return contactList[index];
    }
};
```

### 4. **When You Still Need Pointers**

```cpp
class PhoneBook {
private:
    Contact* dynamicContacts;   // ✅ Good: Dynamic array
    size_t capacity;
    size_t count;

public:
    PhoneBook(size_t maxContacts) : capacity(maxContacts), count(0) {
        dynamicContacts = new Contact[capacity];  // ✅ Pointer needed for new[]
    }

    ~PhoneBook() {
        delete[] dynamicContacts;   // ✅ Pointer needed for delete[]
    }

    // ✅ Good: Optional search result
    Contact* findContact(const std::string& name) {
        for (size_t i = 0; i < count; i++) {
            if (dynamicContacts[i].getName() == name) {
                return &dynamicContacts[i];     // Return pointer (might be null)
            }
        }
        return nullptr;             // Not found
    }
};
```

## Migration Guide: C → C++

### What to Change:

1. **Function Parameters:**

   ```cpp
   // C style
   void func(MyStruct* s) { s->field = value; }

   // C++ style
   void func(MyStruct& s) { s.field = value; }
   ```

2. **Function Returns:**

   ```cpp
   // C style
   MyStruct* getStruct() { return &globalStruct; }

   // C++ style
   const MyStruct& getStruct() { return globalStruct; }
   ```

3. **Optional Parameters:**

   ```cpp
   // Keep C style for optional/nullable
   void processOptional(MyStruct* s = nullptr) {
       if (s != nullptr) { /* use s */ }
   }

   // Or use better C++ alternatives (std::optional in C++17)
   void processRequired(MyStruct& s) { /* s guaranteed to exist */ }
   ```

### What to Keep:

1. **Dynamic Memory:** Still use pointers with `new`/`delete`
2. **Arrays:** C-style arrays still use pointer syntax
3. **Legacy APIs:** When interfacing with C libraries

## Summary for 42 Projects

For your PhoneBook project and beyond:

```cpp
class Contact {
private:
    std::string firstName;

public:
    // ✅ Pass by const reference (read-only, efficient)
    void setFirstName(const std::string& name) {
        firstName = name;
    }

    // ✅ Return const reference (efficient, safe)
    const std::string& getFirstName() const {
        return firstName;
    }
};

class PhoneBook {
public:
    // ✅ Pass by const reference (efficient input)
    void addContact(const Contact& newContact) {
        // Implementation
    }

    // ✅ Return reference (allows modification)
    Contact& getContact(size_t index) {
        return contactList[index];
    }

    // ✅ Return const reference (read-only access)
    const Contact& getContact(size_t index) const {
        return contactList[index];
    }
};
```

**Golden Rule:** Use references by default, pointers only when you need null/optional semantics or dynamic memory management.

## 42 Project Tips

```cpp
// In your Contact class methods:
void setFirstName(const string &name) {  // Efficient input
		firstName = name;
}

const string& getFirstName() const {     // Efficient output
		return firstName;
}

// In PhoneBook methods:
void addContact(const Contact &contact) { // No copy
		contactList[contactCount] = contact;
}
```

## Advanced Reference Patterns

### Reference Wrappers (C++11)

When you need to store references in containers or pass them as template arguments:

```cpp
#include <functional>
#include <vector>

void workWithReferences() {
    int a = 1, b = 2, c = 3;

    // Cannot store references directly in containers
    // std::vector<int&> refs;  // ERROR!

    // Use reference_wrapper instead
    std::vector<std::reference_wrapper<int>> refs;
    refs.push_back(std::ref(a));
    refs.push_back(std::ref(b));
    refs.push_back(std::ref(c));

    // Access the referenced values
    for (auto& ref : refs) {
        ref.get() *= 2;  // Modifies original variables
    }
}
```

### Forwarding References (C++11)

For perfect forwarding in template functions:

```cpp
template<typename T>
void forwardingFunction(T&& param) {  // Forwarding reference
    // Forwards param to another function preserving its value category
    anotherFunction(std::forward<T>(param));
}
```

### Dangling References (Common Pitfall)

Never return references to local variables:

```cpp
// ❌ DANGEROUS - Dangling reference
const std::string& dangerousFunction() {
    std::string local = "This will be destroyed";
    return local;  // Returns reference to destroyed object!
}

// ✅ SAFE - Return by value instead
std::string safeFunction() {
    std::string local = "This is safe";
    return local;  // Copy returned
}

// ✅ SAFE - Return reference to member or static
class MyClass {
private:
    std::string member;
public:
    const std::string& getMember() const {
        return member;  // Safe - member outlives function call
    }
};
```

### Reference Initialization Rules

```cpp
void referenceRules() {
    int x = 42;
    const int cx = 100;

    // ✅ Valid reference bindings
    int& r1 = x;                    // Non-const ref to non-const variable
    const int& r2 = x;              // Const ref to non-const variable
    const int& r3 = cx;             // Const ref to const variable
    const int& r4 = 42;             // Const ref to literal (temporary)

    // ❌ Invalid reference bindings
    // int& r5 = cx;                // Non-const ref to const variable
    // int& r6 = 42;                // Non-const ref to literal
    // int& r7 = x + 1;             // Non-const ref to temporary
}
```
