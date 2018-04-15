#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

/* 交換 _pos1 及 _pos2 字元，並回傳 */
char * SWAP(char _arr[], int _pos1, int _pos2)
{
  char tmp;
  
  tmp = _arr[_pos1];
  _arr[_pos1] = _arr[_pos2];
  _arr[_pos2] = tmp;

  return _arr;
}

void perm(char _arr[], int _left, int _right)
{
  if( _left == _right)  // cannot swap any charactor
  {
    cout << _arr << endl;
    return;
  }

  for(int i = _left; i <= _right; i++)
  {
    perm( SWAP(_arr, _left, i), _left+1, _right);
    _arr = SWAP(_arr, _left, i);
  }
  
}

int main()
{
  char arr[10];
  cout << "string:";
  cin >> arr;
  perm(arr, 0, strlen(arr)-1);
  return 0;
}
