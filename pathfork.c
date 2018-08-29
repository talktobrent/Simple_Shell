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


	while (all->patharray[count] != NULL)
	{
		/*if path exists then execute(pathname, token, null)*/

		append = _strcat(all->patharray[count], all->cmdarray[0]);
		if (append == NULL)
		{
			_error(all, "Cannot allocate memory");
			all->retval = 1;
		}

		if (access(append, X_OK) == 0)
		{
			process = fork();

			if (process == 0)
			{

				if (execve(append, all->cmdarray, all->env) == -1)
				{
					perror("Error ");
					_exit(1);
				}
				else
				{
					exit(0);
				}
			}
			else
			{
				wait(&status);
				if (WIFEXITED(status))
					all->retval = WEXITSTATUS(status);
				free(append);
				return (all->retval);
			}
		}
		if (access(append, F_OK) == 0)
		{
			_error(all, "Permission denied");
			free(append);
			return (126);
		}
		free(append);
		append = NULL;
		count++;
	}

	if (all->patharray[count] == NULL)
	{
		_error(all, "not found");
		return (127);
	}

	return (0);
}
