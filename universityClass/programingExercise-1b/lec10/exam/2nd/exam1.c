#include <stdio.h>

// ビット長を求める関数
int cnt_bits(unsigned z)
{
    int bits = 0;
    while (z != 0)
    {
        bits++;
        z >>= 1;
    }
    return bits;
}

int main(void)
{
    unsigned a = 555, b = 37;
    int x = cnt_bits(a);
    for (int i = x - 1; i >= 0; i--)
    {
        putchar(((a >> i) & 1U) ? '1' : '0');
    };
    printf("\naを2ビット右シフト = %u\n", a >> 2); // aを2ビット右シフト
    printf("aを2ビット左シフト = %u\n", a << 2);   // aを2ビット左シフト
    printf("octal a+b = 0%o,\nhex a+b = 0x%x\n", a + b, a + b);
    return 0;
}
