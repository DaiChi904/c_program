#include <stdio.h>
int main () {
    int x, y = 0;
    printf("In the first loop: \n");
    for (x = 0; x < 3; x++) {
        y += x;
        printf("(x,y) = (%d,%d)\n", x, y);
    }
    printf("In the second loop: \n");
    for (x = 3; x <= 5; x++) {
        if (x % 2 == 1) {
            y += x;
        }
        printf("(x,y) = (%d,%d)\n", x, y);
    }
    return 0;
}
