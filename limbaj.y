
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
     std::string* Str;
}

//%destructor { delete $$; } <Str> 

%token MAIN_MK BGIN END ASSIGN NR 
%token<Str> ID TYPE
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
               ;

class : ID '{' param_list '}'
      ;

param_list : param
           | param_list ','  param 
           ;

opt_param_list : 
               | param_list
               ;

param : TYPE ID 
      ; 

func: TYPE ID '(' opt_param_list ')' '{' code_block '}'
    ;

main : TYPE MAIN_MK '(' ')' '{' code_block '}'
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
     cout << "Variables:" <<endl;
     current->printVars();
     delete current;
} 