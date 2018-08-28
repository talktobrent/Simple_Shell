#include "shell.h"

/**
 *pathfork - if user's input is not a direct path to command,
 *this function will go through paths to find command
 *then execute
 *@all: all variables
 *
 *Return: 0 upon success
 */
int pathfork(struct wrap *all)
{
	char *append = NULL;
        int count = 0, status;
	pid_t process;


	while(all->patharray[count] != NULL)
	{
		/*if path exists then execute(pathname, token, null)*/

		append = _strcat(all->patharray[count], all->cmdarray[0]);
		/*printf("append %s\n", append);*/

		if (access(append, X_OK) == 0)
		{
			process = fork();
			
			if (process == 0)
			{
				
				if (execve(append, all->cmdarray, all->patharray) == -1)
					perror("Error");
				else
					return(0);
			}
			else
			{
				wait(&status);
				/*printf("winner: %s\n", append);*/
				free(append);
				break;
			}
	        }
		if (access(append, F_OK) == 0)
		{
			/*printf("Hit me!\n");*/
			_error(all, "Permission denied");
			free(append);
			break;
		}

		/*printf("before free append in loop\n");*/
		free(append);
		append = NULL;
		count++;
	}

	if(all->patharray[count] == NULL)
	{
		_error(all, "not found");
		return(127);
	}

	/*printf("before path0\n");
	  printf("before patharry\n");*/
	return(0);
}
