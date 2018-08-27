#include "shell.h"

/**
 *_error: function to print custom errors for all error checks
 *@all: all variables
 *@string: custom message
 */
void _error(struct wrap *all, char *string)
{
	char *code;
	int len = 0, len1 = 0, len2 = 0, len3 = 0;

	while (all->cmdarray[0][len])
		len++;

	while (all->argvzero[len1] != '\0')
                len1++;

	code = intostring(all->loop);
	while(code[len2])
		len2++;

	while(string[len3])
		len3++;

	write(1, all->argvzero, len1);
	write(1, ": ", 2);

	write(1, code, len2);
	write(1, ": ", 2);

	write(1, all->cmdarray[0], len);
	write(1, ": ", 2);

	write(1, string, len3);
	write(1, "\n", 2);
	free(code);
}
