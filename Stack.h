#pragma once 

namespace jay {
template<typename T>
class Stack {

    struct Node {
        T val;
        Node *next;
        Node *prev;

        Node(T val){
            this->val = val;
            this->next = 0, this->prev = 0;
        }
    };

public:
    Node *head, *tail;

    Stack() : head(0), tail(0) {}

    Stack(Stack<T> &other){
        this->head = other.head;
        this->tail  = other.tail;
    }

    ~Stack(){
        while(!head){
            Node *next = head->next;
            if(!next){
                head = next;
                continue;
            }
            delete head;
            head = next;
        }
    }

    void push(T item){
        if(!head){
            head = new Node(item);
            tail = head;
        }
        else {
            tail->next = new Node(item);
            tail->next->prev = tail;
            tail = tail->next;
        }
    }

    T peek(){
        return tail->val;
    }

    T pop(){
        T item = tail->val;
        if(tail != head){
            tail = tail->prev;
            delete tail->next;
            tail->next = 0;
        }
        else {
            delete head;
            head = 0, tail = 0;
        }
        return item;
    }

    bool isEmpty(){
        return !head;
    }

};
}