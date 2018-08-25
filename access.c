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
        char **checks;
        int status, loop = 0, forks, paths;
	pid_t process;

	do {

		checks = getinput(argv[0]);

		if (checks != NULL)
		{

        		if ((access(checks[0], X_OK) == 0))
        		{
				forks = forkitfunction(checks);
        		}
        		else
        		{
				paths = pathfork(argv[0], checks, env);
			}
        		free(checks[0]);
			free(checks);
		}

	} while (loop == 0);
        return (0);
}

