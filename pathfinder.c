#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
 *pathfinder - finds the PATH variable in env
 *@env: enviroment
 *Return: pointer to PATH string just AFTER "PATH="
 */

char *pathfinder(char **env)
{
	int count, count2;
	char *string = NULL, *path = "PATH=";

	count = 0;
	count2 = 0;

	while (env[count] != NULL)
	{
		while (env[count][count2] == path[count2])
			count2++;

		if (count2 == 5)
		{
			string = &env[count][count2];
			break;
		}

		count++;
		count2 = 0;
	}
	if (env[count] != NULL)
		string = _strdup(string);
	else
		string = NULL;
	return (string);
}
