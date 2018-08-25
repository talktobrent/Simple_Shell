#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int pathfork(char *argv, char **checks, char **patharray)
{
	char *append;
        int count = 0, status;
	pid_t process;

	printf("i printed the path");

	while(patharray[count])
	{
		/*if path exists then execute(pathname, token, null)*/

		append = _strcat(patharray[count], checks[0]);
		printf("append %s\n", append);
		if (access(append, X_OK) == 0)
		{
			process = fork();

			if (process == 0)
			{

				if (execve(append, checks, patharray) == -1)
					perror("Error");
				else
					return(0);
			}
			else
			{
				wait(&status);
				printf("winner: %s\n", append);
				free(append);
				break;
			}
		}
		free(append);
		append = NULL;
		count++;
	}

	if(patharray[count] == NULL)
	{
		_error(argv, checks[0], "1");
		printf("before fail free\n");
	}

	printf("before path0\n");
	printf("before patharry\n");
        free(patharray);
	return(0);
}
