#include "monty.h"
/**
 * push - pushes an element to the stack
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp = *stack;
	int number, bol = 0, i = 0;

	for (; argument[0][i]; i++)
		bol = _isalpha((int)argument[0][i]);

	if (bol != 0)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		argument[0] = "FAIL";
		return;
	}
	number = atoi(argument[0]);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		argument[0] = "FAIL";
		return;
	}
	new->n = number;
	if (strcmp(argument[1], "queue") == 0)
	{
		if (temp)
			temp->next = new;
		else
			*stack = new;
	}
	else
	{
		new->next = *stack;
		new->prev = NULL;
		if (*stack)
			(*stack)->prev = new;
		*stack = new;
	}
}


/**
 * _isalpha - checks for alphabetic character
 * @c: is a character
 * Return: nothing
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}

/**
 * free_stack - frees a stack
 * @stack: stack to be freed
 * Return: nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	if (stack)
	{
		while ((temp = stack))
		{
			stack = stack->next;
			free(temp);
		}
	}
}

/**
 * pall - prints all the values on the stack
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	UNUSED(line_number);
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	temp = NULL;
}

/**
 * pint - prints the value at the top of the stack
 * @stack: the stack
 * @line_number: instruction line number
 * Return: nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		argument[0] = "FAIL";
		return;
	}
	printf("%d\n", (*stack)->n);
}

