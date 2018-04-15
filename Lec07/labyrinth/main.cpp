#include <Labyrinth.h>

#include <iostream>

using namespace std;

int main()
{
  int rowSize, colSize;
  cout << "Row size: ";
  cin >> rowSize;
  cout << "Col Size: ";
  cin >> colSize;

  Labyrinth LabyrinthObj(rowSize, colSize);
  LabyrinthObj.path();

  return 0;
}
