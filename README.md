# Micro/Ex Compiler

A robust compiler for the Micro/Ex programming language that generates optimized three-address intermediate code. Built using Lex and Yacc, this implementation supports variable declarations, control structures, and arithmetic operations with strong type checking.

## Features

✅ **Core Language Elements**
- Integer and float variables
- Fixed-size arrays (both integer and float)
- Arithmetic expressions (+, -, *, /)
- Print statements with multiple arguments

✅ **Control Structures**
- FOR loops (both TO and DOWNTO)
- IF-THEN-ELSE conditionals
- Nested control structures

✅ **Type System**
- Static type checking
- Array bounds checking
- Multiple variable declarations

## Quick Start

### Building the Compiler

```bash
# Using make
make clean && make

# Or manually
yacc -d microex.y
lex microex.l
gcc -g -Wall -o microex lex.yy.c y.tab.c -ly -lfl
```

### Running a Program

```bash
./microex your_program.microex
```

## Language Syntax

### Program Structure
```
Program MyProgram
Begin
    // declarations
    // statements
End
```

### Variable Declarations
```
declare x, y as integer;              // Integer variables
declare a, b, c as float;            // Float variables
declare arr[100] as integer;         // Integer array
declare matrix[50] as float;         // Float array
```

### Assignment Statements
```
x := 42;                    // Integer assignment
a := 3.14;                 // Float assignment
arr[0] := 100;             // Array element assignment
matrix[i] := a + b;        // Expression assignment
```

### Control Structures

#### FOR Loops
```
FOR (i := 1 TO 100)
    x := x + i;
ENDFOR

FOR (i := 10 DOWNTO 1)
    arr[i] := i * 2;
ENDFOR
```

#### IF-THEN-ELSE
```
IF (x >= 10) THEN
    print(x);
ENDIF

IF (a < b) THEN
    print(1);
ELSE
    print(2);
ENDIF
```

### Print Statements
```
print(x);                  // Single value
print(x, y);              // Multiple values
print(arr[i], 3.14);      // Expressions
```

## Three-Address Code Output

The compiler generates optimized three-address code. Example:

Input:
```
Program Example
Begin
    declare i as integer;
    declare a, b as float;
    a := -b + 3.14;
    IF (a >= 10.0) THEN
        print(a);
    ENDIF
End
```

Output:
```
START Example

Declare i, Integer
Declare a, Float
Declare b, Float

F_UMINUS b,T&1
F_ADD T&1,3.14,T&2
F_STORE T&2,a
F_CMP a,10.0
JL lb&1
CALL print, a
lb&1:

HALT Example
```

## Testing

Built-in test suite covers all language features:

```bash
# Run individual feature tests
make test-declarations       # Variable declarations
make test-assignments       # Assignment statements
make test-for-loops        # FOR loop constructs
make test-if-statements    # IF-THEN-ELSE statements

# Run all tests
make test-all
```

## Project Structure

```
microex-lex-compiler/
├── microex.l              # Lexical analyzer (Lex)
├── microex.y              # Parser/Code generator (Yacc)
├── Makefile              # Build configuration
├── build_and_test.sh     # Test automation script
└── test_*.microex        # Test suite files
```

## Generated Instructions

### Arithmetic Operations
- `I_ADD`, `I_SUB`, `I_MUL`, `I_DIV` (Integer)
- `F_ADD`, `F_SUB`, `F_MUL`, `F_DIV` (Float)
- `I_UMINUS`, `F_UMINUS` (Unary minus)

### Memory Operations
- `I_STORE`, `F_STORE` (Assignment)
- Array access with indexed notation

### Control Flow
- `JMP`, `JL`, `JLE`, `JG`, `JGE`, `JE`, `JNE`
- Labels for loops and conditionals

### System
- `START`, `HALT` (Program boundaries)
- `CALL print` (Output)
- `Declare` (Variable/Array declaration)

## Requirements

- Lex/Flex
- Yacc/Bison
- GCC
- Make

## Known Limitations

1. Fixed-size arrays only
2. No string type support
3. Basic type system (integer/float)
4. Single-file programs only

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

## License

MIT License - Feel free to use and modify

## Author

Your Name  
Contact: your.email@example.com
