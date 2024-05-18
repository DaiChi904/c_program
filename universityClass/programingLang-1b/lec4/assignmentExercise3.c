#include <stdio.h>

int main() {
    int x = 8;
    double y1, y2, y3, y4, y5, y6;
    x /= 3;
    y1 = x;
    y1 += 5;
    y2 = y1;
    y2 *= 5;
    y3 = y1;
    y3 = x;
    y4 = y1;
    y4 /= 5;
    y5 = y1;
    y5 *= x;
    y6 = y1;
    y6 /= x;
    printf("y1 = %6.3f, ", y1);
    printf("y2 = %6.3f, ", y2);
    printf("y3 = %6.3f, ", y3);
    printf("y4 = %6.3f, ", y4);
    printf("y5 = %6.3f, ", y5);
    printf("y6 = %6.3f\n", y6);
    return 0;
}
