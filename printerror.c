#include "shell.h"
#include <stdio.h>
#include <unistd.h>

void _error(char *argv, char *checks, char *message)
{
	int len = 0, len1 = 0, len2 = 0;

	while (checks[len])
		len++;

	while (argv[len1] != '\0')
                len1++;

	while(message[len2])
		len2++;

	write(1, argv, len1);
	write(1, ": ", 2);

	write(1, message, len2);
	write(1, ": ", 2);

	write(1, checks, len);
	write(1, ": ", 2);

	write(1, "not found", 9);
	write(1, "\n", 2);
}
