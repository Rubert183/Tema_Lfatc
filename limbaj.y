%code requires {
    #include <string>
    #include <vector>
    class ASTNode;
    class SymTable;
    struct Expr;
    struct ProgramLists;
    struct CallParams;
}

%{
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include "SymTable.h"
#include "Expr.h"
#include "Ast.h"

using namespace std;

struct CallParams {
    vector<string>* types;
    vector<ASTNode*>* asts;
};

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
    std::vector<ASTNode*>* ast_list;
    Expr *expr;
    ASTNode* ast;
    CallParams* call_params;
}

%type <expr> expression
%type <expr> class_element
%type <expr> call
%type <ast> assign_statement
%type <ast> print_statement
%type <ast> if_st
%type <ast> if_else_st
%type <ast> while_loop
%type <ast> call_statement
%type <ast> return_statement
%type <ast_list> main_code_block
%type <ast_list> code_block
%type <ast_list> code_block_no_definitions
%type <ast> func
%type <ast> class
%type <ast> method
%type <ast_list> top_level
%type <ast> top_level_decl
%type <ast_list> main

%type <call_params> call_params
%type <ast_list> func_body
%type <ast_list> method_body
%type <ast_list> class_list
%type <ast> return_val

%token CLASS_MK MAIN_MK PRINT RETURN
%token ASSIGN EQ NEQ LE GE LT GT NR NOT AND OR
%token IF WHILE ELSE TRU FLS
%token <intVal> INT_CONST
%token <floatVal> FLOAT_CONST
%token <strVal> STRING_CONST
%token <strVal> ID TYPE

%start progr

%left OR
%left AND
%left EQ NEQ
%left LT GT LE GE
%left '+' '-' 
%left '*' '/' '%'
%right NOT 
%nonassoc '(' ')'

%%

progr : top_level main {
            if (errorCount == 0) {
                cout << "The program is correct!" << endl;
                SymTable* global_scope = current;
                std::vector<ASTNode*>* definitions = $1;
                std::vector<ASTNode*>* main_instrs = $2;
                
                if (definitions) {
                    for (ASTNode* def : *definitions) {
                        if (def) {
                            def->setDefinitionsList(definitions);
                        }
                    }
                }

                if (main_instrs) {
                    for (ASTNode* instr : *main_instrs) {
                        if (instr) {
                            try {
                                if (definitions) {
                                    instr->setDefinitionsList(definitions);
                                }
                                instr->eval(*global_scope);
                            } catch (const std::exception& e) {
                                cout << "Runtime error: " << e.what() << endl;
                                exit(1);
                            }
                        }
                    }
                }
            }
        }
      ;

top_level : {
            $$ = new vector<ASTNode*>();
        }
          | top_level top_level_decl {
            if ($2) {
                $1->push_back($2);
            }
            $$ = $1;
        }
          ;

top_level_decl : class { $$ = $1; }
               | func { $$ = $1; }
               | var { $$ = nullptr; }
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
                        /*current->addFunction(currentType, *$2);
                        SymTable* funcScope = new SymTable(*$2, current);
                        currentIdInfo=current->getFunction(*$2);
                        currentIdInfo->function_scope = funcScope;
                        current = current->getFunctionScope(*$2);*/
                        current->addFunction(currentType, *$2);
                        currentIdInfo = current->getFunction(*$2);
                        current = current->getFunctionScope(*$2);
             }
         } '(' opt_param_list ')' '{' func_body '}' {
            string func_name = *$2;
            SymTable* func_scope = current->getFunctionScope(func_name);
            current=current->getParent();
            if (errorCount == 0 && $8) {
                $$ = new ASTFunctionDef(func_name, *$8, func_scope);
            } else {
                $$ = nullptr;
            }
         }
    ;

func_body : code_block { $$ = $1; }
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
            /*current->addClass(className);
            SymTable* classScope = new SymTable(className, current);
            current->getClass(className)->class_scope = classScope;
            current = classScope;*/
            current->addClass(className);
            current = current->getClassScope(className);
        }
      } '{' class_list '}' ';' {
            string className = *$2;
            SymTable* class_scope = current->getClassScope(className);
            current=current->getParent();
            if (errorCount == 0 && class_scope) {
                ASTClassDef* class_def = new ASTClassDef(className, class_scope);
                if ($5) {
                    for (ASTNode* method_node : *$5) {
                        ASTFunctionDef* method_def = dynamic_cast<ASTFunctionDef*>(method_node);
                        if (method_def) {
                            class_def->addMethod(method_def->getName(), method_def);
                        }
                    }
                }
                $$ = class_def;
            } else {
                $$ = nullptr;
            }
        }
      ;

