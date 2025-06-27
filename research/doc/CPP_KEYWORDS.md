# C++ Keywords

**Keywords** are reserved words in C++ that have special meaning to the compiler. They cannot be used as identifiers (variable names, function names, etc.) because they are part of the language syntax.

## What Are Keywords?

Keywords are predefined, reserved words that:

- Have specific meaning to the C++ compiler
- Cannot be used as variable names, function names, or other identifiers
- Are case-sensitive (e.g., `int` is a keyword, but `Int` is not)
- Form the basic building blocks of C++ syntax

---

## Complete List of C++ Keywords

### Data Types

| Keyword    | Description                     | Example                       |
| ---------- | ------------------------------- | ----------------------------- |
| `bool`     | Boolean data type               | `bool isValid = true;`        |
| `char`     | Character data type             | `char letter = 'A';`          |
| `double`   | Double-precision floating point | `double pi = 3.14159;`        |
| `float`    | Single-precision floating point | `float rate = 2.5f;`          |
| `int`      | Integer data type               | `int count = 42;`             |
| `long`     | Long integer modifier           | `long bigNumber = 123456L;`   |
| `short`    | Short integer modifier          | `short small = 100;`          |
| `signed`   | Signed integer modifier         | `signed int value = -10;`     |
| `unsigned` | Unsigned integer modifier       | `unsigned int positive = 10;` |
| `void`     | No type/no return value         | `void function();`            |
| `wchar_t`  | Wide character type             | `wchar_t wide = L'λ';`        |

### Storage Classes & Qualifiers

| Keyword    | Description                          | Example                 |
| ---------- | ------------------------------------ | ----------------------- |
| `auto`     | Automatic type deduction (C++11)     | `auto x = 42;`          |
| `const`    | Constant qualifier                   | `const int MAX = 100;`  |
| `extern`   | External linkage                     | `extern int globalVar;` |
| `mutable`  | Allows modification in const objects | `mutable int counter;`  |
| `register` | Register storage hint (deprecated)   | `register int fast;`    |
| `static`   | Static storage duration              | `static int count = 0;` |
| `volatile` | Prevents compiler optimization       | `volatile int flag;`    |

### Control Flow

| Keyword    | Description              | Example                       |
| ---------- | ------------------------ | ----------------------------- |
| `break`    | Exit from loop or switch | `break;`                      |
| `case`     | Switch case label        | `case 1: return true;`        |
| `continue` | Skip to next iteration   | `continue;`                   |
| `default`  | Default case in switch   | `default: return false;`      |
| `do`       | Do-while loop            | `do { } while(condition);`    |
| `else`     | Alternative condition    | `else { }`                    |
| `for`      | For loop                 | `for(int i = 0; i < 10; i++)` |
| `goto`     | Jump to label (avoid!)   | `goto label;`                 |
| `if`       | Conditional statement    | `if(condition) { }`           |
| `return`   | Return from function     | `return value;`               |
| `switch`   | Multi-way branch         | `switch(variable) { }`        |
| `while`    | While loop               | `while(condition) { }`        |

### Object-Oriented Programming

| Keyword     | Description                     | Example                       |
| ----------- | ------------------------------- | ----------------------------- |
| `class`     | Define a class                  | `class MyClass { };`          |
| `struct`    | Define a structure              | `struct Point { int x, y; };` |
| `enum`      | Define enumeration              | `enum Color { RED, GREEN };`  |
| `namespace` | Define namespace                | `namespace MyNamespace { }`   |
| `private`   | Private access specifier        | `private: int data;`          |
| `protected` | Protected access specifier      | `protected: int value;`       |
| `public`    | Public access specifier         | `public: void method();`      |
| `friend`    | Grant access to private members | `friend class Helper;`        |
| `inline`    | Inline function hint            | `inline int getX() { }`       |
| `virtual`   | Virtual function                | `virtual void draw();`        |
| `this`      | Pointer to current object       | `this->member;`               |

### Memory Management

| Keyword  | Description                 | Example                   |
| -------- | --------------------------- | ------------------------- |
| `new`    | Dynamic memory allocation   | `int* ptr = new int(42);` |
| `delete` | Dynamic memory deallocation | `delete ptr;`             |
| `sizeof` | Size of type/variable       | `sizeof(int);`            |

### Type Casting

| Keyword            | Description            | Example                        |
| ------------------ | ---------------------- | ------------------------------ |
| `const_cast`       | Remove const qualifier | `const_cast<int&>(constVar)`   |
| `dynamic_cast`     | Safe polymorphic cast  | `dynamic_cast<Derived*>(base)` |
| `reinterpret_cast` | Low-level cast         | `reinterpret_cast<int*>(ptr)`  |
| `static_cast`      | Compile-time cast      | `static_cast<float>(intVar)`   |

### Exception Handling

| Keyword | Description                    | Example                              |
| ------- | ------------------------------ | ------------------------------------ |
| `try`   | Begin exception handling block | `try { }`                            |
| `catch` | Handle exceptions              | `catch(const std::exception& e)`     |
| `throw` | Throw an exception             | `throw std::runtime_error("error");` |

