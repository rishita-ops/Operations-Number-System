# DSA — Multi-Base Arithmetic Calculator

A C++ menu-driven calculator that performs the four basic arithmetic operations — **Addition, Subtraction, Multiplication, and Division** — across four number base contexts: **Decimal, Binary, Octal, and Hexadecimal**. The program uses a **two-level nested switch structure** for navigation, making it a practical exercise in hierarchical menu design, nested control flow, and structured user interaction. It also serves as a clear illustration of where code duplication starts to accumulate — and how function extraction resolves it.

---

## Program Flow

```
Level 1 Menu → Select Base (Decimal / Binary / Octal / Hex)
     ↓
Level 2 Menu → Select Operation (Add / Subtract / Multiply / Divide)
     ↓
Enter two numbers → See result
```

**Example Interaction:**
```
Menu:
1.Decimal
2.Binary
3.Octal
4.Hexadecimal
Enter your choice: 1

DECIMAL
1.Addition
2.Subtraction
3.Multiplication
4.Division
Enter your choice: 1

Addition
Enter two numbers: 25 17
Sum: 42
```

---

## The Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int choice1;
    cout << "Menu:\n";
    cout << "1.Decimal\n";
    cout << "2.Binary\n";
    cout << "3.Octal\n";
    cout << "4.Hexadecimal\n";
    cout << "Enter your choice: ";
    cin >> choice1;

    switch(choice1)
    {
        case 1: { /* DECIMAL — nested switch for Add/Sub/Mul/Div */ break; }
        case 2: { /* BINARY  — nested switch for Add/Sub/Mul/Div */ break; }
        case 3: { /* OCTAL   — nested switch for Add/Sub/Mul/Div */ break; }
        case 4: { /* HEX     — nested switch for Add/Sub/Mul/Div */ break; }
        default: cout << "Invalid choice!" << endl;
    }
    return 0;
}
```

*(Each case contains an identical four-operation inner switch — see full source for complete code)*

---

## ⚠️ The Most Important Thing to Understand About This Code

**All four base cases perform the same integer arithmetic.** There is no base-aware computation anywhere in the program.

```cpp
// Case 2 — BINARY, Addition
int a, b;
cin >> a >> b;
cout << "Sum: " << a + b << endl;
```

`cin >> a` reads the input as a standard **decimal integer**. If the user enters `1010` intending it as binary (decimal 10), the program stores `1010` and computes `1010 + 1010 = 2020` — not `10 + 10 = 20`.

The base labels (`BINARY`, `OCTAL`, `HEXADECIMAL`) are **display labels only** — they change the prompt header and nothing else. The arithmetic underneath is identical across all four cases.

| User selects | Computation performed | Base-aware? |
|-------------|----------------------|-------------|
| Decimal     | `a + b` on `int`     | ✅ Yes (decimal is the native int type) |
| Binary      | `a + b` on `int`     | ❌ No — reads decimal digits |
| Octal       | `a + b` on `int`     | ❌ No — reads decimal digits |
| Hexadecimal | `a + b` on `int`     | ❌ No — reads decimal digits |

This is the core scope limitation of the current implementation — and it is worth understanding explicitly before extending it.

---

## How It Works — The Two-Level Nested Switch

### Level 1 — Base Selection

`choice1` selects the number base context. Each case (1–4) prints a base-specific header and then enters a second switch.

### Level 2 — Operation Selection

`choice2` selects the arithmetic operation. Each inner case reads two integers and performs the operation.

The complete decision matrix:

| `choice1` | `choice2` | Operation |
|-----------|-----------|-----------|
| 1 (Decimal) | 1 | Decimal Addition |
| 1 (Decimal) | 2 | Decimal Subtraction |
| 1 (Decimal) | 3 | Decimal Multiplication |
| 1 (Decimal) | 4 | Decimal Division |
| 2 (Binary)  | 1–4 | Same operations, binary-labeled |
| 3 (Octal)   | 1–4 | Same operations, octal-labeled |
| 4 (Hex)     | 1–4 | Same operations, hex-labeled |

**Total paths: 16 operation paths + 2 invalid-choice exits = 18 reachable states**

---

## Algorithm (Pseudocode)

```
read choice1

