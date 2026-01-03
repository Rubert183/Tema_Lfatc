#pragma once
#include <vector>
#include "SymTable.h"
#include "Ast.h"

class ProgramAST {
public:
    std::vector<ASTNode*> mainStatements;

    void execute(SymTable& global) {
        for (ASTNode* stmt : mainStatements)
            stmt->eval(global);
    }
};