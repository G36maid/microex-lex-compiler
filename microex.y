
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 1000
#define MAX_TEMPS 100
#define MAX_LABELS 100

// Symbol table entry
typedef struct {
    char name[50];
    char type[20];    // "integer", "float", "integer_array", "float_array"
    int array_size;   // 0 for non-arrays
    int declared;
} symbol_t;

// Symbol table
symbol_t symbol_table[MAX_SYMBOLS];
int symbol_count = 0;
int temp_count = 0;
int label_count = 0;

// Function prototypes
void yyerror(const char* s);
int yylex(void);
int lookup_symbol(const char* name);
int add_symbol(const char* name, const char* type, int array_size);
char* new_temp(const char* type);
char* new_label();
void gen_code(const char* op, const char* arg1, const char* arg2, const char* result);
void gen_label(const char* label);
void gen_jump(const char* label);
void gen_conditional_jump(const char* op, const char* label);

extern FILE* yyout;
%}

%union {
    int intval;
    float floatval;
    char* strval;
    struct {
        char* addr;
        char* type;
    } expr_attr;
}

%token <strval> IDENTIFIER
%token <intval> INTEGER_LITERAL
%token <floatval> FLOAT_LITERAL
%token PROGRAM BEGIN_ END DECLARE AS INTEGER_TYPE FLOAT_TYPE
%token FOR TO DOWNTO ENDFOR IF THEN ELSE ENDIF PRINT
%token ASSIGN SEMICOLON COMMA LPAREN RPAREN LBRACKET RBRACKET
%token PLUS MINUS MULTIPLY DIVIDE
%token GE LE GT LT EQ NE

%type <expr_attr> expression
%type <strval> identifier_list
%type <strval> type_spec

%left PLUS MINUS
%left MULTIPLY DIVIDE
%left GE LE GT LT EQ NE
%right UMINUS

%%

program:
    PROGRAM IDENTIFIER { 
        printf("START %s\n", $2); 
        printf("\n"); 
    }
    program_body {
        printf("HALT %s\n", $2);
        // Print temporary variable declarations
        for(int i = 1; i < temp_count; i++) {
            printf("\nDeclare T&%d, Float\n", i);
        }
    }
    ;

program_body:
    BEGIN_ declaration_list statement_list END
    ;

declaration_list:
    declaration_list declaration
    | declaration
    ;

