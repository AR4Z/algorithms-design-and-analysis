#include <stdio.h>

int mcd(int x, int y, int mtz[][y])
{
    //printf("%d, %d\n", x, y);
    if (mtz[x][y] == -1)
    {
        if (!y)
        {
            mtz[x][y] = x;
        }
        else
        {
            mtz[y][x % y] = mcd(y, x % y, mtz);
            mtz[x][y] = mtz[y][x % y];
        }
    }
    return mtz[x][y];
}

//void m

void showMtz(int m, int n, int mtz[][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", mtz[i][j]);
        }
        printf("\n");
    }
}

void prepareMtz(int f, int c, int mtz[][c])
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            mtz[i][j] = -1;
        }
    }
}

int main()
{
    int mtz[61][61];
    prepareMtz(61, 61, mtz);
    printf("%d\n", mcd(36, 60, mtz));
    //showMtz(61, 61, mtz);
}