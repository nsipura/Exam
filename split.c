Assignment

Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);

Prototype / program

char    **ft_split(char *str);

#include <stdlib.h>

static int	is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	count_words(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i]))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_sep(str[i]))
			i++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**res;
	int		i;
	int		start;
	int		w;

	res = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!res)
		return (NULL);
	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i]))
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && !is_sep(str[i]))
			i++;
		res[w] = malloc(sizeof(char) * (i - start + 1));
		if (!res[w])
			return (NULL);
		{
			int	k;
			int	s;

			k = 0;
			s = start;
			while (s < i)
				res[w][k++] = str[s++];
			res[w][k] = '\0';
		}
		w++;
	}
	res[w] = NULL;
	return (res);
}