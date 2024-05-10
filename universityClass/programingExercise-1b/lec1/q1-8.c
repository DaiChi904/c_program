 // 整数値を入力し、13を足して出力

#include <stdio.h>

int main(void) {
    int num;
    printf("整数を入力してください。");
    scanf("%d", &num);
    printf("%dに13を加えると%dです", num, num + 13);
    return 0;
}
