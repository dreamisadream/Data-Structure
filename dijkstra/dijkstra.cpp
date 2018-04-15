#include "dijkstra.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define INFINITE 2<<20

dijkstra::dijkstra()
{
  cout << "From:";
  cin >> startPoint;
  cout << "To:";
  cin >> endPoint;
}


dijkstra::~dijkstra()
{
  for(int i = 0; i<vertex_number; i++)
    delete adjoint[i];
  delete adjoint;
  
  delete [] cost;
  delete [] prev;
  delete [] visit;
}


void dijkstra::init(char *_fileName)
{  
  fstream fin;
  int from, to, weight;

  fin.open(_fileName, ios::in);

  //確認是否成功讀取檔案
  if(!fin.good())
  {
    cerr << "read failed...";
    exit(1);
  }

  fin >> vertex_number;

  //配置記憶體，因為陣列從0開始，所以+1
  adjoint = new int* [vertex_number+1];
  for(int i = 1; i<=vertex_number; i++)
    adjoint[i] = new int [vertex_number+1];
  
  cost = new int [vertex_number+1];
  prev = new int [vertex_number+1];
  visit = new bool [vertex_number+1];

  //設定初始值
  for(int i = 1; i<=vertex_number; i++)
  {
    for(int j = 1; j<=vertex_number; j++)
      if(i!=j)
        adjoint[i][j] = INFINITE;
      else
        adjoint[i][j] = 0;

    visit[i] = false;
  }

  //寫入資料
  while( !fin.eof() )
  {
    fin >> from >> to >> weight;
    adjoint[from][to] = weight;
  }

  //設定起始位置資料
  visit[startPoint] = true;
  
}

void dijkstra::run()
{
  int current_vertex;
  int distant = INFINITE;

  //設定cost、prev初值，並找尋下一個出發點
  for(int i = 1; i<=vertex_number; i++)
  {
    cost[i] = adjoint[startPoint][i];
    prev[i] = 1;

    if(cost[i] < distant)
    {
      current_vertex = i;
      distant = cost[i];
    }
  }

  //運行dijkstra，共執行vertex_number-1次（扣掉最後一個點）
  for(int i = 0; i<vertex_number-1; i++)
  {
    visit[current_vertex] = true;
    cout << "current_vertex = " << current_vertex << endl;
    current_vertex = nearest_vertex(current_vertex);
    print_costTable();
  }

  cout << "=============================================\n";
  cout << "The shortest Path from V" << startPoint << " to V" << endPoint << ":\n";
  backtrace(endPoint);
  cout << endPoint <<endl;
}


int dijkstra::nearest_vertex(int _vertex)
{
  int distant = INFINITE;
  int retn_vertex = -1;

  //更新cost 並找尋下一個出發點（花費最少的點）
  for(int i = 1; i<=vertex_number; i++)
  {
    if(!visit[i])
    {
      if(cost[_vertex] + adjoint[_vertex][i] < cost[i])
      {
        cost[i] = cost[_vertex] + adjoint[_vertex][i];
        prev[i] = _vertex;                             //設定路徑
      }
      if(cost[i] < distant)
      {
        retn_vertex = i;
        distant = cost[i];
      }
    }
  }

  return retn_vertex;
}


void dijkstra::backtrace(int _vertex)
{
  if(prev[_vertex] != startPoint)
    backtrace(prev[_vertex]);

  cout << prev[_vertex] << "->";
}


void dijkstra::print_costTable()
{
  cout << "=============================================\n";
  for(int i = 1; i<=vertex_number; i++)
    cout << setw(4) << "D[" << i << "]";
  cout << "\n";

  for(int i = 1; i<=vertex_number; i++)
    if(cost[i] == INFINITE)
      cout << setw(6) << "-";
    else
      cout << setw(6) << cost[i];

  cout << "\n";


  cout << "=============================================\n";
  for(int i = 1; i<=vertex_number; i++)
    cout << setw(4) << "P[" << i << "]";
  cout << "\n";

  for(int i = 1; i<=vertex_number; i++)
    cout << setw(6) << prev[i];

  cout << "\n";
}
