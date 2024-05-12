// 整数を入力して正負を出力 → 繰り返し

#include <stdio.h>

int main(void) {
    int a;
    char* result = "";
    do {
        int num;
        printf("Please input int num.\n");
        scanf("%d", &num);
        if (num > 0)
            result = "plus";
        else if (num < 0)
            result = "minus";
        else
            result = "zero";
        printf("%d is %s\n", num, result);
        puts("Input 0, if you wanna do it again.\n");
        scanf("%d", &a);
    } while(a == 0);
    return 0;
}
