#include "shell.h"

/**
 * free_p - frees pointer
 * ptr: pointer to be freed
 */
void free_p(char *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	ptr = NULL;
}

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

/**
 * _isalpha - checks if a character is a letter
 * @c: the given character
 *
 * Return: 0 if true, else 1
 */
int _isalpha(char c)
{
        if ((c >= 48) && (c <= 57))
                return (1);
        return (0);
}

/**
 * _atoi - converts string to integer.
 * @str: string to be converted.
 *
 * Return: int.
 */
int _atoi(char *str)
{
	int len = 0, i = 0, FLAG = 0, d = 0, n = 0, digit;

	while (str[len] != '\0')
            len++;

	while (i < len && FLAG == 0)
	{
		if (str[i] == '-')
			++d;

		if (str[i] >= 48 && str[i] <= 57)
		{
			digit = str[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			FLAG = 1;
			if (str[i + 1] < 48 || str[i + 1] > 57)
				break;
			FLAG = 0;
		}
		i++;
	}
	if (FLAG == 0)
		return (0);

	return (n);
}
