#ifndef MASTER_H
#define MASTER_H

#include "lists.h"
#include "stackops.h"

__local void (*get(char *opcode))(stack_t **stack, uint line_number)
{
	instruction_t opt[] = {
                {"push", push},
                {"pall", pall},
                {NULL, NULL} };
	int i;

	for (i = 0; opt[i].opcode; i++)
	{
		if (!strcmp(opcode, opt[i].opcode))
			return (opt[i].f);
	}

	return (NULL);
}

__local int handler(int ac, char **av)
{
	stack_t *stack;
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	uint l_num;

	fi(ac != 2) FAIL_ARGNUM;
	stack = malloc(sizeof(stack_t));
	fi(!stack) FAIL_MALLOC;

	fp = fopen(av[1], "r");
	fi(!fp) FAIL_FILE(av[1]);

	for (l_num = 1; (read = getline(&line, &len, fp)) != EOF; l_num++)
	{
		for (state.token = strtok(line, state.delim); state.token;)
		{
			if (get(state.token))
				get(state.token)(&stack, l_num);
			else
			{
				empty_stack(stack);
				FAIL_OPCODE(l_num, state.token);
			}
			break;
		}
	}
	empty_stack(stack);
	free(state.token);
	fclose(fp);
	return (0);
}

#endif
