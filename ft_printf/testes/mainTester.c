/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainTester.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberthal <lberthal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:36:16 by daribeir          #+#    #+#             */
/*   Updated: 2023/12/18 12:05:26 by lberthal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int		len1;
	int		len2;
/*	char	*test = "44568";

	ft_printf("N%d was %s!\n", 43, "there");
	ft_printf("my: Format", "N43", "W4s", "Th3r3", "!");
	len1 = ft_printf((const char *)"N43 W4s Th3r3!\n%s %p\n", "mon pointeur:", test);
	len2 = printf("ptf pointeur: %p\n", test);
	printf("test p1 : %d -> %d\n", len1, len2);

*/	ft_printf("##########\n");
	ft_printf("# test c #\n");
	ft_printf("##########\n\n");
	
	len1 = ft_printf("myc1: %c %c %c \n", '0', 0, '1');
	len2 = printf("pfc1: %c %c %c \n", '0', 0, '1');
	printf("test c1 : %d -> %d\n", len1, len2);
	len1 = ft_printf("myc2:  %c %c %c \n", ' ', ' ', ' ');
	len2 = printf("pfc2:  %c %c %c \n", ' ', ' ', ' ');
	printf("test c2 : %d -> %d\n", len1, len2);
	len1 = ft_printf("myc3:  %c %c %c \n", '1', '2', '3');
	len2 = printf("pfc3:  %c %c %c \n", '1', '2', '3');
	printf("test c3 : %d -> %d\n", len1, len2);
	len1 = ft_printf("myc4:  %c %c %c \n", '2', '1', 0);
	len2 = printf("pfc4:  %c %c %c \n", '2', '1', 0);
	printf("test c4 : %d -> %d\n", len1, len2);
	len1 = ft_printf("myc5:  %c %c %c \n", 0, '1', '2');
	len2 = printf("pfc5:  %c %c %c \n", 0, '1', '2');
	printf("test c5 : %d -> %d\n\n", len1, len2);

	ft_printf("##########\n");
	ft_printf("# test s #\n");
	ft_printf("##########\n\n");

	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. Posuere \
	libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	len1 = ft_printf("mys1:  %s %s \n", " - ", "");
	len2 = printf("pfs1:  %s %s \n", " - ", "");
	printf("test s1 : %d -> %d\n", len1, len2);
	len1 = ft_printf("mys2:  %s %s %s %s %s\n", " - ", "", "4", "", s2);
	len2 = printf("pfs2:  %s %s %s %s %s\n", " - ", "", "4", "", s2);
	printf("test s2 : %d -> %d\n", len1, len2);
	len1 = ft_printf("mys3:  %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	len2 = printf("pfs3:  %s %s %s %s %s \n", " - ", "", "4", "", "2 ");
	printf("test s3 : %d -> %d\n", len1, len2);
	len1 = ft_printf("mys4: NULL %s NULL \n", NULL);
	len2 = printf("pfs4: NULL %s NULL \n", NULL);
	printf("test s4 : %d -> %d\n\n", len1, len2);
	//printf("test s4 : %d\n", len1);


	ft_printf("##########\n");
	ft_printf("# test p #\n");
	ft_printf("##########\n\n");

	len1 = ft_printf("myp1: %p \n", -1);
	len2 = printf("pfp1: %p \n", -1);
	printf("test p1 : %d -> %d\n", len1, len2);
	len1 = ft_printf("myp2: %p \n", 15);
	len2 = printf("pfp2: %p \n", 15);
	printf("test p2 : %d -> %d\n", len1, len2);
	len1 = ft_printf("myp3: %p \n", 16);
	len2 = printf("pfp3: %p \n", 16);
	printf("test p3 : %d -> %d\n", len1, len2);
	len1 = ft_printf("myp4: %p \n", 17);
	len2 = printf("pfp4: %p \n", 17);
	printf("test p4 : %d -> %d\n", len1, len2);
	len1 = ft_printf("myp5: %p %p \n", LONG_MIN, LONG_MAX);
	len2 = printf("pfp5: %p %p \n", LONG_MIN, LONG_MAX);
	printf("test p5 : %d -> %d\n", len1, len2);
	len1 = ft_printf("myp6: %p %p \n", LONG_MIN, LONG_MAX);
	len2 = printf("pfp6: %p %p \n", LONG_MIN, LONG_MAX);
	printf("test p6 : %d -> %d\n", len1, len2);
	len1 = ft_printf("myp7: %p %p \n", INT_MIN, INT_MAX);
	len2 = printf("pfp7: %p %p \n", INT_MIN, INT_MAX);
	printf("test p7 : %d -> %d\n", len1, len2);
	len1 = ft_printf("myp8: %p %p \n", ULONG_MAX, -ULONG_MAX);
	len2 = printf("pfp8: %p %p \n", ULONG_MAX, -ULONG_MAX);
	printf("test p8 : %d -> %d\n", len1, len2);
	len1 = ft_printf("myp9: %p %p \n", 0, 0);
	len2 = printf("pfp9: %p %p \n", 0, 0);
	printf("test p9 : %d -> %d\n\n", len1, len2);

	ft_printf("##########\n");
	ft_printf("# test d #\n");
	ft_printf("##########\n\n");
	
	len2 = printf("pfd5: %d \n", 10);
	len1 = ft_printf("myd5: %d \n", 10);
	printf("test d5 : %d -> %d\n\n", len1, len2);
	len2 = printf("pfd6: %d \n", 11);
	len1 = ft_printf("myd6: %d \n", 11);
	printf("test d6 : %d -> %d\n\n", len1, len2);
	len2 = printf("pfd7: %d \n", 15);
	len1 = ft_printf("myd7: %d \n", 15);
	printf("test d7 : %d -> %d\n\n", len1, len2);
	len2 = printf("pfd8: %d \n", 16);
	len1 = ft_printf("myd8: %d \n", 16);
	printf("test d8 : %d -> %d\n\n", len1, len2);
	len2 = printf("pfd9: %d \n", 17);
	len1 = ft_printf("myd9: %d \n", 17);
	printf("test d9 : %d -> %d\n\n", len1, len2);
	len2 = printf("pfd10: %d \n", 99);
	len1 = ft_printf("myd10: %d \n", 99);
	printf("test d10 : %d -> %d\n", len1, len2);
	len2 = printf("pfd11: %d \n", 100);
	len1 = ft_printf("myd11: %d \n", 100);
	printf("test d11 : %d -> %d\n\n", len1, len2);
	len2 = printf("pfd12: %d \n", 101);
	len1 = ft_printf("myd12: %d \n", 101);
	printf("test d12 : %d -> %d\n\n", len1, len2);
	len2 = printf("pfd13: %d \n", -10);
	len1 = ft_printf("myd13: %d \n", -10);
	printf("test d13 : %d -> %d\n\n", len1, len2);
	len2 = printf("pfd14: %d \n", -11);
	len1 = ft_printf("myd14: %d \n", -11);
	printf("test d14 : %d -> %d\n\n", len1, len2);
	len2 = printf("pfd15: %d \n", -14);
	len1 = ft_printf("myd15: %d \n", -14);
	printf("test d15 : %d -> %d\n\n", len1, len2);
	len2 = printf("pfd16: %d \n", -15);
	len1 = ft_printf("myd16: %d \n", -15);
	printf("test d16 : %d -> %d\n\n", len1, len2);
	len2 = printf("pfd17: %d \n", -16);
	len1 = ft_printf("myd17: %d \n", -16);
	printf("test d17 : %d -> %d\n\n", len1, len2);
	len2 = printf("pfd18:%d \n", -100);
	len1 = ft_printf("myd18:%d \n", -100);
	printf("test d18 : %d -> %d\n\n", len1, len2);

	ft_printf("##########\n");
	ft_printf("# test u #\n");
	ft_printf("##########\n\n");

	len1 = ft_printf("myu12: %u \n", -1);
	len2 = printf("myd12: %u \n", -1);
	printf("test u12 : %d -> %d\n\n", len1, len2);
	len1 = ft_printf("myu13: %u \n", -9);
	len2 = printf("pfu13: %u \n", -9);
	printf("test u13 : %d -> %d\n\n", len1, len2);
	len1 = ft_printf("myu14: %u \n", -10);
	len2 = printf("pfd14: %u \n", -10);
	printf("test u14 : %d -> %d\n\n", len1, len2);
	len1 = ft_printf("myu15: %u \n", -11);
	len2 = printf("pfd15: %u \n", -11);
	printf("test u15 : %d -> %d\n\n", len1, len2);
	len1 = ft_printf("myu16: %u \n", -14);
	len2 = printf("pfd16: %u \n", -14);
	printf("test u16 : %d -> %d\n\n", len1, len2);
	len1 = ft_printf("myu17: %u \n", -15);
	len2 = printf("pfu17: %u \n", -15);
	printf("test u17 : %d -> %d\n\n", len1, len2);
	len1 = ft_printf("myu18: %u \n", -16);
	len2 = printf("pfd18: %u \n", -16);
	printf("test u18 : %d -> %d\n\n", len1, len2);
	len1 = ft_printf("myu19: %u \n", -99);
	len2 = printf("pfd19: %u \n", -99);
	printf("test u19 : %d -> %d\n\n", len1, len2);
	len1 = ft_printf("myu20: %u \n", -100);
	len2 = printf("pfd20: %u \n", -100);
	printf("test u20 : %d -> %d\n\n", len1, len2);
	len1 = ft_printf("myu21: %u \n", -101);
	len2 = printf("pfd21: %u \n", -101);
	printf("test u21 : %d -> %d\n\n", len1, len2);
	len1 = ft_printf("myu22: %u \n", INT_MIN);
	len2 = printf("pfd22: %u \n", INT_MIN);
	printf("test u22 : %d -> %d\n\n", len1, len2);
	len1 = ft_printf("myu23: %u \n", LONG_MAX);
	len2 = printf("pfd23: %u \n", LONG_MAX);
	printf("test u23 : %d -> %d\n\n", len1, len2);
	len1 = ft_printf("myu24: %u \n", UINT_MAX);
	len2 = printf("pfd24: %u \n", UINT_MAX);
	printf("test u24 : %d -> %d\n\n", len1, len2);
	len1 = ft_printf("myu25: %u \n", ULONG_MAX);
	len2 = printf("pfd25: %u \n", ULONG_MAX);
	printf("test u25 : %d -> %d\n\n", len1, len2);
	len1 = ft_printf("myu26: %u \n", 9223372036854775807LL);
	len2 = printf("pfd26: %u \n", 9223372036854775807LL);
	printf("test u26 : %d -> %d\n\n", len1, len2);


/*	ft_printf("\nmy: Hello n43\n");
	printf("pf: Hello n43\n");
	ft_printf("\nmy: %s\n",       "Hello n43");
	printf("pf: %s\n",       "Hello n43");
	ft_printf("\nmy: 1024  -> %d\n",       1024);
	printf("pf: 1024  -> %d\n",       1024);
	ft_printf("\nmy: -1024 -> %d\n",       -1024);
	printf("pf: -1024 -> %d\n",       -1024);
	ft_printf("\nmy: 1024  -> %i\n",       1024);
	printf("pf: 1024  -> %i\n",       1024);
	ft_printf("\nmy: -1024 -> %i\n",       -1024);
	printf("pf: -1024 -> %i\n",       -1024);
	ft_printf("\nmy: 1024u -> %u\n",       1024u);
	printf("pf: 1024u -> %u\n",       1024u);
	ft_printf("\nmy: -1024u -> %u\n",       -1024u);
	printf("pf: -1024u -> %u\n",       -1024u);
	ft_printf("\nmy: 0x1234abcd -> %x\n",       0x1234abcdu);
	printf("pf: 0x1234abcd -> %x\n",       0x1234abcdu);
	ft_printf("\nmy: -0x1234abcdu -> %x\n",       -0x1234abcdu);
	printf("pf: -0x1234abcdu -> %x\n",       -0x1234abcdu);
	ft_printf("\nmy: 0x1234abcdu -> %X\n",       0x1234abcdu);
	printf("pf: 0x1234abcdu -> %X\n",       0x1234abcdu);
	ft_printf("\nmy: -0x1234abcdu -> %X\n",       -0x1234abcdu);
	printf("pf: -0x1234abcdu -> %X\n",       -0x1234abcdu);
	ft_printf("\nmy: 'x' -> %c\n",       'x');
	printf("pf: 'x' -> %c\n",       'x');
	ft_printf("\nmy: zerobite -> %c\n",       '\0');
	printf("\npf: zerobite -> %c\n",       '\0');


	ft_printf("\nmy: %  %%\n");
	printf("pf: %  7%%\n");
*/
	return (0);
}