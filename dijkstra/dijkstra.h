#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

class dijkstra
{
  public:
    dijkstra();
    ~dijkstra();
    void init(char *_fileName);
    void run();
    void print_costTable();
    void backtrace(int _vertex);
    int nearest_vertex(int _vertex);
    
  private:
    // Path info
    int vertex_number;
    int **adjoint;     //紀錄整個路徑的資訊
    int *cost;         //紀錄起始點至各點的暫時距離
    int *prev;         //紀錄路程
    bool *visit;       //紀錄該點是否以找到最短距離

    // configuration
    int startPoint;
    int endPoint;
};

#endif
