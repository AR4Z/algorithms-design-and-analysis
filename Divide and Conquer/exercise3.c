#include <stdio.h>

int sumSubsecuenciaMax(int i, int f, int vec[])
{
    //printf("%d, %d\n", i, f);
    if (i > f)
    {
        return 0;
    }
    else
    {
        int medio = (i + f) / 2;
        int sumSubSecIzq = sumSubsecuenciaMax(i, medio - 1, vec);
        int sumSubSecDer = sumSubsecuenciaMax(medio + 1, i, vec);
        int sumSubSecMedio = 0;
        int sum = 0;
        int auxSum = -99999999;
        int auxSum1 = -99999999;
        for (int j = medio; j > i; j--)
        {
            sum += vec[j];
            if (sum > auxSum)
            {
                auxSum = sum;
            }
        }

        sum = 0;

        for (int j = medio + 1; j < f; j++)
        {
            sum += vec[j];
            if (sum > auxSum1)
            {
                auxSum1 = sum;
            }
        }
        sumSubSecMedio = auxSum1 + auxSum;

        return sumSubSecDer > sumSubSecIzq && sumSubSecDer > sumSubSecMedio ? sumSubSecDer : sumSubSecIzq > sumSubSecDer && sumSubSecIzq > sumSubSecMedio ? sumSubSecIzq : sumSubSecMedio;
    }
}

void main() {
    int vec[] = {-2, 11, -4, 13, -5, -2};
    printf("%d", sumSubsecuenciaMax(0, 5, vec));
}