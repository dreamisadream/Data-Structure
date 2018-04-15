#include <iostream>

using namespace std;

int fact(int n)
{
  if( n == 0 )
    return 1;
  else
    return n*fact(n-1);
}

int main()
{
  int number;
  cout << "Please enter a number:";
  cin >> number;
  cout << number << "! = " << fact(number) << endl;
  return 0;
}
