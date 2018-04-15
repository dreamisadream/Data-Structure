#include <iostream>

using namespace std;

template <class KeyType>
class Queue
{
    //objects: A finite ordered list with zero or more elements
    public:
        Queue(int MaxQueueSize);
        // Create an empty Queue whose maximun size is MaxQueueSize
        bool IsFull();
        // if number of elements in the queue is equal to the maximun size of
        // the queue, return TRUE(1); otherwise, return FALSE(0)
        void Add(const KeyType& item);
        // if IsFull(), then QueueFull(); else insert item at rear of the queue
        bool IsEmpty();
        // if number of elements in the queue is equal to 0, return TRUE(1)
        // else return FALSE(0)
        KeyType* Delete(KeyType&);
        // if IsEmpty(), then QueueEmpty() and return 0;
        // elser remove the front of the queue and return a point to it
    private:
        int front, rear;
        KeyType *queue;
        int MaxSize;
};


template <class KeyType>
Queue<KeyType>::Queue(int MaxQueueSize): MaxSize(MaxQueueSize)
{
  queue = new KeyType[MaxSize];
  front = 0;
  rear = 0;
}


template <class KeyType>
inline bool Queue<KeyType>::IsFull()
{
  if( (rear+1)%MaxSize == front) return true;
  else return false;
}


template <class KeyType>
inline bool Queue<KeyType>::IsEmpty()
{
  if( front == rear) return true;
  else return false;
}


template <class KeyType>
void Queue<KeyType>::Add(const KeyType& item)
{
  /* add an item into the global Queue */
  if(IsFull())
    cout << "Queue is full\n"; //Queue_Full()
  else{
    queue[rear] = item;
    rear = (rear+1)%MaxSize;
  }
}


template <class KeyType>
KeyType* Queue<KeyType>::Delete(KeyType& item)
{
  if(IsEmpty()){
    cout << "Queue is empty\n"; //Queue_Empty()
    return 0;
  }
  item = queue[front];
  front = (front+1)%MaxSize;
  return &item;
}
