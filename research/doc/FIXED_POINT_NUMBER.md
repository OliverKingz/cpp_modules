# Fixed-Point Number Representation: A Comprehensive Guide

## Introduction

Fixed-point numbers provide an efficient alternative to floating-point for representing real numbers in computing systems, particularly valuable in performance-critical applications.

**Key Characteristics:**

- Represents fractional numbers using integer hardware
- Fixed binary point position
- Deterministic precision
- Native performance on all processors

**Common Applications:**

- Digital Signal Processing (DSP)
- Game development physics engines
- Embedded systems without FPUs
- Financial calculations requiring exact decimal behavior

## Fundamental Concepts

### Binary Number System Review

#### Integer Representation
```

Binary: 110101
Decimal: 1×2⁵ + 1×2⁴ + 0×2³ + 1×2² + 0×2¹ + 1×2⁰
= 32 + 16 + 4 + 1
= 53

```

#### Fractional Extension
The binary point enables fractional representation:
```

Binary: 11010.1
Decimal: 1×2⁴ + 1×2³ + 0×2² + 1×2¹ + 0×2⁰ + 1×2⁻¹
= 16 + 8 + 2 + 0.5
= 26.5

```

### Binary Point Mechanics
The binary point functions identically to a decimal point, but with base-2 weights:

| Bit Position | 2³ | 2² | 2¹ | 2⁰ | • | 2⁻¹ | 2⁻² | 2⁻³ |
|--------------|----|----|----|----|---|-----|-----|-----|
| Weight       | 8  | 4  | 2  | 1  | • | 0.5 | 0.25| 0.125|

**Example:**
```

Binary: 101.1101
Calculation: 4 + 0 + 1 + 0.5 + 0.25 + 0 + 0.0625 = 5.8125

```

## Fixed-Point Representation

### Notation: `fixed<w,b>`
- **w**: Total bit width (including sign bit if signed)
- **b**: Number of fractional bits (binary point position)

### Representation Examples

#### 8-bit Unsigned (`fixed<8,3>`)
```

Bit pattern: 00010110
Interpretation: 00010.110
Calculation: 2 + 0.5 + 0.25 = 2.75

````

#### Same Bit Pattern as Different Types
| Type        | Interpretation | Decimal Value |
|-------------|----------------|---------------|
| `fixed<8,3>`| 00010.110      | 2.75          |
| `fixed<8,5>`| 000.10110      | 0.6875        |
| Integer     | 00010110       | 22            |

### Range and Precision Characteristics

#### Signed 16-bit Examples
| Type          | Integer Range | Fractional Precision | Smallest Number | Largest Number |
|---------------|---------------|----------------------|-----------------|----------------|
| `fixed<16,0>` | -32768-32767  | 1.0                  | 1.0             | 32767.0        |
| `fixed<16,4>` | -2048-2047.9375 | 0.0625            | 0.0625          | 2047.9375      |
| `fixed<16,8>` | -128-127.9961 | 0.00390625           | 0.00390625      | 127.9961       |

### Negative Numbers (2's Complement)

#### 4-bit Signed Examples (`fixed<4,1>`)
| Binary | Integer Value | Fixed-Point Value |
|--------|---------------|-------------------|
| 1000   | -8            | -4.0              |
| 1001   | -7            | -3.5              |
| 1010   | -6            | -3.0              |
| ...    | ...           | ...               |
| 1111   | -1            | -0.5              |
| 0000   | 0             | 0.0               |
| 0001   | 1             | 0.5               |

## Arithmetic Operations

### Multiplication
```c
// fixed<16,8> multiplication
int32_t multiply_fixed(int16_t a, int16_t b) {
    return (int32_t)a * b >> 8;
}
````

**Example:**

```
1.5 (0x0180) × 2.25 (0x0240) = 3.375 (0x0360)
Actual: 0x0180 * 0x0240 = 0x02D000 → Right shift 8 → 0x0360 (3.375)
```

### Division

```c
// fixed<16,8> division
int16_t divide_fixed(int16_t a, int16_t b) {
    return ((int32_t)a << 8) / b;
}
```

**Example:**

