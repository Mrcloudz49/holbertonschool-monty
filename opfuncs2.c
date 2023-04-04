#include "monty.h"
/**
 * pop - Removes node from top of stack
 * @stack: pointer to stack
 * @line_number: number line in the m file
 *
 * Return: Void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}
/** unlinking the front node and then freeing it*/
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - Swaps the top two nodes on the stack
 * @stack:Pointer to stack
 * @line_number: line number
 *
 * Return: Void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int i = 1;

	for (temp = *stack; i < 3; i++, temp = temp->next)
	{
		if (temp == NULL)
		{
			fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
/*assigning x to temp, then y to x, then temp to y so long as it exists */
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
/**
 * nop - uh...
 * @stack: points to stack
 * @line_number: line num
 *
 * Return : Void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * add - replaces first two nodes with the sum of the two at the top
 * @stack: linked list
 * @line_number: current line
 */
void add(stack_t **stack, unsigned int line_number)
{
/* temp node to store the sum of 1 and 2 */
	stack_t *temp;
	int i = 1;

	for (temp = *stack; i < 3; i++, temp = temp->next)
	{
		if (!temp || !temp->next)
		{
			fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
			free_stack(stack);
			err();
		}
	}
/* adding 1 and 2 into the new node that is now replacing them, freeing temp*/
	temp->next->n += temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;
	free(temp);
}
