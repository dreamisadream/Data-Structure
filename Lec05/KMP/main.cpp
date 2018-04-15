#include <KMP.h>

#include <iostream>

#define MaxLenth 0x100

using namespace std;

int main()
{
  KMP KMPOBJ(0x100, 0x30);

  int result;
  result = KMPOBJ.stringCompare();

  if(result == -1)
    cout << "Not found!" << endl;
  else
    cout << "Pattern in postion " << result << endl;

  return 0;
}
