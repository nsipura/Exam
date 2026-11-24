Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter dddf6vewg64f gtwthgdwthdwgefewehgwrekhwjwi | cat -e
dfewg$
$>./inter "rien" "cettephrasenecomparerien" | cat -e
rien$
$>./inter | cat -e
$
$>
$>./inter "rien" | cat -e
$
$>

Prototype / program

int main(int argc, char **argv);

#include <unistd.h>

static int	seen_before(char *s, char c, int upto)
{
	int	i;

	i = 0;
	while (i < upto)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	in_string(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (in_string(argv[2], argv[1][i])
				&& !seen_before(argv[1], argv[1][i], i))
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}