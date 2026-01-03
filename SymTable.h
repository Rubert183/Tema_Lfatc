#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "Value.h"

using namespace std;

class SymTable;

class IdInfo {
public:
    string name, type;
    Value value;

    vector<pair<string,string>> params;
    void add_param(const string& type,const string& name){
        params.push_back(make_pair(type,name));
    };
    SymTable* function_scope = nullptr;

    SymTable* class_scope = nullptr;

    IdInfo() = default;
    IdInfo(const string& name, const string& type) : name(name), type(type) {
        if (type == "int") {
            value.data = 0;
            value.type = ValueType::INT;
        }
        else if (type == "float") {
            value.data = 0.f;
            value.type = ValueType::FLOAT;
        }
        else if (type == "bool") {
            value.data = true;
            value.type = ValueType::BOOL;
        }
        else if (type == "string") {
            value.data = "";
            value.type = ValueType::STRING;
        }
        else {
            value.data = 0;
            value.type = ValueType::VOID;
        }
    }
};

class SymTable {
private:
    string name;
    SymTable* parent;

    map<string, IdInfo> variables;
    map<string, IdInfo> functions;
    map<string, IdInfo> classes;

public:
    SymTable(const string& name, SymTable* parent = nullptr);

    void addVar(const string& type, const string& name);
    void addFunction(const string& type,const string& name,const vector<pair<string,string>>& params = {});
    void addClass(const string& name);

    void updateVar(const string& name, const Value& val);

    bool existsVar(const string& name) const;
    bool existsFunction(const string& name) const;
    bool existsClass(const string& name) const;

    bool existsVar_current(const string& name) const;
    bool existsFunction_current(const string& name) const;
    bool existsClass_current(const string& name) const;

    IdInfo* getVar(const string& name);
    IdInfo* getFunction(const string& name);
    IdInfo* getClass(const string& name);

    IdInfo* getVar_current(const string& name);
    IdInfo* getFunction_current(const string& name);
    IdInfo* getClass_current(const string& name);

    SymTable* getClassScope(const string& className);
    SymTable* getFunctionScope(const string& funcName);

    SymTable* getParent() const { return parent; }
};

