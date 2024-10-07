#pragma once
#include "defs.h"
namespace jay {
template<class K>
class Calculator {
public:
	Calculator();
	~Calculator();
	K eval();
};
} // jay
