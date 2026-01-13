#pragma once
#include <string>
#include <variant>
#include <iostream>

using namespace std;

enum class ValueType {
    INT,
    FLOAT,
    BOOL,
    STRING,
    OBJECT,
    VOID // folosit numai ca default value in constructor
};

class Value {
public:
    ValueType type;
    variant<int, float, bool, string> data;

    Value() : type(ValueType::VOID) {}

    static Value makeInt(int v = 0) {
        Value new_val;
        new_val.type = ValueType::INT;
        new_val.data = v;
        return new_val;
    }
    static Value makeFloat(float v = 0.f) {
        Value new_val;
        new_val.type = ValueType::FLOAT;
        new_val.data = v;
        return new_val;
    }
    static Value makeBool(bool v = true) {
        Value new_val;
        new_val.type = ValueType::BOOL;
        new_val.data = v;
        return new_val;
    }
    static Value makeString(string v = "") {
        Value new_val;
        new_val.type = ValueType::STRING;
        new_val.data = v;
        return new_val;
    }
    static Value makeObject(string instanceName) {
        Value new_val;
        new_val.type = ValueType::OBJECT;
        new_val.data = instanceName; 
        return new_val;
    }
    void print() {
        switch (type) {
            case ValueType::INT:
                cout << get<int>(data) << endl; 
                break;
            case ValueType::FLOAT:
                cout << get<float>(data) << endl;
                break;
            case ValueType::BOOL:
                cout << (get<bool>(data) ? "true" : "false") << endl;
                break;
            case ValueType::STRING:
                cout << get<std::string>(data) << endl;
                break;
            case ValueType::VOID:
                cout<<"Can't print VOID expresions"<<endl;
            default:
                cout<<"Can't print objects of type "<< get<std::string>(data) <<" since deserialization for this type is not implemented"<<endl;
                break;
        }
    }
    string toString() const {
        switch (type) {
            case ValueType::INT:
                return to_string(get<int>(data));
            case ValueType::FLOAT:
                return to_string(get<float>(data));
            case ValueType::BOOL:
                return get<bool>(data) ? "true" : "false";
            case ValueType::STRING:
                return "\"" + get<std::string>(data) + "\"";
            case ValueType::OBJECT:
                return "Object(" + get<std::string>(data) + ")"; 
            default:
                return "void";
        }
    }
};