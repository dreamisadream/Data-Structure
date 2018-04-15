#include <polynomial.h>

#include <iostream>

using namespace std;

int main()
{
  polynomial polyA('A');
  polynomial polyB('B');

  polynomial polyC;
  polyC = polyA.Add(polyB);
  polyC.printResult();

  return 0;
}