switch choice1:
    case 1–4:
        print base name
        read choice2

        switch choice2:
            case 1: read a, b → print a + b
            case 2: read a, b → print a - b
            case 3: read a, b → print a * b
            case 4: read a, b → print a / b
            default: "Invalid choice"

    default: "Invalid choice"
```

---

## Dry Run

**Inputs:** `choice1 = 2` (Binary), `choice2 = 3` (Multiplication), `a = 6`, `b = 7`

```
Menu → 2 selected → prints "BINARY"
Inner menu → 3 selected → prints "Multiplication"
Enter two numbers: 6 7
Product: 42
```

*(Note: `6` and `7` are treated as decimal integers — no binary interpretation occurs)*

---

## ⚠️ Division by Zero — Unguarded Crash

The division case has no zero check:

```cpp
case 4:
{
    int a, b;
    cin >> a >> b;
    cout << "Quotient: " << a / b << endl;   // ← undefined behavior if b == 0
    break;
}
```

If `b = 0` is entered, **the program produces undefined behavior** — on most systems this manifests as a crash (`SIGFPE` — floating point exception, which covers integer division by zero in C++).

**Fix:**
```cpp
if(b == 0)
    cout << "Error: Division by zero is undefined." << endl;
else
    cout << "Quotient: " << a / b << endl;
```

This applies to all four base cases — the vulnerability exists in all of them identically.

---

## The Code Duplication Problem

The inner switch block is **copy-pasted four times** — once for each base. All 16 operation cases are byte-for-byte identical except for the header label printed at the start of each outer case.

**Lines of code that are pure duplication: ~100 out of ~130 total**

This is a textbook case for **function extraction**:

```cpp
void performOperation(int choice2)
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    switch(choice2)
    {
        case 1: cout << "Sum: "        << a + b   << endl; break;
        case 2: cout << "Difference: " << a - b   << endl; break;
        case 3: cout << "Product: "    << a * b   << endl; break;
        case 4:
            if(b == 0) cout << "Error: Division by zero." << endl;
            else       cout << "Quotient: " << a / b     << endl;
            break;
        default: cout << "Invalid choice!" << endl;
    }
}
```

Then each outer case becomes:

```cpp
case 1:
{
    cout << "DECIMAL\n";
    // print operation menu...
    int choice2; cin >> choice2;
    performOperation(choice2);
    break;
}
```

This reduces the program from ~130 lines to ~50 lines with identical behavior and a single point of maintenance.

---

## Integer Division — Truncation Behavior

The division case uses integer division:

```cpp
cout << "Quotient: " << a / b << endl;
```

In C++, integer division **truncates toward zero** — the fractional part is discarded entirely:

| `a` | `b` | `a / b` (integer) | Actual |
|-----|-----|-------------------|--------|
| 10  | 3   | 3                 | 3.333… |
| 7   | 2   | 3                 | 3.5    |
| -7  | 2   | -3                | -3.5   |
| 5   | 5   | 1                 | 1.0    |

If decimal results are expected, the operands should be cast to `double`:

```cpp
cout << "Quotient: " << (double)a / b << endl;
```

---

## Edge Cases

| Scenario | Behavior |
|----------|----------|
| `choice1` outside 1–4 | `default` prints `"Invalid choice!"` ✅ |
| `choice2` outside 1–4 | Inner `default` prints `"Invalid choice!"` ✅ |
| `b = 0` for division | ⚠️ Undefined behavior — program likely crashes |
| Negative numbers | Arithmetic works correctly for add/sub/mul; division truncates toward zero |
| Entering `1010` for "binary" | Stored as decimal integer `1010` — no base conversion ⚠️ |
| Integer overflow (`a * b` large) | Silently wraps for `int` — use `long long` for large inputs |
| Non-integer input (e.g. `3.5`) | `cin >> int` truncates to `3` — no error raised |

---

## Complexity Analysis

| Metric | Complexity |
|--------|------------|
| Time   | **O(1)** — all operations are constant-time arithmetic on two integers |
| Space  | **O(1)** — only two integer variables per operation; no arrays or dynamic allocation |

---

## What Base-Aware Arithmetic Would Actually Look Like

For the calculator to genuinely operate in other bases, each non-decimal case would need:

**1. Parse inputs from the target base into decimal integers:**
```cpp
// Binary string input → decimal int (Horner's method)
string binaryStr;
cin >> binaryStr;
int a = 0;
for(char c : binaryStr) a = a * 2 + (c - '0');
```

**2. Perform arithmetic in decimal** (C++ `int` arithmetic is always decimal internally)

**3. Format the result back into the target base:**
```cpp
// Decimal int → Binary string
string result = "";
while(a > 0) { result = to_string(a % 2) + result; a /= 2; }
```

This is exactly what the **Base Converter** (previous repository in this series) implements — combining both programs would produce a fully functional multi-base calculator.

---

## Repository Structure

```
DSA-MultiBase-Calculator/
│
├── multibase_calc.cpp      # Main C++ implementation
└── README.md               # Project documentation
```

---

## How to Compile and Run

**Prerequisites:** GCC / G++

```bash
# Clone the repository
git clone https://github.com/rishita-ops/DSA-MultiBase-Calculator.git
cd DSA-MultiBase-Calculator

