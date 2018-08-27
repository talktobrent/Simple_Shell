#include "shell.h"

/**
 *forkitfunction - if user's is already a direct path to command, the function
 *will execute
 *@all: all variables
 *
 *Return: 0 upon success
 */
int forkitfunction(struct wrap *all)
{
	pid_t process = fork();

	if (process == -1)
		return (-1);

	if (process == 0)
	{
		if (execve(all->cmdarray[0], all->cmdarray, NULL) == -1)
			exit (1);
		else
			exit(0);
	}
	else
	{
		wait(NULL);
		return (0);
	}
	return (0);
}
