#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <string.h>                                                             
#include <unistd.h>                                                             
#include "shell.h"                                                              
#include <sys/wait.h>                                                           
#include <sys/types.h>

struct wrap {
	int loop;
	int retval;
	char *argvzero;
	char **env;
	char *line;
	char *cmd;
	char **cmdarray;
	char *path;
	char **patharray;
	int off;
};

typedef struct funcs {
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
char *intostring(int n);

int builtins(const char *input, built_in *build, struct wrap *all);
int myenv (struct wrap *all);
int myexit (struct wrap *all);	

#endif /* _SHELL_H_ */


