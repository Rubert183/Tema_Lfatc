#pragma once
#include <stdexcept>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "Value.h"
#include "SymTable.h"

using namespace std;

// Used to jump out of nested loops/ifs when 'return' is hit
class ReturnException : public exception
{
public:
    Value value;
    ReturnException(Value v) : value(v) {}
};

class ASTFunctionDef;
class ASTClassDef;

// Simulates the Heap: Stores values for specific instances (e.g., p1.age vs p2.age)
class InstanceManager
{
public:
    static map<string, map<string, Value>> memory;

    static Value getField(const string &instanceName, const string &fieldName)
    {
        return memory[instanceName][fieldName];
    }

    static void setField(const string &instanceName, const string &fieldName, Value val)
    {
        memory[instanceName][fieldName] = val;
    }

    static bool hasField(const string &instanceName, const string &fieldName)
    {
        if (memory.find(instanceName) == memory.end())
            return false;
        return memory[instanceName].find(fieldName) != memory[instanceName].end();
    }
};

map<string, map<string, Value>> InstanceManager::memory;

class ASTNode
{
public:
    virtual ~ASTNode() = default;
    virtual Value eval(SymTable &sym) = 0;
    virtual void setDefinitionsList(vector<ASTNode *> *defs) {}
};

class ASTConstant : public ASTNode
{
    Value value;

public:
    ASTConstant(const Value &v) : value(v) {}
    Value eval(SymTable &sym) override { return value; }
};

class ASTId : public ASTNode
{
    string name;

public:
    ASTId(const string &n) : name(n) {}
    Value eval(SymTable &sym) override
    {
        IdInfo *val = sym.getVar(name);
        if (!val)
            return Value();
        return val->value;
    }
    string get_name() const { return name; }
};

class ASTOther : public ASTNode
{
public:
    Value eval(SymTable &) override { return Value(); }
};

class ASTUnaryOp : public ASTNode
{
    string op;
    ASTNode *child;

public:
    ASTUnaryOp(const string &o, ASTNode *c) : op(o), child(c) {}
    void setDefinitionsList(vector<ASTNode *> *defs) override
    {
        if (child)
            child->setDefinitionsList(defs);
    }
    Value eval(SymTable &sym) override
    {
        Value child_val = child->eval(sym);
        if (op == "not")
            return Value::makeBool(!get<bool>(child_val.data));
        if (op == "-")
        {
            if (child_val.type == ValueType::INT)
                return Value::makeInt(-get<int>(child_val.data));
            if (child_val.type == ValueType::FLOAT)
                return Value::makeFloat(-get<float>(child_val.data));
        }
        return Value();
    }
};

class ASTBinaryOp : public ASTNode
{
    string op;
    ASTNode *left, *right;

public:
    ASTBinaryOp(const string &o, ASTNode *l, ASTNode *r) : op(o), left(l), right(r) {}

    void setDefinitionsList(vector<ASTNode *> *defs) override
    {
        if (left)
            left->setDefinitionsList(defs);
        if (right)
            right->setDefinitionsList(defs);
    }

