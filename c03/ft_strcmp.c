
#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i]) && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
		return (s1[i] - s2[i]);
}
/*
int main(void)
{
	char	s1[] = "yyyyyhy";
	char	s2[] = "yyyyyy";
	int result;

	result = strcmp(s1, s2);
	printf("%d\n", ft_strcmp(s1, s2));
	printf("%d\n", result);
}
*/
