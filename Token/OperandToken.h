#pragma once
#include "Token.h"

template <class T>
class OperandToken : Token<T> {
public:

	

	OperandToken(T item){
		this->item = item;
	}
	
	bool isOperand(void){
		return true;
	}

};
