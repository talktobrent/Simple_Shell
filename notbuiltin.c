#include "shell.h"

/**
 *notbuiltin - if user's input is not a builtin,
 *this function will execute their
 *@all: all variables
 */
void notbuiltin(struct wrap *all)
{
	int size = 0;
	char *col = ":";

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
		all->path = pathfinder(all->env);
		if (all->path != NULL)
		{
			size = stringprep(all->path, ':', '\0');
			all->patharray = buildarray(all->path, col, size);

			if (all->patharray == NULL)
			{
				_error(all, "Cannot allocate memory");
				all->retval = 1;
			}
			all->retval = pathfork(all);
			free(all->path);
			all->path = NULL;
			if (all->patharray != NULL)
			{
				free(all->patharray);
				all->patharray = NULL;
			}
		}
		else
		{
			_error(all, "not found");
			all->retval = 127;
		}
	}
	free(all->cmdarray);
	all->cmdarray = NULL;

}
