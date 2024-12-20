#pragma once

template <class T>
class Token {

protected:
	T item;
public:

	Token(void){}

	Token(const T item) : item(item){
	}
	const T getItem(void){
		return this->item;
	}

	virtual bool isOperand(void) {
		return false;
	}
	virtual bool isOperator(void) {
		return false;
	}
};

