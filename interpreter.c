#include "monty.h"
/**
 * interpreter - interprets and executes
 * @instruction: instruction to be interpreted
 * @stack: stack
 * @line: line number
 * Return: nothing
 */
void interpreter(char *instruction, unsigned int line, stack_t **stack)
{
	instruction_t array[] = INSTRUCTIONS;
	int i = 0, bol = 0;
	void (*func)(stack_t **stack, unsigned int line_number);
	char *opcode, *arg;

	if (*instruction)
	{
		opcode = strtok(instruction, " \n\t");
		if (opcode && opcode[0] != '#')
		{
			arg = strtok(NULL, " \n\t#");
			while (i < 17)
			{
				if (strcmp(opcode, array[i].opcode) == 0)
				{
					if (strcmp(opcode, array[0].opcode) == 0 && arg)
					argument[0] = arg;
				func = array[i].f;
				bol = 1;
			}
			if (bol)
				break;
			i++;
		}
		if (bol)
		{
			func(stack, line);
			if (strcmp(argument[0], "FAIL") == 0)
				return;
			argument[0] = "reset";
		}
		else
		{
			dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line, opcode);
			argument[0] = "FAIL";
			return;
		}
		}
	}
}

