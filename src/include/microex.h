/**
 * @file microex.h
 * @brief Common declarations and data structures for the Micro/Ex compiler
 */

#ifndef MICROEX_H
#define MICROEX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */
#define MAX_SYMBOLS 1000
#define MAX_TEMPS 100
#define MAX_LABELS 100
#define MAX_ID_LENGTH 50
#define MAX_TYPE_LENGTH 20

/* Symbol table entry structure */
typedef struct {
    char name[MAX_ID_LENGTH];
    char type[MAX_TYPE_LENGTH];    // "integer", "float", "integer_array", "float_array"
    int array_size;               // 0 for non-arrays
    int declared;                 // Declaration flag
} symbol_t;

/* Extern declarations for global variables */
extern symbol_t symbol_table[MAX_SYMBOLS];
extern int symbol_count;
extern int temp_count;
extern int label_count;
extern int line_num;
extern FILE* yyin;
extern int yylineno;

/* Function declarations for lexer/parser */
extern int yylex(void);
extern int yyparse(void);
extern void yyerror(const char* s);

/* Symbol table management */
int lookup_symbol(const char* name);
int add_symbol(const char* name, const char* type, int array_size);

/* Code generation utilities */
char* new_temp(void);
char* new_label(void);

/* Error handling */
void error(const char* format, ...);
void warning(const char* format, ...);

/* Initialization */
void init_compiler(void);
void cleanup_compiler(void);

/* Debug utilities */
#ifdef DEBUG
void dump_symbol_table(void);
void print_debug(const char* format, ...);
#endif

#endif /* MICROEX_H */