# Compile
g++ multibase_calc.cpp -o multibase_calc

# Run
./multibase_calc
```

**On Windows:**
```bash
g++ multibase_calc.cpp -o multibase_calc.exe
multibase_calc.exe
```

---

## Key Concepts Covered

- **Nested switch-case** — two-level hierarchical menu navigation and control flow
- **Scoped `case` blocks** — using `{}` inside each `case` to allow local variable declarations
- **Code duplication recognition** — identifying when identical blocks should be extracted into a function
- **Function extraction refactoring** — how a single `performOperation()` function eliminates ~100 lines of duplication
- **Integer division truncation** — C++ truncates toward zero; cast to `double` for decimal results
- **Division by zero** — undefined behavior in C++ integer arithmetic; always guard before dividing
- **Label-only differentiation** — understanding when two code paths appear different but are computationally identical
- **`bits/stdc++.h`** — only `<iostream>` is needed here

---

## Why This Program Matters in DSA

| Concept | Connection |
|---------|------------|
| Nested switch / decision trees | Direct application — two-level menu maps to a 4×4 decision matrix |
| DRY principle (Don't Repeat Yourself) | The 4× duplication here is the canonical example of why functions exist |
| Software design patterns | The `performOperation()` refactor is a micro-example of the **Command Pattern** |
| Base-aware arithmetic | Combining this with the Base Converter produces a fully functional multi-base calculator |
| Integer overflow | `a * b` with large inputs silently overflows `int` — real-world introduction to overflow awareness |
| Menu-driven programs | Foundation of CLI tools, embedded system interfaces, and interactive DSA problem runners |

---

## Contributing

Contributions are welcome. Consider adding:
- **Division by zero guard** across all four base cases
- **Function extraction refactor** — replace the 4 duplicate inner switches with one `performOperation()` function
- **Genuine base-aware arithmetic** — parse binary/octal/hex input, compute, format output in the same base
- **`double` division option** for non-integer quotients
- A **loop** so the user can perform multiple operations without restarting
- Implementations in Python, Java, or JavaScript

```bash
git checkout -b feature/your-feature
git commit -m "Add: your feature description"
git push origin feature/your-feature
# Then open a Pull Request
```

---

## License

This project is open-source and available under the [MIT License](LICENSE).

---

*Part of a structured DSA practice series — fundamentals, done right.*
