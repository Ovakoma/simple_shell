#include "shell.h"

/**
 * _strcpy - copies the content of a string to another
 * @dest: destination string
 * @str: string to copy or source string
 * Return: pointer to destination string
 */
char *_strcpy(char *dest, char *str)
{
	size_t i = 0;

	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 0(success), -1 if str1 < str2
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while ((str1[i] == str2[i]) && str1[i])
		i++;

	if (str1[i] > str2[i])
		return (1);
	if (str1[i] < str2[i])
		return (-1);
	return (0);
}

/**
 * _strcat - concatenates two strings
 * @s1: string one
 * @s2: second string
 * Return: concatenated string
 */
char *_strcat(char *s1, const char *s2)
{
	int i = 0, len;

	len = _strlen(s1);

	while (s2[i])
		s1[len++] = s2[i++];
	s1[len] = '\0';

	return (s1);
}

/**
 * _strlen - returns string length
 * @str: string passed to function
 * Return: length of string
 */
int _strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i] != 0; i++)
		;
	return (i);
}

/**
 * _strdup - duplicates a string
 * @str: string passed to function
 * Return: pointer to duplicated string
 */
char *_strdup(const char *str)
{
	size_t size = _strlen(str);
	char *dest;

	if (!str)
		return (NULL);
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	_memcpy(dest, str, size + 1);

	return (dest);
}
