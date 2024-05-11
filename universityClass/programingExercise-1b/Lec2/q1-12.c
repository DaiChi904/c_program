// 整数値を3つ入力し、総和を出力

#include <stdio.h>

int main(void) {
    int num1, num2, num3;
    printf("整数値を3つ順位入力してください。");
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("3つの総和は%d", num1 + num2 + num3);
    return 0;
}
