#pragma once
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include "Value.h"
#include "SymTable.h"

using namespace std;

class ASTFunctionDef;
class ASTClassDef;

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual Value eval(SymTable& sym) = 0;
    virtual void setDefinitionsList(vector<ASTNode*>* defs) {
    }
};

class ASTConstant : public ASTNode {
    Value value;

public:
    ASTConstant(const Value& v) : value(v) {}

    Value eval(SymTable& sym) override {
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
    
    void setDefinitionsList(vector<ASTNode*>* defs) override {
        if (child) child->setDefinitionsList(defs);
    }

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
    
    void setDefinitionsList(vector<ASTNode*>* defs) override {
        if (left) left->setDefinitionsList(defs);
        if (right) right->setDefinitionsList(defs);
    }

    Value eval(SymTable& sym) override {
        Value left_val = left->eval(sym), right_val = right->eval(sym);

        if (op == "+") {
            if (left_val.type == ValueType::INT)
                return Value::makeInt(get<int>(left_val.data) + get<int>(right_val.data));
            return Value::makeFloat(get<float>(left_val.data) + get<float>(right_val.data));
        }

        if (op == "-") {
            if (left_val.type == ValueType::INT)
                return Value::makeInt(get<int>(left_val.data) - get<int>(right_val.data));
            return Value::makeFloat(get<float>(left_val.data) - get<float>(right_val.data));
        }

        if (op == "*") {
            if (left_val.type == ValueType::INT)
                return Value::makeInt(get<int>(left_val.data) * get<int>(right_val.data));
            return Value::makeFloat(get<float>(left_val.data) * get<float>(right_val.data));
        }

        if (op == "/") {
            if (left_val.type == ValueType::INT)
                return Value::makeInt(get<int>(left_val.data) / get<int>(right_val.data));
            return Value::makeFloat(get<float>(left_val.data) / get<float>(right_val.data));
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
            if (left_val.type == ValueType::FLOAT)
                return Value::makeBool(get<float>(left_val.data) == get<float>(right_val.data));
            if (left_val.type == ValueType::BOOL)
                return Value::makeBool(get<bool>(left_val.data) == get<bool>(right_val.data));
            if (left_val.type == ValueType::STRING)
                return Value::makeBool(get<string>(left_val.data) == get<string>(right_val.data));
        }

        if (op == "!=") {
            if (left_val.type == ValueType::INT)
                return Value::makeBool(get<int>(left_val.data) != get<int>(right_val.data));
            if (left_val.type == ValueType::FLOAT)
                return Value::makeBool(get<float>(left_val.data) != get<float>(right_val.data));
            if (left_val.type == ValueType::BOOL)
                return Value::makeBool(get<bool>(left_val.data) != get<bool>(right_val.data));
            if (left_val.type == ValueType::STRING)
                return Value::makeBool(get<string>(left_val.data) != get<string>(right_val.data));
        }

        if (op == "&&") {
            return Value::makeBool(get<bool>(left_val.data) && get<bool>(right_val.data));
        }

        if (op == "||") {
            return Value::makeBool(get<bool>(left_val.data) || get<bool>(right_val.data));
        }

        return Value();
    }
};

class ASTAssign : public ASTNode {
    ASTId* id;
    ASTNode* expr;

public:
    ASTAssign(ASTId* i, ASTNode* e) : id(i), expr(e) {}
    
    void setDefinitionsList(vector<ASTNode*>* defs) override {
        if (expr) expr->setDefinitionsList(defs);
    }

    Value eval(SymTable& sym) override {
        Value expr_val = expr->eval(sym);
        sym.updateVar(id->get_name(), expr_val);
        return expr_val;
    }
};

class ASTPrint : public ASTNode {
    ASTNode* expr;

public:
    ASTPrint(ASTNode* e) : expr(e) {}
    
    void setDefinitionsList(vector<ASTNode*>* defs) override {
        if (expr) expr->setDefinitionsList(defs);
    }

    Value eval(SymTable& sym) override {
        Value expr_val = expr->eval(sym);
        expr_val.print();
        return expr_val;
    }
};

class ASTNull : public ASTNode {
public:
    Value eval(SymTable& sym) override {
        return Value();
    }
};

class ASTReturn : public ASTNode {
    ASTNode* return_value;
    bool has_value;

public:
    ASTReturn() : return_value(nullptr), has_value(false) {}
    ASTReturn(ASTNode* val) : return_value(val), has_value(true) {}
    ~ASTReturn() {
        if (return_value) delete return_value;
    }

    Value eval(SymTable& sym) override {
        if (has_value && return_value) {
            return return_value->eval(sym);
        }
        return Value();
    }
    
    bool hasReturnValue() const { return has_value; }
};

class ASTWhile : public ASTNode {
    ASTNode *condition;
    vector<ASTNode*> instructions;

public:
    ASTWhile(ASTNode* c, vector<ASTNode*> i) : condition(c), instructions(i) {}
    
