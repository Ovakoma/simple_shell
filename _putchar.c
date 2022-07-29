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
