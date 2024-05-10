// 整数値2つを入力し、乗算結果を出力

#include <stdio.h>

int main(void) {
    int num1, num2;
    printf("整数を2つ入力してください。");
    scanf("%d %d", &num1, &num2);
    printf("%d*%dは%d", num1, num2, num1*num2);
    return 0;
}
