#include <stdio.h>

int searchI(int i, int f, int vec[]) {
    if (i <= f) {
        int current = (i+f)/2;
        if (vec[current] == current) {
            return current;
        } else {
            if (vec[current] > current) {
                return searchI(i, current - 1, vec);
            } else {
                return searchI(current + 1, f, vec);
            }
        }
    } else {
        return -1;
    }
}

void main() {
    int vec[] = {-4, -3, 0, 2, 4, 7, 8};
    int i = searchI(0, 6, vec);
    printf("%d", i);
}