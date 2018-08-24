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

char **pathfinder(char **env)
{
        int count, count2;
        char *string, **array, path[] = {'P', 'A', 'T', 'H', '='};
	
	printf("im about to enter a loop\n");
    

        while(env[count] != NULL)
        {
                while(env[count][count2] == path[count2])
                {
                        count2++;
                }
                if (count2 == 5)
                {

			string = env[count] + 5;
                        printf("%s\n", string);
                        break;
                }

		count++;
		count2 = 0;
        }

	string = _strdup(string);
	
	count  = stringprep(string, ':', '\0');

	array = buildarray(string, ':', count);

	printf("array 0 is %s\n", array[0]);
	return (array);
}
