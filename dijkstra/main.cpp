#include <dijkstra.h>

#include <iostream>

using namespace std;

int main()
{
  char* fileName = "path.txt";   

  dijkstra dijkstraObj; 
  
  dijkstraObj.init(fileName);
  dijkstraObj.run();
  
  return 0;
}
