#include <stdio.h>
#include <stdlib.h>

/**
*_free: it frees up buffers.
*@c- the buffer to be freed
*Return - doent return anything
*/

void _free(char **buff)
{
    int i;
    if (!buff || buff == NULL)
        return ;
    while(buff[i])
    {
	free(buff[i]);
        i++;
    }
    free(buff);
}
