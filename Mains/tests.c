#include "libft.h"
#include <bsd/string.h>

int main(void)
{
	char str[] = "petit test pour voir";
	const char str1[] = "autre chose";

	printf("%lu\n", strlcpy(str, str1, 4));
}