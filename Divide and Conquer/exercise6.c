#include <stdio.h>
typedef struct {
    int l;
    int h;
    int r;
} Building;

typedef struct {
    int x;
    int y;
} Coordenada;


void skyLineB(Building b, Coordenada vec[]) {
    Coordenada c1 = {b.l, b.h};
    Coordenada c2 = {b.r, 0};
}

Coordenada mergeSkyLine(Coordenada b1, Coordenada b2, int lastH) {
    Coordenada m;

    if(b1.x == b2.x) {
        m.x = b1.x;
        m.y = b1.y > b2.y ? b1.y: b2.y;
    } else {
        if(b1.x > b2.x) {
            m.x = b2.x;
            m.y = lastH < b2.y ? b2.y : lastH; 
        } else {
            m.x = b1.x;
            m.y = lastH < b1.y ? b1.y : lastH;
        }
    }

    return m;
}

void main() {
    Coordenada b1 = {3, 5};
    Coordenada b2 = {3, 3}; 
    Coordenada p = mergeSkyLine(b1, b2, 0);
    printf("%d, %d\n", p.x, p.y);
}