
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
YACC = yacc
LEX = lex
YFLAGS = -d -v
LFLAGS =

# Default target
.PHONY: all clean test-declarations test-assignments test-for-loops test-if-statements test-all

all: microex

# Build the compiler
microex: lex.yy.c y.tab.c
	@echo "Building microex compiler..."
	@$(CC) $(CFLAGS) -o microex lex.yy.c y.tab.c -ly -lfl
	@echo "Build successful!"

# Generate parser from yacc
y.tab.c y.tab.h: microex.y
	@echo "Generating parser..."
	@$(YACC) $(YFLAGS) microex.y
	@if [ ! -f y.tab.c ] || [ ! -f y.tab.h ]; then \
		echo "Error: Parser generation failed"; \
		exit 1; \
	fi

# Generate lexer from lex
lex.yy.c: microex.l y.tab.h
	@echo "Generating lexer..."
	@$(LEX) $(LFLAGS) microex.l
	@if [ ! -f lex.yy.c ]; then \
		echo "Error: Lexer generation failed"; \
		exit 1; \
	fi

# Clean up generated files
clean:
	@echo "Cleaning generated files..."
	@rm -f lex.yy.c y.tab.c y.tab.h y.output microex *.o
	@echo "Clean complete"

# Test targets for different grading levels
test-declarations: microex
	@echo "Testing declarations..."
	@./microex test_declarations.microex

test-assignments: microex
	@echo "Testing assignments..."
	@./microex test_assignments.microex

test-for-loops: microex
	@echo "Testing FOR loops..."
	@./microex test_for_loops.microex

test-if-statements: microex
	@echo "Testing IF statements..."
	@./microex test_if_statements.microex

test-all: microex test-declarations test-assignments test-for-loops test-if-statements
	@echo "Testing complete implementation..."
	@./microex test_complete.microex
	@echo "All tests completed!"
