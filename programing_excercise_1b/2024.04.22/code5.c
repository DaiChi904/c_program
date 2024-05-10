#include <stdio.h>

int main(void)
{
	int anda = 262, dasuu = 704;
    anda = anda*10000;
    dasuu = dasuu*10000;
    int hitRate = (anda/dasuu);

	printf("イチローの2004年の打率：.%d\n", &hitRate);

	return 0;
}
