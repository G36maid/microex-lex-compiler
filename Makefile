# Micro/Ex Compiler Makefile

# Compiler and flags
CC = gcc
CFLAGS = -g -Wall -Wextra -I./src/include
LDFLAGS = -ly -lfl
YACC = yacc
LEX = lex
YFLAGS = -d -v
LFLAGS =

# Directories
SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests
DOC_DIR = docs

# Source files
LEX_SRC = $(SRC_DIR)/lexer.l
YACC_SRC = $(SRC_DIR)/parser.y
HEADERS = $(wildcard $(SRC_DIR)/include/*.h)

# Generated files
YACC_C = $(BUILD_DIR)/y.tab.c
YACC_H = $(BUILD_DIR)/y.tab.h
LEX_C = $(BUILD_DIR)/lex.yy.c
TARGET = microex

# Default target
.PHONY: all
all: prepare $(TARGET)

# Prepare build directory
prepare:
	@mkdir -p $(BUILD_DIR)

# Build the compiler
$(TARGET): $(YACC_C) $(LEX_C)
	@echo "Building $(TARGET)..."
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Build successful!"

# Generate parser from yacc
$(YACC_C) $(YACC_H): $(YACC_SRC)
	@echo "Generating parser..."
	@$(YACC) $(YFLAGS) -b $(BUILD_DIR)/y $<
	@if [ ! -f $(YACC_C) ] || [ ! -f $(YACC_H) ]; then \
		echo "Error: Parser generation failed"; \
		exit 1; \
	fi

# Generate lexer from lex
$(LEX_C): $(LEX_SRC) $(YACC_H)
	@echo "Generating lexer..."
	@$(LEX) $(LFLAGS) -o $@ $<
	@if [ ! -f $(LEX_C) ]; then \
		echo "Error: Lexer generation failed"; \
		exit 1; \
	fi

# Clean up generated files
.PHONY: clean
clean:
	@echo "Cleaning generated files..."
	@rm -rf $(BUILD_DIR) $(TARGET)
	@echo "Clean complete"

# Test targets
.PHONY: test test-declarations test-assignments test-for-loops test-if-statements test-complete

test: test-declarations test-assignments test-for-loops test-complete
	@echo "All tests completed!"

test-declarations: $(TARGET)
	@echo "Testing declarations..."
	@./$(TARGET) $(TEST_DIR)/test_declarations.microex

test-assignments: $(TARGET)
	@echo "Testing assignments..."
	@./$(TARGET) $(TEST_DIR)/test_assignments.microex

test-for-loops: $(TARGET)
	@echo "Testing FOR loops..."
	@./$(TARGET) $(TEST_DIR)/test_for_loops.microex

test-complete: $(TARGET)
	@echo "Testing complete implementation..."
	@./$(TARGET) $(TEST_DIR)/test_complete.microex

# Documentation targets
.PHONY: docs
docs:
	@echo "Building documentation..."
	@if command -v pandoc >/dev/null 2>&1; then \
		pandoc $(DOC_DIR)/compiler-guide.md -o $(DOC_DIR)/compiler-guide.pdf; \
		echo "Documentation generated in $(DOC_DIR)/compiler-guide.pdf"; \
	else \
		echo "Error: pandoc not found. Please install pandoc to generate documentation."; \
		exit 1; \
	fi

# Development helpers
.PHONY: format
format:
	@if command -v clang-format >/dev/null 2>&1; then \
		find $(SRC_DIR) -type f -name "*.h" -o -name "*.c" | xargs clang-format -i; \
		echo "Source files formatted"; \
	else \
		echo "Error: clang-format not found. Please install clang-format to use this target."; \
		exit 1; \
	fi

# Install target (optional)
.PHONY: install
install: $(TARGET)
	@echo "Installing $(TARGET) to /usr/local/bin..."
	@sudo cp $(TARGET) /usr/local/bin/
	@echo "Installation complete"

# Debug build with symbols and debug info
.PHONY: debug
debug: CFLAGS += -DDEBUG -g3 -O0
debug: clean all

# Help target
.PHONY: help
help:
	@echo "Micro/Ex Compiler Build System"
	@echo ""
	@echo "Available targets:"
	@echo "  all              - Build the compiler (default)"
	@echo "  clean            - Remove generated files"
	@echo "  test             - Run all tests"
	@echo "  test-declarations- Test variable declarations"
	@echo "  test-assignments - Test assignment statements"
	@echo "  test-for-loops   - Test FOR loop constructs"
	@echo "  test-complete    - Test complete implementation"
	@echo "  docs             - Generate documentation (requires pandoc)"
	@echo "  format           - Format source code (requires clang-format)"
	@echo "  install          - Install compiler to /usr/local/bin"
	@echo "  debug            - Build with debug symbols"
	@echo "  help             - Show this help message"
