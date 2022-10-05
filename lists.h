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
#endif
