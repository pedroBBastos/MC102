#include <stdio.h>

int mult(int a, int b)
{
	if(b == 1)
		return a;

	return a +  mult(a, b-1);
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("mult -> %d\n", mult(a, b));
}
