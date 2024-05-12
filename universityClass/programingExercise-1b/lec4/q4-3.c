// 自然数を入力して0までカウントダウン表示

#include <stdio.h>

int main(void) {
    int num;
    puts("Please input natural number.:");
    scanf("%d", &num);
    if (num > 0)
        while (num >= 0) {
            printf("%d\n", num);
            num--;
        }
    else 
        puts("Your input is invalid.");
    return 0;
}
