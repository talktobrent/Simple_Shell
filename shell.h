#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>

/**
 *struct wrap - a struct for all variables used to make custom shell
 *@size: number of arguments user entered
 *@loop: shell loop count
 *@retval: return values
 *@argvzero: executable name
 *@env: enviroment array
 *@line: command line buffer
 *@cmdarray: array of command line arguments
 *@path: entire PATH string
 *@patharray: array of tokenized PATH directory
 *@off: true or false integer to stop shell program
 */
struct wrap
{
	int size;
	int loop;
	int retval;
	char *argvzero;
	char **env;
	char *line;
	char **cmdarray;
	char *path;
	char **patharray;
	int off;
};

/**
 *struct funcs - matches user's input with built-in functions
 *@cmd: string to trigger built-in command
 *@call: built-in function to execute
 */
typedef struct funcs
{
	char *cmd;
	int (*call)(struct wrap *all);
} built_in;



char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int forkitfunction(struct wrap *all);
int pathfork(struct wrap *all);
char **buildarray(char *string, char delimeter, int elements);
int stringprep(char *string, char delimeter, char end);
char *pathfinder(struct wrap *all);
char *getinput(struct wrap *all);
void _error(struct wrap *all, char *string);
char *intostring(int x);

int builtins(struct wrap *all);
int myenv(struct wrap *all);
int myexit(struct wrap *all);
void notbuiltin(struct wrap *all);
#endif /* _SHELL_H_ */


