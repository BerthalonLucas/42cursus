
#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		i++;
	}
	while (s2[j])
	{
		j++;
	}
	if (i < j)
		return (-i);
	else if (i == j)
		return (0);
	else
		return (j);
}

int main(void)
{
	char	src[] = "salut a tous c'est jean";
	char	dest[] = "yo les petits potes";
	int result;

	result = strcmp(src, dest);
	printf("%d\n", ft_strcmp(src, dest));
	printf("%d\n", result);
}

