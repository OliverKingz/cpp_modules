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

📖 **For detailed information about references in C++, see:** [CPP_REFS.md](CPP_REFS.md)

This file contains:

- Reference syntax and characteristics
- References vs. pointers comparison
- Function parameters and return values
- Best practices for pass by value vs. reference vs. pointer
- Migration guide for C programmers
- Advanced reference patterns and use cases

---
