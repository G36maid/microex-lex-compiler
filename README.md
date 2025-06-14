# Micro/Ex Compiler - Final Project

A complete compiler implementation for the Micro/Ex programming language using Lex and Yacc, generating three-address intermediate code.

##  Project Status:

**Variable Declarations** (70 points)
**Assignment Statements** (80 points)
**FOR Loop Constructs** (85 points)
**IF-THEN-ELSE Statements** (90 points)

##  usage

1. **Build the compiler:**
   ```bash
   chmod +x build_and_test.sh
   ./build_and_test.sh
   ```

2. **Or build manually:**
   ```bash
   yacc -d microex.y
   lex microex.l
   gcc -g -Wall -o microex lex.yy.c y.tab.c -ly -ll
   ```

3. **Run the compiler:**
   ```bash
   ./microex test_complete.microex
   ```

## File Overview

| File | Description |
|------|-------------|
| `microex.l` | Lexical analyzer (Lex specification) |
| `microex.y` | Parser with semantic actions (Yacc specification) |
| `Makefile` | Build configuration |
| `build_and_test.sh` | Automated build and test script |
| `demo_outputs.sh` | Demonstration of expected outputs |
| `test_*.microex` | Test files for each grading level |
| `micro-ex-compiler-guide.md` | Complete documentation |

## Test Files

- **test_declarations.microex** - Variable declarations (70 pts)
- **test_assignments.microex** - Declarations + assignments (80 pts)
- **test_for_loops.microex** - + FOR loops (85 pts)
- **test_complete.microex** - + IF-THEN-ELSE (90 pts)
- **test_pdf_example.microex** - Original PDF example

## Example Usage

**Input (Micro/Ex code):**
```
Program testP
Begin
    declare I as integer;
    declare A,B,C,D, LLL[100] as float;

    FOR (I := 1 TO 100)
        A := -LLL[I] + B * D - C;
    ENDFOR

    IF (A >= 10000.0) THEN
        print(1);
    ELSE
        print(2, 1.4);
    ENDIF
End
```

**Output (Three-Address Code):**
```
START testP

Declare I, Integer
Declare A, Float
Declare B, Float
Declare C, Float
Declare D, Float
Declare LLL, Float_array,100

I_STORE 1,I
lb&1:
F_UMINUS LLL[I],T&1
F_MUL B,D,T&2
F_ADD T&1,T&2,T&3
F_SUB T&3,C,T&4
F_STORE T&4,A

INC I
I_CMP I,100
JLE lb&1

F_CMP A,10000.0
JL lb&2

CALL print, 1

J lb&3
lb&2:
CALL print,2,1.4
lb&3:
HALT testP

Declare T&1, Float
Declare T&2, Float
Declare T&3, Float
Declare T&4, Float
```

##  Technical Implementation

### Language Features Supported
- **Variable Declarations**: Integer, float, and array types
- **Arithmetic Expressions**: +, -, *, / with proper precedence
- **Assignment Statements**: Variables and array elements
- **Control Flow**: FOR loops (TO/DOWNTO), IF-THEN-ELSE
- **Comparison Operators**: >=, <=, >, <, ==, !=
- **Print Statements**: Single and multiple parameters
- **Array Access**: Dynamic indexing in expressions

### Code Generation
- **Three-Address Instructions**: I_ADD, F_MUL, I_STORE, etc.
- **Control Flow**: Labels, jumps, and conditional branches
- **Symbol Table**: Type checking and scope management
- **Temporary Variables**: Automatic allocation for expressions
- **Error Handling**: Lexical, syntax, and semantic errors

## Requirements

This implementation fulfills all requirements from the project specification:

1.  **Lex and Yacc Usage**: Complete lexical and syntactic analysis
2.  **Three-Address Code**: All required instruction types generated
3.  **Symbol Table**: Variable declaration and type checking
4.  **Control Structures**: FOR loops and IF-THEN-ELSE
5.  **Expression Evaluation**: Arithmetic with proper precedence
6.  **Array Support**: Declaration and element access
7.  **Error Handling**: Comprehensive error detection

## Development Process

The compiler was developed following standard compiler construction principles:

1. **Lexical Analysis** - Pattern recognition and tokenization
2. **Syntax Analysis** - Grammar-based parsing with Yacc
3. **Semantic Analysis** - Symbol table and type checking
4. **Code Generation** - Three-address intermediate code
5. **Testing** - Comprehensive test suite for all features

## Tools and Dependencies

- **Lex/Flex**: Lexical analyzer generator
- **Yacc/Bison**: Parser generator
- **GCC**: C compiler
- **Make**: Build automation

## Documentation

See `micro-ex-compiler-guide.md` for complete technical documentation including:
- Detailed language syntax
- Three-address code specifications
- Implementation details
- Error handling strategies
- Testing procedures

## Learning Outcomes

This project demonstrates mastery of:
- Compiler construction theory and practice
- Lexical analysis with regular expressions
- Syntax analysis with context-free grammars
- Semantic analysis and symbol table management
- Intermediate code generation techniques
- Three-address machine architecture
- Error handling and recovery mechanisms
