#ifndef _SHELL_H_
#define _SHELL_H_

char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int forkitfunction(char **checks);
int pathfork(char *argv, char **checks, char **patharray);
char **buildarray(char *string, char delimeter, int elements);
int stringprep(char *string, char delimeter, char end);
char *pathfinder(char **env);
char *getinput(char *argv);
void _error(char *argv, char *checks, char *message);
char *freebuffer, *freepath;

#endif /* _SHELL_H_ */


