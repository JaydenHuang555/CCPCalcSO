#include "stdio.h"
#include "dlfcn.h"
#include "defs.h"
#include "signal.h"
#include "iostream"
#include "String.h"
/*
#include "CalculatorEngine.h"

int main(int argc, byte **argv){
	const byte *test1 = "1+2*3";
	const byte *test2 = "10+20*30";
	const byte *test3 = "-10-20(38)";
	
	jay::String lk;
	lk += test1;

	jay::Calculator<double> *calc = new jay::Calculator<double>();
	calc->eval(lk);

	delete calc;
}
*/

int main(void){
	jay::String str;
	str += "4594";
	std::cout << str.parseDouble()  << "\n";

}
