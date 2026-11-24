Assignment

Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it`s a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>

Prototype / program

int main(int argc, char **argv);

#include <unistd.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static void	process(char *s)
{
	int	i;
	int	start;

	i = 0;
	start = 1;
	while (s[i])
	{
		if (start && s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		else if (!start && s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		start = is_space(s[i]);
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		write(1, "\n", 1);
	i = 1;
	while (i < argc)
	{
		process(argv[i]);
		i++;
	}
	return (0);
}