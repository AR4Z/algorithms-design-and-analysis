#include <stdio.h>

int mcd(int x, int y) {
    if (!y) {
        return x;
    } else {
        return mcd(y, x % y);
    }
}

void main() {
    printf("%d", mcd(5, 7));
}