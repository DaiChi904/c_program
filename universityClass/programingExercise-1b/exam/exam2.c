#include <stdio.h>

int main(void) {
    int x, y, fxy = 1, i;
    puts("Please input x, y");
    scanf("%d %d", &x, &y);

    for (i = 0; i <=x; i++) {
        if (i == 1) {
            fxy %= y;
        } else {
            fxy = (i * i * fxy) % y;
        }
    }
    printf("%d", fxy);
    return 0;
}

