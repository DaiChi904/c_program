// 正整数を入力して、2つの正整数に因数分解できる組を全て表示

#include <stdio.h>

int main(void) {
    int num;
    printf("Input positive integer : ");
    scanf("%d", &num);
    for (int i = 1; i*i <= num; i++) {
        if (i*i > num) break;
        if (num%i != 0) continue;
        printf("%d * %d\n", i, num/i);
    }
    return 0;
}
