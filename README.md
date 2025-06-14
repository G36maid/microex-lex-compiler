# Micro/Ex Compiler

A robust compiler implementation for the Micro/Ex programming language that generates optimized three-address intermediate code. Built using Lex/Flex and Yacc/Bison, this compiler features strong type checking, control structures, and comprehensive error handling.

## Features
**Core Language Support**
- Integer and float variable declarations
- Fixed-size array support
- Multiple variable declarations
- Type checking and validation

**Control Structures**
- FOR loops (TO/DOWNTO)
- IF-THEN-ELSE statements
- Nested control structures
- Print statements

**Expression Support**
- Arithmetic operations (+, -, *, /)
- Comparison operators (>=, <=, >, <, ==, !=)
- Array element access
- Unary minus operator

## Project Structure

```
microex-lex-compiler/
├── src/                    # Source code
│   ├── include/           # Header files
│   │   └── microex.h     # Common declarations
│   ├── lexer.l           # Lexical analyzer
│   └── parser.y          # Parser and code generator
│
├── docs/                  # Documentation
│   ├── compiler-guide.md # Technical documentation
│   └── README.md         # Project overview
│
├── tests/                 # Test files
│   ├── test_declarations.microex
│   ├── test_assignments.microex
│   ├── test_for_loops.microex
│   ├── test_complete.microex
│   └── test_pdf_example.microex
│
├── build/                 # Generated files
│   ├── lex.yy.c
│   ├── y.tab.c
│   └── y.tab.h
│
└── Makefile              # Build system
```

## Prerequisites

- GCC compiler
- Flex (lexical analyzer generator)
- Bison (parser generator)
- Make build system
- (Optional) Pandoc for documentation
- (Optional) clang-format for code formatting

## Quick Start
```
git clone <repository>
cd microex-lex-compiler
```

1. **Build the compiler**
   ```bash
   make clean && make && make test
   ```

2. **Run tests**
   ```bash
   make test              # Run all tests
   make test-declarations # Test declarations only
   make test-assignments  # Test assignments only
   make test-for-loops   # Test FOR loops
   make test-complete    # Test full implementation
   make test-all
   ```

3. **Generate documentation**
   ```bash
   make docs
   ```

## Usage

1. **Write your Micro/Ex program** (example.microex):
   ```
   Program Example
   Begin
       declare i as integer;
       declare a, b as float;

       a := 3.14;
       b := 2.0;

       FOR (i := 1 TO 10)
           a := a * b;
       ENDFOR

       IF (a >= 100.0) THEN
           print(a);
       ENDIF
   End
   ```

2. **Compile your program**:
   ```bash
   ./microex example.microex
   ```

3. **View the generated three-address code**:
   ```
   START Example

   Declare i, Integer
   Declare a, Float
   Declare b, Float

   F_STORE 3.14,a
   F_STORE 2.0,b

   I_STORE 1,i
   lb&1:
   F_MUL a,b,T&1
   F_STORE T&1,a

   INC i
   I_CMP i,10
   JLE lb&1

   F_CMP a,100.0
   JL lb&2
   CALL print, a
   lb&2:

   HALT Example
   ```

## Make Targets

| Target | Description |
|--------|-------------|
| `make` | Build the compiler |
| `make clean` | Remove generated files |
| `make test` | Run all tests |
| `make docs` | Generate documentation |
| `make format` | Format source code |
| `make install` | Install to /usr/local/bin |
| `make debug` | Build with debug symbols |
| `make help` | Show available targets |

## Development

### Adding New Features

1. **Update Grammar**: Modify `src/parser.y`
2. **Update Lexer**: Modify `src/lexer.l`
3. **Add Tests**: Create new test file in `tests/`
4. **Update Documentation**: Modify files in `docs/`

### Running Tests

```bash
# Run specific test
make test-declarations

# Run all tests
make test

# Debug build and test
make debug && make test
```

### Code Formatting

```bash
# Format all source files
make format
```

## Documentation

- **compiler-guide.md**: Complete technical documentation
- **Example programs**: See `tests/` directory
- **Generated documentation**: Run `make docs`

## Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Add tests for new features
5. Submit a pull request

## License

MIT License - See LICENSE file for details

## Support

For bug reports and feature requests, please:
1. Check existing issues
2. Create a new issue with detailed description
3. Include example code and error messages

## Authors

Your Name
Contact: your.email@example.com