    Value eval(SymTable &sym) override
    {
        Value l = left->eval(sym);
        Value r = right->eval(sym);

        // Strict Type Checking & Arithmetic Logic
        if (op == "+" || op == "-" || op == "*" || op == "/")
        {
            // Integer Logic
            if (l.type == ValueType::INT && r.type == ValueType::INT)
            {
                int v1 = get<int>(l.data);
                int v2 = get<int>(r.data);
                if (op == "+")
                    return Value::makeInt(v1 + v2);
                if (op == "-")
                    return Value::makeInt(v1 - v2);
                if (op == "*")
                    return Value::makeInt(v1 * v2);
                if (op == "/")
                {
                    if (v2 == 0)
                        throw std::runtime_error("Division by zero");
                    return Value::makeInt(v1 / v2);
                }
            }
            // Float Logic
            else if (l.type == ValueType::FLOAT && r.type == ValueType::FLOAT)
            {
                float v1 = get<float>(l.data);
                float v2 = get<float>(r.data);
                if (op == "+")
                    return Value::makeFloat(v1 + v2);
                if (op == "-")
                    return Value::makeFloat(v1 - v2);
                if (op == "*")
                    return Value::makeFloat(v1 * v2);
                if (op == "/")
                {
                    if (v2 == 0.0f)
                        throw std::runtime_error("Division by zero");
                    return Value::makeFloat(v1 / v2);
                }
            }
            else
            {
                throw std::runtime_error("Type mismatch in arithmetic operation '" + op + "'");
            }
        }

        if (op == "%")
        {
            if (l.type == ValueType::INT && r.type == ValueType::INT)
            {
                int v2 = get<int>(r.data);
                if (v2 == 0)
                    throw std::runtime_error("Modulo by zero");
                return Value::makeInt(get<int>(l.data) % v2);
            }
            throw std::runtime_error("Modulo operator (%) requires two integers");
        }

        if (op == "&&" || op == "||")
        {
            if (l.type == ValueType::BOOL && r.type == ValueType::BOOL)
            {
                bool v1 = get<bool>(l.data);
                bool v2 = get<bool>(r.data);
                if (op == "&&")
                    return Value::makeBool(v1 && v2);
                if (op == "||")
                    return Value::makeBool(v1 || v2);
            }
            throw std::runtime_error("Logical operator '" + op + "' requires boolean operands");
        }

        if (op == "<" || op == ">" || op == "<=" || op == ">=")
        {
            if (l.type == ValueType::INT && r.type == ValueType::INT)
            {
                int v1 = get<int>(l.data);
                int v2 = get<int>(r.data);
                if (op == "<")
                    return Value::makeBool(v1 < v2);
                if (op == ">")
                    return Value::makeBool(v1 > v2);
                if (op == "<=")
                    return Value::makeBool(v1 <= v2);
                if (op == ">=")
                    return Value::makeBool(v1 >= v2);
            }
            else if (l.type == ValueType::FLOAT && r.type == ValueType::FLOAT)
            {
                float v1 = get<float>(l.data);
                float v2 = get<float>(r.data);
                if (op == "<")
                    return Value::makeBool(v1 < v2);
                if (op == ">")
                    return Value::makeBool(v1 > v2);
                if (op == "<=")
                    return Value::makeBool(v1 <= v2);
                if (op == ">=")
                    return Value::makeBool(v1 >= v2);
            }
            throw std::runtime_error("Comparison '" + op + "' requires matching number types");
        }

        if (op == "==" || op == "!=")
        {
            if (l.type != r.type)
                throw std::runtime_error("Cannot compare different types for equality");

            bool result = false;
            if (l.type == ValueType::INT)
                result = (get<int>(l.data) == get<int>(r.data));
            else if (l.type == ValueType::FLOAT)
                result = (get<float>(l.data) == get<float>(r.data));
            else if (l.type == ValueType::BOOL)
                result = (get<bool>(l.data) == get<bool>(r.data));
            else if (l.type == ValueType::STRING)
                result = (get<string>(l.data) == get<string>(r.data));

            if (op == "==")
                return Value::makeBool(result);
            if (op == "!=")
                return Value::makeBool(!result);
        }

        throw std::runtime_error("Unknown operator " + op);
    }
};

class ASTFieldAccess : public ASTNode
{
    ASTNode *object;
    string field_name;

public:
    ASTFieldAccess(ASTNode *obj, const string &field) : object(obj), field_name(field) {}
    ~ASTFieldAccess() {}

    void setDefinitionsList(vector<ASTNode *> *defs) override
    {
        if (object)
            object->setDefinitionsList(defs);
    }

    Value eval(SymTable &sym) override
    {
        // 1. Evaluam obiectul (poate fi un ID sau un apel de functie)
        Value val = object->eval(sym);

        // 2. Verificam daca rezultatul este o referinta catre un obiect
        if (val.type != ValueType::OBJECT)
        {
            // Eroare de runtime sau return default
            return Value();
        }

        // 3. Extragem numele instantei (cheia din Heap)
        string instance_name = get<string>(val.data);

        // 4. Cautam in Heap
        if (InstanceManager::hasField(instance_name, field_name))
        {
            return InstanceManager::getField(instance_name, field_name);
        }

        // 5. Lazy Load (Default values din definitia clasei)
        // Avem nevoie sa stim tipul clasei. Din pacate, Value stocheaza doar numele instantei.
        // Putem deduce tipul cautand instanta in SymTable curent sau parinti.
        IdInfo *varInfo = sym.getVar(instance_name);
        if (varInfo)
        {
            string class_name = varInfo->type;
            IdInfo *class_info = sym.getClass(class_name);
            if (class_info && class_info->class_scope)
            {
                IdInfo *default_field = class_info->class_scope->getVar(field_name);
                if (default_field)
                {
                    InstanceManager::setField(instance_name, field_name, default_field->value);
                    return default_field->value;
                }
            }
        }

        return Value();
    }

