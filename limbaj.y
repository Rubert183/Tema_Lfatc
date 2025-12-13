
%code requires {
  #include <string>
  using namespace std;
}

%{
#include <iostream>
#include "SymTable.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yylex();
void yyerror(const char * s);
class SymTable* current;
int errorCount = 0;
%}

%union {
    int intVal;
    float floatVal;
    std::string* strVal;
    struct Expr {
        std::string* type;
        int i;
        float f;
        std::string* s;
    } *expr;
}

//%destructor { delete $$; } <Str> 

%token CLASS_MK MAIN_MK 
%token ASSIGN EQ LE GE LT GT NR 
%token IF WHILE ELSE
%token <intVal> INT_CONST
%token <floatVal> FLOAT_CONST
%token <strVal> STRING_CONST
%token <strVal> ID TYPE
%start progr

%left '+' '-' 
%left '*' 



%%
progr : top_level main {if (errorCount == 0) cout<< "The program is correct!" << endl;}
      ;

top_level :
          | top_level top_level_decl
          ;

top_level_decl : class
               | func
               | var 
               ;

var : TYPE ID ';'
    ;

func: TYPE ID '(' opt_param_list ')' '{' code_block '}' ';'
    ;

opt_param_list : 
               | param_list
               ;

param_list : param
           | param_list ','  param 
           ;

param : TYPE ID 
      ; 

class : CLASS_MK ID '{' class_list '}' ';'
      ;

class_list : field
           | method
           | class_list ',' field
           | class_list ',' method
           ;

field : TYPE ID
    ;

method : TYPE ID '(' opt_param_list ')' '{' code_block '}'
       ;

main : MAIN_MK '(' ')' '{' code_block '}'
     ;

code_block :
           ;
%%
void yyerror(const char * s){
     cout << "error:" << s << " at line: " << yylineno << endl;
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     current = new SymTable("global");
     yyparse();
     //cout << "Variables:" <<endl;
     //current->printVars();
     delete current;
} 