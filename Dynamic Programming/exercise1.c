#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    bool fromDia;
    bool fromIzq;
    bool fromArr;
    int cont;
} Paso;

void levenshtein(char str1[], int len_str_1, char str2[], int len_str_2, Paso mtz[][len_str_1])
{
    Paso p;
    for (int i = 0; i < len_str_1; i++)
    {
        p.cont = i;
        mtz[0][i] = p;
    }

    for (int i = 1; i < len_str_2; i++)
    {
        p.cont = i;
        mtz[i][0] = p;
    }

    for (int f = 1; f < len_str_2; f++)
    {
        for (int c = 1; c < len_str_1; c++)
        {
            bool menorIzq = mtz[f][c - 1].cont <= mtz[f - 1][c - 1].cont && mtz[f][c - 1].cont <= mtz[f - 1][c].cont;
            bool menorDia = mtz[f - 1][c - 1].cont <= mtz[f][c - 1].cont && mtz[f - 1][c - 1].cont <= mtz[f - 1][c].cont;
            bool menorArr = mtz[f - 1][c].cont <= mtz[f - 1][c - 1].cont && mtz[f - 1][c].cont <= mtz[f][c - 1].cont;
            Paso paso;
            paso.fromDia = false;
            paso.fromIzq = false;
            paso.fromArr = false;
            if (menorDia)
            {
                printf("menorDia %d,%d\n", f, c);
                paso.fromDia = true;
                paso.cont = mtz[f - 1][c - 1].cont;

                if (str1[c - 1] != str2[f - 1])
                {
                    paso.cont++;
                }
            }
            else if (menorIzq)
            {
                printf("menorIzq %d,%d\n", f, c);
                paso.fromIzq = true;
                paso.cont = mtz[f][c - 1].cont + 1;
            }
            else
            {
                printf("menorArr %d,%d\n", f, c);
                paso.fromArr = true;
                paso.cont = mtz[f - 1][c].cont + 1;
            }
            mtz[f][c] = paso;
        }
    }
}

void showMtz(int m, int n, Paso mtz[][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", mtz[i][j].cont);
        }
        printf("\n");
    }
}

void solutionForHumans(char str1[], int len_str_1, char str2[], int len_str_2, Paso mtz[][len_str_1])
{
    int f = len_str_2 - 1;
    int c = len_str_1 - 1;
    int totalCambios = mtz[f][c].cont;

    while (totalCambios >= 1)
    {
        //printf("coordenada: %d, %d\n", f, c);
        if (mtz[f][c].fromDia)
        {
            if (str1[c - 1] != str2[f - 1])
            {
                printf("Cambia %c por %c\n", str1[c - 1], str2[f - 1]);
                totalCambios--;
            }
            f--;
            c--;
        }
        else if (mtz[f][c].fromIzq)
        {
            printf("elimine %c\n", str1[c - 1]);
            totalCambios--;
            c--;
        }
        else if(mtz[f][c].fromArr)
        {
            printf("agregue %c\n", str2[f - 1]);
            totalCambios--;
            f--;
        }
        
    }
}


int main()
{
    char str1[] = "casa";
    char str2[] = "calle";
    Paso mtz[6][5];
    levenshtein(str1, 5, str2, 6, mtz);
    showMtz(6, 5, mtz);
    solutionForHumans(str1, 5, str2, 6, mtz);
}