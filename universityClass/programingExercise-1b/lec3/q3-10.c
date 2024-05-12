// 整数を2つ入力し、条件演算子を用いて最小値を出力

#include <stdio.h>

int main(void) {
    int num1, num2;
    puts("Please input two int nums.");
    scanf("%d %d", &num1, &num2);
    printf("Minimum number is %d", (num1 < num2) ? num1 : num2);
    return 0;
}
