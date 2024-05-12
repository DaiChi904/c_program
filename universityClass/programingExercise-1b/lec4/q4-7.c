// 正整数を入力して1から入力値まで2のべき乗をカウントアップ表示

#include <stdio.h>

int main(void) {
    int num, cnt = 0;
    printf("Please input natural number.:");
    scanf("%d", &num);
    if (num > 0) {
        while (cnt <= num) {
            if ((cnt & (cnt - 1)) == 0 && !(cnt == 0)) {
                printf("%d\n", cnt);
                cnt++;
            } else {
                cnt++;
            }
        }
    } else {
        puts("Your input is invalid.");
    } 
    return 0;
}
