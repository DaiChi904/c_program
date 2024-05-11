// 実数を入力し、2倍の値を出力

#include <stdio.h>

int main(void) {
    double num;
    puts("Please input real number.");
    scanf("%lf", &num);
    printf("two times of %f is %f", num, num*2);
    return 0;
}
