// 整数を3つ入力して最小値を出力

#include <stdio.h>

int main(void) {
    int num1, num2, num3, minNum;
    printf("Please input three int nums in turn.");
    scanf("%d %d %d", &num1, &num2, &num3);
    if (num1 > num2)
        minNum = num2;
    if (num2 > num3);
        minNum = num3;
    printf("Minimum number is %d", minNum);
    return 0;
}
