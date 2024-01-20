#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include "monty.h"
container_t container = {NULL, NULL, 0, 0, NULL, NULL};
/**
 * main - check the code
 * @argc: the number of arguments that is passed
 * @argv: array of pointer pointing to arguments strings
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	instruction_t cmd [] = {{"push", push}, {"pall", pall}, {"pint", pint}, {NULL, NULL}};
	char *line, *command_part, *value_part;
	size_t size = 0;
	ssize_t get = 0;
	int i, tracker, value;
	unsigned int line_number = 1;
	FILE *monty_file;
	stack_t *top = NULL;
	
	line = NULL;
	command_part = NULL;
	if (argc != 2)
	{
		/**free_stack(top);**/
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		/**free_stack(top);**/
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	do
	{
		get = getline(&line, &size, monty_file);
		if (get == -1)
			break;
		line_number++;
		command_part = strtok(line, " \n\t");
		if (command_part == NULL)
			continue;
		value_part = strtok(NULL, " \n\t");
		container.integral = value_part;
		container.file = monty_file;
		container.line = line;
		tracker = -1;
		for (i = 0; cmd[i].opcode != NULL; i++)
		{
			value = strcmp(command_part,cmd[i].opcode);
			if (value == 0)
			{
				container.argument = command_part;
				cmd[i].f(&top, line_number);
				tracker++;
			}	
		}
		if (tracker == -1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command_part);
			fclose(monty_file);
			free(line);
			free_stack(top);
			exit(EXIT_FAILURE);
		}
	} while (get);
	/**
	if (tracker == -1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command_part);
		fclose(monty_file);
		free(line);
		free_stack(top);
		exit(EXIT_FAILURE);
	}
	**/
	fclose(monty_file);
	free(line);
	free_stack(top);
	return (0);
}
