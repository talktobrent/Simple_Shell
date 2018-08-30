#include "shell.h"

/**
 *main - runs customs shell
 *@ac: argument count, UNUSED
 *@argv: argument array
 *@env: environ ment array
 *
 *Return: 0 upon success, others on error
 */

int main(int ac, char **argv, char **env)
{
	int checkbuilt = 0;
	char *sp = " ";

	struct wrap all;

		all.loop = 1;
		all.retval = 0;
		all.argvzero = argv[0];
		all.env = env;
		all.off = 0;
		all.size = 0;
		all.line = NULL;
		all.cmdarray = NULL;
		all.patharray = NULL;

		(void)(ac);
	do {

		all.line = getinput(&all);
		all.size = stringprep(all.line, ' ', '\n');

		if (all.size > 0)
		{
			all.cmdarray = buildarray(all.line, sp, all.size);
			if (all.cmdarray == NULL)
			{
				_error(&all, "Cannot allocate memory");
				all.retval = 1;
			}
		}

		if (all.cmdarray != NULL)
		{
			checkbuilt = builtins(&all);

			all.retval = 0;

			if (checkbuilt == 1)
			{
				notbuiltin(&all);
			}
		}
		free(all.line);
		all.line = NULL;

		all.size = 0;

		all.cmdarray = NULL;

		if (all.loop == INT_MAX)
			all.loop = 0;
		all.loop++;

	} while (all.loop > 0);

	return (0);
}

