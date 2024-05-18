#include <stdio.h>
int main() {
    int x = 8;
    double y1, y2, y3, y4, y5, y6;
    y1 = x / 3;
    y2 = 20 / x;
    y3 = (double)x / 3;
    y4 = (double)(x / 3);
    y5 = x + 3.0;
    y6 = x / 3.0;
    printf("y1 = %6.3f, ", y1);
    printf("y2 = %6.3f, ", y2);
    printf("y3 = %6.3f, ", y3);
    printf("y4 = %6.3f, ", y4);
    printf("y5 = %6.3f, ", y5);
    printf("y6 = %6.3f\n", y6);
    return 0;
}
