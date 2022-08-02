#include "shell.h"

/**
 * parser - removes delimeters(space) and newline
 * from command input for execution
 * @input: string input being received 
 * @bufcpy: copy of string input for other purposes
 * Return: void
 */
 void parser(char *input, char *bufcpy)
 {
    char *token;
    char delim[] = " \n", **argv = NULL;
    int n_token = 0, i;

    token = strtok(input, delim);
    while (token)
    {
      n_token++;
      token = strtok(NULL, delim);
    }
    n_token++;
    argv = malloc(sizeof(char *) * n_token);
    token = strtok(bufcpy, delim);
    for (i = 0; token; i++)
    {
         argv[i] = malloc(sizeof(char) * _strlen(token));
         _strcpy(argv[i], token);
         token = strtok(NULL, delim);

         if (token == NULL)
         {
               i++;
               argv[i] = NULL;
         }
    }
    hsh_exec(argv);
    free(argv);
    free(token);
 }

/**
 * hsh_exec - executes users parsed input
 * @argv: argument passed to function
 */
 void hsh_exec(char **argv)
 {
      pid_t pid = fork();

      if (pid != 0)
      {
            wait(NULL);
            hsh_readline();
      }
      else
      {
            if (execve(argv[0], argv, NULL) == -1)
                  perror("No such file or directory");
      }
      execve(argv[0], argv, NULL);
 }

/**
 * _getenv - get the value of an environmental variable
 * @var: variable name
 * Return: variable name
 */
char *_getenv(const char *var)
{
   int i = 0, j = 0;

   while (env[i])
   {
         while (env[i][j] && *var)
         {
            if (env[i][j] != *var || (env[i][j] == '='))
                  break;
            j++;
            var++;
         }
         if (env[i][j] == '=' && != *name)
               return ((*(env + i) + ++j));
         i++;
   }
   return (NULL);
}