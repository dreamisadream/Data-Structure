#include "Calculator.h"

#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

Calculator::Calculator()
{
  createFormula();
}


void Calculator::createFormula()
{
  cout << "\nInput a formula: ";
  cin.getline(formula, MaxSize-1);
}

void Calculator::postfix()
{
  stack<char> Operator;
  PFptr = postfix_formula;
  char x;

  // extract each char in formula
  for(int i = 0; formula[i] != 0; i++)
  {
    x = formula[i];

    if(isspace(x))
      continue;

    if(isdigit(x)) // operand
      *PFptr++ = x;
    else if(x == ')'){ // pop until '('
      for(char y = Operator.top(); y != '('; y = Operator.top()){
        *PFptr++ = y;
        Operator.pop();

        if(Operator.empty()){
          cerr << "Error! Parentheses are not match\n";
          exit(1);}
      }
      Operator.pop();} // '('

    else{ // operator
      if(Operator.empty())
        Operator.push(x);
      else{
       for(char y = Operator.top(); ICP(x) > ISP(y); y = Operator.top()){
         *PFptr++ = y;
          Operator.pop();

          if(Operator.empty())
            break;
        }
        Operator.push(x); }
    } // end of else
  } // end of for

  while(!Operator.empty()){
    *PFptr++ = Operator.top();
    Operator.pop();
  }
}


void Calculator::calc()
{
  postfix(); // transfer the formula form into postfix

  stack <int> Operand;

  for(char *ptr = postfix_formula; ptr != PFptr; ptr++){
    if(isdigit(*ptr)) // operand
      Operand.push(*ptr-'0');
    else{ // operator
      int op2    = Operand.top(); Operand.pop();
      int op1    = Operand.top(); Operand.pop();
      int result = calc_value(op1, op2, *ptr);

      Operand.push(result);
    }
  }

  cout << "The answer is " << Operand.top() << endl;
}


void Calculator::print_postfix()
{
  for(char *ptr = postfix_formula; ptr != PFptr; ptr++)
    cout << *ptr;
  cout << endl;
}


int Calculator::calc_value(int _a, int _b, char _symbol)
{
  switch(_symbol){
    case '+':
      return _a + _b;

    case '-':
      return _a - _b;

    case '*':
      return _a * _b;

    case '/':
      return _a / _b;

    case '%':
      return _a % _b;

    default:
      cerr << "Error! Cannot parse " << _symbol << "\n";
      exit(1);
  }
}


// Only consider + - * / % (
inline int Calculator::ICP(char _Operator)
{
  switch(_Operator){
    case '(':
      return 1;

    case '*':case '/': case '%':
      return 2;

    case '+':case '-':
      return 3;

    default:
      cerr << "Error! cannot parse " << _Operator << "\n";
      exit(1);
  }
}


// Only consider + - * / % (
inline int Calculator::ISP(char _Operator)
{
  switch(_Operator){
    case '*':case '/': case '%':
      return 1;

    case '+':case '-':
      return 2;

    case '(':
      return 3;

    default:
      cerr << "Error! cannot parse " << _Operator << "\n";
      exit(1);
  }
}
