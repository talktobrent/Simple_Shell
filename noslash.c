#include "shell.h"

/**
 * noslash - detects if command is direct path or not
 * @string: string given
 * Return: 1 if direct path, 0 if not
 */


int noslash(char *string)
{
	int count = 0;
	int slash = 0;

	while (string[count] != '\0')
	{
		if (string[count] == '/')
		{
			slash = 1;
			break;
		}
		count++;
	}

	return (slash);
}
