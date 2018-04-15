#include "Labyrinth.h"

#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

struct direct_info
{
    int row_offset;
    int col_offset;
}move[8];


Labyrinth::Labyrinth(int _rowSize, int _colSize): rowSize(_rowSize), colSize(_colSize), exitX(_rowSize), exitY(_colSize)
{
  create();
  setLabyr();
}


void Labyrinth::create()
{
  // create a labyrinth surrounding a wall
  maze = new int* [rowSize+2];
  for(int i = 0; i<rowSize+2; i++)
    maze[i] = new int[colSize+2];

  mark = new bool* [rowSize+2];
  for(int i = 0; i<rowSize+2; i++)
    mark[i] = new bool[colSize+2];
}


void Labyrinth::setLabyr()
{
  fill(maze[0], &maze[rowSize+1][colSize+1]+1, 1);

  cout << "input the map:\n";
  for(int i = 1; i<=rowSize; i++)
    for(int j = 1; j<=colSize; j++)
      cin >> maze[i][j];
}


void Labyrinth::path()
// Output a path (if any) in the maze;
// maze[j][0] = maze[j][p+1] = 1, 0<=i, <= p+1, 0<= j <= m+1
{    //start at (1, 1)
    setDirectionInfo();

    mark[1][1] = 1;
    stack <step> trace;
    step temp;
    temp.x = 1; temp.y = 1; temp.dir = 2;
    trace.push(temp);

    while(!trace.empty()) // stack not empty
    {
      temp = trace.top();  //unstack
      trace.pop();

      int X = temp.x; int Y = temp.y; int Dir = temp.dir;
      while(Dir < 8) // move forward
      {
        int nextX = X + move[Dir].col_offset; int nextY = Y + move[Dir].row_offset;
        if((nextX == exitX) && (nextY == exitY)){ // reached exit
          temp.x = nextX; temp.y = nextY;
          trace.push(temp);
          printTrace(trace);
          return;
        }
        if(!maze[nextY][nextX] //legal move
            && !mark[nextY][nextX]) // haven't been there
        {
          mark[nextY][nextX] = 1;
          temp.x = nextX; temp.y = nextY; temp.dir = Dir+1;
          trace.push(temp);
          X = nextX; Y = nextY; Dir = 0;
        }// end of if
        else
          Dir++;
      }// end of while
    }// end of while

    cout << "no path in maze" << endl;
}


void Labyrinth::setDirectionInfo()
{
  /* North */
  move[0] = {-1, 0};
  /* North East */
  move[1] = {-1, 1};
  /* East */
  move[2] = {0, 1};
  /* South East */
  move[3] = {1, 1};
  /* Sourht */
  move[4] = {1, 0};
  /* South West */
  move[5] = {1, -1};
  /* West */
  move[6] = {0, -1};
  /* North West */
  move[7] = {-1, -1};
}


void Labyrinth::printTrace(stack<step> trace)
{
  step temp;
  cout << endl;
  while(!trace.empty()){
    temp = trace.top();
    cout << temp.x << " " << temp.y << endl;
    trace.pop();
  }
}
