#include <stdio.h>
/**
*


int _free(char **c)
{
    int i;
    if (!c || c == NULL)
      return ;
    while(c[i])
     {
      free (c[i]);
      i++;
     }
     free(c);
     
   return 0;
}
