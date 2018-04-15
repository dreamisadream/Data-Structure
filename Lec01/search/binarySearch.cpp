#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool binarySearch(int arr[], int size, int target)
{
  int left = 0;
  int right = size - 1;
  int middle = (left + right)/2;

  while(right >= left)
  {
    if(target < arr[middle])        
      right = middle - 1;
    else if(target == arr[middle])
      return true;                    //找到
    else
      left = middle + 1;

    middle = (left + right)/2;
  }
  
  return false;   //沒找到
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

  /*配置一個長度為size的array*/
  srand(time(NULL));
 
  arr = new int [size];
  for(int i = 0; i<size; i++)
    arr[i] = rand()%100;

  sort(arr, arr+size);   

  for(int i = 0; i<size; i++)
    cout << arr[i] << " ";
  cout << endl;

  /*執行binarySearch*/
  if( binarySearch(arr, size, target) )
     cout << "found\n";
  else
     cout << "nope!\n";

  delete [] arr;

  return 0;
}
