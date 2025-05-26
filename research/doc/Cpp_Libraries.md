C++ iostream objects
The <iostream> library provides objects which can read user input and output data to the console or to a file.

A list of all iostream objects can be found in the table below.

Object Description
cerr An output stream for error messages
clog An output stream to log program information
cin An input stream that reads keyboard input from the console by default
cout An output stream which writes output to the console by default
wcerr The same as cerr but outputs wide char (wchar_t) data rather than char data
wclog The same as clog but outputs wide char (wchar_t) data rather than char data
wcin The same as cin but interprets each input character as a wide char (wchar_t)
wcout The same as cout but outputs wide char (wchar_t) data rather than char data

---

C++ string Functions
The <string> library has many functions that allow you to perform tasks on strings.

A list of popular string functions can be found in the table below.

Function Description
at() Returns an indexed character from a string
length() Returns the length of a string
size() Alias of length(). Returns the length of a string
max_size() Returns the maximum length of a string
empty() Checks wheter a string is empty or not
append() Appends a string (or a part of a string) to another string
substr() Returns a part of a string from a start index (position) and length
find() Returns the index (position) of the first occurrence of a string or character
rfind() Returns the index (position) of the last occurrence of a string or character
replace() Replaces a part of a string with another string
insert() Inserts a string at a specified index (position)
erase() Removes characters from a string
compare() Compares two strings

---

C++ cstring Functions
The <cstring> library has many functions that allow you to perform tasks on arrays and C-style strings.

Note that C-style strings are different than regular strings. A C-style string is an array of characters, created with the char type. To learn more about C-style strings, read our C Strings Tutorial.

A list of all cstring functions can be found in the table below.

Function Description
memchr() Returns a pointer to the first occurrence of a value in a block of memory
memcmp() Compares two blocks of memory to determine which one represents a larger numeric value
memcpy() Copies data from one block of memory to another
memmove() Copies data from one block of memory to another accounting for the possibility that the blocks of memory overlap
memset() Sets all of the bytes in a block of memory to the same value
strcat() Appends one C-style string to the end of another
strchr() Returns a pointer to the first occurrence of a character in a C-style string
strcmp() Compares the ASCII values of characters in two C-style strings to determine which string has a higher value
strcoll() Compares the locale-based values of characters in two C-style strings to determine which string has a higher value
strcpy() Copies the characters of a C-style string into the memory of another string
strcspn() Returns the length of a C-style string up to the first occurrence of one of the specified characters
strerror() Returns a C-style string describing the meaning of an error code
strlen() Return the length of a C-style string
strncat() Appends a number of characters from a C-style string to the end of another string
strncmp() Compares the ASCII values of a specified number of characters in two C-style strings to determine which string has a higher value
strncpy() Copies a number of characters from one C-style string into the memory of another string
strpbrk() Returns a pointer to the first position in a C-style string which contains one of the specified characters
strrchr() Returns a pointer to the last occurrence of a character in a C-style string
strspn() Returns the length of a C-style string up to the first character which is not one of the specified characters
strstr() Returns a pointer to the first occurrence of a C-style string in another string
strtok() Splits a string into pieces using delimiters
strxfrm() Convert characters in a C-style string from ASCII encoding to the encoding of the current locale

---


