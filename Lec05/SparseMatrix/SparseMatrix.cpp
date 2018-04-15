#include "SparseMatrix.h"

#include <iostream>
#include <iomanip>

using namespace std;

SparseMatrix::SparseMatrix()
{
    //ctor
}


SparseMatrix::SparseMatrix(int _MaxRows, int _MaxCols, int _MaxTerms): Rows(_MaxRows), Cols(_MaxCols), Terms(_MaxTerms)
{
  cout << "\n        row col value : both row and col start from 0\n";
  for(int i = 0; i<_MaxTerms; i++){
    cout << "Terms " << i << ": ";
    cin >> smArray[i].row >> smArray[i].col >> smArray[i].value;
  }
  cout << endl;
}


SparseMatrix SparseMatrix::Transpose1()
// return the transpose of a(*this)
{
  SparseMatrix b;
  b.Rows = Cols;    //rows in b = columns in a
  b.Cols = Rows;    //columns in b = rows in a
  b.Terms = Terms;  //terms in b = terms in a
  if(Terms>0)       //nonzero matrix
  {
    int CurrentB = 0;
    for(int c = 0; c<Cols; c++) //transpose by columns
      for(int i = 0; i<Terms; i++)
      // find elements in column c
        if(smArray[i].col == c){
          b.smArray[CurrentB].row = c;
          b.smArray[CurrentB].col = smArray[i].row;
          b.smArray[CurrentB].value = smArray[i].value;
          CurrentB++;
        }
  } // end of if(Terms > 0)

  return b;
} // end of transpose


SparseMatrix SparseMatrix::Transpose2()
//The transpose of a(*this) is placed in b and is found in Q(terms + columns) time.
{
  int *RowSize  = new int [Cols];
  int *RowStart = new int [Cols];

  SparseMatrix b;
  b.Rows = Cols;
  b.Cols = Rows;
  b.Terms = Terms;

  int i;
  if(Terms>0)   //nonzero matrix
  {
    //compute RowSize[i] = number of terms in row i of b
    for(i = 0; i<Cols; i++) RowSize[i] = 0; //initialize

    for(i = 0; i<Terms; i++) RowSize[smArray[i].col]++;

    //RowStart[i] = starting position of row i in b
    RowStart[0] = 0;
    for(i = 1; i<Cols; i++) RowStart[i] = RowStart[i-1]+RowSize[i-1];

    for(i = 0; i<Terms; i++) //move from a to b
    {
      int j = RowStart[smArray[i].col];
      b.smArray[j].row = smArray[i].col;
      b.smArray[j].col = smArray[i].row;
      b.smArray[j].value = smArray[i].value;
      RowStart[smArray[i].col]++;
    } //end of for
  }// end of if

  delete [] RowSize;
  delete [] RowStart;

  return b;
}// end of FastTranspose


void SparseMatrix::showMatrix()
{
  int matrix[Rows][Cols];

  //init
  int *ptr = matrix[0];
  for(; ptr != matrix[0] + Rows*Cols;ptr++)
    *ptr = 0;

  //assign Terms
  MatrixTerm *Mptr = smArray;
  for(;Mptr != smArray+Terms; Mptr++)
    matrix[Mptr->row][Mptr->col] = Mptr->value;

  //show
  ptr = matrix[0];
  for(; ptr != matrix[0] + Rows*Cols;)
  {
    for(int i = 0; i<Cols; i++, ptr++)
      cout << fixed << setw(3) << *ptr << " ";
    cout << endl;
  }
  cout << endl;
}


void SparseMatrix::showMatrixList()
{
  MatrixTerm *mptr = smArray;
  for(; mptr != smArray+Terms;mptr++)
    cout << fixed << setw(3) << mptr->row << fixed << setw(3) << mptr->col << fixed << setw(3) << mptr->value << endl;
  cout << endl;
}
