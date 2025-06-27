# C++ Standard I/O Streams Guide

## Table of Contents

1. [Overview](#overview)
2. [Required Libraries](#required-libraries)
3. [Stream Types](#stream-types)
4. [std::stringstream Deep Dive](#stdstringstream-deep-dive)
5. [String to Number Conversion](#string-to-number-conversion)
6. [Stream Operators](#stream-operators)
7. [Error Handling](#error-handling)
8. [Practical Examples](#practical-examples)
9. [Best Practices](#best-practices)
10. [C++98 vs Modern C++](#c98-vs-modern-c)

## Overview

C++ streams provide a unified interface for input/output operations. They use operator overloading (`<<` and `>>`) to provide intuitive syntax for data flow.

**Key Concept:** Streams treat data as a sequence of characters flowing in one direction.

## Required Libraries

```cpp
#include <iostream>   // std::cin, std::cout, std::cerr
#include <sstream>    // std::stringstream, std::istringstream, std::ostringstream
#include <iomanip>    // Stream manipulators (setw, setprecision, etc.)
#include <string>     // std::string (often needed with streams)
```

## Stream Types

### 1. Standard I/O Streams

```cpp
std::cin   // Standard input (keyboard)
std::cout  // Standard output (console)
std::cerr  // Standard error (console, unbuffered)
std::clog  // Standard log (console, buffered)
```

### 2. String Streams

```cpp
std::stringstream  // Read and write to string
std::istringstream // Read from string (input)
std::ostringstream // Write to string (output)
```

### 3. File Streams

```cpp
std::ifstream      // Read from file
std::ofstream      // Write to file
std::fstream       // Read and write to file
```

## std::stringstream Deep Dive

### What is it?

`std::stringstream` combines string storage with stream operations, allowing you to:

- Parse strings into different data types
- Format data into strings
- Extract multiple values from a single string

### Basic Usage

```cpp
#include <sstream>

// Creating a stringstream
std::stringstream ss;
std::stringstream ss("initial content");
std::stringstream ss(someString);
```

### Extraction (Reading from stream)

```cpp
std::string data = "42 hello 3.14";
std::stringstream ss(data);

int num;
std::string word;
double pi;

ss >> num;    // Extracts "42"
ss >> word;   // Extracts "hello"
ss >> pi;     // Extracts "3.14"

// Or chain them:
ss >> num >> word >> pi;
```

### Insertion (Writing to stream)

```cpp
std::stringstream ss;
ss << "Name: " << "John" << ", Age: " << 25 << ", Score: " << 95.5;
std::string result = ss.str(); // "Name: John, Age: 25, Score: 95.5"
```

### Getting the String

```cpp
std::stringstream ss;
ss << "Hello World";
std::string content = ss.str(); // Extract the built string
```

## String to Number Conversion

### Safe Conversion Function (C++98 Compatible)

```cpp
bool stringToInt(const std::string& str, int& result) {
    std::stringstream ss(str);
    return (ss >> result) && ss.eof();
}

bool stringToDouble(const std::string& str, double& result) {
    std::stringstream ss(str);
    return (ss >> result) && ss.eof();
}

bool stringToSizeT(const std::string& str, size_t& result) {
    std::stringstream ss(str);
    return (ss >> result) && ss.eof();
}
```

### Usage Examples

```cpp
std::string input = "123";
int number;

if (stringToInt(input, number)) {
    std::cout << "Valid number: " << number << std::endl;
} else {
    std::cout << "Invalid input!" << std::endl;
}

// Test cases
stringToInt("123", num);     // ✓ Valid: num = 123
stringToInt("123abc", num);  // ✗ Invalid: extra characters
stringToInt("abc123", num);  // ✗ Invalid: starts with letters
stringToInt("", num);        // ✗ Invalid: empty string
stringToInt("  123  ", num); // ✗ Invalid: whitespace (depending on implementation)
```

### Why `ss.eof()` is Critical

```cpp
std::string test = "123abc";
std::stringstream ss(test);
int num;

// Without eof() check - DANGEROUS!
if (ss >> num) {
    // This succeeds! num = 123
    // But "abc" is ignored - potential bug!
}

// With eof() check - SAFE!
if ((ss >> num) && ss.eof()) {
    // This fails because "abc" prevents reaching end-of-stream
    // Ensures ENTIRE string was a valid number
}
```

## Stream Operators

### Extraction Operator `>>`

**Direction:** Stream → Variable

```cpp
std::stringstream ss("42");
int num;
ss >> num; // Extracts 42 from stream into num
```

### Insertion Operator `<<`

**Direction:** Variable → Stream

```cpp
std::stringstream ss;
int num = 42;
ss << num; // Inserts 42 from num into stream
```

### Chaining Operations

```cpp
// Input chaining
ss >> var1 >> var2 >> var3;

// Output chaining
ss << "Value1: " << var1 << ", Value2: " << var2;
```

### Are These the Same as `std::cout` and `std::cin`?

**Yes, exactly!** The `<<` and `>>` operators used with `std::stringstream` are the **same operators** you use with `std::cout` and `std::cin`.

### The Same Operators, Different Streams

```cpp
// Standard output stream
std::cout << "Hello" << std::endl;

// String stream (same operators!)
std::stringstream ss;
ss << "Hello" << std::endl;

// Standard input stream  
std::cin >> variable;

// String stream (same operators!)
std::stringstream ss("42");
ss >> variable;
```

### How It Works - Operator Overloading

C++ uses **operator overloading** to make the same operators (`<<` and `>>`) work with different stream types:

```cpp
// All of these use the SAME << operator
std::cout << 42;           // Output to console
std::cerr << "Error!";     // Output to error stream  
std::stringstream ss;
ss << 42;                  // Output to string stream
std::ofstream file("test.txt");
file << 42;                // Output to file stream
```

### The Direction Metaphor

Think of the operators as **arrows showing data flow:**

```cpp
// Data flows FROM variables TO output stream
std::cout << variable;    // variable → cout
ss << variable;           // variable → stringstream

// Data flows FROM input stream TO variables  
std::cin >> variable;     // cin → variable
ss >> variable;           // stringstream → variable
```

### Why This Design is Brilliant

**1. Consistent Syntax:**
- Once you learn `std::cout <<`, you know all streams
- Same mental model for all I/O operations

**2. Easy to Switch:**
```cpp
// Change from console output...
std::cout << "Debug: " << value << std::endl;

// ...to string building (same syntax!)
std::stringstream ss;
ss << "Debug: " << value << std::endl;
std::string result = ss.str();
```

**3. Polymorphic Behavior:**
```cpp
template<typename StreamType>
void printData(StreamType& stream, const std::string& data) {
    stream << "Data: " << data << std::endl;
}

// Works with ANY stream type!
printData(std::cout, "console");          // Prints to console
printData(stringstream, "string");        // Builds string
printData(filestream, "file");            // Writes to file
```

### Complete Example

```cpp
#include <iostream>
#include <sstream>

int main() {
    // Same operators, different streams!
    
    // 1. Console output
    std::cout << "Enter a number: ";
    
    // 2. Console input
    std::string input;
    std::cin >> input;
    
    // 3. String stream processing (same operators!)
    std::stringstream ss(input);
    int number;
    
    if (ss >> number) {  // Same >> operator!
        // 4. String stream building (same operators!)
        std::stringstream result;
        result << "You entered: " << number << " (doubled: " << (number * 2) << ")";
        
        // 5. Console output again
        std::cout << result.str() << std::endl;
    }
    
    return 0;
}
```

**Key Takeaway:** `<<` and `>>` are the exact same operators you use with `std::cout` and `std::cin`. The beauty of C++ streams is this **unified interface** across all stream types!

## Error Handling

### Stream States

```cpp
std::stringstream ss("123abc");
int num;
ss >> num;

// Check states
if (ss.good())    // All operations successful
if (ss.eof())     // End of stream reached
if (ss.fail())    // Last operation failed
if (ss.bad())     // Serious error occurred
```

### Clearing Error States

```cpp
ss.clear();       // Clear error flags
ss.ignore();      // Skip next character
ss.ignore(100, '\n'); // Skip up to 100 chars or until newline
```

### Robust Input Function

```cpp
template<typename T>
bool safeExtract(const std::string& str, T& result) {
    std::stringstream ss(str);
    T temp;

    if (!(ss >> temp)) {
        return false; // Extraction failed
    }

    if (!ss.eof()) {
        return false; // Extra characters remain
    }

    result = temp;
    return true;
}
```

## Practical Examples

### 1. Parsing Contact Information

```cpp
std::string contactData = "John Doe 30 555-1234";
std::stringstream ss(contactData);

std::string firstName, lastName, phone;
int age;

if (ss >> firstName >> lastName >> age >> phone) {
    std::cout << "Name: " << firstName << " " << lastName << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Phone: " << phone << std::endl;
}
```

### 2. Building Formatted Messages

```cpp
std::string buildContactSummary(const std::string& name, int age, const std::string& phone) {
    std::stringstream ss;
    ss << "Contact: " << name << " (Age: " << age << ", Phone: " << phone << ")";
    return ss.str();
}
```

### 3. Safe Index Input (PhoneBook Example)

```cpp
size_t inputIndex(const std::string& prompt, size_t maxIndex) {
    std::string input;
    size_t index;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        std::stringstream ss(input);
        if ((ss >> index) && ss.eof() && index < maxIndex) {
            return index;
        }

        std::cout << "Invalid index. Please enter 0-" << (maxIndex - 1) << std::endl;
    }
}
```

### 4. Multi-Value Parsing with Validation

```cpp
bool parsePhoneBookEntry(const std::string& line, std::string& name,
                        std::string& phone, int& age) {
    std::stringstream ss(line);
    std::string tempName, tempPhone;
    int tempAge;

    // Try to extract all values
    if (!(ss >> tempName >> tempPhone >> tempAge)) {
        return false;
    }

    // Check if anything remains (extra data)
    std::string remainder;
    if (ss >> remainder) {
        return false; // Extra data found
    }

    // All validations passed
    name = tempName;
    phone = tempPhone;
    age = tempAge;
    return true;
}
```

### 5. Number Formatting

```cpp
std::string formatCurrency(double amount) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << "$" << amount;
    return ss.str();
}

std::string formatPercentage(double ratio) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << (ratio * 100) << "%";
    return ss.str();
}
```

### 6. CSV Parsing

```cpp
std::vector<std::string> parseCSVLine(const std::string& line) {
    std::vector<std::string> fields;
    std::stringstream ss(line);
    std::string field;

    while (std::getline(ss, field, ',')) {
        fields.push_back(field);
    }

    return fields;
}
```

### 7. Command Parsing

```cpp
struct Command {
    std::string action;
    std::vector<std::string> arguments;
};

Command parseCommand(const std::string& input) {
    Command cmd;
    std::stringstream ss(input);

    ss >> cmd.action; // First word is the command

    std::string arg;
    while (ss >> arg) {
        cmd.arguments.push_back(arg);
    }

    return cmd;
}
```

## Best Practices

### 1. Always Check Extraction Success

```cpp
// BAD
ss >> value;

// GOOD
if (ss >> value) {
    // Use value
} else {
    // Handle error
}
```

### 2. Use `eof()` for Complete Validation

```cpp
// Ensures entire string was consumed
if ((ss >> value) && ss.eof()) {
    // Complete and valid
}
```

### 3. Clear Stream State When Reusing

```cpp
std::stringstream ss;
ss << "first data";
std::string first = ss.str();

ss.str("");          // Clear content
ss.clear();          // Clear error flags
ss << "second data"; // Ready for reuse
```

### 4. Prefer Templates for Generic Functions

```cpp
template<typename T>
bool stringToValue(const std::string& str, T& result) {
    std::stringstream ss(str);
    return (ss >> result) && ss.eof();
}
```

### 5. Handle Whitespace Appropriately

```cpp
// Skip leading whitespace (default behavior)
ss >> value;

// Preserve whitespace
ss >> std::noskipws >> value;

// Read entire line including spaces
std::getline(ss, line);
```

## C++98 vs Modern C++

### String to Number Conversion

**C++98 (Your Project):**

```cpp
// Using stringstream (recommended)
bool stringToInt(const std::string& str, int& result) {
    std::stringstream ss(str);
    return (ss >> result) && ss.eof();
}

// Using atoi (less safe)
int result = atoi(str.c_str()); // No error checking!
```

**C++11+ (Modern):**

```cpp
try {
    int result = std::stoi(str);
    size_t result = std::stoul(str);
    double result = std::stod(str);
} catch (const std::exception& e) {
    // Handle conversion error
}
```

### Why Stringstream Still Matters

Even in modern C++, `std::stringstream` is preferred for:

- **Complex parsing** (multiple values)
- **Formatted output** (building strings)
- **Fine-grained control** over conversion
- **Custom formatting** requirements

### Migration Path

```cpp
// C++98 style (what you should use now)
std::stringstream ss(phoneStr);
size_t phoneNum;
if ((ss >> phoneNum) && ss.eof()) {
    // Valid phone number
}

// Future C++11+ style
try {
    size_t phoneNum = std::stoul(phoneStr);
    // Valid phone number
} catch (const std::exception&) {
    // Invalid phone number
}
```

## Summary

`std::stringstream` provides:

- **Type-safe** string ↔ data conversion
- **Flexible** parsing capabilities
- **Consistent** syntax with other streams
- **Error detection** through stream states
- **C++98 compatibility** for your current project

Key takeaways:

1. Always validate with `ss.eof()` for complete string consumption
2. Check stream states for error detection
3. Use templates for reusable conversion functions
4. Clear stream state when reusing stringstream objects
5. Prefer stringstream over C-style functions for safety

This makes `std::stringstream` an essential tool for robust C++ programs, especially when working with C++98 constraints.
