#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iterator>

using namespace std;
enum SymKind{
    VAR,
    FUNCTION,
    PARAM,
    CLASS,
    FIELD,
    METHOD
};
class SymTable;
class SymInfo {
    public:
    SymKind kind;
    string type;
    string name;
    SymTable *inner_scope;
    SymInfo();
    SymInfo(const SymKind kind,const string& type,const string& name);
    ~SymInfo();
};

class SymTable {
    SymTable* parent;
    map<string, SymInfo*> symbols;
    string scopeName;
    public:
    SymTable(const string& scope_name, SymTable* parent = nullptr);
    bool exists(const string& sym_name);
    void add(SymInfo *info);
    SymTable* get_parent();
    SymInfo* lookup(const string& name);
    ~SymTable();
};