    string getFieldName() const { return field_name; }
    ASTNode *getObjectNode() const { return object; }
};

class ASTAssign : public ASTNode
{
    ASTNode *target;
    ASTNode *expr;

public:
    ASTAssign(ASTNode *t, ASTNode *e) : target(t), expr(e) {}

    void setDefinitionsList(vector<ASTNode *> *defs) override
    {
        if (expr)
            expr->setDefinitionsList(defs);
    }

    Value eval(SymTable &sym) override
    {
        Value expr_val = expr->eval(sym);

        // Cazul 1: Asignare simpla (x = y sau x = func())
        ASTId *id_node = dynamic_cast<ASTId *>(target);
        if (id_node)
        {
            sym.updateVar(id_node->get_name(), expr_val);
            return expr_val;
        }

        // Cazul 2: Asignare la camp (obj.field = val)
        ASTFieldAccess *field_node = dynamic_cast<ASTFieldAccess *>(target);
        if (field_node)
        {
            // Evaluam obiectul din stanga punctului pentru a afla instanta
            Value objRef = field_node->getObjectNode()->eval(sym);

            if (objRef.type == ValueType::OBJECT)
            {
                string instance_name = get<string>(objRef.data);
                string field_name = field_node->getFieldName();

                // Actualizam Heap-ul
                InstanceManager::setField(instance_name, field_name, expr_val);
                return expr_val;
            }
        }
        return Value();
    }
};

class ASTPrint : public ASTNode
{
    ASTNode *expr;

public:
    ASTPrint(ASTNode *e) : expr(e) {}
    void setDefinitionsList(vector<ASTNode *> *defs) override
    {
        if (expr)
            expr->setDefinitionsList(defs);
    }
    Value eval(SymTable &sym) override
    {
        Value v = expr->eval(sym);
        v.print();
        return v;
    }
};

class ASTNull : public ASTNode
{
public:
    Value eval(SymTable &) override { return Value(); }
};

class ASTReturn : public ASTNode
{
    ASTNode *return_value;
    bool has_value;

public:
    ASTReturn() : return_value(nullptr), has_value(false) {}
    ASTReturn(ASTNode *val) : return_value(val), has_value(true) {}

    void setDefinitionsList(vector<ASTNode *> *defs) override
    {
        if (has_value && return_value)
        {
            return_value->setDefinitionsList(defs);
        }
    }

    Value eval(SymTable &sym) override
    {
        Value result;
        if (has_value && return_value)
        {
            result = return_value->eval(sym);
        }
        // Throw exception to break control flow (loops/ifs)
        throw ReturnException(result);
    }
};

class ASTWhile : public ASTNode
{
    ASTNode *condition;
    vector<ASTNode *> instructions;

public:
    ASTWhile(ASTNode *c, vector<ASTNode *> i) : condition(c), instructions(i) {}
    void setDefinitionsList(vector<ASTNode *> *defs) override
    {
        if (condition)
            condition->setDefinitionsList(defs);
        for (auto *node : instructions)
            if (node)
                node->setDefinitionsList(defs);
    }
    Value eval(SymTable &sym) override
    {
        while (true)
        {
            Value c = condition->eval(sym);
            if (!get<bool>(c.data))
                break;
            for (auto *node : instructions)
                if (node)
                    node->eval(sym);
        }
        return Value::makeInt();
    }
};

class ASTIf : public ASTNode
{
    ASTNode *condition;
    vector<ASTNode *> instructions;
    vector<ASTNode *> else_instructions;

public:
    ASTIf(ASTNode *c, vector<ASTNode *> i, vector<ASTNode *> e = {}) : condition(c), instructions(i), else_instructions(e) {}
    void setDefinitionsList(vector<ASTNode *> *defs) override
    {
        if (condition)
            condition->setDefinitionsList(defs);
        for (auto *node : instructions)
            if (node)
                node->setDefinitionsList(defs);
        for (auto *node : else_instructions)
            if (node)
                node->setDefinitionsList(defs);
    }
    Value eval(SymTable &sym) override
    {
        Value c = condition->eval(sym);
        if (get<bool>(c.data))
        {
            for (auto *node : instructions)
                if (node)
                    node->eval(sym);
        }
        else if (!else_instructions.empty())
        {
            for (auto *node : else_instructions)
                if (node)
                    node->eval(sym);
        }
        return Value::makeInt();
    }
};

