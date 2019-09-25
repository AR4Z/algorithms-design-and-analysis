#include <stdio.h>

void matrixProductRecursiveless(int rowsA, int colsA, int A[][colsA], int rowsB, int colsB, int B[][colsB], int C[][colsB]) {
    for(int row = 0; row < rowsA; row++) {
        for(int col = 0; col < colsB; col++) {
            int result = 0;
            for(int row2 = 0; row2 < rowsB; row2++) {
                result += A[row][row2] * B[row2][col];
            }
            C[row][col] = result;
        }
    }
}

void recursiveMatrixProduct(int rowsA, int colsA, int A[][colsA], int rowsB, int colsB, int B[][colsB], int C[][colsB], int j, int k, int l, int aux) {
    if(j < rowsA) {
        if(k < colsB) {
            if(l < rowsB) {
                aux += A[j][l] * B[l][k];
                recursiveMatrixProduct(rowsA, colsA, A, rowsB, colsB, B, C, j, k, l+1, aux);
            } else {
                C[j][k] = aux;
                recursiveMatrixProduct(rowsA, colsA, A, rowsB, colsB, B, C, j, k+1, 0, 0);
            }
        } else {
            recursiveMatrixProduct(rowsA, colsA, A, rowsB, colsB, B, C, j+1, 0, 0, 0);
        }
    }
}

void printMatrix(int rows, int cols, int mtx[][cols]) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%4d", mtx[i][j]);
        }
        printf("\n");
        
    }
}

void main() {
    int mtz [][3] = {{1, 2, 3},{4, 5, 6}};
    int mtz2 [][2] = {{5, -1}, {1, 0}, {-2, 3}};
    int product [2][2];
    recursiveMatrixProduct(2, 3, mtz, 3, 2, mtz2, product, 0, 0, 0, 0);
    printMatrix(2, 2, product);
}