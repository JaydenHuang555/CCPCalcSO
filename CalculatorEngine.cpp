#include "CalculatorEngine.h"
#include "OrderedList.h"
#include "String.h"
#include "Stack.h"
#include "token/Token.h"
#include "token/OperatorToken.h"
#include "stdio.h"
#include "defs.h"

namespace jay {

static OrderedList<Token*> digested = 0;

static size_t len(const byte *cc){
  byte *c = (byte*)cc;
  while(*c) c++;
  return (size_t)(c - cc);
}



CalculatorEngine::CalculatorEngine(void){
}

CalculatorEngine::~CalculatorEngine(void){
}

void digest(const byte *buff){
  Stack<OperatorToken> *operators = new Stack<OperatorToken>();

  for(int i = 0; i < len(buff); i++){
    byte c = buff[i];
    bool hasLow = i != 0;
    bool hasHigh = i + 1 < len(buff);
  }

  while(!operators.isEmpty()) digested.add(operators.pop());
  delete operators;
}

double CalculatorEngine::eval(const byte *buff){
  return 0;
}
}
