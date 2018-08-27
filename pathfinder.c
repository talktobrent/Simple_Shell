#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/*
 * pathfinder - finds the PATH variable in env
 * @path: finds path (example: "PATH=")
 * @env: environmental extern variable (array of strings)
 * Description: finds the PATH variable in the env
 * Return: pointer to PATH string just AFTER "PATH="
 */

char *pathfinder(struct wrap *all)
{
        int count, count2;
        char *string, **array, *compare, path[] = {'P', 'A', 'T', 'H', '='};

	printf("im about to enter a loop\n");

	count = 0;
	count2 = 0;

	array = all->env;

        while(array[count] != NULL)
        {
		compare = array[count];
                while(*compare++ == path[count2])
                {
                        count2++;
                }
                if (count2 == 5)
                {

			printf("hit\n");
			string = compare - 1;
                        printf("%s\n", string);
                        break;
                }

		count++;
		count2 = 0;
        }

	string = _strdup(string);

	return (string);
}
