%code requires {
  #include <string>
  #include <vector>
  using namespace std;

  class SymTable;
  struct Expr {
    std::string* type;
    std::string* name;
    class SymTable* cur_scope=nullptr;
    int i;
    float f;
    bool b;
    std::string* s;
  };

  inline Expr* makeExpr(const string& t) {
        Expr* e = new Expr();
        e->type = new string(t);
        return e;
    };
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
    std::vector<std::string>* types;
    int expr_comp_op;
    Expr *expr;
}

%type <expr> expression
%type <expr> logic_expression
%type <expr> logic_and
%type <expr> logic_not
%type <expr> logic_atom
%type <expr> expression_or_logic
%type <expr> any_value_no_bool_const
%type <expr> class_element
%type <expr> call
%type <types> call_param_list
%type <expr_comp_op> expression_comparisom

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
             } else if(current->existsFunction(*$1)){
                    cout << "Variable " << *$1 << " has the name of a function at line " << yylineno << endl;
                    errorCount++;
             } else if(current->existsVar_current(*$1)){
                    cout << "Redeclared variable " << *$1 << " at line " << yylineno << endl;
                    errorCount++;
             } else {
                    current->addVar(currentType, *$1);
             }
         } ',' list_var
         | ID {
             if(current->existsClass(*$1)){
                 cout << "Variable " << *$1 << " has the name of a class at line " << yylineno << endl;
                 errorCount++;
             } else if(current->existsFunction(*$1)){
                    cout << "Variable " << *$1 << " has the name of a function at line " << yylineno << endl;
                    errorCount++;
             } else if(current->existsVar_current(*$1)){
                    cout << "Redeclared variable " << *$1 << " at line " << yylineno << endl;
                    errorCount++;
             } else {
                    current->addVar(currentType, *$1);
             }
         }
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
             } else if(current->existsVar_current(*$2)){
                    cout << "Function " << *$2 << " has the name of a variable at line " << yylineno << endl;
                    errorCount++;
             } else if(current->existsFunction(*$2)){
                        cout << "Redeclared function " << *$2 << " at line " << yylineno << endl;
                        errorCount++;
             } else {
                        current->addFunction(currentType, *$2);
                        SymTable* funcScope = new SymTable(*$2, current);
                        currentIdInfo=current->getFunction(*$2);
                        currentIdInfo->function_scope = funcScope;
                        current = current->getFunctionScope(*$2);
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
             } else if(current->existsFunction_current(*$2)){
                    cout << "Parameter " << *$2 << " has the name of a function at line " << yylineno << endl;
                    errorCount++;
             } else if(current->existsVar_current(*$2)){
                    cout << "Redeclared Parameter " << *$2 << " at line " << yylineno << endl;
                    errorCount++;
             } else {
                        currentIdInfo->add_param(currentType,*$2);
                        current->addVar(currentType, *$2);
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
        } else if(current->existsFunction_current(fieldName)){
            cout << "Field " << fieldName << " has the name of a function at line " << yylineno << endl;
            errorCount++;
        } else if(current->existsVar_current(fieldName)){
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
    } else if(current->existsVar_current(methodName)){
        cout << "Method " << methodName << " has the name of a variable at line " << yylineno << endl;
        errorCount++;
    } else if(current->existsFunction_current(methodName)){
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
                | call ';' main_code_block
                | while_loop main_code_block
                | assign_statement ';' main_code_block
                | print_statement ';' main_code_block
                ;

code_block_no_definitions : 
                          | if_else_st code_block_no_definitions
                          | if_st code_block_no_definitions
                          | call ';' code_block_no_definitions
                          | while_loop code_block_no_definitions
                          | assign_statement ';' code_block_no_definitions
                          | print_statement ';' code_block_no_definitions
                          | return_val ';'
                          | return_nothing ';'
                          ;

code_block : 
           | if_else_st code_block
           | if_st code_block
           | call ';' code_block
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

call
    : ID '(' call_param_list ')'
{
    IdInfo* f = current->getFunction(*$1);
    if(!f){
        cout << "Undefined function " << *$1
             << " at line " << yylineno << endl;
        errorCount++;
        $$ = makeExpr("");
    } else {
        if(f->params.size() != $3->size()){
            cout << "Function " << *$1
                 << " called with wrong number of parameters at line "
                 << yylineno << endl;
            errorCount++;
        } else {
            for(size_t i = 0; i < $3->size(); i++){
                if(f->params[i].first!= (*$3)[i]){
                    cout << "Type mismatch for parameter "
                         << i+1 << " in function " << *$1
                         << " at line " << yylineno << endl;
                    errorCount++;
                }
            }
        }
        $$ = makeExpr(f->type);
    }
}
| class_element '.' ID '(' call_param_list ')'
{
    IdInfo* typeInfo = current->getClass(*$1->type);
    if(!typeInfo){
        cout << "Type " << *$1->type
             << " is not a class at line " << yylineno << endl;
        errorCount++;
        $$ = makeExpr("");
    } else {
        SymTable* classScope = typeInfo->class_scope;
        IdInfo* m = classScope->getFunction(*$3);
        if(!m){
            cout << "Undefined method " << *$3
                 << " at line " << yylineno << endl;
            errorCount++;
            $$ = makeExpr("");
        } else {
            if(m->params.size() != $5->size()){
                cout << "Method " << *$3
                     << " called with wrong number of parameters at line "
                     << yylineno << endl;
                errorCount++;
            } else {
                for(size_t i = 0; i < $5->size(); i++){
                    if(m->params[i].first != (*$5)[i]){
                        cout << "Type mismatch for parameter "
                             << i+1 << " in method " << *$3
                             << " at line " << yylineno << endl;
                        errorCount++;
                    }
                }
            }
            $$ = makeExpr(m->type);
        }
    }
}
;

while_loop : WHILE '(' logic_expression ')' '{' code_block_no_definitions '}'
           ;

assign_statement : class_element ASSIGN expression_or_logic
                 {
                    if(*$3->type!=""){
                        if (*$1->type != *$3->type) {
                            if(*$1->type!="")
                                cout << "Cannot assign type "<< *$3->type << " to type "<< *$1->type << " at line "<< yylineno << endl;
                            errorCount++;
                        }
                    }
                 }
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

any_value : call
          | class_element
          | TRU
          | FLS
          | INT_CONST
          | FLOAT_CONST
          ;

any_value_no_bool_const : call
                        | class_element
                        | INT_CONST {
                            $$ = makeExpr("int");
                            $$->i=$1;
                        }
                        | FLOAT_CONST {
                            $$ = makeExpr("float");
                            $$->f=$1;
                        }
                        ;

logic_expression : logic_expression OR logic_and {
                    $$ = makeExpr("bool");
                    $$->b = $1->b || $3->b;
                 }
                 | logic_and {
                    $$ = $1; 
                 }
                 ;

logic_and : logic_and AND logic_not {
            $$ = makeExpr("bool");
            $$->b = $1->b && $3->b;
            }
          | logic_not {
            $$ = $1; 
          }
          ;

logic_not : NOT logic_not {
            $$ = makeExpr("bool");
            $$->b = !$2->b;
            }
          | logic_atom {
            $$ = $1; 
          }
          ;

logic_atom
    : '(' logic_expression ')' { $$ = $2; }
    | expression expression_comparisom expression {
        if(*$1->type!=*$3->type){
            if(*$1->type!="")
                cout << "Invalid comparisom of type " << *$1->type << " and type " <<*$3->type<<" called at line " << yylineno << endl;
            $$=makeExpr("");
            errorCount++;
        } else {
            if(*$1->type=="int" || *$3->type=="float"){
                $$=makeExpr("bool");
                switch($2){
                    case 1:{
                        if(*$1->type=="int"){
                            $$->b= $1->i < $3->i;
                        } else {
                            $$->b= $1->f < $3->f;
                        }
                        break;
                    }
                    case 2:{
                        if(*$1->type=="int"){
                            $$->b= $1->i == $3->i;
                        } else {
                            $$->b= $1->f == $3->f;
                        }
                        break;
                    }
                    case 3:{
                        if(*$1->type=="int"){
                            $$->b= $1->i != $3->i;
                        } else {
                            $$->b= $1->f != $3->f;
                        }
                        break;
                    }
                    case 4:{
                        if(*$1->type=="int"){
                            $$->b= $1->i > $3->i;
                        } else {
                            $$->b= $1->f > $3->f;
                        }
                        break;
                    }
                    case 5:{
                        if(*$1->type=="int"){
                            $$->b= $1->i <= $3->i;
                        } else {
                            $$->b= $1->f <= $3->f;
                        }
                        break;
                    }
                    case 6:{
                        if(*$1->type=="int"){
                            $$->b= $1->i >= $3->i;
                        } else {
                            $$->b= $1->f >= $3->f;
                        }
                        break;
                    }
                    default:{break;}
                }
            }
            else{
                cout << "Invalid comparisom of elements of the type " << *$1->type <<" called at line " << yylineno << endl;
                $$=makeExpr("");
                errorCount++;
            }
        }
    }
    | TRU {$$=makeExpr("bool"); $$->b=true;}
    | FLS {$$=makeExpr("bool"); $$->b=false;}
    ;

expression_comparisom : LT {$$=1;}
                      | EQ {$$=2;}
                      | NEQ {$$=3;}
                      | GT {$$=4;}
                      | LE {$$=5;}
                      | GE {$$=6;}
                      ;

expression : '(' expression ')' {$$=$2;}
           | expression '+' expression {
            if(*$1->type!=*$3->type){
                cout << "Tried to make an addition on a " << *$1->type <<" with a "<<*$3->type<< " at line " << yylineno << endl;
                errorCount++;
            }
            else if(*$1->type=="int"||*$1->type=="float"){
                if(*$1->type=="int"){
                    $$=makeExpr("int");
                    $$->i=$1->i+$3->i;
                }
                else{
                    $$=makeExpr("float");
                    $$->f=$1->f+$3->f;
                }
            }
            else{
                 if(*$1->type!="")
                    cout << "Invalid add operation for the type " << *$1->type << " called at line " << yylineno << endl;
                 $$=makeExpr("");
                 errorCount++;
            }
           }
           | expression '-' expression {
            if(*$1->type!=*$3->type){
                cout << "Tried to substract from a " << *$1->type <<" with a "<<*$3->type<< " at line " << yylineno << endl;
                errorCount++;
            }
            else if(*$1->type=="int"||*$1->type=="float"){
                if(*$1->type=="int"){
                    $$=makeExpr("int");
                    $$->i=$1->i-$3->i;
                }
                else{
                    $$=makeExpr("float");
                    $$->f=$1->f-$3->f;
                }
            }
            else{
                 if(*$1->type!="")
                    cout << "Invalid substract operation for the type " << *$1->type << " called at line " << yylineno << endl;
                $$=makeExpr("");
                 errorCount++;
            }
           }
           | expression '/' expression{
            if(*$1->type!=*$3->type){
                cout << "Tried to divide a " << *$1->type <<" with a "<<*$3->type<< " at line " << yylineno << endl;
                errorCount++;
            }
            else if(*$1->type=="int"||*$1->type=="float"){
                if(*$1->type=="int"){
                    if($3->i!=0){
                        $$=makeExpr("int");
                        $$->i=$1->i/$3->i;
                    }
                    else{
                        cout << "Tried to divide with a 0 at line " << yylineno << endl;
                        $$=makeExpr("");
                        errorCount++;
                    }
                }
                else{
                    if($3->f!=0.0){
                        $$=makeExpr("float");
                        $$->f=$1->f/$3->f;
                    }
                    else{
                        cout << "Tried to divide with a 0 at line " << yylineno << endl;
                        $$=makeExpr("");
                        errorCount++;
                    }
                }
            }
            else{
                 if(*$1->type!="")
                    cout << "Invalid div operation for the type " << *$1->type << " called at line " << yylineno << endl;
                 $$=makeExpr("");
                 errorCount++;
            }
           }
           | expression '*' expression{
            if(*$1->type!=*$3->type){
                cout << "Tried to mutiply a " << *$1->type <<" with a "<<*$3->type<< " at line " << yylineno << endl;
                errorCount++;
            }
            else if(*$1->type=="int"||*$1->type=="float"){
                if(*$1->type=="int"){
                    $$=makeExpr("int");
                    $$->i=$1->i*$3->i;
                }
                else{
                    $$=makeExpr("float");
                    $$->i=$1->f*$3->f;
                }
            }
            else{
                 if(*$1->type!="")
                    cout << "Invalid multiply operation for the type " << *$1->type << " called at line " << yylineno << endl;
                 $$=makeExpr("");
                 errorCount++;
            }
           }
           | expression '%' expression{
            if(*$1->type!=*$3->type){
                cout << "Tried to do a mod operation on a " << *$1->type <<" with a "<<*$3->type<< " at line " << yylineno << endl;
                errorCount++;
            }
            else if(*$1->type=="int"){
                    if($3->i!=0){
                        $$=makeExpr("int");
                        $$->i=$1->i%$3->i;
                    }
                    else{
                        cout << "Tried a mod operation with a 0 at line " << yylineno << endl;
                        $$=makeExpr("");
                        errorCount++;
                    }
            }
            else{
                 if(*$1->type!="")
                    cout << "Invalid mod operation for the type " << *$1->type << " called at line " << yylineno << endl;
                 $$=makeExpr("");
                 errorCount++;
            }
           }
           | any_value_no_bool_const
           ;

call_param_list
    :
    {
        $$ = new vector<string>();
    }
    | expression ',' call_param_list
    {
        $$ = $3;
        $$->insert($$->begin(), *$1->type);
    }
    | logic_expression ',' call_param_list
    {
        $$ = $3;
        $$->insert($$->begin(), "bool");
    }
    | expression
    {
        $$ = new vector<string>();
        $$->push_back(*$1->type);
    }
    | logic_expression
    {
        $$ = new vector<string>();
        $$->push_back("bool");
    }
    ;


class_element
    : ID
        {
            IdInfo* v = current->getVar(*$1);
            if(!v){
                cout << "Undefined variable " << *$1 << " at line " << yylineno << endl;
                errorCount++;
                $$ = makeExpr("");
            } else {
                $$ = makeExpr(v->type);
            }
        }
    | class_element '.' ID
{
    SymTable* classScope = nullptr;
    IdInfo* typeInfo = current->getClass(*$1->type);
    if(!typeInfo){
        cout << "Type " << *$1->type << " is not a class at line " << yylineno << endl;
        errorCount++;
        $$ = makeExpr("");
    } else {
        classScope = typeInfo->class_scope;
        if(!classScope){
            cout << "Class " << *$1->type << " has no scope at line " << yylineno << endl;
            errorCount++;
            $$ = makeExpr("");
        } else {
            // Mai întâi verificăm dacă e câmp
            IdInfo* field = classScope->getVar_current(*$3);
            if(field){
                $$ = makeExpr(field->type);
            } else {
                // Dacă nu e câmp, verificăm dacă e funcție (metodă)
                IdInfo* method = classScope->getFunction(*$3);
                if(method){
                    $$ = makeExpr(method->type);
                    $$->cur_scope = classScope; // marcăm că e un call
                } else {
                    cout << "Undefined class element or method " << *$3 << " at line " << yylineno << endl;
                    errorCount++;
                    $$ = makeExpr("");
                }
            }
        }
    }
}
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
     delete current;
}