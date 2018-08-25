#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include <sys/wait.h>
#include <sys/types.h>

/**
 *
 *
 *
 *
 */
int main(int ac, char **argv, char **env)
{
        char **checks, *path, *commands, **patharray;
        int status, size, loop = 0;

	do {

		commands = getinput(argv[0]);
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
        		else
        		{
				path = pathfinder(env);
				size = stringprep(path, ':', '\0');
				patharray = buildarray(path, ':', size);
				pathfork(argv[0], checks, patharray);
			}
        		printf("before free chk0\n");
			free(commands);
			free(path);
        		printf("before free chkarray\n");
			free(checks);
		}

		checks = NULL;

	} while (loop == 0);

        return (0);
}

