
CC = gcc
CFLAGS = -g -Wall
YACC = yacc
LEX = lex

# Default target
all: microex

# Build the compiler
microex: lex.yy.c y.tab.c
	$(CC) $(CFLAGS) -o microex lex.yy.c y.tab.c -ly -lfl

# Generate parser from yacc
y.tab.c y.tab.h: microex.y
	$(YACC) -d microex.y

# Generate lexer from lex
lex.yy.c: microex.l y.tab.h
	$(LEX) microex.l

# Clean up generated files
clean:
	rm -f lex.yy.c y.tab.c y.tab.h microex *.o

# Test targets for different grading levels
test-declarations: microex
	./microex test_declarations.microex

test-assignments: microex
	./microex test_assignments.microex

test-for-loops: microex
	./microex test_for_loops.microex

test-if-statements: microex
	./microex test_if_statements.microex

test-all: microex
	./microex test_complete.microex

.PHONY: all clean test-declarations test-assignments test-for-loops test-if-statements test-all
