#include "shell.h"

/**
 *_error - function to print custom errors for all error checks
 *@all: all variables
 *@string: custom message
 */
void _error(struct wrap *all, char *string)
{
	char *code = NULL;
	int len = 0, len1 = 0, len2 = 0, len3 = 0;

	while (all->cmdarray[0][len])
		len++;

	while (all->argvzero[len1] != '\0')
		len1++;

	code = intostring(all->loop);
	while (code[len2])
		len2++;

	while (string[len3])
		len3++;

	write(STDERR_FILENO, all->argvzero, len1);
	write(STDERR_FILENO, ": ", 2);

	write(STDERR_FILENO, code, len2);
	write(STDERR_FILENO, ": ", 2);

	write(STDERR_FILENO, all->cmdarray[0], len);
	write(STDERR_FILENO, ": ", 2);

	write(STDERR_FILENO, string, len3);
	write(STDERR_FILENO, "\n", 2);
	free(code);
}
