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
        char *append, **pt;
        char **checks;
        int status, count = 0, forks, paths;
	pid_t process;

	do {

		checks = getinput(/*&buffy, &size, stdin*/);

        /*input stands for command entered
          if input is found, execute*/
	printf("before access\n");
        if ((access(checks[0], X_OK) == 0))
        {
		forks = forkitfunction(checks);
        }
        else
        {
                /*pt equals array of paths 
                pt = path(env);
                /* loop through array of path
                while(pt[count])
                {
                        /*if path exists then execute(pathname, token, null)

                         append = _strcat(pt[count], checks[0]);
			printf("append %s\n", append);
                        if (access(append, X_OK) == 0)
                        {
                                process = fork();

				if (process == 0)
				{

					if (execve(append, checks, env) == -1)
						perror("Error");
					else
						return(0);
				}
				else
				{
					wait(&status);
					printf("winner: %s\n", append);
					free(append);
					append = NULL;
					break;
				}
		        }
			free(append);
			append = NULL;
                        count++;
                }
		count = 0;
        free(pt[0]);
	free(pt);*/

		paths = pathfork(checks, env);
	}
	free(checks[0]);
	free(checks);

	} while (checks != NULL);

        return (0);
}

