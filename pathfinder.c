#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
 *pathfinder - finds the PATH variable in env
 *@all: all variables
 *Return: pointer to PATH string just AFTER "PATH="
 */

char *pathfinder(struct wrap *all)
{
	int count, count2;
	char *string, **array, *compare, path[] = {'P', 'A', 'T', 'H', '='};

	count = 0;
	count2 = 0;

	array = all->env;

	while (array[count] != NULL)
	{
		compare = array[count];
		while (*compare++ == path[count2])
			count2++;

		if (count2 == 5)
		{
			string = compare - 1;
			break;
		}

		count++;
		count2 = 0;
	}
	if (array[count] != NULL)
		string = _strdup(string);
	else
		string = NULL;

	return (string);
}
