#include "shell.h"
#include <stdlib.h>

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

/**
* _strdup - returns pointer to copy of a string
* @str: string given
* Return: pointer to copy of string, NULL if insufficient memory
*/

char *_strdup(char *str)
{
	char *strptr;
	int count;

	if (str == NULL)
		return (NULL);

	for (count = 0; str[count] != '\0'; count++)
	{
	}

	strptr = malloc(sizeof(char) * (count + 1));
	if (strptr == NULL)
		return (NULL);

	for (count = 0; str[count] != '\0'; count++)
		strptr[count] = str[count];

	strptr[count] = '\0';

	return (strptr);
}


/**
 *_strcat - used to concatenate user's input with pathname to
 *execute command, also adds a forward slash
 *@dest: original string
 *@src: string to be added to end of dest
 *Return: concatenated string with foward slash between
 */
char *_strcat(char *dest, char *src)
{

        int dest_count, src_count, count;
        char *space;

        src_count = 0;
	dest_count = 0;

        while (dest[dest_count] != 0)
                dest_count++;

        while(src[src_count] != '\0')
                src_count++;

        space = malloc(sizeof(char) * (dest_count + src_count) + 2);
	if (space == NULL)
		printf("malloc fail1\n");

        count = 0;
        while(dest[count] != '\0')
        {
                space[count] = dest[count];
                count++;
        }

        /* 47 is forward slash*/
        space[count++] = 47;

	src_count = 0;
        while (src[src_count] != 0)
                space[count++] = src[src_count++];

	space[count] = 0;

        return (space);
}



