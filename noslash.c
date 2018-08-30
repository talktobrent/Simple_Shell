#include "shell.h"


int noslash(char *string)
{
	int count = 0;
	slash = 0;

	while(string[count] != '\0')
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
