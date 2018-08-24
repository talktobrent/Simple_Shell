#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int pathfork(char *argv, char **checks, char **env)
{
	char **path, *append;
        int count = 0, status;
	pid_t process;

	path = pathfinder(env);

	printf("i printed the path");

	while(path[count])
	{
		/*if path exists then execute(pathname, token, null)*/

		append = _strcat(path[count], checks[0]);
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
	if (access(append, X_OK) == -1)
		_error(argv, checks[0], "1");
	count = 0;
        free(path[0]);
        free(path);
	return(0);
}
