#include <stdio.h>

// long	ft_atol(char *str)
// {
// 	int		i;
// 	long	sign;
// 	long	res;

// 	if (!str)
// 		return (0);
// 	i = 0;
// 	sign = 1;
// 	res = 0;
// 	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r'
// 		|| str[i] == '\f' || str[i] == ' ')
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		res = res * 10 + str[i] - 48;
// 		i++;
// 	}
// 	return (res * sign);
// }


// int parsing(int ac, char **av)
// {
// 	if (ac == 1)
// 		return (0);
	
	
// }

int main(int ac, char **av)
{
	int i = 0;

	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	printf("%d\n", ac);
	return (0);
}