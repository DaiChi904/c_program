// 整数値を入力し、+7, -7, *7, /7, %7を出力

#include <stdio.h>

int main(void) {
    int num;

    printf("Please input int number.");
    scanf("%d", &num);
    printf("%d + 7 = %d\n", num, num + 7);
    printf("%d - 7 = %d\n", num, num - 7);
    printf("%d * 7 = %d\n", num, num * 7);
    printf("%d / 7 = %d\n", num, num / 7);
    printf("%d %% 7 = %d\n", num, num % 7);
    return 0;
}
