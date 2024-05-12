// 正整数を入力して1から入力値までカウントアップ表示

#include <stdio.h>

int main(void) {
    int num, cnt = 0;
    puts("Please input natural number.:");
    scanf("%d", &num);
    if (num > 0)
        while (cnt <= num) {
            printf("%d\n", cnt);
            cnt++;
        }
    else 
        puts("Your input is invalid.");
    return 0;
}
