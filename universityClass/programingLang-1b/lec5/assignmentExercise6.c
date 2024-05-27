#include <stdio.h>
int main () {
    int i, j, y = 0;
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 2; j++) {
            y += (i + j);
            printf("(i,j,y) = (%d,%d,%d)\n", i, j, y);
        }
    }
    return 0;
}
