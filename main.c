#include "monty.h"

int numMonty;

/**
 * main - takes input and sends to sub function
 * @argc: arg counter
 * @argv: arg vector
 * Return: 1
 */
int main(__attribute__((unused))int argc, char **argv)
{
	FILE *fd;
	char linebuf[1024];
	unsigned int lineNumber = 1;
	stack_t *stack = NULL;
	stack_t *tmp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(linebuf, 1024, fd) != NULL)
	{
		tokenize_call(linebuf, lineNumber, &stack);
		lineNumber++;
	}
	fclose(fd);
	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	if (stack)
		free(stack);
	return (1);
}

/**
 * tokenize_call - tokenize a line and call a function if possible
 * @linebuf: line we want to check
 * @lineNumber: line number
 * @stack: link list as a stack
 */
void tokenize_call(char *linebuf, unsigned int lineNumber, stack_t **stack)
{
	char *tok = "1";
	char delim[] = " \t\n";
	int i = 0;

	instruction_t inst[] = {
		{"push", push_f},
		{"pall", pall_f},
		{"pint", pint_f},
		{"pop", pop_f},
		{"swap", swap_f},
		{"add", add_f},
		{"nop", nop_f},
		{NULL, NULL},
	};

	while (tok)
	{
		tok = strtok(linebuf, delim);
		linebuf = NULL;
		for (; inst[i].opcode != NULL ; i++)
		{
			if (!tok)
				return;
			if (tok && strcmp(inst[i].opcode, tok) == 0)
			{
				tok = strtok(linebuf, delim);
				if (i == 0)
					numberval(tok, lineNumber);
				inst[i].f(stack, lineNumber);
				return;
			}
		}
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, tok);
		exit(EXIT_FAILURE);
	}
	free(tok);
}

/**
 * numberval - transforms num imput into integer
 * @num: number
 * @line: line number
 */
void numberval(char *num, int line)
{
	int i = 0;

	if (!num)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	for (i = 0 ; num[i] ; i++)
	{
		if (!(num[0] == '-' || (num[i] >= 48 && num[i] <= 57)))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			exit(EXIT_FAILURE);
		}
	}
	numMonty = atoi(num);
}

