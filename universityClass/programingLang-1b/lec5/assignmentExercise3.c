#include <stdio.h>
int main () {
    int x = 3, y = -1, z = -1;

    switch (x) {
        case 1:
            y = x;
            break;
        case 3:
            y = x;
            x += 2;
        case 5:
        default:
            y = x;
            x += 2;
            break;
            z = x;
    }
    printf("x = %d, ", x);
    printf("y = %d, ", y);
    printf("z = %d\n", z);

    return 0;
}
