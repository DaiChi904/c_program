#include <stdio.h>

int main(void)
{
	int x, y;

	printf("x=");  scanf("%d", &x);
	printf("y=");  scanf("%d", &y);

	int fxy = x^2 + 3*x*y + 2*(y^2) + 1;

	printf("f(%d,%d)=%d \n", x, y, fxy);

	return 0;
}
