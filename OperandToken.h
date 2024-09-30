#pragma once
#include "Token.h"

class OperandToken : Token {
	OperandToken(const byte *item){
		this->item = item;
		this->type = OPERAND;
	}
};
