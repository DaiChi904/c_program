// 整数を入力して絶対値を出力

#include <stdio.h>

int main(void) {
    int num, absNum;
    puts("Please input int num");
    scanf("%d", &num);
    if (num < 0)
        absNum = -num;
    else
        absNum = num;
    printf("|%d| = %d", num, absNum);
    return 0;
}