declaration:
    DECLARE identifier_list AS type_spec SEMICOLON {
        // Process the identifier list and type
        char* token = strtok($2, ",");
        while(token != NULL) {
            // Remove leading/trailing spaces
            while(*token == ' ') token++;
            char* end = token + strlen(token) - 1;
            while(end > token && *end == ' ') end--;
            *(end + 1) = 0;

            // Check for array notation [size]
            char* bracket = strchr(token, '[');
            if(bracket) {
                *bracket = 0;
                bracket++;
                char* close_bracket = strchr(bracket, ']');
                if(close_bracket) {
                    *close_bracket = 0;
                    int array_size = atoi(bracket);
                    char array_type[30];
                    sprintf(array_type, "%s_array", $4);
                    add_symbol(token, array_type, array_size);
                    printf("Declare %s, %s,%d\n", token, 
                           strcmp($4, "integer") == 0 ? "Integer_array" : "Float_array", 
                           array_size);
                }
            } else {
                add_symbol(token, $4, 0);
                printf("Declare %s, %s\n", token, 
                       strcmp($4, "integer") == 0 ? "Integer" : "Float");
            }
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
    ;

identifier_list:
    identifier_list COMMA IDENTIFIER {
        $$ = malloc(strlen($1) + strlen($3) + 2);
        sprintf($$, "%s,%s", $1, $3);
    }
    | IDENTIFIER {
        $$ = strdup($1);
    }
    ;

type_spec:
    INTEGER_TYPE { $$ = strdup("integer"); }
    | FLOAT_TYPE { $$ = strdup("float"); }
    ;

statement_list:
    statement_list statement
    | statement
    ;

statement:
    assignment_statement
    | for_statement  
    | if_statement
    | print_statement
    ;

assignment_statement:
    IDENTIFIER ASSIGN expression SEMICOLON {
        int sym_idx = lookup_symbol($1);
        if(sym_idx == -1) {
            yyerror("Undeclared variable");
            return 1;
        }

        symbol_t* sym = &symbol_table[sym_idx];
        if(strcmp(sym->type, "integer") == 0) {
            printf("I_STORE %s,%s\n", $3.addr, $1);
        } else {
            printf("F_STORE %s,%s\n", $3.addr, $1);
        }
        printf("\n");
    }
    | IDENTIFIER LBRACKET expression RBRACKET ASSIGN expression SEMICOLON {
        int sym_idx = lookup_symbol($1);
        if(sym_idx == -1) {
            yyerror("Undeclared array variable");
            return 1;
        }

        symbol_t* sym = &symbol_table[sym_idx];
        if(strstr(sym->type, "integer") != NULL) {
            printf("I_STORE %s,%s[%s]\n", $6.addr, $1, $3.addr);
        } else {
            printf("F_STORE %s,%s[%s]\n", $6.addr, $1, $3.addr);
        }
        printf("\n");
    }
    ;

for_statement:
    FOR LPAREN IDENTIFIER ASSIGN expression TO expression RPAREN statement_list ENDFOR {
        char* loop_label = new_label();
        char* end_label = new_label();

        // Initialize loop variable
        printf("I_STORE %s,%s\n", $5.addr, $3);

        // Loop start label
        printf("%s: \n", loop_label);

        // Generate statements in loop body (already handled in statement_list)

        // Increment loop variable
        printf("INC %s\n", $3);

        // Compare and conditional jump
        printf("I_CMP %s,%s\n", $3, $7.addr);
        printf("JLE %s\n", loop_label);

        printf("\n");
    }
    | FOR LPAREN IDENTIFIER ASSIGN expression DOWNTO expression RPAREN statement_list ENDFOR {
        char* loop_label = new_label();
        char* end_label = new_label();

        // Initialize loop variable  
        printf("I_STORE %s,%s\n", $5.addr, $3);

        // Loop start label
        printf("%s: \n", loop_label);

        // Generate statements in loop body (already handled in statement_list)

        // Decrement loop variable
        printf("DEC %s\n", $3);

        // Compare and conditional jump
        printf("I_CMP %s,%s\n", $3, $7.addr);
        printf("JGE %s\n", loop_label);

        printf("\n");
    }
    ;

if_statement:
    IF LPAREN expression GE expression RPAREN THEN statement_list ENDIF {
        char* false_label = new_label();

        printf("F_CMP %s,%s\n", $3.addr, $5.addr);
        printf("JL %s\n", false_label);
        printf("\n");

        // True block statements already generated in statement_list

        printf("%s: \n", false_label);
    }
    | IF LPAREN expression LE expression RPAREN THEN statement_list ENDIF {
        char* false_label = new_label();

        printf("F_CMP %s,%s\n", $3.addr, $5.addr);
        printf("JG %s\n", false_label);
        printf("\n");

        // True block statements already generated in statement_list

        printf("%s: \n", false_label);
    }
    | IF LPAREN expression GT expression RPAREN THEN statement_list ENDIF {
        char* false_label = new_label();

        printf("F_CMP %s,%s\n", $3.addr, $5.addr);
        printf("JLE %s\n", false_label);
        printf("\n");

        // True block statements already generated in statement_list

        printf("%s: \n", false_label);
    }
    | IF LPAREN expression LT expression RPAREN THEN statement_list ENDIF {
        char* false_label = new_label();

        printf("F_CMP %s,%s\n", $3.addr, $5.addr);
        printf("JGE %s\n", false_label);
        printf("\n");

        // True block statements already generated in statement_list

        printf("%s: \n", false_label);
    }
    | IF LPAREN expression GE expression RPAREN THEN statement_list ELSE statement_list ENDIF {
        char* false_label = new_label();
        char* end_label = new_label();

        printf("F_CMP %s,%s\n", $3.addr, $5.addr);
        printf("JL %s\n", false_label);
        printf("\n");

        // True block statements already generated
        printf("J %s\n", end_label);

        printf("%s: \n", false_label);
        // False block statements already generated

        printf("%s: \n", end_label);
    }
    ;

print_statement:
    PRINT LPAREN expression RPAREN SEMICOLON {
        printf("CALL print, %s\n", $3.addr);
        printf("\n");
    }
    | PRINT LPAREN expression COMMA expression RPAREN SEMICOLON {
        printf("CALL print,%s,%s\n", $3.addr, $5.addr);
        printf("\n");
    }
    ;

expression:
    INTEGER_LITERAL {
        $$.addr = malloc(20);
        sprintf($$.addr, "%d", $1);
        $$.type = strdup("integer");
    }
    | FLOAT_LITERAL {
        $$.addr = malloc(20);
        sprintf($$.addr, "%.2f", $1);
        $$.type = strdup("float");
    }
    | IDENTIFIER {
        int sym_idx = lookup_symbol($1);
        if(sym_idx == -1) {
            yyerror("Undeclared variable");
            return 1;
        }
        $$.addr = strdup($1);
        $$.type = strdup(symbol_table[sym_idx].type);
    }
    | IDENTIFIER LBRACKET expression RBRACKET {
        int sym_idx = lookup_symbol($1);
        if(sym_idx == -1) {
            yyerror("Undeclared array variable");
            return 1;
        }
        $$.addr = malloc(strlen($1) + strlen($3.addr) + 4);
        sprintf($$.addr, "%s[%s]", $1, $3.addr);
        $$.type = strdup("float"); // Assume float arrays for simplicity
    }
    | expression PLUS expression {
        char* temp = new_temp("float");
        printf("F_ADD %s,%s,%s\n", $1.addr, $3.addr, temp);
        $$.addr = strdup(temp);
        $$.type = strdup("float");
    }
    | expression MINUS expression {
        char* temp = new_temp("float");
        printf("F_SUB %s,%s,%s\n", $1.addr, $3.addr, temp);
        $$.addr = strdup(temp);
        $$.type = strdup("float");
    }
    | expression MULTIPLY expression {
        char* temp = new_temp("float");
        printf("F_MUL %s,%s,%s\n", $1.addr, $3.addr, temp);
        $$.addr = strdup(temp);
        $$.type = strdup("float");
    }
    | expression DIVIDE expression {
        char* temp = new_temp("float");
        printf("F_DIV %s,%s,%s\n", $1.addr, $3.addr, temp);
        $$.addr = strdup(temp);
        $$.type = strdup("float");
    }
    | MINUS expression %prec UMINUS {
        char* temp = new_temp("float");
        printf("F_UMINUS %s,%s\n", $2.addr, temp);
        $$.addr = strdup(temp);
        $$.type = strdup("float");
    }
    | LPAREN expression RPAREN {
        $$ = $2;
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}

int lookup_symbol(const char* name) {
    for(int i = 0; i < symbol_count; i++) {
        if(strcmp(symbol_table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int add_symbol(const char* name, const char* type, int array_size) {
    if(symbol_count >= MAX_SYMBOLS) {
        yyerror("Symbol table overflow");
        return -1;
    }

    if(lookup_symbol(name) != -1) {
        yyerror("Variable already declared");
        return -1;
    }

    strcpy(symbol_table[symbol_count].name, name);
    strcpy(symbol_table[symbol_count].type, type);
    symbol_table[symbol_count].array_size = array_size;
    symbol_table[symbol_count].declared = 1;

    return symbol_count++;
}

char* new_temp(const char* type) {
    char* temp = malloc(10);
    sprintf(temp, "T&%d", temp_count++);
    return temp;
}

char* new_label() {
    char* label = malloc(10);
    sprintf(label, "lb&%d", label_count++);
    return label;
}

int main(int argc, char** argv) {
    if(argc > 1) {
        FILE* fp = fopen(argv[1], "r");
        if(fp) {
            extern FILE* yyin;
            yyin = fp;
        }
    }
    return yyparse();
}
