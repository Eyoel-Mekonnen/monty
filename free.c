#include "monty.h"
/**
 * free_strtow - frees allocated memory
 * @argv: address of double pointer passed
 *
 */
void free_strtow(char **argv)
{
	int i;

	if (argv != NULL)
	{
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv[i]);
		free(argv);
	}
}
