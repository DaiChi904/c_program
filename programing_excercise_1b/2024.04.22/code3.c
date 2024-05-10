#include <stdio.h>

int main(void)
{
	int n;

	printf("Input :");  scanf("%d", &n);
	printf("%d + 7 = %d\n", n, n+7);
	printf("%d - 7 = %d\n", n, n-7);
	printf("%d * 7 = %d\n", n, n*7);
	printf("%d / 7 = %d\n", n, n/7);
	printf("%d %% 7 = %d\n", n, n%7);

	return 0;
}