    void setDefinitionsList(vector<ASTNode*>* defs) override {
        if (condition) condition->setDefinitionsList(defs);
        for (auto* node : instructions) {
            if (node) node->setDefinitionsList(defs);
        }
    }
    ~ASTWhile() {
        delete condition;
        for (auto* node : instructions) delete node;
    }

    Value eval(SymTable& sym) override {
        while (true) {
            Value cond_val = condition->eval(sym);
            if (cond_val.type != ValueType::BOOL)
            {
                throw std::invalid_argument("The expression does not evaluate to a logical value");
            }
            if (!get<bool>(cond_val.data)) {
                break;
            }

            for (auto* node : instructions) {
                if (node) node->eval(sym);
            }
        }

        return Value::makeInt();
    }
};

class ASTIf : public ASTNode {
    ASTNode *condition;
    vector<ASTNode*> instructions;
    vector<ASTNode*> else_instructions;

public:
    ASTIf(ASTNode* c, vector<ASTNode*> i) : condition(c), instructions(i) {}
    ASTIf(ASTNode* c, vector<ASTNode*> i, vector<ASTNode*> e) : condition(c), instructions(i), else_instructions(e) {}
    
    void setDefinitionsList(vector<ASTNode*>* defs) override {
        if (condition) condition->setDefinitionsList(defs);
        for (auto* node : instructions) {
            if (node) node->setDefinitionsList(defs);
        }
        for (auto* node : else_instructions) {
            if (node) node->setDefinitionsList(defs);
        }
    }
    ~ASTIf() {
        delete condition;
        for (auto* node : instructions) delete node;
        for (auto* node : else_instructions) delete node;
    }

    Value eval(SymTable& sym) override {
        Value cond_val = condition->eval(sym);
        if (cond_val.type != ValueType::BOOL)
        {
            throw std::invalid_argument("The expression does not evaluate to a logical value");
        }
        if (get<bool>(cond_val.data))
        {
            for (auto* node : instructions) {
                if (node) node->eval(sym);
            }
        }
        else if (!else_instructions.empty())
        {
            for (auto* node : else_instructions) {
                if (node) node->eval(sym);
            }
        }

        return Value::makeInt();
    }
};

class ASTFieldAccess : public ASTNode {
    ASTNode* object;
    string field_name;

public:
    ASTFieldAccess(ASTNode* obj, const string& field) : object(obj), field_name(field) {}
    ~ASTFieldAccess() { delete object; }
    
    void setDefinitionsList(vector<ASTNode*>* defs) override {
        if (object) object->setDefinitionsList(defs);
    }

    Value eval(SymTable& sym) override {
        ASTId* obj_id = dynamic_cast<ASTId*>(object);
        if (!obj_id) {
            return Value();
        }

        string obj_name = obj_id->get_name();
        IdInfo* obj_var = sym.getVar(obj_name);
        if (!obj_var) {
            return Value();
        }

        string class_name = obj_var->type;
        IdInfo* class_info = sym.getClass(class_name);
        if (!class_info || !class_info->class_scope) {
            return Value();
        }

        IdInfo* field = class_info->class_scope->getVar(field_name);
        if (!field) {
            return Value();
        }

        // For now, return the field's default value
        // In a full implementation, we'd need to track instance-specific field values
        return field->value;
    }
};

class ASTFunctionDef : public ASTNode {
    string function_name;
    vector<ASTNode*> body_statements;
    SymTable* function_scope;

public:
    ASTFunctionDef(const string& name, vector<ASTNode*> body, SymTable* scope)
        : function_name(name), body_statements(body), function_scope(scope) {}
    ~ASTFunctionDef() {
        for (auto* stmt : body_statements) delete stmt;
    }

    string getName() const { return function_name; }
    vector<ASTNode*>& getBody() { return body_statements; }
    SymTable* getScope() const { return function_scope; }

    Value eval(SymTable& sym) override {
        Value result;
        for (auto* stmt : body_statements) {
            if (stmt) {
                ASTReturn* ret = dynamic_cast<ASTReturn*>(stmt);
                if (ret) {
                    return ret->eval(sym);
                }
                result = stmt->eval(sym);
            }
        }
        return result;
    }
};

class ASTClassDef : public ASTNode {
    string class_name;
    map<string, ASTFunctionDef*> methods;
    SymTable* class_scope;

public:
    ASTClassDef(const string& name, SymTable* scope)
        : class_name(name), class_scope(scope) {}
    ~ASTClassDef() {
        for (auto& pair : methods) delete pair.second;
    }

    string getName() const { return class_name; }
    void addMethod(const string& method_name, ASTFunctionDef* method_def) {
        methods[method_name] = method_def;
    }
    ASTFunctionDef* getMethod(const string& method_name) {
        auto it = methods.find(method_name);
        return (it != methods.end()) ? it->second : nullptr;
    }
    SymTable* getScope() const { return class_scope; }

