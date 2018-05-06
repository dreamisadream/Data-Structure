#include "List.h"

#include <cstdlib>
#include <iostream>

using namespace std;

char manual[] = "\n1. Attach\n2. Invert\n3. Concatenate\n4. show\n5. exit\nYour choice: ";

int main()
{
    cout << "Welcome to the linked list world!\n";

    List<int> A, B;

    int op;
    int value;
    char listId;

    while(1){
        cout << manual;
        cin >> op;

        switch(op){

            case 1:
                cout << "LIST(A/B): ";
                cin >> listId;
                cout << "value: ";
                cin  >> value;
                if(listId == 'A')
                    A.Attach(value);
                else if(listId == 'B')
                    B.Attach(value);

                break;

            case 2:
                cout << "LIST(A/B): ";
                cin >> listId;
                if(listId == 'A')
                    A.Invert();
                else if(listId == 'B')
                    B.Invert();

                break;

            case 3:
                cout << "1. A || B\n2. B || A \n num: ";
                cin >> op;

                if(op == 1)
                    A.Concatenate(B);
                else if(op == 2)
                    B.Concatenate(A);

                break;

            case 4:

                cout << "A or B : ";
                cin >> listId;

                if(listId == 'A')
                    A.showList();
                else if(listId == 'B')
                    B.showList();

                break;

            case 5:
                exit(1);
                break;

            default:
                cout << "Invalid input\n\n";
                break;
        }
    }
    return 0;
}
