#include <SparseMatrix.h>

#include <iostream>

using namespace std;

char func[] = "1: Transpose method 1\n2: Transpose method 2\n3: Show matrix list\n4: Show matrix\n5: exit\nYour choice: ";

int main()
{
  int rows, cols, terms;
  cout << "row:";
  cin >> rows;
  cout << "col:";
  cin >> cols;
  cout << "nonzero terms number:";
  cin >> terms;

  SparseMatrix SparseMatrixOBJ(rows, cols, terms);

  int choice;
  while(true)
  {
    cout << func;
    cin >> choice;
    cout << "\n";

    switch(choice){

      case 1:
        SparseMatrixOBJ = SparseMatrixOBJ.Transpose1();
        break;
      case 2:
        SparseMatrixOBJ = SparseMatrixOBJ.Transpose2();
        break;
      case 3:
        SparseMatrixOBJ.showMatrixList();
        break;
      case 4:
        SparseMatrixOBJ.showMatrix();
        break;
      default:
        cout << "Invalid choice" << endl;
        break;
    }//end of switch

  }//end of while

  return 0;
}
