#include "Calculator.h"
#include "Token.h"
#include "stdlib.h"
namespace jay {
template<class T>
struct Stack {
	struct Node {
		T item;
		Node(T item) : item(item){}
	};
	unsigned long cap;
	T *head;
	T *tail;
	Stack(){
		this->cap = 32;
		head = (T*)malloc(sizeof(T) * cap);
	}
};
Token *tokens = (Token*)0;

Calculator::Calculator(){
}
}




