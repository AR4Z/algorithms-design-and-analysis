#include <stdio.h>

int max(int min, int *vec) {
    int max = -1;
    for (int i = 0; i < 6; i++) {
        if (vec[i] <= min && vec[i] > max) {
            max = vec[i];
        }
    }
    return max;
}

void cambio(int total) {
    int res = total;
    int coins[] = { 1, 2, 5, 10, 20, 50 };
    int coin = 0;
    
    while(res >= 1) {
        int max_selected = max(res, coins);
        if( max_selected > 0) {
            printf("Moneda de %d\n", max_selected);
            res -= max_selected;
        } else {
            printf("No hay solución");
            return;
        }
    }
}

void main() {
    printf("Cambio de 36:\n");
    cambio(36);
}
