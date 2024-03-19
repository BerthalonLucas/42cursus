#include <stdio.h>

int ft_strlen(const char *s)
{
	int i = -1;

	while (s[++i]);
	return (i);
}

int	ft_is_digit(const char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	if (*s == '-')
		i++;
	while (i++, s[i] >= '0' && s[i] <= '9');
	if (ft_strlen(s) != i)
		return (0);
	return (1);
}

int main (void)
{
	char *s;
	char *s1;

	s = "trucbidule";
	s1 = "123";

	if (ft_is_digit(s))
		printf("oui [1]\n");
	if (!ft_is_digit(s))
		printf("non [1]\n");
	if (ft_is_digit(s1))
		printf("oui [2]\n");
	if (!ft_is_digit(s1))
		printf("non [2]\n");
	// printf("%d\n", ft_is_digit(s));
	// printf("%d\n", ft_is_digit(s1));
	return (0);

}