// 整数を入力して符号(+ or – or 0)を出力

#include <stdio.h>

int main(void) {
    int num;
    puts("Please input int num.");
    scanf("%d", &num);
    if (num == 0)
        puts("Your input is ");
    else if (num > 0)
        puts("Your input is plus");
    else 
        puts("Your input is minus");
    return 0;
}
