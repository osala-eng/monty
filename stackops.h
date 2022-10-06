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

/**
 * push - stack op push
 * @stack: stack
 * @line_number: line number
 */
__local void push(stack_t **stack, uint line_number)
{
	s.token = strtok(NULL, s.delim);
	fi(!stack) return;

	fi(is_number(s.token)) goto END;
	push_stack(stack, atoi(s.token));
	return;

END:
	fclose(s.fp);
	free(s.line);
	FAIL_INT(line_number, *stack);
}

/**
 * pall - stack op pall
 * @stack: stack
 * @line_number: line number
 */
__local void pall(stack_t **stack, __silent uint line_number)
{
	pall_stack(*stack);
}


#endif
