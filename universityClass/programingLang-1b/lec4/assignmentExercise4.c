#include <stdio.h>

int main() {
    int x1 = 5, x2, x3;
    x1--;
    x2 = -x1--;
    x3 = ++x2;
    printf("x1 = %3d, ", x1);
    printf("x2 = %3d, ", x2);
    printf("x3 = %3d\n", x3);
    return 0;
}
