#include "monty.h"
/**
 * pint_f - print the value at the top of the stack
 * @stack: list
 * @line_number: line count
 */
void pint_f(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop_f - removes the top of the stack
 * @stack: list
 * @line_number: line count
 */
void pop_f(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "t%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp->prev);
	tmp->prev = NULL;
	free(tmp);
}

/**
 * add_f - adds the value of the 2 lasts things
 * @stack: list
 * @line_number: line count
 */
void add_f(stack_t **stack, unsigned int line_number)
{
	int m;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	m = (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = (*stack)->n + m;
}

/**
 * swap_f - swap the last stack
 * @stack: list
 * @line_number: line count
 */
void swap_f(stack_t **stack, unsigned int line_number)
{
	int m;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	m = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = m;
}

/**
 * nop_f - does nothing
 * @stack: list
 * @line_number: line count
 */
void nop_f(stack_t **stack, unsigned int line_number)
{
	(void) *stack;
	(void) line_number;
}
