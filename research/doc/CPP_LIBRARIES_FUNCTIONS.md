# C++ Libraries and Functions Reference

## Table of Contents

1. [iostream Objects](#iostream-objects) - Console input/output objects
2. [iomanip Functions](#iomanip-functions) - Format manipulation for I/O
3. [cctype Functions](#cctype-functions) - Character classification and transformation
4. [string Functions](#string-functions) - C++ string class methods
5. [cstring Functions](#cstring-functions) - C-style string and memory operations
6. [fstream Classes and Functions](#fstream-classes-and-functions) - File input/output operations

---

## iostream Objects

C++ iostream objects
The <iostream> library provides objects which can read user input and output data to the console or to a file.

| Object  | Description                                                                       |
| ------- | --------------------------------------------------------------------------------- |
| `cerr`  | An output stream for error messages                                               |
| `clog`  | An output stream to log program information                                       |
| `cin`   | An input stream that reads keyboard input from the console by default             |
| `cout`  | An output stream which writes output to the console by default                    |
| `wcerr` | The same as `cerr` but outputs wide char (`wchar_t`) data rather than `char` data |
| `wclog` | The same as `clog` but outputs wide char (`wchar_t`) data rather than `char` data |
| `wcin`  | The same as `cin` but interprets each input character as a wide char (`wchar_t`)  |
| `wcout` | The same as `cout` but outputs wide char (`wchar_t`) data rather than `char` data |

---

## iomanip Functions

C++ iomanip Functions  
The `<iomanip>` library provides facilities to manipulate the format of input and output.

| Manipulator           | Description                                              |
| --------------------- | -------------------------------------------------------- |
| `std::setw()`         | Sets the width of the next input/output field            |
| `std::setfill()`      | Sets the fill character used for padding                 |
| `std::setprecision()` | Sets the decimal precision for floating-point values     |
| `std::fixed`          | Uses fixed-point notation for floating-point values      |
| `std::scientific`     | Uses scientific notation for floating-point values       |
| `std::left`           | Left-justifies the output in the field                   |
| `std::right`          | Right-justifies the output in the field                  |
| `std::hex`            | Sets integer output to hexadecimal                       |
| `std::dec`            | Sets integer output to decimal                           |
| `std::oct`            | Sets integer output to octal                             |
| `std::showbase`       | Shows the base prefix (0x, 0, etc.) for integer output   |
| `std::showpoint`      | Always shows the decimal point for floating-point values |
| `std::noshowpoint`    | Does not show the decimal point unless necessary         |
| `std::uppercase`      | Uses uppercase letters for hexadecimal output            |
| `std::nouppercase`    | Uses lowercase letters for hexadecimal output            |

---

## cctype Functions

C++ cctype Functions  
The `<cctype>` library provides functions to classify and transform individual characters.

| Function     | Description                                        |
| ------------ | -------------------------------------------------- |
| `isalnum()`  | Checks if character is alphanumeric                |
| `isalpha()`  | Checks if character is alphabetic                  |
| `iscntrl()`  | Checks if character is a control character         |
| `isdigit()`  | Checks if character is a decimal digit             |
| `isgraph()`  | Checks if character has a graphical representation |
| `islower()`  | Checks if character is lowercase                   |
| `isprint()`  | Checks if character is printable                   |
| `ispunct()`  | Checks if character is a punctuation character     |
| `isspace()`  | Checks if character is a whitespace character      |
| `isupper()`  | Checks if character is uppercase                   |
| `isxdigit()` | Checks if character is a hexadecimal digit         |
| `tolower()`  | Converts character to lowercase                    |
| `toupper()`  | Converts character to uppercase                    |

---

## string Functions

C++ string Functions
The <string> library has many functions that allow you to perform tasks on strings.

A list of popular string functions can be found in the table below.

| Function     | Description                                                                   |
| ------------ | ----------------------------------------------------------------------------- |
| `at()`       | Returns an indexed character from a string                                    |
| `length()`   | Returns the length of a string                                                |
| `size()`     | Alias of `length()`. Returns the length of a string                           |
| `max_size()` | Returns the maximum length of a string                                        |
| `empty()`    | Checks whether a string is empty or not                                       |
| `append()`   | Appends a string (or a part of a string) to another string                    |
| `substr()`   | Returns a part of a string from a start index (position) and length           |
| `find()`     | Returns the index (position) of the first occurrence of a string or character |
| `rfind()`    | Returns the index (position) of the last occurrence of a string or character  |
| `replace()`  | Replaces a part of a string with another string                               |
| `insert()`   | Inserts a string at a specified index (position)                              |
| `erase()`    | Removes characters from a string                                              |
| `compare()`  | Compares two strings                                                          |

---

## cstring Functions

C++ cstring Functions
The <cstring> library has many functions that allow you to perform tasks on arrays and C-style strings.

Note that C-style strings are different than regular strings. A C-style string is an array of characters, created with the char type. To learn more about C-style strings, read our C Strings Tutorial.

A list of all cstring functions can be found in the table below.

| Function     | Description                                                                                                                       |
| ------------ | --------------------------------------------------------------------------------------------------------------------------------- |
| `memchr()`   | Returns a pointer to the first occurrence of a value in a block of memory                                                         |
| `memcmp()`   | Compares two blocks of memory to determine which one represents a larger numeric value                                            |
| `memcpy()`   | Copies data from one block of memory to another                                                                                   |
| `memmove()`  | Copies data from one block of memory to another accounting for the possibility that the blocks of memory overlap                  |
| `memset()`   | Sets all of the bytes in a block of memory to the same value                                                                      |
| `strcat()`   | Appends one C-style string to the end of another                                                                                  |
| `strchr()`   | Returns a pointer to the first occurrence of a character in a C-style string                                                      |
| `strcmp()`   | Compares the ASCII values of characters in two C-style strings to determine which string has a higher value                       |
| `strcoll()`  | Compares the locale-based values of characters in two C-style strings to determine which string has a higher value                |
| `strcpy()`   | Copies the characters of a C-style string into the memory of another string                                                       |
| `strcspn()`  | Returns the length of a C-style string up to the first occurrence of one of the specified characters                              |
| `strerror()` | Returns a C-style string describing the meaning of an error code                                                                  |
| `strlen()`   | Returns the length of a C-style string                                                                                            |
| `strncat()`  | Appends a number of characters from a C-style string to the end of another string                                                 |
| `strncmp()`  | Compares the ASCII values of a specified number of characters in two C-style strings to determine which string has a higher value |
| `strncpy()`  | Copies a number of characters from one C-style string into the memory of another string                                           |
| `strpbrk()`  | Returns a pointer to the first position in a C-style string which contains one of the specified characters                        |
| `strrchr()`  | Returns a pointer to the last occurrence of a character in a C-style string                                                       |
| `strspn()`   | Returns the length of a C-style string up to the first character which is not one of the specified characters                     |
| `strstr()`   | Returns a pointer to the first occurrence of a C-style string in another string                                                   |
| `strtok()`   | Splits a string into pieces using delimiters                                                                                      |
| `strxfrm()`  | Converts characters in a C-style string from ASCII encoding to the encoding of the current locale                                 |

---

## fstream Classes and Functions

C++ fstream Classes and Functions
The `<fstream>` library provides classes and functions for file input/output operations.

## File Stream Classes

| Class      | Description                                       |
| ---------- | ------------------------------------------------- |
| `ifstream` | Input file stream for reading from files          |
| `ofstream` | Output file stream for writing to files           |
| `fstream`  | File stream for both reading and writing to files |

## File Opening Modes

| Mode          | Description                                        |
| ------------- | -------------------------------------------------- |
| `ios::in`     | Open for input operations (reading)                |
| `ios::out`    | Open for output operations (writing)               |
| `ios::binary` | Open in binary mode                                |
| `ios::ate`    | Set initial position at the end of file            |
| `ios::app`    | All output operations are performed at end of file |
| `ios::trunc`  | If file exists, truncate it to zero length         |

## Common File Operations

| Function/Method | Description                                |
| --------------- | ------------------------------------------ |
| `open()`        | Opens a file                               |
| `close()`       | Closes a file                              |
| `is_open()`     | Checks if file is open                     |
| `good()`        | Checks if stream is in good state          |
| `bad()`         | Checks if a non-recoverable error occurred |
| `fail()`        | Checks if an error occurred                |
| `eof()`         | Checks if end-of-file has been reached     |
| `clear()`       | Clears error flags                         |
| `seekg()`       | Sets position of input pointer             |
| `seekp()`       | Sets position of output pointer            |
| `tellg()`       | Returns position of input pointer          |
| `tellp()`       | Returns position of output pointer         |
| `getline()`     | Reads entire line from file                |
| `get()`         | Reads single character from file           |
| `put()`         | Writes single character to file            |
| `read()`        | Reads block of data from file              |
| `write()`       | Writes block of data to file               |

## Example Usage

```cpp
#include <fstream>
#include <iostream>
#include <string>

int main() {
	// Reading from file
	std::ifstream inputFile("example.txt");
	if (inputFile.is_open()) {
		std::string line;
		while (std::getline(inputFile, line)) {
			std::cout << line << std::endl;
		}
		inputFile.close();
	}

	// Writing to file
	std::ofstream outputFile("output.txt");
	if (outputFile.is_open()) {
		outputFile << "Hello, World!" << std::endl;
		outputFile.close();
	}

	// Reading and writing
	std::fstream file("data.txt", std::ios::in | std::ios::out | std::ios::app);
	if (!file) {
		std::cerr << "Error opening data.txt for reading and writing." << std::endl;
		return 1;
	}
	if (file.is_open()) {
		file << "New data" << std::endl;
		file.close();
	}

	return 0;
	}
}
```

---
