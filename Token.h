#pragma once
#include "defs.h"

class Token {
protected:
	enum TokenType {
		NONE = 0,
		OPERAND = 1,
		OPERATOR = 2,
	};
	const byte *item;
	enum TokenType type;
public:
	Token(){
		type = NONE;
	}
	Token(const byte *item) : item(item){
		type = NONE;
	}
	const byte *toString(){
		return this->item;
	}
	enum TokenType getType(){
		return type;
	}
};

