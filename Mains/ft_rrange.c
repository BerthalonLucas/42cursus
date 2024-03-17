#include <stdio.h>
#include <stdlib.h>
#include <libft.h>
int *ft_rrange(int start, int end)
{
	int i = 0;
	int *y;
	long debut = start;
	long fin = end;

	while (debut != fin)
	{
		if (debut > fin)
			debut--;
		else
			debut++;
		i++;
	}
	if (i == 0)
		i = 1;
	y = malloc (sizeof(int) * i);
	if (!y)
		return (0);
	debut = start;
	while (i >= 0)
	{
		y[i] = (int)debut;
		if (fin > debut)
			debut++;
		else
			debut--;
		i--;
	}
	return (y);
}

int main(void)
{
	int i = 11;
	int y = 0;
	int *z;

	z = ft_rrange(0, 10);
	while (i != 0)
	{
		ft_printf("truc");
		y++;
		i--;
	}
	free(z);
}