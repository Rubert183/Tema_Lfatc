
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

%token CLASS_MK MAIN_MK PRINT RETURN
%token ASSIGN EQ NEQ LE GE LT GT NR 
%token IF WHILE ELSE TRU FLS
%token <intVal> INT_CONST
%token <floatVal> FLOAT_CONST
%token <strVal> STRING_CONST
%token <strVal> ID TYPE
%start progr

%left '+' '-' 
%left '*' '/' '%'



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
list_var : ID
         | ID ',' list_var
         ;

var : TYPE list_var ';'
    | ID list_var ';'
    ;

func: TYPE ID '(' opt_param_list ')' '{' code_block '}' ';'
    | ID ID '(' opt_param_list ')' '{' code_block '}' ';'
    ;

opt_param_list : 
               | param_list 
               ;

param_list : param
           | param_list ','  param 
           ;

param : TYPE ID 
      | ID ID
      ; 

class : CLASS_MK ID '{' class_list '}' ';'
      ;

class_list : field
           | method
           | class_list ',' field
           | class_list ',' method
           ;

field : TYPE ID
      | ID ID 
      ;

method : TYPE ID '(' opt_param_list ')' '{' code_block '}'
       | ID ID '(' opt_param_list ')' '{' code_block '}'
       ;

main : TYPE MAIN_MK '(' ')' '{' code_block_no_definitions '}'
     ;

code_block_no_definitions : 
                          | if_else_st code_block_no_definitions
                          | if_st code_block_no_definitions
                          | func_call ';' code_block_no_definitions
                          | method_call ';' code_block_no_definitions
                          | while_loop code_block_no_definitions
                          | assign_statement ';' code_block_no_definitions
                          | print_statement ';' code_block_no_definitions
                          | return_val ';'
                          | return_nothing ';'
                          ;

code_block : 
           | if_else_st code_block
           | if_st code_block
           | func_call ';' code_block
           | method_call ';' code_block
           | while_loop code_block
           | assign_statement ';' code_block
           | var_definition code_block
           | print_statement ';' code_block_no_definitions
           | return_nothing ';'
           | return_val ';'
           ;

print_statement : PRINT '(' print_list ')'
                ;

print_list : print_element
           | print_element ',' print_list
           ;

print_element : STRING_CONST
              | any_value
              ;

if_else_st : IF '(' logic_expression ')' '{' code_block_no_definitions '}' ELSE '{' code_block_no_definitions '}'
           ;

if_st : IF '(' logic_expression ')' '{' code_block_no_definitions '}'
      ;

func_call : ID '(' call_param_list ')'
          ;

class_element : ID '.' ID 
              | ID '.' class_element
              ;

method_call : class_element '(' call_param_list ')'
            ;

while_loop : WHILE '(' logic_expression ')' '{' code_block_no_definitions '}'
           ;

assign_statement : class_element {/*va trebui verificat ca nu-i ID-ul unei functii*/} ASSIGN expression_or_logic
                 | ID ASSIGN expression_or_logic
                 ;

expression_or_logic
    : expression
    | logic_expression
    ;


return_val : RETURN any_value
           | RETURN STRING_CONST
           ;

return_nothing : RETURN
               ;

var_definition : var
               ;

any_value : func_call
          | method_call
          | class_element
          | TRU
          | FLS
          | ID
          | INT_CONST
          | FLOAT_CONST
          ;

any_value_no_bool_const : func_call
                        | method_call
                        | class_element
                        | ID
                        | INT_CONST
                        | FLOAT_CONST
                        ;

logic_expression
    : expression bool_operator expression
    | TRU
    | FLS
    ;

bool_operator
    : LT
    | EQ
    | NEQ
    | GT
    | LE
    | GE
    ;

expression : expression '+' expression
           | expression '-' expression
           | expression '/' expression
           | expression '*' expression
           | expression '%' expression
           | any_value_no_bool_const
           ;

call_param_list : 
                | any_value ',' call_param_list
                | any_value
                ;

%%
void yyerror(const char * s){
     cout << "error:" << s << " at line: " << yylineno << endl;
}

int main(int argc, char** argv){
     yyin=fopen(argv[1],"r");
     const string global="global";
     current = new SymTable(global);
     yyparse();
     //cout << "Variables:" <<endl;
     //current->printVars();
     delete current;
} 