class_list : field {
            $$ = new vector<ASTNode*>();
        }
           | method {
            $$ = new vector<ASTNode*>();
            if ($1) {
                $$->push_back($1);
            }
        }
           | class_list ',' field {
            $$ = $1;
        }
           | class_list ',' method {
            if ($3) {
                $1->push_back($3);
            }
            $$ = $1;
        }
           ;

field : type_or_class ID {
        string fieldName = *$2;
        if(current->existsClass(fieldName)){
            cout << "Field " << fieldName << " has the name of a class at line " << yylineno << endl;
            errorCount++;
        } else if(current->existsFunction_current(fieldName)){
            cout << "Field " << fieldName << " has the name of a method at line " << yylineno << endl;
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
        cout << "Method " << methodName << " has the name of a field at line " << yylineno << endl;
        errorCount++;
    } else if(current->existsFunction_current(methodName)){
        cout << "Redeclared method " << methodName << " at line " << yylineno << endl;
        errorCount++;
    } else {
        /*current->addFunction(currentType, methodName);
        SymTable* methodScope = new SymTable(methodName, current);
        currentIdInfo = current->getFunction(methodName);
        currentIdInfo->function_scope = methodScope;
        current = methodScope;*/
        current->addFunction(currentType, methodName);
        currentIdInfo = current->getFunction(methodName);
        current = current->getFunctionScope(methodName);
    }
    } '(' opt_param_list ')' '{' method_body '}' {
        string methodName = *$2;
        SymTable* method_scope = current->getFunctionScope(methodName);
        current = current->getParent();
        if (errorCount == 0 && method_scope && $8) {
            $$ = new ASTFunctionDef(methodName, *$8, method_scope);
        } else {
            $$ = nullptr;
        }
    }
       ;

method_body : code_block { $$ = $1; }
           ;

main : MAIN_MK '{' main_code_block '}' {
            $$ = $3;
        }
     ;

main_code_block : {
            $$ = new vector<ASTNode*>();
        }
        | main_code_block if_else_st { $1->push_back($2); $$ = $1; }
        | main_code_block if_st { $1->push_back($2); $$ = $1; }
        | main_code_block call_statement { $1->push_back($2); $$ = $1; }
        | main_code_block while_loop { $1->push_back($2); $$ = $1; }
        | main_code_block assign_statement { $1->push_back($2); $$ = $1; }
        | main_code_block print_statement { $1->push_back($2); $$ = $1; }
        ;

code_block_no_definitions : {
            $$ = new vector<ASTNode*>();
        }
        | code_block_no_definitions if_else_st { $1->push_back($2); $$ = $1; }
        | code_block_no_definitions if_st { $1->push_back($2); $$ = $1; }
        | code_block_no_definitions call_statement { $1->push_back($2); $$ = $1; }
        | code_block_no_definitions while_loop { $1->push_back($2); $$ = $1; }
        | code_block_no_definitions assign_statement { $1->push_back($2); $$ = $1; }
        | code_block_no_definitions print_statement { $1->push_back($2); $$ = $1; }
        | code_block_no_definitions return_statement { $1->push_back($2); $$ = $1; }
        ;

return_statement : return_val ';' { $$ = $1; }
                 ;

code_block : {
            $$ = new vector<ASTNode*>();
        }
        | code_block if_else_st { $1->push_back($2); $$ = $1; }
        | code_block if_st { $1->push_back($2); $$ = $1; }
        | code_block call_statement { $1->push_back($2); $$ = $1; }
        | code_block while_loop { $1->push_back($2); $$ = $1; }
        | code_block assign_statement { $1->push_back($2); $$ = $1; }
        | code_block var_definition { $$ = $1; }
        | code_block print_statement { $1->push_back($2); $$ = $1; }
        | code_block return_statement { $1->push_back($2); $$ = $1; }
        ;

print_statement : PRINT '(' expression ')' ';' {
            if ($3 && $3->ast) {
                $$ = new ASTPrint($3->ast);
            } else {
                $$ = new ASTOther();
            }
        }
        ;

