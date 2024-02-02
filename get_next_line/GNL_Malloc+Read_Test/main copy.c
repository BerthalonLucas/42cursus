#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// int main(void)
// {
//     int fd = open("uwu", O_RDONLY);
//     char *cur;
//     cur = (void *)-1;
//     while (cur)
//     {
//         cur = get_next_line(fd);
//         printf("%s", cur);
//         free(cur);
//     }
//     close(fd);
// }

int main(void)
{
	int fd = open("uwu", O_RDONLY);
	char *test;
	test = (void *) -1;
	int i = 0;
	while(test)
	{
		test = get_next_line(fd);
        printf("%s", test);
		printf("%d\n", i++);
        free(test);
	}
	close(fd);
	return (0);
}