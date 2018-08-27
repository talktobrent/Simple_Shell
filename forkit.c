#include "shell.h"

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
