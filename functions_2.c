#include "monty.h"

/**
 * pop - removes the top elelment of the stack
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *save;

	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		argument[0] = "FAIL";
		return;
	}
	save = (*stack)->next;
	free(*stack);
	*stack = save;
}

/**
 * nop - does nothing
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	UNUSED(stack);
	argument[0] = "nothing";
}

/**
 * add - adds the top two elements of the stack
 * @stack: the stack
 * @line_number: instructions line number
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack && (*stack)->next)
		temp = (*stack)->next;
	if (!temp)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack to short\n", line_number);
		argument[0] = "FAIL";
		return;
	}
	temp->n += (*stack)->n;
	free(*stack);
	*stack = temp;
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		argument[0] = "FAIL";
		return;
	}
}


