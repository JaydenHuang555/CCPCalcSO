#pragma once 
#include "defs.h"
#include "stdio.h"
#include "signal.h"

namespace jay {
	class String {
		byte *buff;
		unsigned long size;
		unsigned long cap;

		void fillBuff(byte **buffAddr){
			byte *c = *buffAddr;
			for(int i = 0; i < cap; i++) buffAddr[i] = 0;
		}
public:
		String(){
			this->size = 0;
			this->cap = 8;
			this->buff = new byte[this->cap];
			this->fillBuff(&buff);
		}

		String &operator+=(byte c){
			buff[size++] = c;
			if(size == cap){
				byte *next = new byte[cap *= 2];
				fillBuff(&next);
				for(unsigned long i = 0; i < cap / 2; i++) next[i] = buff[i];
				delete buff;
				next = buff;
			}
			return *this;
		}

		byte operator[](unsigned long index){
			if(index > size){
				fprintf(stderr, "jay::String:error when getting val");
				raise(SIGABRT);
			}
			return buff[index];
		}

		~String(){
			delete buff;
		}
	};
}; // jay
