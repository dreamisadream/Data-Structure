#include <iostream>

using namespace std;

int sum(int n)
{
  if( n == 1 )
    return 1;
  else
    return sum(n-1) + n;
}

int main()
{
  int n;
  cout << "n:";
  cin >> n;
  if(n > 0)
    cout << "sum 1 to " << n << " = " << sum(n) << endl;
  else
    cout << "Invalid n" << endl;

  return 0;
}
