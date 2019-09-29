#include <stdio.h>

int eliminaRepetidos(int vec[], int *n)
{
    int x = 0;
    for (int i = 0; i < *n; i++)
    {
        if (x == 0 || vec[x - 1] != vec[i])
        {
            vec[x++] = vec[i];
        }
    }
    *n = x;
}

int main()
{
    int vec[8] = {123, 84, 84, 62, 42, 42, 42, 12};
    int size = 8;

    eliminaRepetidos(vec, &size);

    for (int i = 0; i < size; i++)
    {
        printf("%4d", vec[i]);
    }
}