%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 1000
#define MAX_TEMPS 100
#define MAX_LABELS 100

extern int yylineno;
extern char* yytext;
extern int line_num;
extern void init_lexer();

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
char* new_temp(void);
char* new_label(void);
%}

%union {
    int intval;
    float floatval;
    char* strval;
    struct {
        char* addr;
        char* type;
    } expr;
    struct {
        char* text;
        int is_array;
        int array_size;
    } id_attr;
}

%token <strval> IDENTIFIER
%token <intval> INTEGER_LITERAL
%token <floatval> FLOAT_LITERAL

%type <strval> type_spec
%type <id_attr> identifier_list array_identifier
%type <expr> expression

%token PROGRAM BEGIN_ END DECLARE AS INTEGER_TYPE FLOAT_TYPE
%token FOR TO DOWNTO ENDFOR IF THEN ELSE ENDIF PRINT
%token ASSIGN SEMICOLON COMMA LPAREN RPAREN LBRACKET RBRACKET
%token PLUS MINUS MULTIPLY DIVIDE GE LE GT LT EQ NE

%left PLUS MINUS
%left MULTIPLY DIVIDE
%right UMINUS

%%

program:
    PROGRAM IDENTIFIER
    {
        if (!$2) {
            yyerror("Invalid program name");
            return 1;
        }
        printf("START %s\n\n", $2);
    }
    program_body
    {
        printf("HALT %s\n\n", $2);
    }
    ;

program_body:
    BEGIN_ declaration_list statement_list END
    ;

declaration_list:
    /* empty */
    | declaration_list declaration
    ;

declaration:
    DECLARE identifier_list AS type_spec SEMICOLON
    {
        char* list = strdup($2.text);
        char* token = strtok(list, ",");
        while (token) {
            while (*token == ' ') token++;
            char* end = token + strlen(token) - 1;
            while (end > token && *end == ' ') end--;
            *(end + 1) = 0;

            char* bracket = strchr(token, '[');
            if (bracket) {
                *bracket = '\0';
                int size;
                if (sscanf(bracket + 1, "%d]", &size) != 1) {
                    yyerror("Invalid array declaration");
                    return 1;
                }
                char array_type[30];
                sprintf(array_type, "%s_array", $4);
                if (add_symbol(token, array_type, size) == -1) return 1;
                printf("Declare %s, %s,%d\n", token,
                       strcmp($4, "integer") == 0 ? "Integer_array" : "Float_array",
                       size);
            } else {
                if (add_symbol(token, $4, 0) == -1) return 1;
                printf("Declare %s, %s\n", token,
                       strcmp($4, "integer") == 0 ? "Integer" : "Float");
            }
            token = strtok(NULL, ",");
        }
        free(list);
        printf("\n");
    }
    ;

identifier_list:
    array_identifier
    {
        $$.text = $1.text;
        $$.is_array = $1.is_array;
        $$.array_size = $1.array_size;
    }
    | identifier_list COMMA array_identifier
    {
        $$.text = malloc(strlen($1.text) + strlen($3.text) + 2);
        sprintf($$.text, "%s,%s", $1.text, $3.text);
        free($1.text);
        $$.is_array = $3.is_array;
        $$.array_size = $3.array_size;
    }
    ;

array_identifier:
    IDENTIFIER
    {
        $$.text = strdup($1);
        $$.is_array = 0;
        $$.array_size = 0;
    }
    | IDENTIFIER LBRACKET INTEGER_LITERAL RBRACKET
    {
        $$.text = malloc(strlen($1) + 20);
        sprintf($$.text, "%s[%d]", $1, $3);
        $$.is_array = 1;
        $$.array_size = $3;
    }
    ;

type_spec:
    INTEGER_TYPE { $$ = strdup("integer"); }
    | FLOAT_TYPE { $$ = strdup("float"); }
    ;

statement_list:
    /* empty */
    | statement_list statement
    ;

statement:
    assignment_statement
    | for_statement
    | if_statement
    | print_statement
    ;

assignment_statement:
    IDENTIFIER ASSIGN expression SEMICOLON
    {
        int idx = lookup_symbol($1);
        if (idx == -1) {
            yyerror("Undefined variable");
            return 1;
        }
        if (strstr(symbol_table[idx].type, "array")) {
            yyerror("Cannot assign to array");
            return 1;
        }
        char* store_op = strstr(symbol_table[idx].type, "integer") ? "I_STORE" : "F_STORE";
        printf("%s %s,%s\n\n", store_op, $3.addr, $1);
    }
    | IDENTIFIER LBRACKET expression RBRACKET ASSIGN expression SEMICOLON
    {
        int idx = lookup_symbol($1);
        if (idx == -1) {
            yyerror("Undefined array");
            return 1;
        }
        if (!strstr(symbol_table[idx].type, "array")) {
            yyerror("Not an array");
            return 1;
        }
        char* store_op = strstr(symbol_table[idx].type, "integer") ? "I_STORE" : "F_STORE";
        printf("%s %s,%s[%s]\n\n", store_op, $6.addr, $1, $3.addr);
    }
    ;