if_else_st : IF '(' expression ')' '{' code_block_no_definitions '}' ELSE '{' code_block_no_definitions '}' {
            if ($3 && $3->ast && $6 && $10) {
                if(*$3->type!="bool"){
                    cout << "The condition of the if at line "<< yylineno << " needs to be a boolean expression"<<endl;
                    $$ = new ASTOther();
                    errorCount++;
                }
                else{
                    ASTNode* cond = $3->ast;
                    vector<ASTNode*> if_body = *$6;
                    vector<ASTNode*> else_body = *$10;
                    $$ = new ASTIf(cond, if_body, else_body);
                }
                
            } else {
                $$ = new ASTOther();
            }
        }
        ;

if_st : IF '(' expression ')' '{' code_block_no_definitions '}' {
            if ($3 && $3->ast && $6) {
                if(*$3->type!="bool"){
                    cout << "The condition of the if at line "<< yylineno << " needs to be a boolean expression"<<endl;
                    $$ = new ASTOther();
                    errorCount++;
                }
                else{
                    ASTNode* cond = $3->ast;
                    vector<ASTNode*> body = *$6;
                    $$ = new ASTIf(cond, body);
                }
                
            } else {
                $$ = new ASTOther();
            }
        }
      ;

call_statement : call ';' {
    if ($1 && $1->ast) {
        $$ = $1->ast;
    } else {
        $$ = new ASTOther();
    }
}
              ;

while_loop : WHILE '(' expression ')' '{' code_block_no_definitions '}' {
            if ($3 && $3->ast && $6) {
                if(*$3->type!="bool"){
                    cout << "The condition of the while at line "<< yylineno << " needs to be a boolean expression"<<endl;
                    $$ = new ASTOther();
                    errorCount++;
                }
                else{
                    ASTNode* cond = $3->ast;
                    vector<ASTNode*> body = *$6;
                    $$ = new ASTWhile(cond, body);
                }
            } else {
                $$ = new ASTOther();
            }
        }
           ;

assign_statement : class_element ASSIGN expression ';'
                 {
                    if($1 && $3 && *$3->type!=""){
                        if (*$1->type != *$3->type) {
                            if(*$1->type!="")
                                cout << "Cannot assign type "<< *$3->type << " to type "<< *$1->type << " at line "<< yylineno << endl;
                            errorCount++;
                        }
                    }
                    ASTNode* right_ast = nullptr;
                    if ($3 && $3->ast) {
                        right_ast = $3->ast;
                    }
                    
                    if ($1 && $1->ast && right_ast) {
                        $$ = new ASTAssign($1->ast, right_ast);
                    } else {
                        $$ = new ASTOther();
                    }
                 }
                 ;

return_val : RETURN expression {
            if ($2 && $2->ast) {
                $$ = new ASTReturn($2->ast);
            } else {
                $$ = new ASTReturn();
            }
        }
           ;

var_definition : var
               ;

