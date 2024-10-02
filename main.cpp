#include "stdio.h"
#include "dlfcn.h"
#include "defs.h"
#include "signal.h"
#include "Calculator.h"

int main(int argc, byte **argv){
	const byte *test1 = "1+2*3";
	const byte *test2 = "10+20*30";
	const byte *test3 = "-10-20(38)";
	
	jay::Calculator *calc = new jay::Calculator();
	delete calc;
	

}
