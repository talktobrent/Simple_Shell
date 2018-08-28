#include "shell.h"

/**
 *main - runs customs shell
 *@ac: UNUSED
 *@argv: executable name
 *@env: enviroment
 *
 *Return: 0 upon success
 */
int main(int ac, char **argv, char **env)
{
	int size;
	int checkbuilt;

	built_in checks [] = {
                {"exit", myexit},
                {"env", myenv},
                {NULL, NULL}
	};

	struct wrap all;

		all.loop = 1;
		all.retval = 0;
		all.argvzero = argv[0];
		all.env = env;
		all.off = 0;
		all.size = 0;

		(void)(ac);
	do {

		all.line = getinput(&all);
	        all.size = stringprep(all.line, ' ', '\n');

		if (all.size > 0)
			all.cmdarray = buildarray(all.line, ' ', all.size);

		if (all.cmdarray != NULL)
		{
			checkbuilt = builtins(all.cmdarray[0], checks, &all);
			all.retval = 0;
			
			if (checkbuilt == 1)
			{
				notbuiltin(&all);
			}
		}
		free(all.line);
		all.loop++;

	} while (all.loop > 0);

        return (0);
}

