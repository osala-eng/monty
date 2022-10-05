#ifndef MASTER_H
#define MASTER_H

#include "lists.h"

__local int handler(int ac, char **av)
{
	/*instruction_t opt[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{NULL, NULL} };*/

	stack_t *stack;
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fi(ac != 2) FAIL_ARGNUM;
	stack = malloc(sizeof(stack_t));
	fi(!stack) FAIL_MALLOC;

	fp = fopen(av[1], "r");
	fi(!fp) FAIL_FILE(av[1]);

	for (; (read = getline(&line, &len, fp)) != EOF;)
		printf("%s\n", line);

	return (0);
}

#endif
