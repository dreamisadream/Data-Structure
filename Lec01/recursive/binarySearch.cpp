#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int COMPARE(int _a, int _b)
{
  if(_a > _b)
    return 1;
  else if(_a == _b)
    return 0;
  else
    return -1;
}

int binarySearch(int _arr[], int _target, int _left, int _right)
{
  if(_left > _right)
    return 0;
  
  int middle;
  
  middle = (_left + _right) /2;
  switch( COMPARE(_arr[middle], _target) )
  {
    case 1: // _arr[middle] > _target
      return binarySearch(_arr, _target, _left, middle-1);
    case 0: //  _arr[middle] = _target
      return _arr[middle];
    case -1: // _arr[middle] < _target
      return binarySearch(_arr, _target, middle+1, _right);
    
    default:
      cerr << "You got FLAG!!"; //Don't ask me what this flag means.
      exit(1);
  }
}

void setArr(int _arr[], int _size)
{
  srand(time(NULL));
  for(int i = 0; i<_size; i++)
    _arr[i] = rand() % 100;
}

void printArr(int _arr[], int _size)
{
  for(int i = 0; i<_size; i++)
    cout << _arr[i] << " ";
  cout << endl;
}

int main()
{
  int *arr;
  int size;
  int target;
  cout << "size:";
  cin >> size;
  cout << "target:";
  cin >> target;
  //allocate memory
  arr = new int [size];

  setArr(arr, size);
  sort(arr, arr+size);
  printArr(arr, size);

  if( binarySearch(arr, target, 0, size-1) )
    cout << "found" << endl;
  else
    cout << "nope!" << endl;

  return 0;
}
