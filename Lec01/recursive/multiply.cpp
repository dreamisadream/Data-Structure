#include <iostream>

using namespace std;

int multi(int a, int b)
{
  if( b == 1 )
    return a;
  else
    return a + multi(a, b-1);
}

int main()
{
  int a, b;
  cout << "a:";
  cin >> a;
  cout << "b:";
  cin >> b;
  cout << "a x b = " << multi(a, b) << endl;
  return 0;
}
