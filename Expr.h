#pragma once
#include <string>
#include "SymTable.h"
#include "Ast.h"

using namespace std;

struct Expr {
    string* type;
    ASTNode* ast;
    SymTable* cur_scope = nullptr;
};

inline Expr* makeExpr(const string& t, ASTNode* node = nullptr) {
    Expr* e = new Expr();
    e->type = new string(t);
    e->ast = node;
    return e;
}
