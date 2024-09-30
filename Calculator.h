#pragma once
#include "defs.h"
namespace jay {
class Calculator {
public:
	Calculator();
	void init();
	Calculator &digest(const byte*);	
	double evald();
};
} // jay