for_statement:
    FOR LPAREN IDENTIFIER ASSIGN expression TO expression RPAREN statement_list ENDFOR
    {
        char* loop_label = new_label();
        printf("I_STORE %s,%s\n", $5.addr, $3);
        printf("%s:\n", loop_label);
        printf("INC %s\n", $3);
        printf("I_CMP %s,%s\n", $3, $7.addr);
        printf("JLE %s\n\n", loop_label);
    }
    | FOR LPAREN IDENTIFIER ASSIGN expression DOWNTO expression RPAREN statement_list ENDFOR
    {
        char* loop_label = new_label();
        printf("I_STORE %s,%s\n", $5.addr, $3);
        printf("%s:\n", loop_label);
        printf("DEC %s\n", $3);
        printf("I_CMP %s,%s\n", $3, $7.addr);
        printf("JGE %s\n\n", loop_label);
    }
    ;

if_statement:
    IF LPAREN condition RPAREN THEN statement_list ENDIF
    | IF LPAREN condition RPAREN THEN statement_list ELSE statement_list ENDIF
    ;

condition:
    expression GE expression { printf("F_CMP %s,%s\nJL ", $1.addr, $3.addr); }
    | expression LE expression { printf("F_CMP %s,%s\nJG ", $1.addr, $3.addr); }
    | expression GT expression { printf("F_CMP %s,%s\nJLE ", $1.addr, $3.addr); }
    | expression LT expression { printf("F_CMP %s,%s\nJGE ", $1.addr, $3.addr); }
    | expression EQ expression { printf("F_CMP %s,%s\nJNE ", $1.addr, $3.addr); }
    | expression NE expression { printf("F_CMP %s,%s\nJE ", $1.addr, $3.addr); }
    ;

print_statement:
    PRINT LPAREN expression RPAREN SEMICOLON
    {
        printf("CALL print, %s\n\n", $3.addr);
    }
    | PRINT LPAREN expression COMMA expression RPAREN SEMICOLON
    {
        printf("CALL print,%s,%s\n\n", $3.addr, $5.addr);
    }
    ;

expression:
    INTEGER_LITERAL
    {
        $$.addr = malloc(20);
        sprintf($$.addr, "%d", $1);
        $$.type = strdup("integer");
    }
    | FLOAT_LITERAL
    {
        $$.addr = malloc(20);
        sprintf($$.addr, "%.2f", $1);
        $$.type = strdup("float");
    }
    | IDENTIFIER
    {
        int idx = lookup_symbol($1);
        if (idx == -1) {
            yyerror("Undefined variable");
            return 1;
        }
        $$.addr = strdup($1);
        $$.type = strdup(symbol_table[idx].type);
    }
    | IDENTIFIER LBRACKET expression RBRACKET
    {
        int idx = lookup_symbol($1);
        if (idx == -1) {
            yyerror("Undefined array");
            return 1;
        }
        $$.addr = malloc(strlen($1) + strlen($3.addr) + 3);
        sprintf($$.addr, "%s[%s]", $1, $3.addr);
        $$.type = strdup("float");
    }
    | expression PLUS expression
    {
        char* temp = new_temp();
        printf("F_ADD %s,%s,%s\n", $1.addr, $3.addr, temp);
        $$.addr = temp;
        $$.type = strdup("float");
    }
    | expression MINUS expression
    {
        char* temp = new_temp();
        printf("F_SUB %s,%s,%s\n", $1.addr, $3.addr, temp);
        $$.addr = temp;
        $$.type = strdup("float");
    }
    | expression MULTIPLY expression
    {
        char* temp = new_temp();
        printf("F_MUL %s,%s,%s\n", $1.addr, $3.addr, temp);
        $$.addr = temp;
        $$.type = strdup("float");
    }
    | expression DIVIDE expression
    {
        char* temp = new_temp();
        printf("F_DIV %s,%s,%s\n", $1.addr, $3.addr, temp);
        $$.addr = temp;
        $$.type = strdup("float");
    }
    | MINUS expression %prec UMINUS
    {
        char* temp = new_temp();
        printf("F_UMINUS %s,%s\n", $2.addr, temp);
        $$.addr = temp;
        $$.type = strdup("float");
    }
    | LPAREN expression RPAREN
    {
        $$ = $2;
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error at line %d: %s\n", line_num, s);
}

int lookup_symbol(const char* name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int add_symbol(const char* name, const char* type, int array_size) {
    if (symbol_count >= MAX_SYMBOLS) {
        yyerror("Symbol table overflow");
        return -1;
    }
    if (lookup_symbol(name) != -1) {
        yyerror("Variable already declared");
        return -1;
    }

    strcpy(symbol_table[symbol_count].name, name);
    strcpy(symbol_table[symbol_count].type, type);
    symbol_table[symbol_count].array_size = array_size;
    symbol_table[symbol_count].declared = 1;

    return symbol_count++;
}

char* new_temp(void) {
    char* temp = malloc(10);
    sprintf(temp, "T&%d", temp_count++);
    return temp;
}

char* new_label(void) {
    char* label = malloc(10);
    sprintf(label, "lb&%d", label_count++);
    return label;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file.microex>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Error: Cannot open input file '%s'\n", argv[1]);
        return 1;
    }

    extern FILE* yyin;
    yyin = fp;
    init_lexer();
    int result = yyparse();
    fclose(fp);
    return result;
}
