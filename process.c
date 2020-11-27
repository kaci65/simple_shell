#include "shell.h"

/**
 * _process - prints PATH when commands/arguments are entered
 * @args: points to an array of pointers to strings
 * Return: 0 if successful
 */
int _process(char **args)                                        
{                                                             
                                                              
  int pid;                                                  
  int child;                                                
  int status;                                               
                                                              
  child = fork();                                           
                                                              
  if (child == 0)                                           
    {                                                       
      if (execvp(args [0], args) < 0)                       
	{                                                   
	  printf("comand not found: %s\n", args[0]);        
	  exit(EXIT_FAILURE);                               
	}                                                   
      else if (child < 0)                                   
	printf("error forking\n");                          
                                                              
      sleep (3);                                            
    }                                                       
  else                                                      
    {                                                       
      wait(&status);                                        
    }                                                       
  return (1);                                               
                                                              
} 
