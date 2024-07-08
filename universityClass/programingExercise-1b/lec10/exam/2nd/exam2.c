#include <stdio.h>

int main(void)
{
    unsigned a = 555, b = 37;
    int x = 0;
    int z = a;
    while (z != 0)
    {
        x++;
        z >>= 1;
    }
    for (int i = x - 1; i >= 0; i--)
    {
        putchar(((a >> i) & 1U) ? '1' : '0');
    };
    printf("\naを2ビット右シフト = %u\n", a >> 2); // aを2ビット右シフト
    printf("aを2ビット左シフト = %u\n", a << 2);   // aを2ビット左シフト
    printf("octal a+b = 0%o,\nhex a+b = 0x%x\n", a + b, a + b);
    return 0;
}
