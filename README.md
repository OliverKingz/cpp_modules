# C++ Modules

<div align="right">

[![GitHub stars](https://img.shields.io/github/stars/oliverkingz/cpp_modules?color=brightgreen)]()
[![Visits Badge](https://badges.pufler.dev/visits/oliverkingz/cpp_modules)]()
[![Created Badge](https://badges.pufler.dev/created/oliverkingz/cpp_modules)]()
[![Updated Badge](https://badges.pufler.dev/updated/oliverkingz/cpp_modules)]()

</div>

[**42 Cursus**] A series of C++ exercises covering fundamental to advanced concepts in the 42 curriculum. Each module introduces new object-oriented programming techniques while adhering to strict C++98 standards.

Keywords

- **C++98**
- **OOP**
- **Memory Management**
- **Standard Library**
- **Makefile**
- **Canonical Form**
- **Pointers**
- **References**

<div align="right">

Made by: [![Contributors Display](https://badges.pufler.dev/contributors/oliverkingz/42-CPP-Modules?size=30&padding=5&perRow=10&bots=true)](https://github.com/OliverKingz)

</div>

---

## Index

- [Overview](#overview)
- [Module Features](#module-features)
- [Requirements](#requirements)
- [How to Run](#how-to-run)
  - [Example Usage](#example-usage)
  - [Testing](#testing)
- [What I Learned](#what-i-learned)
- [Author](#author)
- [Acknowledgments](#acknowledgments)

---

## Overview

This repository contains my solutions for the 42 School C++ modules (00-09). Each module focuses on different aspects of C++ programming, starting with basic syntax and progressing to advanced object-oriented concepts. The projects enforce strict adherence to C++98 standards and proper memory management while prohibiting modern C++ features.

The modules cover:

- Namespaces, classes, and basic OOP (00)
- Memory allocation and references (01)
- Orthodox Canonical Form and inheritance (02)
- And more advanced topics through module 09

---

## General Rules for C++ Modules

### Compiling

- Compile your code using `c++` with the following flags: `-Wall -Wextra -Werror`.
- Your code must also compile successfully if the `-std=c++98` flag is added.

### Formatting and Naming Conventions

- **Exercise Directories:** `ex00`, `ex01`, ..., `exn`.
- **Naming:** Name your files, classes, functions, member functions, and attributes as required by the specific guidelines.
- **Class Names:** Use `UpperCamelCase` for class names. Files containing class code will always be named according to the class name (e.g., `ClassName.hpp`/`ClassName.h`, `ClassName.cpp`, `ClassName.tpp`). For instance, a header file defining a `BrickWall` class will be named `BrickWall.hpp`.
- **Output Messages:** Unless specified otherwise, every output message must end with a newline character and be displayed to the standard output.
- **Coding Style:** No specific coding style is enforced. You are free to follow your preferred style, but prioritize clean and readable code for easier peer evaluation.

### Allowed/Forbidden

- **Standard Library:** You are allowed to use almost everything from the standard library. Favor C++-ish versions of C functions whenever possible.
- **External Libraries:** No other external libraries are permitted. C++11 (and derived forms) and Boost libraries are strictly forbidden.
- **Forbidden Functions:** `*printf()`, `*alloc()`, and `free()`. Use of these functions will result in a grade of 0.
- **Keywords (Modules 00-07):** Unless explicitly stated otherwise, the `using namespace` and `friend` keywords are forbidden. Violation will result in a grade of -42.
- **STL (Modules 00-07):** You are only allowed to use the STL (Containers like `vector`/`list`/`map`, and Algorithms requiring `<algorithm>`) in Modules 08 and 09. Use of STL before then will result in a grade of -42.

### Design Requirements

- **Memory Management:** Prevent memory leaks when allocating memory using the `new` keyword.
- **Orthodox Canonical Form:** From Module 02 to Module 09, your classes must be designed in the Orthodox Canonical Form, unless explicitly stated otherwise.
- **Function Implementations in Headers:** Any function implementation placed in a header file (except for function templates) will result in a grade of 0 for the exercise.
- **Header Independence and Include Guards:** Each of your headers should be usable independently and must include all necessary dependencies. Ensure double inclusion is avoided by adding include guards. Failure to do so will result in a grade of 0.

### Read Me

- **Additional Files:** You may add additional files if needed (e.g., to split your code) as long as mandatory files are submitted.
- **Guidelines and Examples:** Exercise guidelines may appear short, but examples can reveal unwritten requirements. Pay close attention to them.
- **Module Review:** Read each module's instructions completely before starting.
- **Critical Thinking:** Use your brain! Theoretical concepts are important; do not hesitate to research them.
- **Makefile:** The same rules as in C apply for the Makefile (refer to the Norm chapter about Makefiles).
- **Class Implementation:** You will implement many classes. Scripting your text editor can be helpful.
- **Freedom and Responsibility:** You are given some freedom, but mandatory rules must be followed. Avoid laziness to gain useful information and understanding.

---

## Module Features

### Module 00: Basic C++

- **Megaphone**: String manipulation program
- **PhoneBook**: Contact management system
- **Account**: Bank account simulation (bonus)

### Module 01: Memory & References

- **Zombie**: Class with stack/heap allocation
- **Brain**: Pointer/reference demonstration
- **Weapon/Human**: Class interaction
- **Sed**: File manipulation program
- **Harl**: Switch statement implementation

### Module 02-09:

_(Features will be added as modules are completed)_

---

## How to Run

Each module has its own directory (ex00, ex01, etc.) with a Makefile:

1. Clone this repository:
   ```bash
   git clone https://github.com/oliverkingz/42-CPP-Modules.git
   cd 42-CPP-Modules
   ```
2. Navigate to a module:
   ```bash
   cd ex00
   ```
3. Compile:
   ```bash
   make
   ```
4. Run the program:
   ```bash
   ./[program_name] [arguments]
   ```

---

## What I Learned

- **C++98 Standards**: Working with legacy C++ features
- **Memory Management**: Proper allocation/deallocation
- **OOP Principles**: Encapsulation, inheritance, polymorphism
- **Makefiles**: Building multi-file projects
- **Debugging**: Using valgrind and gdb
- **Canonical Form**: Proper class structure
- **STL Limitations**: Implementing solutions without containers

---

## Author

<div align="center">

| **Name**               | **GitHub Profile**                            | **42 Login** |
| ---------------------- | --------------------------------------------- | ------------ |
| **Oliver King Zamora** | [OliverKingz](https://github.com/oliverkingz) | **ozamora-** |

</div>

---

## Acknowledgments

This project is part of the **42 Cursus** curriculum. Special thanks to:

- 42 staff for the challenging projects
- Peers for code reviews and feedback
- The C++ community for documentation and resources

---
