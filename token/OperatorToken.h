#pragma once
#include "Token.h"

template<class T>
class OperatorToken : Token<const char*> {

public:

    OperatorToken(){
    }

    virtual T eval(T a, T b) = 0;

    bool isOperator(void){
        return true;
    }

};

template<class T>
class AddOperator : OperatorToken<T> {
public:
    AddOperator(){
    }

    T eval(T a, T b){
        return a + b;
    }
};
template<class T>
class MultiOperator : OperatorToken<T> {
public:
    MultiOperator(){}

    T eval(T a, T b){
        return a * b;
    }
};

template<class T>
class SubOperator : OperatorToken<T> {
public:
    SubOperator(){
    }

    T eval(T a, T b){
        return a - b;
    }
};

template<class T>
class DivOperator : OperatorToken<T> {
public:
    DivOperator(){
    }

    T eval(T a, T b){
        return a / b;
    }
};