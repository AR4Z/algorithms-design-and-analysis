#include <stdio.h>

int ceroi(int i, int f, int vec[]) {
    if (i < f) {
        int medio = (i+f)/2;
        if(!vec[medio]) {
            if (vec[medio-1]) {
                return medio;
            } else {
                return ceroi(i, medio-1, vec);
            }
        } else {
            if(!vec[medio+1]) {
                return medio+1;
            } else {
                return ceroi(medio+1, f, vec);
            }
        }
    }
    return -1;
}

void main() {
    int vec[] = {1, 1, 1, 1, 1};
    printf("%d", ceroi(0, 4, vec));
}