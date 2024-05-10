// 整数3つを入力して最小値を出力

#include <stdio.h>

int main(void)  {

    int a, b, c, min;

    printf("a :");  scanf("%d", &a);
    printf("b :");  scanf("%d", &b);
    printf("c :");  scanf("%d", &c);
    min = a;  if (min > b)  min = b;  if (min > c) min = c;

    printf("min=%d\n", min);

    return 0;
}