expression 
    : '(' expression ')' { $$ = $2; }
    | expression '+' expression {
        if(*$1->type!=*$3->type){
            cout << "Invalid addition type mismatch at line " << yylineno << endl;
            errorCount++;
            $$=makeExpr("");
        } else if(*$1->type=="int"||*$1->type=="float"){
            $$=makeExpr(*$1->type);
            if ($1->ast && $3->ast) $$->ast = new ASTBinaryOp("+", $1->ast, $3->ast);
        } else {
            cout << "Invalid add operation at line " << yylineno << endl;
            $$=makeExpr("");
            errorCount++;
        }
    }
    | expression '-' expression {
        if(*$1->type!=*$3->type){
            cout << "Type mismatch -" << endl; errorCount++; $$=makeExpr("");
        } else if(*$1->type=="int"||*$1->type=="float"){
            $$=makeExpr(*$1->type);
            if ($1->ast && $3->ast) $$->ast = new ASTBinaryOp("-", $1->ast, $3->ast);
        } else {
            cout << "Invalid sub op" << endl; errorCount++; $$=makeExpr("");
        }
    }
    | expression '*' expression {
        if(*$1->type!=*$3->type){
            cout << "Type mismatch *" << endl; errorCount++; $$=makeExpr("");
        } else if(*$1->type=="int"||*$1->type=="float"){
            $$=makeExpr(*$1->type);
            if ($1->ast && $3->ast) $$->ast = new ASTBinaryOp("*", $1->ast, $3->ast);
        } else {
            cout << "Invalid mul op" << endl; errorCount++; $$=makeExpr("");
        }
    }
    | expression '/' expression {
        if(*$1->type!=*$3->type){
            cout << "Type mismatch /" << endl; errorCount++; $$=makeExpr("");
        } else if(*$1->type=="int"||*$1->type=="float"){
            $$=makeExpr(*$1->type);
            if ($1->ast && $3->ast) $$->ast = new ASTBinaryOp("/", $1->ast, $3->ast);
        } else {
            cout << "Invalid div op" << endl; errorCount++; $$=makeExpr("");
        }
    }
    | expression '%' expression {
        if(*$1->type!=*$3->type){
            cout << "Type mismatch %" << endl; errorCount++; $$=makeExpr("");
        } else if(*$1->type=="int"){
            $$=makeExpr("int");
            if ($1->ast && $3->ast) $$->ast = new ASTBinaryOp("%", $1->ast, $3->ast);
        } else {
            cout << "Invalid mod op" << endl; errorCount++; $$=makeExpr("");
        }
    }
    | '-' expression %prec NOT { 
        if (*$2->type == "int" || *$2->type == "float") {
            $$ = makeExpr(*$2->type);
            if ($2->ast) $$->ast = new ASTUnaryOp("-", $2->ast);
        } else {
             cout << "Type mismatch for unary minus at line " << yylineno << endl;
             errorCount++;
             $$ = makeExpr("");
        }
    }
    | expression OR expression {
        $$ = makeExpr("bool");
        if ($1->ast && $3->ast) $$->ast = new ASTBinaryOp("||", $1->ast, $3->ast);
    }
    | expression AND expression {
        $$ = makeExpr("bool");
        if ($1->ast && $3->ast) $$->ast = new ASTBinaryOp("&&", $1->ast, $3->ast);
    }
    | NOT expression {
        $$ = makeExpr("bool");
        if ($2->ast) $$->ast = new ASTUnaryOp("not", $2->ast);
    }
    | expression LT expression {
        if(*$1->type != *$3->type) { cout << "Type mismatch for operator '<' at line " << yylineno << endl; errorCount++; $$=makeExpr(""); }
        else { $$=makeExpr("bool"); if($1->ast && $3->ast) $$->ast = new ASTBinaryOp("<", $1->ast, $3->ast); }
    }
    | expression GT expression {
        if(*$1->type != *$3->type) { cout << "Type mismatch for operator '>' at line " << yylineno << endl; errorCount++; $$=makeExpr(""); }
        else { $$=makeExpr("bool"); if($1->ast && $3->ast) $$->ast = new ASTBinaryOp(">", $1->ast, $3->ast); }
    }
    | expression LE expression {
        if(*$1->type != *$3->type) { cout << "Type mismatch for operator '<=' at line " << yylineno << endl;errorCount++; $$=makeExpr(""); }
        else { $$=makeExpr("bool"); if($1->ast && $3->ast) $$->ast = new ASTBinaryOp("<=", $1->ast, $3->ast); }
    }
    | expression GE expression {
        if(*$1->type != *$3->type) { cout << "Type mismatch for operator '>=' at line " << yylineno << endl;errorCount++; $$=makeExpr(""); }
        else { $$=makeExpr("bool"); if($1->ast && $3->ast) $$->ast = new ASTBinaryOp(">=", $1->ast, $3->ast); }
    }
    | expression EQ expression {
        if(*$1->type != *$3->type) { cout << "Type mismatch for operator '==' at line " << yylineno << endl;errorCount++; $$=makeExpr(""); }
        else { $$=makeExpr("bool"); if($1->ast && $3->ast) $$->ast = new ASTBinaryOp("==", $1->ast, $3->ast); }
    }
    | expression NEQ expression {
        if(*$1->type != *$3->type) { cout << "Type mismatch for operator '!=' at line " << yylineno << endl; errorCount++; $$=makeExpr(""); }
        else { $$=makeExpr("bool"); if($1->ast && $3->ast) $$->ast = new ASTBinaryOp("!=", $1->ast, $3->ast); }
    }
    | call { $$ = $1; }
    | class_element { $$ = $1; }
    | TRU { $$ = makeExpr("bool", new ASTConstant(Value::makeBool(true))); }
    | FLS { $$ = makeExpr("bool", new ASTConstant(Value::makeBool(false))); }
    | INT_CONST { $$ = makeExpr("int", new ASTConstant(Value::makeInt($1))); }
    | FLOAT_CONST { $$ = makeExpr("float", new ASTConstant(Value::makeFloat($1))); }
    | STRING_CONST { $$ = makeExpr("string", new ASTConstant(Value::makeString(*$1))); }
    ;

