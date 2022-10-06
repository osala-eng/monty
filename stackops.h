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

	fi(is_number(s.token)) goto KILL;
	push_stack(stack, atoi(s.token));
	return;

KILL:
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

/**
 * pint - stack op pint
 * @stack: stack
 * @line_number: line number
 */
__local void pint(stack_t **stack, uint line_number)
{
	fi(!stack || !*stack) goto KILL;
	printf("%d\n", (*stack)->n);
	return;

KILL:	fclose(s.fp);
	free(s.line);
	FAIL_STACK_UNDERFLOW(line_number, "pint", *stack);
}

/**
 * pop - stack op pop
 * @stack: stack
 * @line_number: line number
 */
__local void pop(stack_t **stack, uint line_number)
{
        fi(!stack || !*stack) goto KILL;
        pop_stack(stack);
	return;

KILL:	fclose(s.fp);
	free(s.line);
	FAIL_STACK_UNDERFLOW(line_number, "pop", *stack);
}

__local void swap(stack_t **stack, uint line_number)
{
	size_t elements = 0;
	int i, j;

	elements = len(*stack);
	fi(elements < 2) goto KILL;
	i = (*stack)->n;
	pop_stack(stack);
	j = (*stack)->n;
	(*stack)->n = i;
	push_stack(stack, j);
	return;

KILL:	fclose(s.fp);
	free(s.line);
	FAIL_ELEMENTS(line_number, "swap", *stack);
}

__local void add(stack_t **stack, uint line_number)
{
	size_t elements = 0;
	int i;

	elements = len(*stack);
	fi(elements < 2) goto KILL;
	i = (*stack)->n;
	pop_stack(stack);
	(*stack)->n += i;
	return;

KILL:	fclose(s.fp);
	free(s.line);
	FAIL_ELEMENTS(line_number, "add", *stack);
}

__local void nop(__silent stack_t **stack, __silent uint line_number)
{
	return;
}

__local void sub(stack_t **stack, uint line_number)
{
        size_t elements = 0;
        int i;

        elements = len(*stack);
        fi(elements < 2) goto KILL;
        i = (*stack)->n;
        pop_stack(stack);
        (*stack)->n -= i;
        return;

KILL:   fclose(s.fp);
        free(s.line);
        FAIL_ELEMENTS(line_number, "sub", *stack);
}

__local void div(stack_t **stack, uint line_number)
{
        size_t elements = 0;
        int i;

        elements = len(*stack);
        fi(elements < 2) goto KILL;
        i = (*stack)->n;
	fi(!i) goto KILL;
        pop_stack(stack);
        (*stack)->n /= i;
        return;

KILL:   fclose(s.fp);
        free(s.line);
	fi(!i) FAIL_DIV0(line_number, *stack);
        FAIL_ELEMENTS(line_number, "div", *stack);
}

__local void mul(stack_t **stack, uint line_number)
{
        size_t elements = 0;
        int i;

        elements = len(*stack);
        fi(elements < 2) goto KILL;
        i = (*stack)->n;
        pop_stack(stack);
        (*stack)->n *= i;
        return;

KILL:   fclose(s.fp);
        free(s.line);
        FAIL_ELEMENTS(line_number, "mul", *stack);
}

__local void mod(stack_t **stack, uint line_number)
{
        size_t elements = 0;
        int i;

        elements = len(*stack);
        fi(elements < 2) goto KILL;
        i = (*stack)->n;
        fi(!i) goto KILL;
        pop_stack(stack);
        (*stack)->n %= i;
        return;

KILL:   fclose(s.fp);
        free(s.line);
        fi(!i) FAIL_DIV0(line_number, *stack);
        FAIL_ELEMENTS(line_number, "mod", *stack);
}


#endif
