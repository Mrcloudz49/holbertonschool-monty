#include "monty.h"
/**
 * main - main function for monty
 * @ac: arnuments count
 * @av: atruments inventory
 * Return: nothing
 */
int main(int ac, char *av[])
{
	int i = 0;
	unsigned int line = 1;
	ssize_t read_val = 0;
	size_t bytes = 1;
	char *buffer = NULL, *token = NULL;
	FILE *fd;
	stack_t *stack = NULL;

	argument[0] = "SCSS", argument[1] = "SCSS";
	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (!fd)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file%s\n", av[1]);
		free(buffer), free(token);
		exit(EXIT_FAILURE);
	}
	while (read_val != EOF && (strcmp(argument[0], "FAIL") != 0))
	{
		buffer = NULL;
		read_val = getline(&buffer, &bytes, fd);

		if (read_val == -1)
		{
			free(buffer);
			break;
		}
		token = buffer;
		interpreter(token, line, &stack);
		i++;
		line++;
		free(buffer);
	}
	if (strcmp(argument[0], "FAIL") == 0)
	{
		fclose(fd);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	free_stack(stack);
	fclose(fd);
	return (0);
}
