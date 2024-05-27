#include <stdio.h>
int main () {
    int x = 1, y = 0;
    while (x <= 16) {
        y += x;
        x *= 2;
        printf("(x,y) = (%d,%d)\n", x, y);
    }
    return 0;
}
