#include <Calculator.h>

#include <cstdio>
#include <iostream>

using namespace std;

char manual[] = "\n1. change the formula\n2. print the postfix of formula\n3: print the answer\nYour choice: ";

int main()
{
    Calculator CalculatorObj;
    int op;

    while(true)
    {
      cout << manual;
      cin >> op;

      switch(op){
        case 1:
          getchar();
          CalculatorObj.createFormula();
          break;

        case 2:
          CalculatorObj.postfix();
          CalculatorObj.print_postfix();
          break;

        case 3:
          CalculatorObj.calc();
          break;

        default:
          cerr << "Invalid choice!\n";
          break;
      }
    }
    return 0;
}
