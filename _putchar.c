#include "shell.h"
/**
*_putchar - prints the charater c 
*@c : the charater to be pushed.
*Return :  returns c.
*/

int _putchar(char c)
{
  return(write(1, &c, 1));
}

/**
*print_st - prints a string 
*@c : pointer to the string it is pointing to.
*Return : the number of i.
*/

int print_st(char* c)
{
  int i =0;

  while (c[i] != '\0')
  {
    _putchar(c[i]);
    i++;
  }
  return (i);
}
