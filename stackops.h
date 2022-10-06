#ifndef _STACK_OPS_H
#define _STACK_OPS_H

#include "lists.h"

/**
 * is_number - iterates each character of string to check of isdigit
 * @n: integer
 * Return: 0 if is number, else -1 if not
 */
int is_number(const char *n)
{
	int i = 0;

	if (*n == '-')
		i = 1;
	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
			return (-1);
	}
	return (0);
}

__local void push(stack_t **stack, uint line_number)
{
	state.token = strtok(NULL, state.delim);
	fi(!stack) return;

	fi(is_number(state.token)) FAIL_INT(line_number, stack);
	push_stack(stack, atoi(state.token));
}

__local void pall(stack_t **stack, __silent uint line_number)
{
	pall_stack(*stack);
}


#endif
