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
 * _getenv - get the value of an environmental variable
 * @var: variable name
 * Return: variable name
 */
char *_getenv(const char *var)
{
   int i = 0, j = 0;

   while (environ[i])
   {
         while (environ[i][j] && *var)
         {
            if (environ[i][j] != *var || (environ[i][j] == '='))
                  break;
            j++;
            var++;
         }
         if (environ[i][j] == '=' && environ[i][j] != *var)
               return ((*(environ + i) + ++j));
         i++;
   }
   return (NULL);
}
