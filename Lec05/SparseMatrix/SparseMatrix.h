#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#define MaxTerms 1000

class MatrixTerm
{
    friend class SparseMatrix;
    private:
        int row, col, value;
};

class SparseMatrix
{
    public:
        SparseMatrix();
        SparseMatrix(int _MaxRows, int _MaxCols, int _MaxTerms);
        SparseMatrix Transpose1();
        SparseMatrix Transpose2();

        void showMatrix();
        void showMatrixList();

    private:
        int Rows, Cols, Terms;
        MatrixTerm smArray[MaxTerms];
};

#endif // SPARSEMATRIX_H
