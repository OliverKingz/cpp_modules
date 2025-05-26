Data Type Size Description
boolean 1 byte Stores true or false values
char 1 byte Stores a single character/letter/number, or ASCII values
int 2 or 4 bytes Stores whole numbers, without decimals
float 4 bytes Stores fractional numbers, containing one or more decimals. Sufficient for storing 6-7 decimal digits
double 8 bytes Stores fractional numbers, containing one or more decimals. Sufficient for storing 15 decimal digits

float vs. double

The precision of a floating point value indicates how many digits the value can have after the decimal point. The precision of float is only six or seven decimal digits, while double variables have a precision of about 15 digits. Therefore it is safer to use double for most calculations.

Auto Keyword. For C++11

---

# Casting in C++98

| Cast                   | Use Case                     | Safety        | 42 Allowed? |
| ---------------------- | ---------------------------- | ------------- | ----------- |
| **C-style**            | Quick conversions            | Unsafe        | ❌ Avoid    |
| **`static_cast`**      | Numeric, inheritance (safe)  | Compile-time  | ✅ Yes      |
| **`const_cast`**       | Remove `const`               | Risky         | ❗ Rarely   |
| **`reinterpret_cast`** | Low-level pointer hacking    | Very unsafe   | ❌ No       |
| **`dynamic_cast`**     | Safe polymorphic downcasting | Runtime-check | ✅ Yes      |

## **Best Practices**

1. **Prefer `static_cast`** for most conversions (e.g., `int` → `float`).
2. **Avoid `reinterpret_cast`** (forbidden in most modules).
3. **Never use C-style casts** (they bypass compiler checks).
4. **Use `dynamic_cast` sparingly** (only when polymorphism is needed).
