#pragma once
#include "Value.h"
#include "SymTable.h"

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual Value eval(SymTable& sym) = 0;
};

class ASTConstant : public ASTNode {
    Value value;

public:
    ASTConstant(const Value& v) : value(v) {}

    Value eval(SymTable&) override {
        return value;
    }
};

class ASTId : public ASTNode { // Aici Id = Id de variabila (NU CLASA/FUNCTIE)
    string name;

public:
    ASTId(const string& n) : name(n) {}

    Value eval(SymTable& sym) override {
        IdInfo* val = sym.getVar(name);
        if (!val) return Value();
        return val->value;
    }
    string get_name() {
        return name;
    }
};

class ASTOther : public ASTNode {
public:
    Value eval(SymTable&) override {
        return Value();
    }
};

class ASTUnaryOp : public ASTNode {
    string op;
    ASTNode* child;

public:
    ASTUnaryOp(const string& o, ASTNode* c) : op(o), child(c) {}

    Value eval(SymTable& sym) override {
        Value child_val = child->eval(sym);

        if (op == "not") {
            return Value::makeBool(!get<bool>(child_val.data)); // cu get<type> se acceseaza valorile dintr-un variant
        }

        if (op == "-") {
            if (child_val.type == ValueType::INT) return Value::makeInt(-get<int>(child_val.data));
            if (child_val.type == ValueType::FLOAT) return Value::makeFloat(-get<float>(child_val.data));
        }

        return Value();
    }
};

class ASTBinaryOp : public ASTNode {
    string op;
    ASTNode *left, *right;

public:
    ASTBinaryOp(const string& o, ASTNode* l, ASTNode* r) : op(o), left(l), right(r) {}

    Value eval(SymTable& sym) {
        Value left_val = left->eval(sym), right_val = right->eval(sym);

        if (op == "+") {
            if (left_val.type == ValueType::INT)
                return Value::makeInt(get<int>(left_val.data) + get<int>(right_val.data));
            return Value::makeInt(get<float>(left_val.data) + get<float>(right_val.data));
        }

        if (op == "-") {
            if (left_val.type == ValueType::INT)
                return Value::makeInt(get<int>(left_val.data) - get<int>(right_val.data));
            return Value::makeInt(get<float>(left_val.data) - get<float>(right_val.data));
        }

        if (op == "*") {
            if (left_val.type == ValueType::INT)
                return Value::makeInt(get<int>(left_val.data) * get<int>(right_val.data));
            return Value::makeInt(get<float>(left_val.data) * get<float>(right_val.data));
        }

        if (op == "/") {
            if (left_val.type == ValueType::INT)
                return Value::makeInt(get<int>(left_val.data) / get<int>(right_val.data));
            return Value::makeInt(get<float>(left_val.data) / get<float>(right_val.data));
        }

        if (op == "%") {
            return Value::makeInt(get<int>(left_val.data) % get<int>(right_val.data));
        }

        if (op == "<") {
            if (left_val.type == ValueType::INT)
                return Value::makeBool(get<int>(left_val.data) < get<int>(right_val.data));
            return Value::makeBool(get<float>(left_val.data) < get<float>(right_val.data));
        }

        if (op == "<=") {
            if (left_val.type == ValueType::INT)
                return Value::makeBool(get<int>(left_val.data) <= get<int>(right_val.data));
            return Value::makeBool(get<float>(left_val.data) <= get<float>(right_val.data));
        }

        if (op == ">") {
            if (left_val.type == ValueType::INT)
                return Value::makeBool(get<int>(left_val.data) > get<int>(right_val.data));
            return Value::makeBool(get<float>(left_val.data) > get<float>(right_val.data));
        }

        if (op == ">=") {
            if (left_val.type == ValueType::INT)
                return Value::makeBool(get<int>(left_val.data) >= get<int>(right_val.data));
            return Value::makeBool(get<float>(left_val.data) >= get<float>(right_val.data));
        }

        if (op == "==") {
            if (left_val.type == ValueType::INT)
                return Value::makeBool(get<int>(left_val.data) == get<int>(right_val.data));
            return Value::makeBool(get<float>(left_val.data) == get<float>(right_val.data));
        }

        if (op == "!=") {
            if (left_val.type == ValueType::INT)
                return Value::makeBool(get<int>(left_val.data) != get<int>(right_val.data));
            return Value::makeBool(get<float>(left_val.data) != get<float>(right_val.data));
        }

        if (op == "&&") {
            return Value::makeBool(get<bool>(left_val.data) && get<bool>(right_val.data));
        }

        if (op == "||") {
            return Value::makeBool(get<bool>(left_val.data) || get<bool>(right_val.data));
        }
    }
};

class ASTAssign : public ASTNode {
    ASTId* id;
    ASTNode* expr;

public:
    ASTAssign(ASTId* i, ASTNode* e) : id(i), expr(e) {}

    Value eval(SymTable sym) {
        Value expr_val = expr->eval(sym);
        sym.updateVar(id->get_name(), expr_val);
        return expr_val;
    }
};

class ASTPrint : public ASTNode {
    ASTNode* expr;

public:
    ASTPrint(ASTNode* e) : expr(e) {}

    Value eval(SymTable& sym) override {
        Value expr_val = expr->eval(sym);
        expr_val.print();
        return expr_val;
    }
};

class ASTNull : public ASTNode {
public:
    Value eval(SymTable&) override {
        return Value();
    }
};