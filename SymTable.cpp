#include "SymTable.h"

vector<SymTable*> SymTable::all_tables;

SymTable::SymTable(const string& name, SymTable* parent,bool save)
    : name(name), parent(parent) {
        if(save){
            all_tables.push_back(this);
        }
    }


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

void SymTable::printTable(ostream& out) {
    out << "========================================" << endl;
    out << "Scope Name: " << name << endl;
    if (parent) {
        // Accesam numele parintelui. Trebuie sa adaugi getter pentru nume in .h 
        // SAU fiind in aceeasi clasa putem accesa parent->name direct daca e private
        out << "Parent Scope: " << parent->name << endl; 
    } else {
        out << "Parent Scope: NULL (Global)" << endl;
    }
    out << "----------------------------------------" << endl;
    
    // 1. Variabile
    if (!variables.empty()) {
        out << "Variables:" << endl;
        out << "  [Type] [Name] = [Value]" << endl;
        for (const auto& pair : variables) {
            const IdInfo& info = pair.second;
            out << "   " << info.type << " " << info.name << " = " << info.value.toString() << endl;
        }
    } else {
        out << "Variables: None" << endl;
    }

    // 2. Functii
    if (!functions.empty()) {
        out << "\nFunctions:" << endl;
        for (const auto& pair : functions) {
            const IdInfo& info = pair.second;
            out << "   Function: " << info.name << " | Return Type: " << info.type << endl;
            out << "     Params: ";
            if (info.params.empty()) {
                out << "None";
            } else {
                for (size_t i = 0; i < info.params.size(); ++i) {
                    out << info.params[i].first << " " << info.params[i].second; // Type Name
                    if (i < info.params.size() - 1) out << ", ";
                }
            }
            out << endl;
        }
    }

    // 3. Clase
    if (!classes.empty()) {
        out << "\nClasses Defined Here:" << endl;
        for (const auto& pair : classes) {
             out << "   Class: " << pair.first << endl;
        }
    }
    out << endl;
}

void SymTable::printAllTables(const string& filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "Error: Could not open file " << filename << " for writing." << endl;
        return;
    }

    for (SymTable* table : all_tables) {
        table->printTable(out);
    }
    
    out.close();
    cout << "Symbol tables dumped to " << filename << endl;
}