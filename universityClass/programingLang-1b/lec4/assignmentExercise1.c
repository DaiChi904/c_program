#include <stdio.h>
int main() {
    int x = 3, y1, y2, y3, y4;
    y1 = x * 3;
    y2 = 10 * (x + 2) / 8;
    y3 = 10 / 8 * (x + 2);
    y4 = 10 * (x + 2) % 8;
    printf("y1 = %d\n", y1);
    printf("y2 = %d\n", y2);
    printf("y3 = %d\n", y3);
    printf("y4 = %d\n", y4);
    return 0;
}