call_params
    : {
        CallParams* cp = new CallParams();
        cp->types = new vector<string>();
        cp->asts = new vector<ASTNode*>();
        $$ = cp;
    }
    | expression ',' call_params {
        $$ = $3;
        string param_type = (*$1->type == "bool") ? "bool" : *$1->type;
        $$->types->insert($$->types->begin(), param_type);
        if ($1 && $1->ast) $$->asts->insert($$->asts->begin(), $1->ast);
        else $$->asts->insert($$->asts->begin(), new ASTOther());
    }
    | expression {
        CallParams* cp = new CallParams();
        cp->types = new vector<string>();
        cp->asts = new vector<ASTNode*>();
        string param_type = (*$1->type == "bool") ? "bool" : *$1->type;
        cp->types->push_back(param_type);
        if ($1 && $1->ast) cp->asts->push_back($1->ast);
        else cp->asts->push_back(new ASTOther());
        $$ = cp;
    }
    ;

call : ID '(' call_params ')' {
    IdInfo* f = current->getFunction(*$1);
    Expr* expr_result = nullptr;
    if(!f){
        cout << "Undefined function " << *$1 << " at line " << yylineno << endl;
        errorCount++;
        expr_result = makeExpr("");
        expr_result->ast = new ASTOther();
    } else {
        vector<string>* types = $3->types;
        vector<ASTNode*>* asts = $3->asts;
        if(f->params.size() != types->size()){
            cout << "Function " << *$1 << " called with wrong params" << endl;
            errorCount++;
            expr_result = makeExpr("");
            expr_result->ast = new ASTOther();
        } else {
             for(size_t i = 0; i < types->size(); i++){
                if(f->params[i].first!= (*types)[i]){
                    cout << "Type mismatch for param " << i+1 << " in function " << *$1 << endl;
                    errorCount++;
                }
            }
            expr_result = makeExpr(f->type);
            if (asts) expr_result->ast = new ASTFunctionCall(*$1, *asts);
            else expr_result->ast = new ASTOther();
        }
    }
    $$ = expr_result;
}
| class_element '.' ID '(' call_params ')' {
    IdInfo* typeInfo = current->getClass(*$1->type);
    Expr* expr_result = nullptr;
    if(!typeInfo){
        cout << "Type " << *$1->type << " is not a class at line " << yylineno << endl;
        errorCount++;
        expr_result = makeExpr("");
        expr_result->ast = new ASTOther();
    } else {
        SymTable* classScope = typeInfo->class_scope;
        IdInfo* m = classScope->getFunction(*$3);
        if(!m){
            cout << "Undefined method " << *$3 << endl;
            errorCount++;
            expr_result = makeExpr("");
            expr_result->ast = new ASTOther();
        } else {
             vector<string>* types = $5->types;
            vector<ASTNode*>* asts = $5->asts;
            if(m->params.size() != types->size()){
                cout << "Wrong number of params" << endl; errorCount++;
                expr_result = makeExpr(""); expr_result->ast = new ASTOther();
            } else {
                 for(size_t i = 0; i < types->size(); i++){
                    if(m->params[i].first != (*types)[i]){
                        cout << "Type mismatch param" << endl; errorCount++;
                    }
                }
                expr_result = makeExpr(m->type);
                if ($1->ast && asts) expr_result->ast = new ASTMethodCall($1->ast, *$3, *asts);
                else expr_result->ast = new ASTOther();
            }
        }
    }
    $$ = expr_result;
}
| call '.' ID '(' call_params ')' {
    // 1. Verificam daca rezultatul apelului anterior ($1) este o clasa
    IdInfo* typeInfo = current->getClass(*$1->type);
    Expr* expr_result = nullptr;

    if(!typeInfo){
        cout << "Type " << *$1->type << " returned by function is not a class at line " << yylineno << endl;
        errorCount++;
        expr_result = makeExpr("");
        expr_result->ast = new ASTOther();
    } else {
        SymTable* classScope = typeInfo->class_scope;
        // 2. Cautam metoda in scope-ul clasei returnate
        IdInfo* m = classScope->getFunction(*$3);
        
        if(!m){
            cout << "Undefined method " << *$3 << " in class " << *$1->type << endl;
            errorCount++;
            expr_result = makeExpr("");
            expr_result->ast = new ASTOther();
        } else {
            vector<string>* types = $5->types;
            vector<ASTNode*>* asts = $5->asts;
            
            // 3. Validam parametrii
            if(m->params.size() != types->size()){
                cout << "Wrong number of params for method " << *$3 << endl;
                errorCount++;
                expr_result = makeExpr(""); 
                expr_result->ast = new ASTOther();
            } else {
                 for(size_t i = 0; i < types->size(); i++){
                    if(m->params[i].first != (*types)[i]){
                        cout << "Type mismatch param " << i+1 << " in method " << *$3 << endl;
                        errorCount++;
                    }
                }
                // 4. Succes! Cream ASTMethodCall
                expr_result = makeExpr(m->type);
                // Obiectul pe care apelam metoda este AST-ul apelului anterior ($1->ast)
                if ($1->ast && asts) 
                    expr_result->ast = new ASTMethodCall($1->ast, *$3, *asts);
                else 
                    expr_result->ast = new ASTOther();
            }
        }
    }
    $$ = expr_result;
}
;


