// 101以上111以下の奇数を入力し、素数かどうか出力(swich文)

#include <stdio.h>

int main(void) {
    int num;
    printf("num :");
    scanf("%d", &num);
    switch (num) {
        case 101 : puts("prime number"); break;
        case 103 : puts("prime number"); break;
        case 105 : puts("not prime number"); break;
        case 107 : puts("prime number"); break;
        case 109 : puts("prime number"); break;
        case 111 : puts("not prime number"); break;
        default : puts("invalid number!"); break;
    }
    return 0;
}