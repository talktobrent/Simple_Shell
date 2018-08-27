#include "shell.h"

/**
 *
 *
 *
 *
 */
int main(int ac, char **argv, char **env)
{
        int status, size;

	struct wrap all;

		all.loop = 1;
		all.retval = 0;
		all.argvzero = argv[0];
		all.env = env;
		all.off = 0;

	do {
		all.line = NULL;
		all.cmdarray = NULL;
		all.path = NULL;
		all.patharray = NULL;

		all.line = getinput(&all);
		all.retval = 0;
		size = stringprep(all.line, ' ', '\n');

		if (size > 0)
			all.cmdarray = buildarray(all.line, ' ', size);

		if (all.cmdarray != NULL)
		{

        		if ((access(all.cmdarray[0], X_OK) == 0))
        		{
				forkitfunction(&all);
        		}
			else if ((access(all.cmdarray[0], F_OK) == 0))
			{
				_error(&all, "Permission denied");
				all.retval = 126;
			}

		        else
        		{
				all.path = pathfinder(&all);
				size = stringprep(all.path, ':', '\0');
				all.patharray = buildarray(all.path, ':', size);
				all.retval = pathfork(&all);
				printf("before free allpath\n");
				free(all.path);
				printf("before free allarray\n");
				free(all.patharray);
			}

        		printf("before free commands\n");
			//free(commands);
        		printf("before free chkarray\n");
			free(all.cmdarray);
		}
		free(all.line);
		all.loop++;

	} while (all.loop > 0);

        return (0);
}

