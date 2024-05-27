#include <stdio.h>

int main () {
    int i, x = 0, y = 0;
    for (i = 0; i < 5; i++) {
        while (x % 5 == 0) {
            x++;
        }
        x += i;
        y += x;
    }
    printf("(i,x,y) = (%d,%d,%d)\n", i, x, y);
    return 0;
}
