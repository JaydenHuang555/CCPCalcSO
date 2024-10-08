#pragma once
#include "signal.h"
#include "stdio.h"

namespace jay {
	template <typename T>
	class ArrayList {
		T *subList = 0;
		unsigned long cap;
		unsigned long size;
public:
		ArrayList(){
			this->cap = 16;
			this->size = 0;
			this->subList = new T[cap];
		}
		~ArrayList(){
			delete subList;
		}

		T operator[](unsigned long index){
			if(index > cap){
				printf("unable to get element at index");
				raise(SIGABRT);
			}
			return subList[index];
		}

		void add(T item){
			subList[size++] = item;
			if(size == cap){
				T next = new T[cap *= 2];
				for(int i = 0; i < cap / 2; i++) next[i] = subList[i];
				delete subList;
				subList = next;
			}
		}
	};
} // jay 
