# **SShell - Simple Shell**

A simple UNIX command interpreter written as part of the low-level programming at Holberton School.

## **Description**

SShell is a simple UNIX command interpreter that reads commands from either a file or standard input and executes them.

## **Invocation**

To invoke SShell, compile all .c files in the repository and run the resulting executable:

```
gcc *.c -o SShell

./SShell
```
## **Command Execution**

After receiving a command, SShell tokenizes it into words using " /;" as delimiters. The first word is considered the command and all remaining words are considered a
\guments to that command.

1. If the first character of the command is neither a slash (\\) nor dot (.), the shell searches for it in the list of shell builtins.

If there exists a shell builtin by that name, the builtin is invoked.

2. If the first character of the command is none of a slash (\\), dot (.\), nor builtin, SShell searches each element of the PATH environmental variable for a directo
y containing an executable file by that name.
3. If the first character of the command is a slash (\\) or dot (.) or either of the above searches was successful, the shell executes the named program with any rema
ning arguments given in a separate execution environment.

## **Builtin Commands**

###### **exit**

Usage: exit (status) where status is an integer used to exit the shell.

Exits the shell.

If no argument is given, the command is interpreted as exit 0.

###### **env**

Usage: env

Prints the current environment.

# **Authors**
Wanjiku Karugi <w.karugi19@launchpad.com>
Wendy Omondi <w.omondi19@launchpad.com>
