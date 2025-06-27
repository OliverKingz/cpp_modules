## Data Types in C++

| Data Type | Size         | Description                                              |
| --------- | ------------ | -------------------------------------------------------- |
| `bool`    | 1 byte       | Stores `true` or `false` values                          |
| `char`    | 1 byte       | Stores a single character/letter/number (ASCII values)   |
| `int`     | 2 or 4 bytes | Stores whole numbers, without decimals                   |
| `float`   | 4 bytes      | Stores fractional numbers (6-7 decimal digits precision) |
| `double`  | 8 bytes      | Stores fractional numbers (15 decimal digits precision)  |

### `float` vs. `double`

- **Precision**:
  - `float`: ~6-7 decimal digits
  - `double`: ~15 decimal digits
- **Best Practice**: Prefer `double` for most calculations due to higher precision.

---

# Casting in C++98

| Cast                   | Use Case                     | Safety        | 42 Allowed? |
| ---------------------- | ---------------------------- | ------------- | ----------- |
| **C-style**            | Quick conversions            | Unsafe        | ❌ Avoid    |
| **`static_cast`**      | Numeric, inheritance (safe)  | Compile-time  | ✅ Yes      |
| **`const_cast`**       | Remove `const`               | Risky         | ❗ Rarely   |
| **`reinterpret_cast`** | Low-level pointer hacking    | Very unsafe   | ❌ No       |
| **`dynamic_cast`**     | Safe polymorphic downcasting | Runtime-check | ✅ Yes      |

### **Best Practices**

1. **Prefer `static_cast`** for most conversions (e.g., `int` → `float`).
2. **Avoid `reinterpret_cast`** (forbidden in most modules).
3. **Never use C-style casts** (they bypass compiler checks).
4. **Use `dynamic_cast` sparingly** (only when polymorphism is needed).

---

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

int main() {
		int x = 1, y = 2;

		badSwap(x, y);      // x and y unchanged
		cout << x << y;     // Prints: 12

		goodSwap(x, y);     // x and y are swapped
		cout << x << y;     // Prints: 21
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
