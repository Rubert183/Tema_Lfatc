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
            default:
                break;
        }
    }
};