```
3.375 (0x0360) / 1.5 (0x0180) = 2.25 (0x0240)
(0x036000 / 0x0180) = 0x0240
```

### Addition/Subtraction

```c
// fixed<16,8> addition (no scaling needed)
int16_t add_fixed(int16_t a, int16_t b) {
    return a + b;  // Binary points must align
}
```

## Implementation in C

### Basic Type Definition

```c
typedef int32_t fixed_t;
#define FRAC_BITS 16  // Q16.16 format
#define FIXED_SCALE (1 << FRAC_BITS)
```

### Conversion Functions

```c
fixed_t float_to_fixed(float f) {
    return (fixed_t)(f * FIXED_SCALE + (f >= 0 ? 0.5f : -0.5f));
}

float fixed_to_float(fixed_t f) {
    return (float)f / FIXED_SCALE;
}
```

### Math Operations

```c
fixed_t fixed_mult(fixed_t a, fixed_t b) {
    return (fixed_t)(((int64_t)a * b) >> FRAC_BITS);
}

fixed_t fixed_div(fixed_t a, fixed_t b) {
    return (fixed_t)(((int64_t)a << FRAC_BITS) / b);
}
```

## Comparison with Floating-Point

### Performance Characteristics

| Operation    | Fixed-Point (cycles) | Floating-Point (cycles) |
| ------------ | -------------------- | ----------------------- |
| Add/Subtract | 1                    | 3-10                    |
| Multiply     | 1-4                  | 5-20                    |
| Divide       | 10-40                | 20-100                  |

### Precision Comparison

| Metric         | Fixed-Point    | Floating-Point (32-bit) |
| -------------- | -------------- | ----------------------- |
| Relative Error | Constant       | Variable                |
| Smallest Value | 2⁻ᵇ (fixed)    | ~1.4×10⁻⁴⁵              |
| Largest Value  | (2ʷ⁻¹-1)/2ᵇ    | ~3.4×10³⁸               |
| Decimal Digits | ~log₁₀(2ʷ⁻ᵇ⁻¹) | ~7.2                    |

## Practical Considerations

### Pros and Cons Analysis

**Advantages:**

- ✅ **Deterministic behavior** - No surprise rounding
- ✅ **Hardware efficiency** - Uses integer ALU
- ✅ **Memory efficiency** - Exact bit-width control
- ✅ **Performance** - 5-100x faster than floating-point

**Disadvantages:**

- ❌ **Fixed precision** - Cannot adapt to value magnitude
- ❌ **Manual scaling** - Programmer must track binary point
- ❌ **Limited range** - Smaller dynamic range than float

### When to Use Fixed-Point

1. **Embedded systems** without FPUs
2. **Real-time systems** requiring deterministic timing
3. **DSP algorithms** needing consistent performance
4. **Financial calculations** requiring exact decimal behavior
5. **Game physics** engines needing reproducible results

## Advanced Topics

### Overflow Prevention

```c
// Safe multiplication with overflow check
fixed_t safe_fixed_mult(fixed_t a, fixed_t b) {
    int64_t temp = (int64_t)a * b;
    if (temp > (0x7FFFFFFF << FRAC_BITS)) {
        // Handle overflow
    }
    return (fixed_t)(temp >> FRAC_BITS);
}
```

### Q-Format Notation

Common fixed-point formats:
| Format | Integer Bits | Fractional Bits | Range | Precision |
|----------|--------------|-----------------|----------------|---------------|
| Q15.16 | 15 | 16 | ±16384.0 | ~15.5 digits |
| Q7.8 | 7 | 8 | ±128.0 | ~7.2 digits |
| Q31.32 | 31 | 32 | ±1B | ~31.5 digits |

## Conclusion

Fixed-point arithmetic provides a crucial middle ground between integer and floating-point computation, offering:

1. **Predictable performance** - Critical for real-time systems
2. **Hardware efficiency** - Utilizes existing integer units
3. **Deterministic behavior** - Essential for reproducible results

While floating-point remains superior for scientific computing, fixed-point dominates in:

- Digital signal processing
- Embedded systems
- Game development
- Financial applications

**Final Recommendation:** Use fixed-point when performance and determinism outweigh the need for automatic range/precision adjustment.