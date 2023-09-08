/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:41:23 by lberthal          #+#    #+#             */
/*   Updated: 2023/09/06 17:45:46 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_count(char *to_find);
int ft_lengh(char	*str,char	*to_find);
int ft_strcmp(char *str, char *to_find, int i);
char *ft_strstr(char *str, char *to_find);

int ft_count(char *to_find)
{
	int cb;

	cb = 0;
	while (to_find[cb])
	{
		cb++;
	}
	return (cb);
}
int ft_lengh(char	*str,char	*to_find)
{
	int c;

	c = 0;
	while (str[c] == to_find[c])
	{
		c++;
	}
	if (ft_count(to_find) == c)
		return (1);
	else
		return (0);
}

int ft_strcmp(char *str, char *to_find, int i)
{
	if (str[i] == to_find[i])
		return (1);
	else
		return (0);
}
char *ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (str[i]) /* on balaye str aec une boucle en commançant caractère zéro */
	{
		if (str[i] == to_find[0]) /* à chaque caractère on regarde si il correspond au premier caractère de la chaine à chercher */
		{
			/* si oui on commence une sous boucle pour balayer les deux chaines en // */
			j = 0; /* un compteur pour lire la chaine to_find */
			k = i; /* un autre compteur pour balayer la chaine str depuis la position i à laquelle on a trouve la correspondance */
			while (str[k] == to_find[j] && to_find[j] && str[k]) /* tant que la correspondance est vraie et que on est pas au bout de to_find et que on est pas au bout de str */
 			{
				j++; /* on avance le compteur de to_find */
				k++; /* on avance le compteur de str */
			}
			
			if (to_find[j] = 0) { return(*str[i]); } /* si on est sorti de la boucle parce qu'on est arrivé au bout de to_find et que les correspondance ont toute été satisfaite du coup on renvoit le pointeur sur la position i pour str */

			if (str[k] == 0) 
			{
				return (0);
			}/* si on est sorti car on a finit str on renvoit zéro */

			if (to_find[j] != 0) {break;}/* on est sorti car on a fini la correspondance sans avoir totale égalité des caractères , on sort de la boucle et on prend le caractère str suivant */

		}
		i++; /* on se place sur le caractère suivant */
	}
	return (0);
}

int	main(void)
{
	char	str[] = "vas me chercher ton slip et met la table";
	char	to_find[] = "slip";

	printf("ma fonction = %s\n", ft_strstr(str, to_find));
	printf("fonction de base = %s\n",  strstr(str, to_find));
}
