#!/bin/bash

echo "=== Building Micro/Ex Compiler ==="

# Clean previous builds
make clean

echo "Generating parser with yacc..."
yacc -d microex.y

echo "Generating lexer with lex..."
lex microex.l

echo "Compiling with gcc..."
gcc -g -Wall -o microex lex.yy.c y.tab.c -ly -lfl

if [ $? -eq 0 ]; then
    echo "✓ Compiler built successfully!"
    echo ""

    echo "=== Testing Different Grading Levels ==="

    echo ""
    echo "1. Testing Variable Declarations (70 points):"
    echo "Input:"
    cat test_declarations.microex
    echo ""
    echo "Output:"
    ./microex test_declarations.microex
    echo ""

    echo "2. Testing Variable Declarations + Assignments (80 points):"
    echo "Input:"
    cat test_assignments.microex
    echo ""
    echo "Output:"
    ./microex test_assignments.microex
    echo ""

    echo "3. Testing with FOR loops (85 points):"
    echo "Input:"
    cat test_for_loops.microex
    echo ""
    echo "Output:"
    ./microex test_for_loops.microex
    echo ""

    echo "4. Testing Complete Implementation with IF-THEN-ELSE (90 points):"
    echo "Input:"
    cat test_complete.microex
    echo ""
    echo "Output:"
    ./microex test_complete.microex
    echo ""

    echo "5. Testing PDF Example:"
    echo "Input:"
    cat test_pdf_example.microex
    echo ""
    echo "Output:"
    ./microex test_pdf_example.microex

else
    echo "✗ Compilation failed!"
    exit 1
fi
