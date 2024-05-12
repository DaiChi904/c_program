// 整数を入力して偶数か奇数かを出力

#include <stdio.h>

int main(void) {
    int num;
    printf("Please input int number.");
    scanf("%d", &num);
    if (num % 2 == 0)
        printf("%d is even.", num);
    else 
        printf("%d is odd.", num);
        return 0;
}
