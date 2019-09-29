#include <stdio.h>

int cuantasVecesEsta(char cadena[], int n, char subCadena[], int m) {
    int x, j, cuantas, coincidencias = 0;

    for (int i = 0; i < n; i++) {
        x = i;
        j = 0, coincidencias = 0;

        while(j < m && x < n && cadena[x] == subCadena[j]) {
            coincidencias++;
            x++;
            j++;
        }

        if (coincidencias == m) {
            cuantas++;
        }
    }
    return cuantas;  
}

int main() {
    char cadena[16] = "LA RISA PISA";
    char subCadena[3] = "ISA";

    printf("%d", cuantasVecesEsta(cadena, 12, subCadena, 3));
}