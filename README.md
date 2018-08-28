# Simple-Shell

## Description
Simple-Shell is a recreation of a shell that takes user's input and executes it. Our shell resembles the Thompson `sh` in a very limited way.

## Enviroment
Our custom shell was developed and tested on `Ubuntu 14.04 LTS` via Vagrant in VirtualBox.

## Features

## Repo Contents

| **File** | **Description** |
|----------|------------------|
| buildarray.c | Function to |
| builtin.c | Built-in functions feat implementations of `env` and `exit` |
| getinput.c | Read arguments from standad input |
| helpfun.c | Helper functions: forkit, _strdup, _strcat |
| intostring.c | Custom itoa function |
| notbuiltin.c | This function will execute a command if input is not a builtin |
| pathfork.c | This function will append user's input to each directory in PATH and execute if input is found |
| pathfinder.c | This function finds enviroment varibale PATH and parses it by directories |
| printerror.c | Custom error function |
| shell.c | Main file |
| shell.h | Header file that holds all structs and prototypes |
| stringprep.c | This function parses user's input |

## Installation

Clone the repository
```
https://github.com/ceecurvin/Simple_Shell.git
```

Change directory to Simple_Shell
```
cd Simple_Shell/
```

Compile with all `.c` files
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
Enter shell with `./hsh`

## Example

Interactive Mode
```
$ ls -l
total 100
-rw-rw-r-- 1 vagrant vagrant  1177 Aug 28 18:56 #README.md#
-rw-rw-r-- 1 vagrant vagrant   155 Aug 28 18:12 Authors
-rw-rw-r-- 1 vagrant vagrant   263 Aug 28 18:19 README.md
-rw-rw-r-- 1 vagrant vagrant  1105 Aug 28 17:59 bman
-rw-rw-r-- 1 vagrant vagrant  1219 Aug 27 23:29 buildarray.c
-rw-rw-r-- 1 vagrant vagrant  1473 Aug 28 04:32 builtins.c
-rw-rw-r-- 1 vagrant vagrant   727 Aug 27 22:45 getinput.c
-rw-rw-r-- 1 vagrant vagrant  2135 Aug 28 18:06 helpfun.c
-rwxrwxr-x 1 vagrant vagrant 14204 Aug 28 18:56 hsh
-rw-rw-r-- 1 vagrant vagrant  1323 Aug 27 22:45 intostring.c
-rw-rw-r-- 1 vagrant vagrant  3467 Aug 28 17:57 mman
-rw-rw-r-- 1 vagrant vagrant   857 Aug 27 23:24 notbuiltin.c
-rwxrwxr-x 1 vagrant vagrant 13712 Aug 27 19:38 ourshell
-rw-rw-r-- 1 vagrant vagrant  1027 Aug 27 23:25 pathfinder.c
-rw-rw-r-- 1 vagrant vagrant  1224 Aug 28 04:59 pathfork.c
-rw-rw-r-- 1 vagrant vagrant   747 Aug 28 01:17 printerror.c
-rw-rw-r-- 1 vagrant vagrant   887 Aug 28 04:19 shell.c
-rw-rw-r-- 1 vagrant vagrant  1937 Aug 28 04:02 shell.h
-rw-rw-r-- 1 vagrant vagrant  1145 Aug 27 23:27 stringprep.c
$ 
```

Non-Interactive Mode
```
[vagrant@vagrant-ubuntu-trusty-64 Simple_Shell]$ echo "ls -l" | ./hsh
total 100
-rw-rw-r-- 1 vagrant vagrant  2300 Aug 28 18:58 #README.md#
-rw-rw-r-- 1 vagrant vagrant   155 Aug 28 18:12 Authors
-rw-rw-r-- 1 vagrant vagrant   263 Aug 28 18:19 README.md
-rw-rw-r-- 1 vagrant vagrant  1105 Aug 28 17:59 bman
-rw-rw-r-- 1 vagrant vagrant  1219 Aug 27 23:29 buildarray.c
-rw-rw-r-- 1 vagrant vagrant  1473 Aug 28 04:32 builtins.c
-rw-rw-r-- 1 vagrant vagrant   727 Aug 27 22:45 getinput.c
-rw-rw-r-- 1 vagrant vagrant  2135 Aug 28 18:06 helpfun.c
-rwxrwxr-x 1 vagrant vagrant 14204 Aug 28 18:56 hsh
-rw-rw-r-- 1 vagrant vagrant  1323 Aug 27 22:45 intostring.c
-rw-rw-r-- 1 vagrant vagrant  3467 Aug 28 17:57 mman
-rw-rw-r-- 1 vagrant vagrant   857 Aug 27 23:24 notbuiltin.c
-rwxrwxr-x 1 vagrant vagrant 13712 Aug 27 19:38 ourshell
-rw-rw-r-- 1 vagrant vagrant  1027 Aug 27 23:25 pathfinder.c
-rw-rw-r-- 1 vagrant vagrant  1224 Aug 28 04:59 pathfork.c
-rw-rw-r-- 1 vagrant vagrant   747 Aug 28 01:17 printerror.c
-rw-rw-r-- 1 vagrant vagrant   887 Aug 28 04:19 shell.c
-rw-rw-r-- 1 vagrant vagrant  1937 Aug 28 04:02 shell.h
-rw-rw-r-- 1 vagrant vagrant  1145 Aug 27 23:27 stringprep.c
[vagrant@vagrant-ubuntu-trusty-64 Simple_Shell]$ 
```

## Exiting Simple_Shell
Simply type `exit`

## Notes
For information of Simple_Shell, visit the man page
```
man -l man_1_simple_shell
```

## Authors
* [**Ca'Nese Curvin**]()
* [**Brent Janksi**]()