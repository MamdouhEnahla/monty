#include "monty.h"

/**
 * _strlen - Check code
 * @s: function arg
 * Return: integer value
 */
int _strlen(char *s)
{
	int ptr = 0;

	if (*s)
		ptr += _strlen(s + 1) + 1;

	return (ptr);
}

/**
 * _srch - search if a char is inside a string
 * @s: string to review
 * @c: char to find
 * Return: 1 if success 0 otherwise
 */
int _srch(char* s, char c)
{
  for (int i = 0; i < _strlen(s); i++) {
    if (s[i] == c) {
      return 1;
    }
  }
  return 0;
}
/**
 * _strtok - function that cut a string into tokens depending of the delimit
 * @s: string to cut in parts
 * @d: delimiters
 * Return: first partition or NULL
 */
char *_strtok(char *s, char *d)
{
	static char *ptr;
	int i = 0, j = 0;

	if (!s)
		s = ptr;
	while (s[i] != '\0')
	{
		if (_srch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ptr = s + i + 1;
			*ptr = '\0';
			s = s + j;
			return (s);
		}
		else if (_srch(d, s[i]) == 0 && _srch(d, s[i + 1]) == 0)
			i++;
		else if (_srch(d, s[i]) == 0 && _srch(d, s[i + 1]) == 1)
		{
			ptr = s + i + 1;
			*ptr = '\0';
			ptr++;
			s = s + j;
			return (s);
		}
		else if (_srch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
/**
 * _strcmp - compares two strings.
 * @s1: first str compared
 * @s2: second str compared
 * Return: 0 for success.
 */
int _strcmp(char *s1, char *s2)
{
	int ret = 0;

	while (*s1)
	{
		if (*s1 != *s2)
		{
			ret = (((int)*s1 - 48) - ((int)*s2 - 48));
			break;
		}
		s1++;
		s2++;
	}
	return (ret);
}
