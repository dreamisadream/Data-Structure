
#include <Queue.h>

#include <iostream>

using namespace std;

char manual[] = "\n1:enqueue\n2:dequeue\n3:view\nYour choice: ";

int main()
{
  Queue<int> QueueObj(10);
  int choice;
  int enqueue_value, dequeue_value, *rear;

  while(true){
    cout << manual;
    cin >> choice;

    switch(choice){
      case 1:
        cout << "value: ";
        cin >> enqueue_value;
        QueueObj.Add(enqueue_value);
        break;

      case 2:
        rear = QueueObj.Delete(dequeue_value);
        if(rear != 0)
          cout << "value = " << dequeue_value << endl;
        break;

      case 3:
        cout << "Please write it by yourself...\n";
        break;

      default:
        cout << "Invalid Choice\n";
        break;
    }
  }

  return 0;
}
