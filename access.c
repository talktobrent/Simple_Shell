#include "shell.h"

/**
 *
 *
 *
 *
 */
int main(int ac, char **argv, char **env)
{
        char **checks, *path, *commands, **patharray;
        int status, size, failchk = 0, loop = 1;

	do {

		commands = getinput(argv[0], failchk, loop);
		size = stringprep(commands, ' ', '\n');

		if (size != 0)
			checks = buildarray(commands, ' ', size);
		else
		{
			checks = NULL;
			free(commands);
		}

		if (checks != NULL)
		{

        		if ((access(checks[0], X_OK) == 0))
        		{
				forkitfunction(checks);
        		}
			else if ((access(checks[0], F_OK) == 0))
				_error(argv[0], loop, checks[0], "Permission denied");

		        else
        		{
				path = pathfinder(env);
				size = stringprep(path, ':', '\0');
				patharray = buildarray(path, ':', size);
				failchk = pathfork(argv[0], checks, patharray, loop);
				free(path);
			}

        		printf("before free commands\n");
			free(commands);
        		printf("before free chkarray\n");
			free(checks);
		}

		checks = NULL;
		commands = NULL;
		path = NULL;
		loop++;

	} while (loop > 0);

        return (0);
}

