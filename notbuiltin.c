#include "shell.h"

/**
 *notbuiltin - if user's input is not a builtin, this function will execute their
 *input or return error if input cannot be executed
 *
 */
void notbuiltin(struct wrap *all)
{
	int size = 0;

	if ((access(all->cmdarray[0], X_OK) == 0))
	{
		forkitfunction(all);
	}
	else if ((access(all->cmdarray[0], F_OK) == 0))
	{
		_error(all, "Permission denied");
		all->retval = 126;
	}

	else
	{
		all->path = pathfinder(all);
		size = stringprep(all->path, ':', '\0');
		all->patharray = buildarray(all->path, ':', size);
		all->retval = pathfork(all);
		printf("before free allpath\n");
		free(all->path);
		printf("before free allarray\n");
		free(all->patharray);
	}

	printf("before free commands\n");
	//free(commands);                                             
	printf("before free chkarray\n");
	free(all->cmdarray);

}
