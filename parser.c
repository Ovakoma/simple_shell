#include "shell.h"

/**
 * rem_nl - removes a newline character
 * input: string passed to function
 * Return: input without newline
 */
char *rem_nl(char *input)
{
      char *temp = input;

      temp = strtok(input, "\n");
      return (temp); 
}

/**
 * parser - removes delimeters(space) and newline
 * from command input for execution
 * @input: string input being received 
 * @bufcpy: copy of string input for other purposes
 * Return: void
 */
char **parser(char *input)
{
   char *token, *temp, **argv = NULL;
   int i = 0;

   if (!input)
      return (NULL);
   argv = malloc(sizeof(char) * _strlen(input));
   if (!argv)
   {
      perror("Logging out");
      return (NULL);
   }
   input = rem_nl(input);
   temp = _strdup(input);
   token = strtok(temp, " ");

   while (token)
   {
      argv[i] = _strdup(token);
      token = strtok(NULL, " ");
   }
   argv[i] = NULL;
   free(temp);
   return (argv);
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
         if (env[i][j] == '=' && env[i][j] != *var)
               return ((*(env + i) + ++j));
         i++;
   }
   return (NULL);
}
