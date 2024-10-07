#include "Calculator.h"
#include "Token.h"
#include "stdlib.h"
#include "stdio.h"
#include "signal.h"

namespace jay {
template<class T>
struct Stack {
	struct Node {
		T item;
		struct Node *next;
		struct Node *prev;
		Node() : next(0) , prev(0) {}
		Node(T item) : item(item), next(0), prev(0) {}
	};
	unsigned long cap;
	struct Node *head;
	Node *tail;
	Stack(){
		head = new Node();
		tail = head;
	}
	void push(T item){
		tail->next = new Node(item);
		tail->next->prev = tail;
		tail = tail->next;
	}
	T peek(){
		return tail->item;
	}
	T pop(){
		T item = peek();
		Node *node = tail->prev;
		if(tail == 0){
			fprintf(stderr, "Stack: error when popping\n");
			raise(SIGABRT);
		}
		delete tail;
		tail = node;
		return item;
	}
	unsigned int isEmpty(){
		return head == tail ? true : false;
	}

	~Stack(){
		for(Node *putback = tail; putback;){
			Node *queue = putback;
			putback = putback->prev;
			delete queue;
		}
	}
};
Token *tokens = 0;
Token *digested = 0;
unsigned long size;
unsigned long cap;
void testStack(){
	Stack<const byte*> *stack = new Stack<const byte*>();
	stack->push("test");
	stack->push("lkjhg");
	while(!stack->isEmpty()) stack->pop();
	delete stack;
}

void init(){
	tokens = new Token[cap];
}

Calculator<const byte*>::Calculator<const byte*>(){
	size = 0;
	cap = 32;
	testStack();
	init();
}

Calculator::~Calculator(){
	delete tokens;
}

} // jay