    Value eval(SymTable& sym) override {
        return Value();
    }
};

class ASTFunctionCall : public ASTNode {
    string function_name;
    vector<ASTNode*> arguments;
    vector<ASTNode*>* definitions_list;

public:
    ASTFunctionCall(const string& name, vector<ASTNode*> args) 
        : function_name(name), arguments(args), definitions_list(nullptr) {}
    ~ASTFunctionCall() {
    }

    void setDefinitionsList(vector<ASTNode*>* defs) override { 
        definitions_list = defs;
        for (auto* arg : arguments) {
            if (arg) arg->setDefinitionsList(defs);
        }
    }
    string getFunctionName() const { return function_name; }
    vector<ASTNode*>& getArguments() { return arguments; }

    Value eval(SymTable& sym) override {
        if (!definitions_list) {
            return Value();
        }

        ASTFunctionDef* func_def = nullptr;
        for (ASTNode* def : *definitions_list) {
            ASTFunctionDef* fd = dynamic_cast<ASTFunctionDef*>(def);
            if (fd && fd->getName() == function_name) {
                func_def = fd;
                break;
            }
        }

        if (!func_def) {
            return Value();
        }

        IdInfo* func_info = sym.getFunction(function_name);
        if (!func_info || !func_info->function_scope) {
            return Value();
        }

        SymTable* func_scope = func_info->function_scope;

        if (func_info->params.size() != arguments.size()) {
            return Value();
        }

        for (size_t i = 0; i < arguments.size(); i++) {
            Value arg_val = arguments[i]->eval(sym);
            func_scope->updateVar(func_info->params[i].second, arg_val);
        }

        Value result;
        for (auto* stmt : func_def->getBody()) {
            if (stmt) {
                result = stmt->eval(*func_scope);
            }
        }
        return result;
    }
};

class ASTMethodCall : public ASTNode {
    ASTNode* object;
    string method_name;
    vector<ASTNode*> arguments;
    vector<ASTNode*>* definitions_list;

public:
    ASTMethodCall(ASTNode* obj, const string& method, vector<ASTNode*> args)
        : object(obj), method_name(method), arguments(args), definitions_list(nullptr) {}
    ~ASTMethodCall() {
        delete object;
    }

    void setDefinitionsList(vector<ASTNode*>* defs) override { 
        definitions_list = defs;
        if (object) object->setDefinitionsList(defs);
        for (auto* arg : arguments) {
            if (arg) arg->setDefinitionsList(defs);
        }
    }
    string getMethodName() const { return method_name; }
    vector<ASTNode*>& getArguments() { return arguments; }
    ASTNode* getObject() const { return object; }

    Value eval(SymTable& sym) override {
        if (!definitions_list) {
            return Value();
        }

        ASTId* obj_id = dynamic_cast<ASTId*>(object);
        if (!obj_id) {
            return Value();
        }

        string obj_name = obj_id->get_name();
        IdInfo* obj_var = sym.getVar(obj_name);
        if (!obj_var) {
            return Value();
        }

        string class_name = obj_var->type;
        IdInfo* class_info = sym.getClass(class_name);
        if (!class_info || !class_info->class_scope) {
            return Value();
        }

        ASTClassDef* class_def = nullptr;
        for (ASTNode* def : *definitions_list) {
            ASTClassDef* cd = dynamic_cast<ASTClassDef*>(def);
            if (cd && cd->getName() == class_name) {
                class_def = cd;
                break;
            }
        }

        if (!class_def) {
            return Value();
        }

        ASTFunctionDef* method_def = class_def->getMethod(method_name);
        if (!method_def) {
            IdInfo* method_info = class_info->class_scope->getFunction(method_name);
            if (!method_info || !method_info->function_scope) {
                return Value();
            }

            SymTable* method_scope = method_info->function_scope;

            if (method_info->params.size() != arguments.size()) {
                return Value();
            }

            for (size_t i = 0; i < arguments.size(); i++) {
                Value arg_val = arguments[i]->eval(sym);
                method_scope->updateVar(method_info->params[i].second, arg_val);
            }

            // For now, return default value
            return Value();
        }

        SymTable* method_scope = class_info->class_scope->getFunction(method_name)->function_scope;
        if (!method_scope) {
            return Value();
        }

        IdInfo* method_info = class_info->class_scope->getFunction(method_name);
        if (method_info->params.size() != arguments.size()) {
            return Value();
        }

        for (size_t i = 0; i < arguments.size(); i++) {
            Value arg_val = arguments[i]->eval(sym);
            method_scope->updateVar(method_info->params[i].second, arg_val);
        }

        Value result;
        for (auto* stmt : method_def->getBody()) {
            if (stmt) {
                result = stmt->eval(*method_scope);
            }
        }
        return result;
    }
};