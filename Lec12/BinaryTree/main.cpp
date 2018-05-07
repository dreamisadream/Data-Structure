#include <Tree.h>

#include <iostream>
#include <stdlib.h>

using namespace std;

char manual[] = "\n1. insert\n2. delete\n3. preorder\n4. inorder\n5. postorder\n6. levelorder\n7. exit\nYour choic: ";

int main()
{
    Tree BinaryTree;

    cout << "Welcome to the BT World!!\n";

    int op;
    while(1){
        cout << manual;
        cin >> op;

        switch(op){
            case 1:
                BinaryTree.InsertNode();
                break;

            case 2:
                BinaryTree.DeleteNode();
                break;

            case 3:
                BinaryTree.preorder();
                break;

            case 4:
                BinaryTree.inorder();
                break;

            case 5:
                BinaryTree.postorder();
                break;

            case 6:
                BinaryTree.levelorder();
                break;

            case 7:
                exit(1);

            default:
                cout << "Invalid input\n";
                break;
        }
    }
    return 0;
}
