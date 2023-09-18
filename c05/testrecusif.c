#include <unistd.h>

int ft_testrecurcif(int *tab)
{
	int i;

	i = 0;
	if (!tab[i])
		return (0);
	write (1, &tab[i], 1);
	return (ft_testrecurcif(tab + 1));
}

int main(void)
{
	int tab[] = {1, 2, 4, 7, 5, 5, 3};

	ft_testrecurcif(tab);
	write (1, "\n", 1);
}
