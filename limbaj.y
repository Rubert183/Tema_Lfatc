
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

%token MAIN_MK CLASS_MK BGIN END ASSIGN NR 
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

class : CLASS_MK ID  {
                         //current=current->get_root();
                         const string id=*$2;
                         if(current->exists(id)==true){
                              errorCount++;
                              cout<<"The name of the class needs to be unique!"<<endl;
                         }
                         else{
                              SymInfo *info=new SymInfo(SymKind::CLASS,"",id);
                              current->add(info);
                              SymTable *new_class=new SymTable(id,current);
                              info->inner_scope=new_class;
                              current=new_class;
                         } 

                    } '{' class_list '}' {
                         current=current->get_parent();
                    }
      ;

class_list : field 
           | class_list field 
           ;

field : TYPE ID ';' {
                    if(current->exists(*$2)==true){
                         errorCount++;
                         cout<<"The names of fields inside classes needs to be unique!"<<endl;
                    }   
                    SymInfo *field=new SymInfo(SymKind::FIELD,*$1,*$2);
                    current->add(field);
                    }
      ;

func: TYPE ID '(' opt_param_list ')' {
                                        //current=current->get_root();
                                        const string id=*$2;
                                        if(current->exists(id)==true){
                                             errorCount++;
                                             cout<<"The name of the function needs to be unique!"<<endl;
                                        }
                                        else{
                                             SymInfo *info=new SymInfo(SymKind::FUNCTION,*$1,id);
                                             current->add(info);
                                             SymTable *new_function=new SymTable(id,current);
                                             info->inner_scope=new_function;
                                             current=new_function;
                                        } 
                                     } '{' code_block '}'  {
                                        current=current->get_parent();
                                     }
    ;

param_list : param
           | param_list ','  param 
           ;

opt_param_list : 
               | param_list 
               ;

param : TYPE ID {
                    if(current->exists(*$2)==true){
                    errorCount++;
                    cout<<"The parameters of functions needs to have unique names!"<<endl;
                    }   
                    SymInfo *param=new SymInfo(SymKind::PARAM,*$1,*$2);
                    current->add(param);
               }
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
     const string global="global";
     current = new SymTable(global);
     yyparse();
     /*cout << "Variables:" <<endl;
     current->printVars();*/
     delete current;
} 