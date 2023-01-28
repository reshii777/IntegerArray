#pragma once
#include <exception>
using namespace std;

class BadLength : public exception {
public:
    virtual const char* what() const noexcept override {
        return "ERROR: Неверная длинна массива!";
    }
};
