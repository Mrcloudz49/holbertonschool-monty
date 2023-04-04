#include "monty.h"

FILE *file = NULL;

/**
*main - Interprets monty files
*@argc: counts arguments
*@argv: array of char pointers listing arguments
*Return: 0 Success , 1 for failure
*/
int main(int argc, char **argv)
{
	void (*f)(stack_t **, unsigned int) = NULL;
	char *buffer = NULL, op[50] = {'\0'}, addNum[50] = {'\0'}, *token = NULL;
	size_t buffsize = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (!file)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	for (; getline(&buffer, &buffsize, file) != EOF; line_number++)
	{
		token = strtok((buffer), " \t\n");
		if (!token)
		{
			free(buffer), buffer = NULL;
			continue;
		}
		strcpy(op, token);
		f = parser(&stack, line_number, op);
		if (!f)
			fprintf(stderr, "Error: malloc failed\n"), err();
		if (strcmp(op, "push") == 0)
		{
			token = strtok(NULL, " \t\n");
			if (!token)
			{
				free(buffer), buffer = NULL, free_stack(&stack);
				fprintf(stderr, "L%d: usage: push integer\n", line_number), err();
			}
			strcpy(addNum, token);
		}
		free(buffer), buffer = NULL;
		f(&stack, line_number);
		if (strcmp(op, "push") == 0)
			pushHelp(&stack, line_number, addNum);
	}
	free(buffer), fclose(file), free_stack(&stack);
	return (EXIT_SUCCESS);
}

/**
*pushHelp - helper for push op that sets val for new node
*@stack: linked list to push to
*@line_number: current line of monty file
*@addNum: number to add to new node
*/
void pushHelp(stack_t **stack, unsigned int line_number, char *addNum)
{
	if (strcmp(addNum, "0") == 0)
	{
		(*stack)->n = 0;
	}
	if (strcmp(addNum, "0") != 0)
	{
		(*stack)->n = atoi(addNum);
		if ((*stack)->n == 0 || (addNum[0] != '-' && (*stack)->n == -1))
		{
			fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
			free_stack(stack);
			err();
		}
	}
}
