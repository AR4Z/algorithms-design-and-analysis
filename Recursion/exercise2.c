#include <stdio.h>

int cuantasEsta(int vec[], int n, int i,  int num) {
    if(i < n) {
        if(vec[i] == num) {
            return 1 + cuantasEsta(vec, n, i+1, num);
        } else {
            return 0 + cuantasEsta(vec, n, i+1, num);
        }
    }  
} 

void masRepetido(int vec[], int n, int veces, int *repetido, int i) {
    if(i < n) {
        int cuantas = cuantasEsta(vec, n, i, vec[i]);
        if(cuantas > veces) {
            veces = cuantas;
            *repetido = vec[i];
        }
        masRepetido(vec, n, veces, repetido, i+1);
    }
}

int main() {
    int vec [21] = {1, 1, 2, 2, 4, 9, 1, 9, 0, 9, 12, 34, 9, 6, 7, 7, 7, 8, 7, 6, 7};
    int repetido = 0;
    masRepetido(vec, 21, 0, &repetido, 0);
    printf("%d", repetido);
}