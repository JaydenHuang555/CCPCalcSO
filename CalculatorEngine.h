#pragma once
#include "defs.h"
namespace jay {
class CalculatorEngine {
public:
  CalculatorEngine();
  ~CalculatorEngine();
  double eval(const byte*);

};
} // jay
