%{
#include <stdio.h>
#include "limbaj.tab.h"
#include <string>
%}
%option noyywrap
%%
"int"|"float"|"bool"|"string" {yylval.Str = new std::string(yytext); return TYPE;}
"main" {return MAIN_MK;}
"class" {return CLASS_MK;}
[a-zA-Z][a-zA-Z0-9]* {yylval.Str = new std::string(yytext); return ID;}
":=" {return ASSIGN;}
[0-9]+ {return NR;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}

 
