#ifndef _SHELL_H_
#define _SHELL_H_

char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int forkitfunction(char **checks);
int pathfork(char **checks, char **env);
char **buildarray(char *string, char delimeter, int elements);
int stringprep(char *string, char delimeter, char end);
char **pathfinder(char **env);
char **getinput(void);

#endif /* _SHELL_H_ */


