#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE 10

void selectionSort(int arr[])
{
  int min;
  for(int i = 0; i<SIZE-1; i++)
  {
    min = i;
    for(int j = i+1; j<SIZE; j++)
      if(arr[j] < arr[min])
        swap(arr[j], arr[min]);
  }
}

void printArr(int arr[])
{
  for(int i = 0; i<SIZE; i++)
    cout << arr[i] << " ";
  cout << endl;
}


int main()
{
  int *arr;

  arr = new int [SIZE];
  srand(time(NULL));
  
  for(int i = 0; i<SIZE; i++)
    arr[i] = rand() % 100;

  selectionSort(arr);
  printArr(arr);
  delete [] arr;
  return 0;
}
