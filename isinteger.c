#include "monty.h"
/**
 * isinteger - checks wether string is integer
 * @str: the string passed
 *
 * Return: True if correct
 */
bool isinteger(char *str)
{
	int i = 0;
	if (str == NULL)
		return (false);
	if (str[0] == '-')
	{
		i++;
		if (str[i] == '\0')
			return (false);
	}
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
