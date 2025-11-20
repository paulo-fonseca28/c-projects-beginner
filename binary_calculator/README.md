# Binary Calculator (C Implementation)

This project is a console-based **binary calculator** written in C.  
It allows the user to input signed binary numbers and perform a variety of arithmetic operations and base conversions using a text-based menu.

The calculator uses a custom signed binary representation where the **first bit indicates the sign**:

- `0` → positive
- `1` → negative

The remaining bits represent the absolute value of the number in binary.

---

## Project Structure

- `binary_calculator.c` – Single source file containing:
  - All arithmetic and conversion functions
  - Menu handling
  - User interaction and input validation

---

## Technologies and Concepts Used

- **Language:** C
- **Standard libraries:**
  - `<stdio.h>` – input and output (`printf`, `scanf`, `fgets`)
  - `<string.h>` – string manipulation (`strlen`, `strcspn`, `memmove`)
  - `<stdlib.h>` – dynamic memory management (`malloc`, `free`, `exit`)
- **Key C concepts practiced:**
  - Functions with parameters and return values
  - **String handling** for representing binary numbers
  - **Character ↔ integer conversion** using `'0'`/`'1'` arithmetic
  - **Loops** (`for`, `while`, `do { } while`) for iteration and menu control
  - **Conditionals** (`if`, `else if`, `else`) for validation and branching
  - **Recursion** (for factorial)
  - **Dynamic memory allocation** for hexadecimal and octal string results
  - **Menu-driven program structure** using `switch` and a loop

---

## Binary Representation

The program uses a simple **sign-magnitude** representation:

- The binary number is read as a string (e.g., `"0110"` or `"1001"`).
- **First bit**:
  - `0` → number is positive
  - `1` → number is negative
- Remaining bits (from index 1 onward) are interpreted as the **absolute value** in binary.

Example:

- `011` → `+3` (sign `0`, magnitude `11₂ = 3₁₀`)
- `111` → `-3` (sign `1`, magnitude `11₂ = 3₁₀`)

The program supports up to **64 characters**, where:
- 1 bit is used for the sign,
- up to 63 bits for the magnitude.

---

## Supported Operations

The calculator presents a menu with the following options:

- `0` – Exit the program
- `1` – Addition (`bin1 + bin2`)
- `2` – Subtraction (`bin1 - bin2`)
- `3` – Multiplication (`bin1 * bin2`)
- `4` – Division (`bin1 / bin2`)
- `5` – Remainder of division (`bin1 % bin2`)
- `6` – Power (`base^exponent`)
- `7` – Absolute value (removes the sign bit from a binary number)
- `8` – Factorial (of the decimal value represented by the binary input)
- `9` – Conversion from binary to decimal
- `10` – Conversion from binary to hexadecimal
- `11` – Conversion from binary to octal

---

## Core Functions

### `long long int binarioDecimal(char *x)`

- Receives a **string** representing a signed binary number.
- Interprets `x[0]` as the sign bit.
- Converts the remaining bits into a decimal integer using base-2 arithmetic.
- Returns:
  - `-value` if sign bit is `1`
  - `value` if sign bit is `0`

### `void decimalBinario(long long int x, char *y)`

- Converts a signed decimal integer `x` into the custom binary format.
- If `x` is negative:
  - Stores the magnitude of `-x` in binary,
  - Marks sign bit as `1`.
- If `x` is non-negative:
  - Stores its magnitude in binary,
  - Marks sign bit as `0`.
- The resulting binary string is written into `y` and null-terminated.

### `long long int potencia(long long int x, long long int y)`

- Computes `x` raised to the power `y` using an iterative loop.
- If `y < 0`, returns `0` (negative exponents are not supported).

### `long long int fatorial(long long int x)`

- Computes `x!` recursively:
  - `0! = 1`
  - `x! = x * (x - 1)!`
- Only valid for non-negative integers; the program checks this before calling it.

### `char *decimalParaHexadecimal(unsigned long long int x)`

- Allocates a new string using `malloc`.
- Converts `x` to a hexadecimal string using `sprintf` with format `"%llx"`.
- Returns the allocated string (the caller is responsible for `free`).

### `char *decimalParaOctal(unsigned long int x)`

- Allocates a new string using `malloc`.
- Converts `x` to an octal string using `sprintf` with format `"%lo"`.
- Returns the allocated string (the caller is responsible for `free`).

---

## How the Program Works

1. The program prints an initial explanation about the sign bit and supported binary size.
2. A `do { ... } while (opcao != 0);` loop is used to show the menu repeatedly.
3. The user selects an option (0–11).
4. Within the `switch (opcao)`:
   - For operations that use two operands (1–6):
     - The program reads **two binary strings** with `fgets`.
     - Converts each to decimal using `binarioDecimal`.
     - Performs the selected arithmetic operation on the decimal values.
     - Converts the result back to binary using `decimalBinario`.
     - Prints the resulting binary string.
   - For **absolute value** (7):
     - The program reads one binary string.
     - Uses `memmove` to remove the first character (sign bit).
     - Prints the remaining bits as the absolute value in binary.
   - For **factorial** (8):
     - Reads one binary string and converts it to decimal.
     - If the number is negative, prints an error message.
     - Otherwise, computes the factorial with `fatorial`.
     - Converts the result back to binary with `decimalBinario` and prints it.
   - For **binary-to-decimal** (9):
     - Reads a binary string and prints the corresponding decimal value.
   - For **binary-to-hexadecimal** (10) and **binary-to-octal** (11):
     - Converts the binary string to decimal.
     - Uses `decimalParaHexadecimal` or `decimalParaOctal` to convert to the target base.
     - Prints the result and frees the allocated string.

5. When the user chooses option `0`, the loop terminates and the program prints a closing message.

---

## How to Compile and Run

### Requirements

- A C compiler (e.g., `gcc`)
- A terminal environment (Linux, WSL, or similar)

### Compilation (Linux/WSL)

From the folder where `binary_calculator.c` is located, run:

```bash
gcc -Wall -Wextra -std=c11 -o binary_calculator binary_calculator.c
```

This will generate an executable named binary_calcultor; run the program with ./binary_calcultor

## Learning Outcomes

By building this project, the following skills were practiced:

- Implementing a menu-driven console application in C
- Working with a custom binary sign-magnitude representation
- Converting between binary, decimal, hexadecimal, and octal
- Using functions to encapsulate logic for:
  - Binary ↔ decimal conversion
  - Power and factorial calculation
- Handling user input safely using `fgets` and `strcspn`
- Managing dynamic memory for strings (`malloc` / `free`)
- Using recursion in the factorial implementation

## Possible Improvements

Judging from nowadays (Nov - 2025)
Future enhancements could include:

- Adding input validation for:
  - Non-binary characters
  - Empty or oversized inputs
- Handling division by zero and reporting errors more explicitly
- Detecting and handling integer overflow in operations such as power and factorial
- Supporting:
  - Configurable bit width
  - Different signed representations (e.g., two’s complement)
- Improving the user interface:
  - Clearer prompts and error messages
  - Option to show all intermediate values (binary and decimal)
- Splitting the code into multiple files (e.g., `conversions.c`, `operations.c`, `main.c`) to improve organization and maintainability
