#pragma once

#include <ostream>
#include <stdexcept>

namespace jay {
template<typename T>
class OrderedList {
#define size (((unsigned long)(tail - subList)))
    unsigned long cap;
    T *subList, *tail;

public:
    OrderedList() : cap(1 << 3) {
        this->subList = new T[this->cap];
        this->tail = subList;
    }

    OrderedList(OrderedList<T> &other){
        this->cap = other.cap;
        this->subList = other.subList;
        this->tail = other.tail;
    }

    ~OrderedList(){
        delete[] subList;
    }
    
    void add(T item){
        *(this->tail++) = item;
        if(size == cap){
            T *next = new T[cap *= 2];
            for(int i = 0; i < cap / 2; i++) next[i] = subList[i];
            delete[] subList;
            subList = next;
            tail = (subList + cap);
        }
    }

    T get(unsigned long index){
        if(index > size || index < 0) throw std::invalid_argument("OrderedList: invalid argument given");
        return subList[index];
    }

    T operator[](unsigned long index){
        return get();
    }

    unsigned long getSize(void){
        return size;
    }
    
    friend std::ostream &operator<<(std::ostream &stream, const OrderedList<T> &list){
        stream << "{ ";
        for(unsigned long i = 0; i < (unsigned long)(list.tail - list.subList); i++) stream << list.subList[i] << ", ";
        stream << "\b\b }";
        return stream;
    }

};
}