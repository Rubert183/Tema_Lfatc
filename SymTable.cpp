#include "SymTable.h"

SymTable::SymTable(const string& name, SymTable* parent)
    : name(name), parent(parent) {}


void SymTable::addVar(const string& type, const string& name) {
    variables[name] = IdInfo(name, type);
}

void SymTable::addFunction(const string& type,const string& name,const vector<pair<string,string>>& params) {
    IdInfo f(name, type);
    f.params = params;

    f.function_scope = new SymTable(name, this);

    functions[name] = f;
}

void SymTable::addClass(const string& name) {
    IdInfo cls(name, name);

    cls.class_scope = new SymTable(name, this);

    classes[name] = cls;
}

void SymTable::updateVar(const string& name, const Value& value) {
    // If variable exists in current scope, update it
    if (variables.count(name)) {
        variables[name].value = value;
    } 
    // Otherwise, try to update in parent scope
    else if (parent) {
        parent->updateVar(name, value);
    }
}

bool SymTable::existsVar(const string& name) const {
    if (variables.count(name))
        return true;
    return parent ? parent->existsVar(name) : false;
}

bool SymTable::existsFunction(const string& name) const {
    if (functions.count(name))
        return true;
    return parent ? parent->existsFunction(name) : false;
}

bool SymTable::existsClass(const string& name) const {
    if (classes.count(name))
        return true;
    return parent ? parent->existsClass(name) : false;
}

bool SymTable::existsVar_current(const string& name) const {
    if (variables.count(name))
        return true;
    return false;
}

bool SymTable::existsFunction_current(const string& name) const {
    if (functions.count(name))
        return true;
    return false;
}

bool SymTable::existsClass_current(const string& name) const {
    if (classes.count(name))
        return true;
    return false;
}

IdInfo* SymTable::getVar(const string& name){
    auto it = variables.find(name);
    if (it != variables.end())
        return &it->second;
    return parent ? parent->getVar(name) : nullptr;
}

IdInfo* SymTable::getFunction(const string& name){
    auto it = functions.find(name);
    if (it != functions.end())
        return &it->second;
    return parent ? parent->getFunction(name) : nullptr;
}

IdInfo* SymTable::getClass(const string& name){
    auto it = classes.find(name);
    if (it != classes.end())
        return &it->second;
    return parent ? parent->getClass(name) : nullptr;
}

IdInfo* SymTable::getVar_current(const string& name){
    auto it = variables.find(name);
    if (it != variables.end())
        return &it->second;
    return nullptr;
}

IdInfo* SymTable::getFunction_current(const string& name){
    auto it = functions.find(name);
    if (it != functions.end())
        return &it->second;
    return nullptr;
}

IdInfo* SymTable::getClass_current(const string& name){
    auto it = classes.find(name);
    if (it != classes.end())
        return &it->second;
    return nullptr;
}

SymTable* SymTable::getClassScope(const string& className) {
    auto it = classes.find(className);
    if (it != classes.end())
        return it->second.class_scope;
    return parent ? parent->getClassScope(className) : nullptr;
}

SymTable* SymTable::getFunctionScope(const string& funcName) {
    auto it = functions.find(funcName);
    if (it != functions.end())
        return it->second.function_scope;
    return parent ? parent->getFunctionScope(funcName) : nullptr;
}

const map<string, IdInfo>& SymTable::getVariables() const {
    return variables;
}

void SymTable::copyVariablesFrom(const SymTable* source) {
    if (!source) return;
    this->variables = source->variables;
}