#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int forkitfunction(char **checks)
{
	pid_t process = fork();

	if (process == -1)
		return (-1);

	if (process == 0)
	{
		if (execve(checks[0], checks, NULL) == -1)
			exit (1);
	}
	else
	{
		wait(NULL);
		return (0);
	}
	return (0);
}
