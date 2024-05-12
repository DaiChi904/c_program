// 正整数を入力して、それ以下の正奇数を全て表示

#include <stdio.h>

int main(void) {
    int num;
    printf("Input positive integer : ");
    scanf("%d", &num);
    for ( int i = 1; i <= num ; i++ ) {
        if (i % 2 != 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}