class ASTFunctionDef : public ASTNode
{
    string function_name;
    vector<ASTNode *> body_statements;
    SymTable *function_scope;

public:
    ASTFunctionDef(const string &name, vector<ASTNode *> body, SymTable *scope)
        : function_name(name), body_statements(body), function_scope(scope) {}
    ~ASTFunctionDef()
    {
        for (auto *stmt : body_statements)
            delete stmt;
    }

    void setDefinitionsList(vector<ASTNode *> *defs) override
    {
        for (auto *node : body_statements)
        {
            if (node)
                node->setDefinitionsList(defs);
        }
    }

    string getName() const { return function_name; }
    vector<ASTNode *> &getBody() { return body_statements; }
    SymTable *getScope() const { return function_scope; }

    Value eval(SymTable &sym) override
    {
        Value result;
        try
        {
            for (auto *stmt : body_statements)
            {
                if (stmt)
                    result = stmt->eval(sym);
            }
        }
        catch (const ReturnException &e)
        {
            return e.value;
        }
        return result;
    }
};

class ASTClassDef : public ASTNode
{
    string class_name;
    map<string, ASTFunctionDef *> methods;
    SymTable *class_scope;

public:
    ASTClassDef(const string &name, SymTable *scope) : class_name(name), class_scope(scope) {}

    void setDefinitionsList(vector<ASTNode *> *defs) override
    {
        for (auto const &[name, method] : methods)
        {
            if (method)
                method->setDefinitionsList(defs);
        }
    }

    string getName() const { return class_name; }
    SymTable *getScope() const { return class_scope; }

    void addMethod(const string &mName, ASTFunctionDef *mDef) { methods[mName] = mDef; }
    ASTFunctionDef *getMethod(const string &mName)
    {
        return (methods.count(mName)) ? methods[mName] : nullptr;
    }
    Value eval(SymTable &sym) override { return Value(); }
};

class ASTFunctionCall : public ASTNode
{
    string function_name;
    vector<ASTNode *> arguments;
    vector<ASTNode *> *definitions_list;

public:
    ASTFunctionCall(const string &name, vector<ASTNode *> args)
        : function_name(name), arguments(args), definitions_list(nullptr) {}

    void setDefinitionsList(vector<ASTNode *> *defs) override
    {
        definitions_list = defs;
        for (auto *arg : arguments)
            if (arg)
                arg->setDefinitionsList(defs);
    }

    // În clasa ASTFunctionCall din Ast.h

    Value eval(SymTable &sym) override
    {
        if (!definitions_list) return Value();

        IdInfo *func_info = sym.getFunction(function_name);
        if (!func_info || !func_info->function_scope) return Value();

        ASTFunctionDef *func_def = nullptr;
        // ... (Logica de cautare a definitiei ramane la fel ca inainte) ...
        for (ASTNode *def : *definitions_list) {
            ASTFunctionDef *fd = dynamic_cast<ASTFunctionDef *>(def);
            if (fd && fd->getName() == function_name) {
                if (fd->getScope() == func_info->function_scope) {
                    func_def = fd; break;
                }
            }
            ASTClassDef *cd = dynamic_cast<ASTClassDef *>(def);
            if (cd) {
                if (func_info->function_scope->getParent() == cd->getScope()) {
                    ASTFunctionDef *potential_method = cd->getMethod(function_name);
                    if (potential_method && potential_method->getScope() == func_info->function_scope) {
                        func_def = potential_method; break;
                    }
                }
            }
        }

        if (!func_def) return Value();

        SymTable *static_scope = func_info->function_scope;
        SymTable runtime_scope("call_frame", static_scope->getParent());
        runtime_scope.copyVariablesFrom(static_scope);

        if (func_info->params.size() != arguments.size()) return Value();

        for (size_t i = 0; i < arguments.size(); i++) {
            Value arg_val = arguments[i]->eval(sym);
            runtime_scope.updateVar(func_info->params[i].second, arg_val);
        }

        Value result;
        try
        {
            for (auto *stmt : func_def->getBody()) {
                if (stmt) result = stmt->eval(runtime_scope);
            }
        }
        catch (const ReturnException &e)
        {
            result = e.value;
        }

        // --- FIX-UL ESTE AICI ---
        // Daca functia returneaza un OBIECT, trebuie sa-l salvam intr-o variabila temporara
        // in scope-ul curent (al apelantului), altfel pierdem referinta la tipul clasei.
        
        if (result.type == ValueType::OBJECT) {
            // Verificam daca tipul returnat de functie este o clasa
            if (sym.existsClass(func_info->type)) {
                string local_name = get<string>(result.data);
                
                // Generam un nume unic temporar (ex: "__temp_Calculator_1")
                static int temp_count = 0;
                string temp_name = "__temp_" + func_info->type + "_" + to_string(temp_count++);

                // 1. Inregistram variabila temporara in scope-ul apelantului (main)
                // Astfel, apelurile ulterioare (ex: .add) vor gasi variabila si tipul ei corect.
                sym.addVar(func_info->type, temp_name);

                // 2. Copiem datele din Heap (InstanceManager)
                // Mutam datele de la instanta locala ("c") la cea temporara
                if (InstanceManager::memory.count(local_name)) {
                    InstanceManager::memory[temp_name] = InstanceManager::memory[local_name];
                }

                // Returnam numele obiectului temporar
                return Value::makeObject(temp_name);
            }
        }
        // -------------------------

        return result;
    }
};

