// 整数値を入力し、5で割った商とあまりを表示

#include <stdio.h>

int main(void) {
    int num;
    puts("Please input int num.");
    scanf("%d", &num);
    printf("%d / 5 = %d ... %d", num, num / 5, num % 5);
    return 0;
}
