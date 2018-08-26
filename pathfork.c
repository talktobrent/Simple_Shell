#include "shell.h"

int pathfork(char *argv, char **checks, char **patharray, int loop)
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
		if (access(append, F_OK) == 0)
		{
			printf("Hit me!\n");
			_error(argv, loop, checks[0], "Permission denied");
			free(append);
			break;
		}


		free(append);
		append = NULL;
		count++;
	}

	if(patharray[count] == NULL)
	{
		_error(argv, loop, checks[0], "not found");
        	free(patharray);
		return(127);
	}

	printf("before path0\n");
        free(patharray);
	printf("before patharry\n");
	return(0);
}
