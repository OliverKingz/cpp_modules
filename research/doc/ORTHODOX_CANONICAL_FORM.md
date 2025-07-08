# Orthodox Canonical Form (OCF) in C++

## Table of Contents

1. [What is Orthodox Canonical Form?](#what-is-orthodox-canonical-form)
2. [The Four Required Functions](#the-four-required-functions)
3. [Default Constructor](#1-default-constructor)
4. [Copy Constructor](#2-copy-constructor)
5. [Copy Assignment Operator](#3-copy-assignment-operator)
6. [Destructor](#4-destructor)
7. [Complete Examples](#complete-examples)
8. [Common Pitfalls](#common-pitfalls)
9. [Best Practices](#best-practices)

---

## What is Orthodox Canonical Form?

The **Orthodox Canonical Form** is a set of four essential member functions that every well-designed C++ class should implement. This ensures proper:

- **Object construction**
- **Object copying**
- **Object assignment**
- **Object destruction**

### Why is OCF Important?

Without OCF, your class may suffer from:

- **Memory leaks** (improper cleanup)
- **Double deletion** (destroying same memory twice)
- **Shallow copying** (multiple objects sharing same memory)
- **Undefined behavior** (accessing invalid memory)

---

## The Four Required Functions

### 1. **Default Constructor**

### 2. **Copy Constructor**

### 3. **Copy Assignment Operator**

### 4. **Destructor**

---

## 1. Default Constructor

### **Purpose**

Creates an object with default/initial values.

### **Syntax**

```cpp
ClassName();
ClassName() : member1(value1), member2(value2) {}  // Initialization list
```

### **Key Points**

- Called when object is created without arguments
- Should initialize ALL member variables
- Use initialization lists for better performance
- Should never throw exceptions if possible

### **Examples**

#### Simple Default Constructor

```cpp
class Student {
private:
    std::string _name;
    int _age;
    double _gpa;

public:
    // Default constructor
    Student() : _name("Unknown"), _age(0), _gpa(0.0) {
        std::cout << "Default constructor called" << std::endl;
    }
};

// Usage
Student student1;  // Calls default constructor
```

#### Default Constructor with Dynamic Memory

```cpp
class DynamicString {
private:
    char* _data;
    size_t _length;

public:
    // Default constructor
    DynamicString() : _data(NULL), _length(0) {
        std::cout << "Default constructor: empty string created" << std::endl;
    }
};
```

#### Multiple Constructors (Overloading)

```cpp
class Rectangle {
private:
    double _width;
    double _height;

public:
    // Default constructor
    Rectangle() : _width(1.0), _height(1.0) {}

    // Parameterized constructor
    Rectangle(double w, double h) : _width(w), _height(h) {}

    // Single parameter constructor
    Rectangle(double side) : _width(side), _height(side) {}
};
```

---

## 2. Copy Constructor

### **Purpose**

Creates a new object as a copy of an existing object.

### **Syntax**

```cpp
ClassName(const ClassName& other);
```

### **Key Points**

- Called when object is initialized with another object
- Takes a **const reference** to avoid infinite recursion
- Must perform **deep copy** for dynamic memory
- Called in: initialization, function parameters, return values

### **When Copy Constructor is Called**

```cpp
Student s1("John", 20);
Student s2(s1);        // Copy constructor called
Student s3 = s1;       // Copy constructor called (NOT assignment!)
func(s1);             // Copy constructor called (parameter passing)
return s1;            // Copy constructor called (return by value)
```

### **Examples**

#### Simple Copy Constructor

```cpp
class Point {
private:
    int _x, _y;

public:
    Point() : _x(0), _y(0) {}

    // Copy constructor
    Point(const Point& other) : _x(other._x), _y(other._y) {
        std::cout << "Copy constructor called" << std::endl;
    }
};
```

#### Deep Copy with Dynamic Memory

```cpp
class DynamicArray {
private:
    int* _array;
    size_t _size;

public:
    DynamicArray() : _array(NULL), _size(0) {}

    // Copy constructor - DEEP COPY
    DynamicArray(const DynamicArray& other) : _size(other._size) {
        if (other._array && _size > 0) {
            _array = new int[_size];  // Allocate new memory
            for (size_t i = 0; i < _size; ++i) {
                _array[i] = other._array[i];  // Copy each element
            }
            std::cout << "Deep copy performed" << std::endl;
        } else {
            _array = NULL;
        }
    }

    ~DynamicArray() {
        delete[] _array;
    }
};
```

#### Shallow vs Deep Copy Comparison

```cpp
// WRONG - Shallow Copy (DON'T DO THIS!)
DynamicArray(const DynamicArray& other) : _size(other._size) {
    _array = other._array;  // DANGER: Both objects point to same memory!
}

// CORRECT - Deep Copy
DynamicArray(const DynamicArray& other) : _size(other._size) {
    if (other._array && _size > 0) {
        _array = new int[_size];  // NEW memory allocation
        for (size_t i = 0; i < _size; ++i) {
            _array[i] = other._array[i];  // Copy values, not pointers
        }
    } else {
        _array = NULL;
    }
}
```

---

## 3. Copy Assignment Operator

### **Purpose**

Assigns the contents of one existing object to another existing object.

### **Syntax**

```cpp
ClassName& operator=(const ClassName& other);
```

### **Key Points**

- Called when using `=` on existing objects
- Must handle **self-assignment** (`obj = obj`)
- Must clean up existing resources before copying
- Returns reference to `*this` for chaining
- Must perform deep copy for dynamic memory

### **Assignment vs Copy Constructor**

```cpp
Student s1("John", 20);
Student s2(s1);        // Copy constructor (creating new object)
Student s3;            // Default constructor
s3 = s1;              // Assignment operator (existing object)
```

### **Examples**

#### Simple Assignment Operator

```cpp
class Point {
private:
    int _x, _y;

public:
    Point() : _x(0), _y(0) {}
    Point(const Point& other) : _x(other._x), _y(other._y) {}

    // Assignment operator
    Point& operator=(const Point& other) {
        std::cout << "Assignment operator called" << std::endl;

        if (this != &other) {  // Self-assignment check
            _x = other._x;
            _y = other._y;
        }
        return *this;  // Return reference for chaining
    }
};

// Usage
Point p1(5, 10);
Point p2;
p2 = p1;          // Assignment operator called
Point p3 = p2 = p1;  // Chaining: p2 = p1, then p3 = p2
```

#### Assignment with Dynamic Memory

```cpp
class DynamicString {
private:
    char* _data;
    size_t _length;

public:
    DynamicString() : _data(NULL), _length(0) {}

    // Assignment operator
    DynamicString& operator=(const DynamicString& other) {
        std::cout << "Assignment operator called" << std::endl;

        if (this != &other) {  // Self-assignment protection
            // Step 1: Clean up existing resources
            delete[] _data;

            // Step 2: Copy new data
            _length = other._length;
            if (other._data && _length > 0) {
                _data = new char[_length + 1];
                strcpy(_data, other._data);
            } else {
                _data = NULL;
            }
        }
        return *this;
    }

    ~DynamicString() {
        delete[] _data;
    }
};
```

#### Self-Assignment Example

```cpp
DynamicString str("Hello");
str = str;  // Self-assignment - must be handled safely!

// Without self-assignment check:
DynamicString& operator=(const DynamicString& other) {
    delete[] _data;        // Destroys str's data
    _data = other._data;   // other._data is now invalid! CRASH!
    return *this;
}

// With self-assignment check (CORRECT):
DynamicString& operator=(const DynamicString& other) {
    if (this != &other) {  // Check if same object
        delete[] _data;
        // ... copy logic
    }
    return *this;
}
```

---

## 4. Destructor

### **Purpose**

Cleans up resources when object is destroyed.

### **Syntax**

```cpp
~ClassName();
```

### **Key Points**

- Called automatically when object goes out of scope
- Should release ALL acquired resources
- Should never throw exceptions
- Only one destructor per class (no overloading)
- Called in reverse order of construction

### **When Destructor is Called**

```cpp
{
    Student s1;        // Constructor called
    Student s2;        // Constructor called
}                     // s2 destructor, then s1 destructor called
```

### **Examples**

#### Simple Destructor

```cpp
class FileHandler {
private:
    std::string _filename;

public:
    FileHandler(const std::string& filename) : _filename(filename) {
        std::cout << "Opening file: " << _filename << std::endl;
    }

    // Destructor
    ~FileHandler() {
        std::cout << "Closing file: " << _filename << std::endl;
        // Close file resources here
    }
};
```

#### Destructor with Dynamic Memory

```cpp
class DynamicArray {
private:
    int* _array;
    size_t _size;

public:
    DynamicArray() : _array(NULL), _size(0) {}

    DynamicArray(size_t size) : _size(size) {
        _array = new int[_size];
        std::cout << "Allocated array of size " << _size << std::endl;
    }

    // Destructor
    ~DynamicArray() {
        delete[] _array;  // Free allocated memory
        std::cout << "Array memory freed" << std::endl;
    }
};
```

#### Multiple Resource Management

```cpp
class ResourceManager {
private:
    char* _buffer;
    FILE* _file;
    int* _numbers;

public:
    ResourceManager() : _buffer(NULL), _file(NULL), _numbers(NULL) {}

    // Destructor cleans up ALL resources
    ~ResourceManager() {
        delete[] _buffer;    // Free dynamic array
        if (_file) {
            fclose(_file);   // Close file
        }
        delete[] _numbers;   // Free another dynamic array

        std::cout << "All resources cleaned up" << std::endl;
    }
};
```

---

## Complete Examples

### Example 1: Student Class

```cpp
class Student {
private:
    std::string* _name;
    int _age;
    double* _grades;
    size_t _gradeCount;

public:
    // 1. Default Constructor
    Student() : _name(NULL), _age(0), _grades(NULL), _gradeCount(0) {
        std::cout << "Student: Default constructor" << std::endl;
    }

    // 2. Copy Constructor
    Student(const Student& other) : _age(other._age), _gradeCount(other._gradeCount) {
        std::cout << "Student: Copy constructor" << std::endl;

        // Deep copy name
        if (other._name) {
            _name = new std::string(*(other._name));
        } else {
            _name = NULL;
        }

        // Deep copy grades array
        if (other._grades && _gradeCount > 0) {
            _grades = new double[_gradeCount];
            for (size_t i = 0; i < _gradeCount; ++i) {
                _grades[i] = other._grades[i];
            }
        } else {
            _grades = NULL;
        }
    }

    // 3. Assignment Operator
    Student& operator=(const Student& other) {
        std::cout << "Student: Assignment operator" << std::endl;

        if (this != &other) {  // Self-assignment check
            // Clean up existing resources
            delete _name;
            delete[] _grades;

            // Copy basic types
            _age = other._age;
            _gradeCount = other._gradeCount;

            // Deep copy name
            if (other._name) {
                _name = new std::string(*(other._name));
            } else {
                _name = NULL;
            }

            // Deep copy grades array
            if (other._grades && _gradeCount > 0) {
                _grades = new double[_gradeCount];
                for (size_t i = 0; i < _gradeCount; ++i) {
                    _grades[i] = other._grades[i];
                }
            } else {
                _grades = NULL;
            }
        }
        return *this;
    }

    // 4. Destructor
    ~Student() {
        std::cout << "Student: Destructor" << std::endl;
        delete _name;
        delete[] _grades;
    }

    // Additional methods
    void setName(const std::string& name) {
        delete _name;
        _name = new std::string(name);
    }

    void addGrade(double grade) {
        double* newGrades = new double[_gradeCount + 1];
        for (size_t i = 0; i < _gradeCount; ++i) {
            newGrades[i] = _grades[i];
        }
        newGrades[_gradeCount] = grade;

        delete[] _grades;
        _grades = newGrades;
        ++_gradeCount;
    }
};
```

### Example 2: Smart Pointer Class

```cpp
template<typename T>
class SmartPtr {
private:
    T* _ptr;

public:
    // 1. Default Constructor
    SmartPtr() : _ptr(NULL) {}

    // Constructor with pointer
    explicit SmartPtr(T* ptr) : _ptr(ptr) {}

    // 2. Copy Constructor
    SmartPtr(const SmartPtr& other) {
        if (other._ptr) {
            _ptr = new T(*(other._ptr));  // Deep copy the pointed object
        } else {
            _ptr = NULL;
        }
    }

    // 3. Assignment Operator
    SmartPtr& operator=(const SmartPtr& other) {
        if (this != &other) {
            delete _ptr;  // Clean up current resource

            if (other._ptr) {
                _ptr = new T(*(other._ptr));  // Deep copy
            } else {
                _ptr = NULL;
            }
        }
        return *this;
    }

    // 4. Destructor
    ~SmartPtr() {
        delete _ptr;
    }

    // Smart pointer operations
    T& operator*() const {
        return *_ptr;
    }

    T* operator->() const {
        return _ptr;
    }

    bool isNull() const {
        return _ptr == NULL;
    }
};

// Usage
SmartPtr<int> ptr1(new int(42));
SmartPtr<int> ptr2 = ptr1;  // Copy constructor
SmartPtr<int> ptr3;
ptr3 = ptr1;               // Assignment operator
// All destructors called automatically
```

---

## Common Pitfalls

### 1. Shallow Copy Problem

```cpp
// WRONG - Shallow copy
class BadString {
    char* _data;
public:
    BadString(const BadString& other) {
        _data = other._data;  // Both objects point to same memory!
    }
};

BadString s1("Hello");
BadString s2 = s1;  // Shallow copy
// When s1 and s2 are destroyed, same memory deleted twice! CRASH!
```

### 2. Forgetting Self-Assignment Check

```cpp
// WRONG - No self-assignment check
BadClass& operator=(const BadClass& other) {
    delete _data;           // Destroys own data!
    _data = new Data(*other._data);  // other._data is now invalid!
    return *this;
}
```

### 3. Memory Leaks in Assignment

```cpp
// WRONG - Memory leak
BadClass& operator=(const BadClass& other) {
    _data = new Data(*other._data);  // Forgot to delete old _data!
    return *this;
}
```

### 4. Forgetting to Return \*this

```cpp
// WRONG - Can't chain assignments
void operator=(const BadClass& other) {  // void return type
    // ... assignment logic
}

// Can't do: obj1 = obj2 = obj3;
```

---

## Best Practices

### 1. Rule of Three/Five

- If you need one of (destructor, copy constructor, assignment operator), you probably need all three
- In modern C++ (C++11+), also consider move constructor and move assignment (Rule of Five)

### 2. Use Initialization Lists

```cpp
// Better performance - direct initialization
Student() : _name(""), _age(0) {}

// Slower - default construction then assignment
Student() {
    _name = "";
    _age = 0;
}
```

### 3. Exception Safety

```cpp
// Exception-safe assignment using copy-and-swap
MyClass& operator=(const MyClass& other) {
    if (this != &other) {
        MyClass temp(other);  // If this throws, original object unchanged
        swap(temp);           // No-throw swap
    }
    return *this;
}
```

### 4. RAII (Resource Acquisition Is Initialization)

```cpp
class FileManager {
    std::ifstream _file;
public:
    FileManager(const std::string& filename) : _file(filename) {
        if (!_file.is_open()) {
            throw std::runtime_error("Cannot open file");
        }
    }
    // Destructor automatically closes file (RAII)
    ~FileManager() {
        // std::ifstream destructor closes file automatically
    }
};
```

### 5. Consider Using Smart Pointers (C++11+)

```cpp
class ModernClass {
    std::unique_ptr<Data> _data;  // Automatic memory management
public:
    // No need for custom destructor, copy constructor, assignment operator
    // if using smart pointers properly
};
```

---

## Summary

The Orthodox Canonical Form ensures your classes behave correctly in all situations:

1. **Default Constructor**: Creates objects with safe initial state
2. **Copy Constructor**: Creates proper copies of objects
3. **Assignment Operator**: Safely assigns one object to another
4. **Destructor**: Cleans up all resources

Remember: **If your class manages resources (memory, files, etc.), you MUST implement all four functions correctly to avoid crashes, memory leaks, and undefined behavior.**
