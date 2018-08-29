#include "shell.h"

/**
 *notbuiltin - if user's input is not a builtin,
 *this function will execute their
 *@all: all variables
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
		if (all->path != NULL)
		{
			size = stringprep(all->path, ':', '\0');
			all->patharray = buildarray(all->path, ':', size);
			if (all->patharray == NULL)
			{
				_error(all, "Cannot allocate memory");
				all->retval = 1;
			}
			all->retval = pathfork(all);
			free(all->path);
			free(all->patharray);
		}
		else
			_error(all, "Cannot find PATH");
	}
	free(all->cmdarray);

}
