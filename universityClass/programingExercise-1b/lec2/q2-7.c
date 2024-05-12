// 半径を入力し、円の面積を求めて出力

#include <stdio.h>
#include <math.h>

int main(void) {
    double radius;
    puts("Please input radius in real number.");
    scanf("%lf", &radius);
    double area = pow(radius,2) * M_PI;
    printf("The area of circle with %f radius is %f", radius, area);
    return 0;
}
