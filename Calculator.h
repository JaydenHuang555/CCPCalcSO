#pragma once
#include "defs.h"
namespace jay {
class Calculator {
public:
	Calculator();
	~Calculator();
	const byte *eval(const byte*);
};
} // jay
