#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct node
{
  int value;
  node *prev, *next;
};


int search(int _arr[], int _size, int _k, bool _small)
{
  if( _size < _k)
  {
     cerr << "k > size" << endl;
     exit(1);
  }

  /*將前k個預設為前k大的數*/
  sort(_arr, _arr+_k);
  for(int i = 0; i<_size; i++)
    cout << _arr[i] << " ";
  cout << endl;
 
  struct node *head, *last, *tmp, *new_last, *new_head;
  struct node top_k_node[_k];
  
  for(int i = 0; i<_k; i++)
  {
    top_k_node[i].value = _arr[i];
    if(i != 0)
      top_k_node[i].prev = &top_k_node[i-1];
    if(i != _k-1)
      top_k_node[i].next = &top_k_node[i+1];
  }
  
  top_k_node[0].prev    = NULL;
  top_k_node[_k-1].next = NULL;

  /*加入其他元素並更新node順序*/
  head = &top_k_node[0];
  last = &top_k_node[_k-1];
  for(int i = _k; i<_size; i++)
  {
    if( _small && _arr[i] < last->value )  //要找第k小的數且發現比第k小的數還要小的數
    {
      tmp = head;
      while(_arr[i] > tmp->value) //找尋第一個比它大的數
        tmp = tmp->next;
        
      /*PS: node為小到大排序，所以拿最後一個做更新
            top_k_arr[_k-1]未必為last　！！！　*/

      if(tmp == head)      //insert front (前端插入)
      {
        /*設定last為此node前一個，並將此node搬移至head前，並設定head為此node*/
        last->value = _arr[i];
        new_last = last->prev;
        new_last->next = NULL;
        last->prev = NULL;
        last->next = head;
        head->prev = last;
        head = last;
        last = new_last;
      }
      else if(tmp == last) //append (尾端插入)
      {
        /*直接更改last的值*/
        last->value = _arr[i];
      }
      else                 //insert (中間插入)
      {
        /*插入此node並將last指到前一個*/
        last->value = _arr[i];
        new_last = last->prev;
        new_last->next = NULL;
        last->next = tmp;
        last->prev = tmp->prev;
        tmp->prev->next = last;
        tmp->prev = last;
        last = new_last;
      }
    }
    
    else if( !_small && _arr[i] > head->value) //要找第ｋ大的數且發現比第k大的數還要大的數
    {
      tmp = head;
      while(tmp != NULL && _arr[i] > tmp->value) //找尋第一個比它大的數
        tmp = tmp->next;
        
      /*PS: node為小到大排序，所以拿第一個做更新
            top_k_arr[0]未必為head　！！！　*/

      if(tmp == head)      //insert front (前端插入)
      {
        /*直接更改head的值*/
        head->value = _arr[i];
      }
      else if(tmp == NULL) //append (尾端插入)
      {
        /*將此node搬移至last後，並設定last為此node，並設定head*/
        head->value = _arr[i];
        new_head = head->next;
        new_head->prev = NULL;
        head->next = NULL;
        head->prev = last;
        last->next = head;
        last = head;
        head = new_head;
      }
      else                 //insert (中間插入)
      {
        /*插入此node並將head指到下一個*/
        head->value = _arr[i];
	new_head = head->next;
        new_head->prev = NULL;
        head->next = tmp;
        head->prev = tmp->prev;
        tmp->prev->next = head;
        tmp->prev = head;
        head = new_head;
      }
    }
  }

  if(_small)
    return last->value;
  else
    return head->value;
}

void setArr(int _arr[], int _size)
{
  srand(time(NULL));
  
  for(int i = 0; i<_size; i++)
    _arr[i] = rand()%100;
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
  int k;
  bool is_small;
  cout << "size:";
  cin >> size;
  cout << "k: ";
  cin >> k;
  cout << "1:第" << k << "小" << " / 0:第" << k << "大:";
  cin >> is_small;

  /*allocate memory*/
  arr = new int [size];
  setArr(arr, size);
  printArr(arr, size);

  cout << search(arr, size, k, is_small);
  
  delete[] arr;
  
  return 0;  
}
