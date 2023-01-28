#pragma once
#include <exception>
using namespace std;

class BadRange : public exception {
public:
    virtual const char* what() const noexcept override {
        return "ERROR: Выход за пределы массива!";
    }
};
