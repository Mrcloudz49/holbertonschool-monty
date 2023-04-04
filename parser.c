#include "monty.h"
/**
*parser - gets matching function from opcode
*@stack: stack operating on
*@code: strinf used for correct function
*@l: line number
*Return: function pointer
*/
void (*parser(stack_t **stack, int l, char *code))(stack_t **, unsigned int)
{
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
	};
	int i = 0;

	while (strcmp(code, instruction[i].opcode) != 0)
	{
		i++;
		if (i > 7)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", l, code);
			free_stack(stack);
			err();
		}
	}
	return (instruction[i].f);
}

/**
*free_stack - frees a linked list stack
*@stack: stack to free
*/
void free_stack(stack_t **stack)
{
	if (!(stack) || !(*stack))
	{
		return;
	}
	free_stack(&((*stack)->next));
	free(*stack);
	*stack = NULL;
}
/**
*err - error handler
*/
void err(void)
{
	fclose(file);
	exit(EXIT_FAILURE);
}
