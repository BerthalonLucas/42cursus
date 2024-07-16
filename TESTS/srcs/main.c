#include "../include/test.h"
#include <stdio.h>

int main(void)
{
	char *input;

	while (1)
	{
		input = readline("minishell> ");
		if (input && *input)
			printf("l'input : [%s]\n", input);
		free(input);
	}
	return (0);
}
