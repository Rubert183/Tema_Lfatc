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
string currentType;
IdInfo *currentIdInfo;
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
%token ASSIGN EQ NEQ LE GE LT GT NR NOT AND OR
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

list_var : ID {
             if(current->existsClass(*$1)){
                 cout << "Variable " << *$1 << " has the name of a class at line " << yylineno << endl;
                 errorCount++;
             } else {
                if(current->existsFunction(*$1)){
                    cout << "Variable " << *$1 << " has the name of a function at line " << yylineno << endl;
                    errorCount++;
                }
                else{
                    if(current->existsVar(*$1)){
                        cout << "Redeclared variable " << *$1 << " at line " << yylineno << endl;
                        errorCount++;
                    } else {
                        current->addVar(currentType, *$1);
                    }
                }
             }
             
         }
         | ID {
             if(current->existsClass(*$1)){
                 cout << "Variable " << *$1 << " has the name of a class at line " << yylineno << endl;
                 errorCount++;
             } else {
                if(current->existsFunction(*$1)){
                    cout << "Variable " << *$1 << " has the name of a function at line " << yylineno << endl;
                    errorCount++;
                }
                else{
                    if(current->existsVar(*$1)){
                        cout << "Redeclared variable " << *$1 << " at line " << yylineno << endl;
                        errorCount++;
                    } else {
                        current->addVar(currentType, *$1);
                    }
                }
             }
             
         } ',' list_var
         ;

type_or_class : TYPE {currentType=*$1;}
              | ID {
                if(!current->existsClass(*$1)){
                 cout << "Undeclared class " << *$1 << " at line " << yylineno << endl;
                 errorCount++;
                }
                currentType=*$1;
              }
              ;

var : type_or_class list_var ';'
    ;

func: type_or_class ID {
             if(current->existsClass(*$2)){
                 cout << "Function " << *$2 << " has the name of a class at line " << yylineno << endl;
                 errorCount++;
             } else {
                if(current->existsVar(*$2)){
                    cout << "Function " << *$2 << " has the name of a variable at line " << yylineno << endl;
                    errorCount++;
                }
                else{
                    if(current->existsFunction(*$2)){
                        cout << "Redeclared function " << *$2 << " at line " << yylineno << endl;
                        errorCount++;
                    } else {
                        current->addFunction(currentType, *$2);
                        SymTable* funcScope = new SymTable(*$2, current);
                        currentIdInfo=current->getFunction(*$2);
                        currentIdInfo->function_scope = funcScope;
                        current = current->getFunctionScope(*$2);
                    }
                }
             }
             
         } '(' opt_param_list ')' '{' code_block '}' { 
            current=current->getParent();
         }';'
    ;

opt_param_list : 
               | param_list 
               ;

param_list : param
           | param_list ','  param 
           ;

param : type_or_class ID {
             if(current->existsClass(*$2)){
                 cout << "Parameter " << *$2 << " has the name of a class at line " << yylineno << endl;
                 errorCount++;
             } else {
                if(current->existsFunction(*$2)){
                    cout << "Parameter " << *$2 << " has the name of a function at line " << yylineno << endl;
                    errorCount++;
                }
                else{
                    if(current->existsVar(*$2)){
                        cout << "Redeclared Parameter " << *$2 << " at line " << yylineno << endl;
                        errorCount++;
                    } else {
                        currentIdInfo->add_param(currentType,*$2);
                        current->addVar(currentType, *$2);
                    }
                }
             }
             
         }
      ; 

class : CLASS_MK ID {
    string className = *$2;
        if(current->existsVar(className)){
            cout << "Class " << className << " has the name of a variable at line " << yylineno << endl;
            errorCount++;
        } else if(current->existsFunction(className)){
            cout << "Class " << className << " has the name of a function at line " << yylineno << endl;
            errorCount++;
        } else if(current->existsClass(className)){
            cout << "Redeclared class " << className << " at line " << yylineno << endl;
            errorCount++;
        } else {
            current->addClass(className);
            SymTable* classScope = new SymTable(className, current);
            current->getClass(className)->class_scope = classScope;
            current = classScope;
        }
      } '{' class_list '}' {current=current->getParent();} ';'
      ;

class_list : field
           | method
           | class_list ',' field
           | class_list ',' method
           ;

field : type_or_class ID {
        string fieldName = *$2;
        if(current->existsClass(fieldName)){
            cout << "Field " << fieldName << " has the name of a class at line " << yylineno << endl;
            errorCount++;
        } else if(current->existsFunction(fieldName)){
            cout << "Field " << fieldName << " has the name of a function at line " << yylineno << endl;
            errorCount++;
        } else if(current->existsVar(fieldName)){
            cout << "Redeclared field " << fieldName << " at line " << yylineno << endl;
            errorCount++;
        } else {
            current->addVar(currentType, fieldName); 
        }
    }   
      ;

method : type_or_class ID {
    string methodName = *$2;
    if(current->existsClass(methodName)){
        cout << "Method " << methodName << " has the name of a class at line " << yylineno << endl;
        errorCount++;
    } else if(current->existsVar(methodName)){
        cout << "Method " << methodName << " has the name of a variable at line " << yylineno << endl;
        errorCount++;
    } else if(current->existsFunction(methodName)){
        cout << "Redeclared method " << methodName << " at line " << yylineno << endl;
        errorCount++;
    } else {
        current->addFunction(currentType, methodName);
        SymTable* methodScope = new SymTable(methodName, current);
        currentIdInfo = current->getFunction(methodName);
        currentIdInfo->function_scope = methodScope;
        current = methodScope;
    }
    } '(' opt_param_list ')' '{' code_block '}' {
        current = current->getParent();
    }
       ;

main : MAIN_MK '{' main_code_block '}'
     ;

main_code_block : 
                | if_else_st main_code_block
                | if_st main_code_block
                | func_call ';' main_code_block
                | method_call ';' main_code_block
                | while_loop main_code_block
                | assign_statement ';' main_code_block
                | print_statement ';' main_code_block
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

print_statement : PRINT '(' expression ')'
                | PRINT '(' STRING_CONST ')'
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

assign_statement : class_element ASSIGN expression_or_logic
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

/*any_not_const : func_call
              | method_call
              | class_element
              | ID
              ;*/

logic_expression : logic_expression OR logic_and
                 | logic_and
                 ;

logic_and : logic_and AND logic_not
          | logic_not
          ;

logic_not : NOT logic_not
          | logic_atom
          ;

logic_atom
    : '(' logic_expression ')'
    | expression expression_comparisom expression
    | TRU
    | FLS
    ;

expression_comparisom : LT
                      | EQ
                      | NEQ
                      | GT
                      | LE
                      | GE
                      ;

expression : '(' expression ')' 
           | expression '+' expression
           | expression '-' expression
           | expression '/' expression
           | expression '*' expression
           | expression '%' expression
           | any_value_no_bool_const
           ;

call_param_list : 
                | expression ',' call_param_list
                | logic_expression ',' call_param_list
                | logic_expression
                | expression
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