// f(x,y) = x^2 + 3xy + 2y^2 + 1を計算して出力

#include <stdio.h>

int main(void) {
    int x, y;
    printf("f(x,y) = x^2 + 3xy + 2y^2 + 1を計算を計算します。\nx, yの値を順に入力してください。");
    scanf("%d %d", &x, &y);
    int ans = x^2 + 3*x*y + 2*y^2 + 1;
    printf("f(%d,%d) = %d", x, y, ans);
}
