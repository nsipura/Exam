Assignment

Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there`s less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>

Prototype / program

int main(int argc, char **argv);

#include <unistd.h>
#include <stdlib.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char **argv)
{
	char	**words;
	int		count;
	int		i;
	int		j;
	int		k;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	count = 0;
	i = 0;
	while (argv[1][i])
	{
		while (argv[1][i] && is_space(argv[1][i]))
			i++;
		if (argv[1][i])
			count++;
		while (argv[1][i] && !is_space(argv[1][i]))
			i++;
	}
	if (count == 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	words = malloc(sizeof(char *) * count);
	if (!words)
		return (0);
	i = 0;
	k = 0;
	while (argv[1][i])
	{
		while (argv[1][i] && is_space(argv[1][i]))
			i++;
		if (!argv[1][i])
			break ;
		int start = i;
		while (argv[1][i] && !is_space(argv[1][i]))
			i++;
		words[k] = malloc(sizeof(char) * (i - start + 1));
		j = 0;
		while (start < i)
			words[k][j++] = argv[1][start++];
		words[k][j] = '\0';
		k++;
	}
	k = 1;
	while (k < count)
	{
		j = 0;
		while (words[k][j])
		{
			write(1, &words[k][j], 1);
			j++;
		}
		write(1, " ", 1);
		k++;
	}
	j = 0;
	while (words[0][j])
	{
		write(1, &words[0][j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}