#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <stack>

class step;

class Labyrinth
{
    public:
      Labyrinth(int _rowSize, int _colSize);
      void create();
      void setLabyr();
      void path();
      void setDirectionInfo();
      void printTrace(std::stack<step>);

    private:
      int rowSize;
      int colSize;
      int **maze;
      int exitX, exitY;
      bool **mark;
};

class step
{
  friend Labyrinth;

  private:
    int x, y, dir;
};


#endif // LABYRINTH_H
