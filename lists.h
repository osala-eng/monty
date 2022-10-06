#ifndef LISTS_H
#define LISTS_H

#include "monty.h"

/**
 * push_stack - add a node to the head of a list
 * @head: pointer to head
 * @n: new node to add
 * Return: new list
 */
__local stack_t *push_stack(stack_t **head, const int n)
{
	stack_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 * free_dlistint - Frees a linked stack_t list.
 * @head: The head of the stack_t list.
 */
__local void empty_stack(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * pop_stack - deletes node at end of doubly linked list
 * @h: pointer to head of doubly linked list
 */
void pop_stack(stack_t **h)
{
	stack_t *del = NULL;

	del = *h;
	if ((*h)->next == NULL)
	{
		*h = NULL;
		free(del);
	}
	else
	{
		*h = (*h)->next;
		(*h)->prev = NULL;
		free(del);
	}
}

/**
 * print_dlistint - print doubly linked list
 * @h: list
 * Return: number of nodes
 */
__local size_t pall_stack(const stack_t *h)
{
	size_t nodes = 0;

	for (; h; nodes++, h = h->next)
		printf("%d\n", h->n);

	return (nodes);
}

/**
 * dlistint_len - print doubly linked list
 * @h: list
 * Return: number of nodes
 */
size_t len(const stack_t *h)
{
	size_t nodes = 0;

	for (; h; nodes++)
		h = h->next;

	return (nodes);
}

#define FAIL_INT(x, y) \
	(fprintf(stderr, "L%u: usage: push integer\n", x), \
	 empty_stack(y), FAIL)

#define FAIL_STACK_UNDERFLOW(x, y, z) \
        (fprintf(stderr, "L%u: cant %s, stack empty\n", x, y), \
	 empty_stack(z), FAIL)

#define FAIL_ELEMENTS(x, y, z) \
	(fprintf(stderr, "L%u: cant %s, stack too short\n", x, y), \
	 empty_stack(z), FAIL)

#define FAIL_DIV0(x, y) \
        (fprintf(stderr, "L%u: division by zero\n", x), \
         empty_stack(y), FAIL)

#endif
