#include "SymTable.h"
using namespace std;

SymInfo::SymInfo(){}
SymInfo::SymInfo(SymKind kind,const string& type,const string& name){
    this->kind=kind;
    this->type=type;
    this->name=name;
    this->inner_scope=nullptr;
}
SymInfo::~SymInfo(){}

SymTable::SymTable(const string& scope_name , SymTable* parent){
    this->scopeName=scope_name;
    this->parent=parent;
}
bool SymTable::exists(const string& sym_name){
    if(this->symbols.find(sym_name)!=this->symbols.end()){
        return true;
    }
    return false;
}
void SymTable::add(SymInfo *info){
    this->symbols[info->name]=info;
}
SymInfo* SymTable::lookup(const string& name){
    auto it=this->symbols.find(name);
    if(it!=this->symbols.end()){
        return it->second;
    }
    if(parent!=nullptr){
        return parent->lookup(name);
    }
    return nullptr;
}
SymTable::~SymTable(){
    for(auto i:this->symbols){
        delete i.second;
    }
    this->symbols.clear();
}
SymTable* SymTable::get_parent(){
    return this->parent;
}












