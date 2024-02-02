#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


// int main(void)
// {
// 	int fd = open("to_read.txt", O_RDONLY);
// 	char *test;
// 	test = (void *) -1;
// 	while(test)
// 	{
// 		test = get_next_line(fd);
//         printf("%s", test);
//         free(test);
// 	}
// 	close(fd);
// 	return (0);
// }

// int main(void)
// {
// 	int fd = open("to_read.txt", O_RDONLY);
// 	char *line;
// 	line = (void *) -1;
// 	int i;
// 	i = 1;
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			printf("[%d] %s", i, line);
// 		else
// 			printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	// free(line);
// 	// printf("%s\n", get_next_line(fd));
// 	close(fd);
// 	// fd = open("error", O_RDONLY);
// 	// line = get_next_line(fd);
// 	// printf("%s", line);
// 	// printf("\n");
// 	// free(line);
// 	// close(fd);
// 	// fd = open("to_read.txt", O_RDONLY);
// 	// i = 0;
// 	// while (i < 4)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	printf("%s", line);
// 	// 	free(line);
// 	// 	i++;
// 	// }
// 	// close(fd);
// }


// // main test fonction read
// int main(void)
// {
// 	int fd = open("to_read.txt", O_RDONLY);
// 	char buf[2];
// 	size_t count;

// 	count = 1;
// 	ssize_t test_read = read(fd, buf, count);
// 	printf("%d\n", fd);
// 	printf("%s\n", buf);
// 	printf("%ld\n", test_read);
// 	close(fd);
// 	return (0);
// }