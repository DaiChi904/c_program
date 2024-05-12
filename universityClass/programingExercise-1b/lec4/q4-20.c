// 正整数を入力して、全ての約数およびその個数を表示

#include <stdio.h>

int main(void) {
    int num, cnt=0;
    printf("Input positive integer : "); scanf("%d", &num);
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d\n", i);
            cnt++;
        }
    }
    printf("cnt:%d\n", cnt);
    return 0;
}
