
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

extern void yyerror(const char* s);
%}

%option nounput
%option noinput

letter      [A-Za-z]
digit       [0-9]
identifier  {letter}({letter}|{digit})*
integer     {digit}+
floatnumber {digit}+"."{digit}+

%%

"Program"       { return PROGRAM; }
"Begin"         { return BEGIN_; }
"End"           { return END; }
"declare"       { return DECLARE; }
"as"            { return AS; }
"integer"       { return INTEGER_TYPE; }
"float"         { return FLOAT_TYPE; }
"FOR"           { return FOR; }
"TO"            { return TO; }
"DOWNTO"        { return DOWNTO; }
"ENDFOR"        { return ENDFOR; }
"IF"            { return IF; }
"THEN"          { return THEN; }
"ELSE"          { return ELSE; }
"ENDIF"         { return ENDIF; }
"print"         { return PRINT; }

":="            { return ASSIGN; }
";"             { return SEMICOLON; }
","             { return COMMA; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULTIPLY; }
"/"             { return DIVIDE; }
">="            { return GE; }
"<="            { return LE; }
">"             { return GT; }
"<"             { return LT; }
"=="            { return EQ; }
"!="            { return NE; }

{identifier}    { 
                    yylval.strval = strdup(yytext); 
                    return IDENTIFIER; 
                }

{integer}       { 
                    yylval.intval = atoi(yytext); 
                    return INTEGER_LITERAL; 
                }

{floatnumber}   { 
                    yylval.floatval = atof(yytext); 
                    return FLOAT_LITERAL; 
                }

[ \t]+          { /* ignore whitespace */ }
\n             { /* ignore newlines */ }

.               { yyerror("Invalid character"); }

%%

int yywrap() {
    return 1;
}
