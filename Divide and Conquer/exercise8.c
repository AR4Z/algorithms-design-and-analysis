#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 32
typedef int Matriz[MAX][MAX];

int minMtz(int x1, int y1, int x2, int y2,  Matriz mtz)
{
    if (x1 == x2 && y1 == y2)
    {
        return mtz[x1][y1];
    }
    else
    {
        if (x1 <= x2 && y1 <= y2) {
            int mx = (x1 + x2) / 2;
            int my = (y1 + y2) / 2;
            int min1 = minMtz( x1, y1, mx, my, mtz);
            int min2 = minMtz( mx + 1, y1, x2, my, mtz);
            int min3 = minMtz( x1, my + 1, mx, y2, mtz);
            int min4 = minMtz( mx + 1, my + 1, x2, y2, mtz);
            printf("(%d, %d, %d, %d)\n", min1, min2, min3, min4);
            return min1 <= min2 && min1 <= min3 && min1 <= min4 ? min1 : min2 <= min1 && min2 <= min3 && min2 <= min4 ? min2 : min3 <= min1 && min3 <= min2 && min3 <= min4 ? min3 : min4;
        }
    }
}

void mostrarMatriz(int m, int n, Matriz mtz)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", mtz[i][j]);
        }
        printf("\n");
    }
}

void llenarMatriz(int m, int n, Matriz mtz)
{
    srand(time(NULL));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mtz[i][j] = (rand() % 20) + 1;
        }
    }
}

void main()
{
    Matriz mtz;
    llenarMatriz(5, 6, mtz);
    mostrarMatriz(5, 6, mtz);
    printf("%d", minMtz(0, 0, 4, 5, mtz));
}
