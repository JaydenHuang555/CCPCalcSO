#include "Calculator.h"
#include "Token.h"
#include "stdlib.h"
#include "stdio.h"
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

void test(){
	Stack<const byte*> *stack = new Stack<const byte*>();
	stack->push("test");
	stack->push("lkjhg");
	while(!stack->isEmpty()) printf("%s\n", stack->pop());
	delete stack;
}

Calculator::Calculator(){
	test();
}

} // jay






