# Understanding Floating-Point Numbers

## Introduction

Floating-point numbers are the most widely used numeric type in programming, yet they behave in surprising ways that often confuse developers. As Jeff Bezanson notes, "floating point numbers provide a kind of illusion; they look like 'real' numbers, with decimals and possibly very large or small magnitudes." This guide explains their representation, limitations, and best practices.

## Fundamental Concepts

### The Accuracy vs. Precision Tradeoff

**Key Insight:**  
Integers and floating-point numbers represent opposite ends of a fundamental tradeoff:

| Characteristic | Integers               | Floating-Point                 |
| -------------- | ---------------------- | ------------------------------ |
| **Accuracy**   | Perfect (exact values) | Approximate (rounding errors)  |
| **Precision**  | Limited (no fractions) | High (can represent fractions) |
| **Behavior**   | Exact arithmetic       | Gradual error accumulation     |

**Bezanson's Analogy:**

- _Integers are like bricks_: Perfect for exact quantities but "chunky" (can't represent values between integers)
- _Floats are like silly putty_: Flexible for modeling but "fuzzy" (small rounding errors inherent)

**Why Fractions Are Problematic:**

> "Floating point numbers are inherently different from integers in that not every fraction can be represented exactly in binary [...] Consider the number 1/3. No finite decimal digit representation can ever be equal to 1/3; we can never have enough 3's."

### Binary Representation Basics

Floating-point uses scientific notation in binary:

```
Value = (-1)^sign × 1.mantissa × 2^(exponent-bias)
```

**Decimal Example:**  
`3.75 = 1.875 × 2^1`  
(1.875 = mantissa, 1 = exponent)

## IEEE-754 Standard Deep Dive

### Bit-Level Layout

**Single Precision (32-bit):**

```
S EEEEEEEE MMMMMMMMMMMMMMMMMMMMMMM
0 1      8 9                    31
```

- **Sign (S)**: 1 bit (0=positive, 1=negative)
- **Exponent (E)**: 8 bits (biased by 127)
- **Mantissa (M)**: 23 bits (with _implied leading 1_)

**Key Innovations:**

1. _Implied Leading 1_: Saves one bit while maintaining precision
2. _Biased Exponent_: Enables comparison as unsigned integers
3. _Special Values_: Clean handling of edge cases

### Special Values Explained

| Bit Pattern              | Value    | Notes              |
| ------------------------ | -------- | ------------------ |
| Exponent=0, Mantissa=0   | ±0       | Signed zeros       |
| Exponent=max, Mantissa=0 | ±∞       | Infinity           |
| Exponent=max, Mantissa≠0 | NaN      | Invalid operations |
| Exponent=0, Mantissa≠0   | Denormal | Gradual underflow  |

**Why This Matters:**  
These special cases enable meaningful computation even with invalid operations, unlike integers which would wrap around.

### Numerical Limits (Single vs Double Precision)

| Property       | Single Precision | Double Precision | Practical Implications     |
| -------------- | ---------------- | ---------------- | -------------------------- |
| Maximum value  | ~3.4×10³⁸        | ~1.8×10³⁰⁸       | Astrophysical calculations |
| Minimum normal | ~1.2×10⁻³⁸       | ~2.2×10⁻³⁰⁸      | Quantum physics            |
| Epsilon        | 1.2×10⁻⁷         | 2.2×10⁻¹⁶        | Tolerance thresholds       |
| Decimal digits | ~7               | ~16              | Financial precision        |

## Common Pitfalls and Solutions

### 1. Equality Testing Gone Wrong

**The Problem:**

> "Floating point numbers that look the same do not necessarily satisfy C's '==' test [...] Results have to be rounded to fit in a finite word."

**Naive Approach:**

```c
#define EPSILON 1e-7
#define flt_equals(a, b) (fabs((a)-(b)) < EPSILON)  // Problematic!
```

**Better Solution - Relative Epsilon:**

```c
bool flt_equal(float a, float b, float rel_eps) {
    float diff = fabs(a - b);
    float scale = fmax(fabs(a), fabs(b));
    return diff <= rel_eps * scale || diff < FLT_MIN;  // Handle near-zero
}
```

**Key Insight:**

> "Precision is measured in significant digits, not in magnitude; it makes no sense to talk of '1.0e-7 of precision'."

### 2. Overflow Catastrophes

**Dangerous Implementation:**

```c
// May overflow for large values
float magnitude(float x, float y) {
    return sqrt(x*x + y*y);  // x² could overflow!
}
```

**Stable Solution:**

```c
float magnitude(float x, float y) {
    x = fabs(x); y = fabs(y);
    float m = fmax(x, y);
    if (m == 0) return 0;
    float r = (x > y) ? y/x : x/y;
    return m * sqrt(1.0 + r*r);  // Scale by largest component
}
```

**Why It Works:**  
By factoring out the larger component first, we prevent intermediate overflow while preserving accuracy.

### 3. Loss of Significance

**Classic Example:**

```c
// Bad: Cancellation when x ≈ y
float bad_subtract(float x, float y) {
    return x - y;  // Loses precision
}

// Better: Algebraic rearrangement
float good_subtract(float x, float y) {
    return (x² - y²)/(x + y);  // When x ≈ y
}
```

**Series Summation Tip:**

```c
// Sum small to large to preserve precision
float sum = 0.0f;
for (int i = N-1; i >= 0; i--) {
    sum += values[i];  // Small terms get their chance
}
```

## Advanced Techniques

### Numerical Stability Principles

1. **Avoid Feedback Loops**  
   Prefer closed-form solutions over iterative updates where possible

2. **Condition Number Awareness**  
   Some problems amplify errors inherently (e.g., matrix inversion)

3. **Algorithm Selection**
   - QR decomposition vs normal equations
   - Kahan summation for accurate series

### When to Avoid Floats

| Use Case         | Better Alternative         | Reason                |
| ---------------- | -------------------------- | --------------------- |
| Exact fractions  | Rational types (int pairs) | Avoid rounding        |
| Financial values | Fixed-point arithmetic     | Predictable precision |
| Small integers   | Plain integers             | Exact representation  |

## Practical Examples

### Quadratic Formula Done Right

**Problematic:**

```c
// Cancellation when b² ≫ 4ac
x = (-b ± sqrt(b² - 4ac))/(2a);
```

**Stable Solution:**

```c
if (b > 0) {
    x1 = (-b - sqrt(b² - 4ac))/(2a);
} else {
    x1 = (-b + sqrt(b² - 4ac))/(2a);
}
x2 = c/(a*x1);  // Vieta's formula
```

### Printing Floating-Point Numbers

**Improved Printer:**

```c
void print_real(double val, int precision) {
    if (isnan(val)) printf("NaN");
    else if (isinf(val)) printf(val > 0 ? "∞" : "-∞");
    else {
        double abs_val = fabs(val);
        if (abs_val > 1e6 || abs_val < 1e-6) {
            printf("%.*e", precision, val);  // Scientific notation
        } else {
            printf("%.*f", precision, val);  // Fixed notation
        }
    }
}
```

## Conclusion

Key takeaways from Bezanson's insights:

1. Floating-point is _fundamentally approximate_ - understand its limits
2. Equality testing requires _thoughtful tolerance_ selection
3. _Algorithm choice_ dramatically affects numerical stability
4. Special values (INF, NaN) are _features not bugs_

> "We know that floats are still useful, though; we just have to prevent those little roundoff errors from stepping on our toes."

## Appendix: Reference Tables

### Common Bit Patterns

| Value | Hex (Single Precision) |
| ----- | ---------------------- |
| 0.0   | 0x00000000             |
| 1.0   | 0x3F800000             |
| -2.0  | 0xC0000000             |
| ∞     | 0x7F800000             |
| NaN   | 0x7FC00000             |

### Operation Costs

| Operation   | Relative Cost | Notes               |
| ----------- | ------------- | ------------------- |
| FP Add      | 1x            | Often pipelined     |
| FP Multiply | 1.5x-3x       | Depends on CPU      |
| FP Divide   | 10x-20x       | Avoid in loops      |
| sqrt()      | 5x-15x        | Approximations used |
