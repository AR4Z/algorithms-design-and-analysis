#include <stdio.h>
#include <stdbool.h>

bool esta(int num, int vec[], int m) {
    return m > 0 && (vec[m - 1] == num || esta(num, vec, m-1));
}

bool estaContenido(int vec[], int n, int subVec[], int m, int i, int j) {
    if(i < n) {
        if(esta(vec[i], subVec, m)) {
            return vec[i] == subVec[j] && estaContenido(vec, n, subVec, m, i+1, j+1);
        } else {
            return true && estaContenido(vec, n, subVec, m, i+1, j);
        }
    } else {
        if (j < m) {
            return false;
        }
    }
    return true;
}


int main() {
    int subVec[4] = {21, 30, 11, 64};
    int vec[8] = {10, 21, 2, 18, 30, 11, 9, 50};

    if(estaContenido(vec, 8, subVec, 4, 0, 0)) {
        printf("esta");
    } else {
        printf("no esta");
    }
}


