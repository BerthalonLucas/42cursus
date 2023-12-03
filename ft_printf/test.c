#include <stdio.h>
#include <unistd.h>



int P_hexa_lower(unsigned long long i, char *base)
{
	int n;

	n = 0;
	if (i > 16)
	{
		P_hexa_lower(i / 16, base);
		n = i % 16;
		write(1, &*base + n, 1);
	}
	return (0);
}

int main(void)
{
	char *base;
	int i = 1;

	base = "0123456789abcdef";
	printf("%p\n", &i);
	P_hexa_lower(&i, base);
	return (0);
}
