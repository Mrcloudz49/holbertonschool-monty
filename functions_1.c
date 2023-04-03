#include "monty.h"
/**
 * push_f - push a new element into the stack
 * @stack: stack
 * @line_number: number of the line
 */
void push_f(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *newNode = NULL;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "L<line_number>: usage: push integer\n");
		exit(EXIT_FAILURE);
	}
	newNode->prev = NULL;
	newNode->next = *stack;
	newNode->n = numMonty;
	if (*stack != NULL)
	{
		(*stack)->prev = newNode;
	}
	*stack = newNode;
}

/**
 * pall_f - print the whole stack
 * @stack: stack
 * @line_number: number of the line
 */
void pall_f(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *toprint = *stack;

	while (toprint != NULL)
	{
		printf("%d\n", toprint->n);
		if (toprint->next != NULL)
		{
			toprint = toprint->next;
		}
		else break;
	}
}


