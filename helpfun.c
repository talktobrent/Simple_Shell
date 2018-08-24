#include "shell.h"
#include <stdlib.h>

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

        space = malloc(sizeof(char) * (dest_count + src_count));

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



