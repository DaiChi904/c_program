// 1からnまでの和を計算して表示

#include <stdio.h>

int main(void) {
    int lim, result = 0;
    printf("Please input limit:");
    scanf("%d", &lim);
    for (int i = 1; i <= lim; i++) {
        result += i;
    }
    printf("Sum is %d.", result);
}
