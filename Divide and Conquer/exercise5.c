#include <stdio.h>

int sqrrt(int n, int i, int f) {
    if(i < f) {
        int mid = (i+f)/2;
        int square = mid*mid;
        if (square == n) {
            return mid;
        } else {
            if (mid < n/mid) {
                return sqrrt(n, mid+1, f);
            } else {
                return sqrrt(n, i, mid-1);
            }
        }
    }
}

void main() {
    printf("%d", sqrrt(4, 0, 2));
}