#include "shell.h"
#include <stdio.h>
#include <unistd.h>

void _error(char *argv, int loop, char *checks, char *string)
{
	int len = 0, len1 = 0, len2 = 0, len3 = 0;

	while (checks[len])
		len++;

	while (argv[len1] != '\0')
                len1++;

	while(code[len2])
		len2++;

	while(string[len3])
		len3++;

	write(1, argv, len1);
	write(1, ": ", 2);

	write(1, code, len2);
	write(1, ": ", 2);

	write(1, checks, len);
	write(1, ": ", 2);

	write(1, string, len3);
	write(1, "\n", 2);
}