class_element
    : ID {
            IdInfo* v = current->getVar(*$1);
            if(!v){
                cout << "Undefined variable " << *$1 << " at line " << yylineno << endl;
                errorCount++;
                $$ = makeExpr("");
                $$->ast = new ASTOther();
            } else {
                $$ = makeExpr(v->type);
                $$->ast = new ASTId(*$1);
            }
        }
    | class_element '.' ID {
        SymTable* classScope = nullptr;
        IdInfo* typeInfo = current->getClass(*$1->type);
        if(!typeInfo){
            cout << "Type " << *$1->type << " is not a class at line " << yylineno << endl;
            errorCount++;
            $$ = makeExpr("");
            $$->ast = new ASTOther();
        } else {
            classScope = typeInfo->class_scope;
            if(!classScope){
                cout << "Class scope error" << endl; errorCount++;
                $$ = makeExpr(""); $$->ast = new ASTOther();
            } else {
                IdInfo* field = classScope->getVar_current(*$3);
                if(field){
                    $$ = makeExpr(field->type);
                    if ($1->ast) $$->ast = new ASTFieldAccess($1->ast, *$3);
                    else $$->ast = new ASTOther();
                } else {
                    IdInfo* method = classScope->getFunction(*$3);
                    if(method){
                        $$ = makeExpr(method->type);
                        $$->cur_scope = classScope;
                        $$->ast = new ASTOther();
                    } else {
                        cout << "Undefined class element " << *$3 << endl;
                        errorCount++;
                        $$ = makeExpr(""); $$->ast = new ASTOther();
                    }
                }
            }
        }
    }
    | call '.' ID {
        SymTable* classScope = nullptr;
        IdInfo* typeInfo = current->getClass(*$1->type);
        
        if(!typeInfo){
            cout << "Type " << *$1->type << " returned by function is not a class at line " << yylineno << endl;
            errorCount++;
            $$ = makeExpr("");
            $$->ast = new ASTOther();
        } else {
            classScope = typeInfo->class_scope;
            if(!classScope){
                cout << "Class scope error" << endl; errorCount++;
                $$ = makeExpr(""); $$->ast = new ASTOther();
            } else {
                IdInfo* field = classScope->getVar_current(*$3);
                if(field){
                    $$ = makeExpr(field->type);
                    if ($1->ast) $$->ast = new ASTFieldAccess($1->ast, *$3);
                    else $$->ast = new ASTOther();
                } else {
                    IdInfo* method = classScope->getFunction(*$3);
                    if(method){
                        $$ = makeExpr(method->type);
                        $$->cur_scope = classScope; 
                        $$->ast = new ASTOther();
                    } else {
                        cout << "Undefined field " << *$3 << " in class returned by function" << endl;
                        errorCount++;
                        $$ = makeExpr(""); $$->ast = new ASTOther();
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
     SymTable::printAllTables("tables.txt");
     delete current;
}