### Templates & Advanced

| Keyword    | Description                 | Example                           |
| ---------- | --------------------------- | --------------------------------- |
| `template` | Define template             | `template<typename T>`            |
| `typename` | Template parameter          | `typename T::value_type`          |
| `typedef`  | Type alias                  | `typedef int Integer;`            |
| `union`    | Union type                  | `union Data { int i; float f; };` |
| `using`    | Using declaration/directive | `using std::cout;`                |

### Operators as Keywords

| Keyword  | Description        | Equivalent |
| -------- | ------------------ | ---------- |
| `and`    | Logical AND        | `&&`       |
| `or`     | Logical OR         | `\|\|`     |
| `not`    | Logical NOT        | `!`        |
| `bitand` | Bitwise AND        | `&`        |
| `bitor`  | Bitwise OR         | `\|`       |
| `xor`    | Bitwise XOR        | `^`        |
| `compl`  | Bitwise complement | `~`        |

### Miscellaneous

| Keyword    | Description                  | Example                     |
| ---------- | ---------------------------- | --------------------------- |
| `asm`      | Inline assembly              | `asm("nop");`               |
| `explicit` | Prevent implicit conversions | `explicit MyClass(int x);`  |
| `operator` | Operator overloading         | `operator+(const T& other)` |
| `typeid`   | Runtime type information     | `typeid(variable).name()`   |

---

## Keywords by C++ Standard

### C++98/03 Core Keywords

Most keywords were available in the original C++ standard, including:

- All data types (`int`, `char`, `bool`, etc.)
- All control flow (`if`, `for`, `while`, etc.)
- All OOP keywords (`class`, `public`, `virtual`, etc.)
- All casting operators (`static_cast`, etc.)

### C++11 Additions

- `auto` (repurposed for type deduction)
- `constexpr` (constant expressions)
- `decltype` (deduce type)
- `nullptr` (null pointer literal)
- `static_assert` (compile-time assertions)
- `thread_local` (thread-local storage)

### C++14/17/20 Additions

- `alignas`, `alignof` (C++11)
- `noexcept` (C++11)
- `consteval`, `constinit` (C++20)
- `concept`, `requires` (C++20)
- `co_await`, `co_yield`, `co_return` (C++20 coroutines)

---

## Usage in Different Contexts

### Modern C++ (C++11 and later)

Modern C++ introduced many new keywords that make programming easier and safer:

- `auto` for type deduction
- `nullptr` for null pointers
- `constexpr` for compile-time constants
- `override` and `final` for better inheritance control

### Legacy C++ (C++98/03)

Older C++ standards have fewer keywords but form the foundation:

- Manual memory management with `new`/`delete`
- Basic OOP with `class`, `public`, `private`, `virtual`
- Exception handling with `try`/`catch`/`throw`

### Template Programming

Advanced C++ relies heavily on template-related keywords:

- `template` for generic programming
- `typename` for dependent types
- `concept` and `requires` (C++20) for constrained templates

---

## Common Mistakes

### ❌ Using Keywords as Identifiers

```cpp
int class = 5;     // ERROR: 'class' is a keyword
int new = 10;      // ERROR: 'new' is a keyword
int Public = 20;   // OK: Capital P, not the keyword 'public'
```

### ❌ Case Sensitivity

```cpp
Int x = 5;         // ERROR: 'Int' is not a keyword (should be 'int')
Class MyClass {};  // ERROR: 'Class' is not a keyword (should be 'class')
```

### ❌ Keyword Variations

```cpp
integer x = 5;     // ERROR: 'integer' is not a keyword (should be 'int')
boolean flag;      // ERROR: 'boolean' is not a keyword (should be 'bool')
```

---

## Best Practices

1. **Never use keywords as identifiers** - the compiler will give you an error
2. **Be aware of reserved words** - even if not currently keywords, avoid future conflicts
3. **Use meaningful names** - don't try to use names that are "almost" keywords
4. **Stay consistent** - use the same keywords throughout your project
5. **Know your standard** - different C++ standards have different keywords available

---

## Quick Examples

### Basic Class Definition

```cpp
class MyClass {
private:              // keyword: access specifier
    static const int MAX_SIZE = 100;  // keywords: static, const, int
    int data;
public:               // keyword: access specifier
    void setData(int value);    // keywords: void, int
    bool isValid() const;       // keywords: bool, const
};
```

### Template Usage

```cpp
template<typename T>     // keywords: template, typename
class Container {
private:
    T* data;            // T is template parameter
public:
    explicit Container(int size) : data(new T[size]) {}  // keywords: explicit, new
    ~Container() { delete[] data; }                      // keyword: delete
};
```

### Exception Handling

```cpp
try {                    // keyword: try
    throw std::runtime_error("Something went wrong");  // keyword: throw
}
catch (const std::exception& e) {   // keywords: catch, const
    std::cout << "Error: " << e.what() << std::endl;
}
```
