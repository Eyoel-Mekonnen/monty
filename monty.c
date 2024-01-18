#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include "main.h"
container_t container = {NULL, 0, 0};
/**
 * main - check the code
 * @argc: the number of arguments that is passed
 * @argv: array of pointer pointing to arguments strings
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	instruction_t cmd [] = {{"push", push}, {NULL, NULL}};
	char *line, *corrected_line, *command_part;
	size_t size = 0;
	ssize_t get;
	int trim = 0, integral_value, value, i;
	unsigned int line_number = 0;
	char **ptr2;
	FILE *monty_file;
	stack_t *top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	do {
		get = getline(&line, &size, monty_file);
		if (get == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		if (line[0] == ' ')
		{
			while (line[trim] == ' ')
				trim++;
		}
		if (line == NULL || line[0] == '\n')
		{
			free(line);
			fprintf(stderr, "EMPTY FILE");
			exit(EXIT_FAILURE);
		}
		corrected_line = line_corrected(line + trim);
		free(line);
		trim = 0;
		line_number++;
		ptr2 = strtow(corrected_line);
		free(corrected_line);
		command_part = ptr2[0];
		for (i = 0; cmd[i].opcode != NULL; i++)
		{
			value = _strcmp1(command_part,cmd[i].opcode);
			if (value == 0)
			{
				container.argument = command_part;
				if (ptr2[1] != NULL && !isinteger(ptr2[1]))
					integral_value = atoi(ptr2[1]);
				container.value_passed = integral_value;
				cmd[i].f(&top, line_number);
			}
		}
	} while (get > 0);
	if (cmd[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, corrected_line);
		fclose(monty_file);
		free(corrected_line);
		free_stack(&top);
	}
	free_strtow(ptr2);
	free_stack(&top);
	fclose(monty_file);
	return (0);
}