class ASTMethodCall : public ASTNode
{
    ASTNode *object;
    string method_name;
    vector<ASTNode *> arguments;
    vector<ASTNode *> *definitions_list;

public:
    ASTMethodCall(ASTNode *obj, const string &method, vector<ASTNode *> args)
        : object(obj), method_name(method), arguments(args), definitions_list(nullptr) {}

    void setDefinitionsList(vector<ASTNode *> *defs) override
    {
        definitions_list = defs;
        if (object)
            object->setDefinitionsList(defs);
        for (auto *arg : arguments)
            if (arg)
                arg->setDefinitionsList(defs);
    }

    // Persist modified fields back to 'Heap' (InstanceManager)
    void saveState(SymTable *method_scope, SymTable *class_scope, const string &instance_name)
    {
        if (class_scope && method_scope)
        {
            for (auto const &[name, info] : class_scope->getVariables())
            {
                // FIX: Verificăm dacă variabila este declarată local în metodă (Shadowing).
                // Dacă existsVar_current returnează true, înseamnă că avem un parametru 
                // sau o variabilă locală cu același nume. În acest caz, NU vrem să 
                // suprascriem câmpul obiectului cu valoarea locală.
                if (method_scope->existsVar_current(name)) {
                    continue; 
                }

                IdInfo *val_in_method = method_scope->getVar(name);
                if (val_in_method)
                {
                    InstanceManager::setField(instance_name, name, val_in_method->value);
                }
            }
        }
    }

    Value eval(SymTable &sym) override
    {
        if (!definitions_list)
            return Value();

        // 1. Evaluam nodul 'object'. Poate fi m (ASTId), m.p (ASTFieldAccess) sau f() (ASTFunctionCall)
        Value obj_val = object->eval(sym);

        // 2. Verificam daca rezultatul evaluarii este un obiect
        if (obj_val.type != ValueType::OBJECT)
            return Value();

        // 3. Extragem numele instantei din Value
        string instance_name = get<string>(obj_val.data);

        IdInfo *obj_var = sym.getVar(instance_name);
        if (!obj_var)
            return Value();
        string class_name = obj_var->type;

        ASTClassDef *class_def = nullptr;
        for (ASTNode *def : *definitions_list)
        {
            ASTClassDef *cd = dynamic_cast<ASTClassDef *>(def);
            if (cd && cd->getName() == class_name)
            {
                class_def = cd;
                break;
            }
        }
        if (!class_def)
            return Value();

        ASTFunctionDef *method_def = class_def->getMethod(method_name);
        if (!method_def)
            return Value();

        SymTable *method_scope = method_def->getScope();
        SymTable *class_scope = class_def->getScope();

        // Load Instance State into Method Scope
        if (class_scope)
        {
            for (auto const &[name, info] : class_scope->getVariables())
            {
                if (InstanceManager::hasField(instance_name, name))
                {
                    method_scope->updateVar(name, InstanceManager::getField(instance_name, name));
                }
                else
                {
                    method_scope->updateVar(name, info.value);
                }
            }
        }

        IdInfo *method_info = class_scope->getFunction(method_name);
        if (method_info && method_info->params.size() == arguments.size())
        {
            for (size_t i = 0; i < arguments.size(); i++)
            {
                Value arg_val = arguments[i]->eval(sym);
                method_scope->updateVar(method_info->params[i].second, arg_val);
            }
        }

        Value result;
        try
        {
            for (auto *stmt : method_def->getBody())
            {
                if (stmt)
                    result = stmt->eval(*method_scope);
            }
        }
        catch (const ReturnException &e)
        {
            saveState(method_scope, class_scope, instance_name);
            return e.value;
        }

        saveState(method_scope, class_scope, instance_name);
        return result;
    }
};