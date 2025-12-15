%{
#include <stdio.h>
#include "limbaj.tab.h"
#include <string>
%}
%option noyywrap
%%
"int"|"float"|"bool"|"string" {yylval.strVal = new std::string(yytext); return TYPE;}
"return" {return RETURN;}
"true" {return TRU;}
"false" {return FLS;}
"main" {return MAIN_MK;}
"class" {return CLASS_MK;}
"if" { return IF; }
"while" { return WHILE; }
"else" { return ELSE; }
[a-zA-Z][a-zA-Z0-9]* {yylval.strVal = new std::string(yytext); return ID;}
":=" {return ASSIGN;}
"==" { return EQ; }
"<=" { return LE; }
">=" { return GE; }
"<"  { return LT; }
">"  { return GT; }
[0-9]+ { yylval.intVal = atoi(yytext); return INT_CONST; }
[0-9]+\.[0-9]+ { yylval.floatVal = atof(yytext); return FLOAT_CONST; }
\"[^\"]*\" { yylval.strVal = new std::string(yytext+1, strlen(yytext)-2); return STRING_CONST; }
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}

 
