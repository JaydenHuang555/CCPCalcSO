#pragma once

#include "String.h"
#include "Stack.h"
#include "OrderedList.h"

#include "Token/Token.h"
#include "Token/OperandToken.h"
#include "Token/OperatorToken.h"
#include <stdexcept>

#include "iostream"

#include "string"

namespace jay {

typedef char byte;

template<class T>
class Calculator {

    jay::OrderedList<Token<T>*> *digested = 0;

    bool isNumber(const byte c){
        return (47 < c && c < 58) || c == '.';
    }

    bool prec(const byte c){
        switch(c){
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^': return 3;
            default: return 0;
        }
    }

    OperatorToken<T> getOperatorType(const byte c){
        switch(c){
            case '+': return new AddOperator<T>();
            case '*': return new MultiOperator<T>(); 
            default:
                throw std::invalid_argument("given param is not an operator");
        }
    }

    void handleOperator(Stack<char> *stack, const char c) {
        if(stack->isEmpty()) stack->push(c);
        else {
            if(prec(stack->peek()) > prec(c)){
                while(!stack->isEmpty() && prec(stack->peek()) > prec(c)) digested->add(getOperatorType(stack->pop()));
                stack->push(c);
                return;
            }
            if(prec(stack->peek()) < prec(c)) digested->add(getOperatorType(c));
        }
    }

public:
    Calculator(void){
        digested = new jay::OrderedList<Token<T>*>();
    }

    ~Calculator(void){
        if(!digested) return;
        for(int i = 0; i < digested->getSize(); i++) delete digested[i];
        delete digested;
    }

    void digest(jay::String equation){
        jay::String *builder = new jay::String();
        jay::Stack<const char> stack;

        for(int i = 0; i < equation.getSize(); i++){
            byte c = equation[i];
            #define isNum ((isNumber(c)))
            #define isOperator ((prec(c)))

            if(isNum) builder += c;
            if(isOperator){
                if(builder->getSize()){
                    int off = 0;
                    digested->add(new OperandToken<T>(builder));
                    builder = new jay::String();
                }
                handleOperator(&stack, c);
            }
            #undef isNum 
            #undef isOperator
        }
        while(!stack.isEmpty()) digested->add(getOperatorType(stack.pop()));
    }

    T eval(jay::String equation){
        digest(equation);
        Stack<Token<T>*> *stack = new Stack<Token<T>*>();
        for(int i = 0; i < digested->getSize(); i++){
            if(isNumber(*digested[i])) stack->push(digested[i]);
            else {
                T right = stack->pop()->getItem();
                T left = stack->pop()->getItem();
                stack->push(((OperatorToken<T>*)digested[i])->eval(left, right));
            }
        }
       delete stack;
       return stack->pop();
    }



};
}