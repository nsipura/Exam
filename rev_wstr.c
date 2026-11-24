Assignment

Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn`t gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>

Prototype / program

int main(int argc, char **argv);

#include <unistd.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	main(int argc, char **argv)
{
	int	i;
	int	end;
	int	start;
	int	first;

	if (argc == 2)
	{
		end = 0;
		while (argv[1][end])
			end++;
		first = 1;
		while (end > 0)
		{
			while (end > 0 && is_space(argv[1][end - 1]))
				end--;
			if (end == 0)
				break ;
			start = end;
			while (start > 0 && !is_space(argv[1][start - 1]))
				start--;
			if (!first)
				write(1, " ", 1);
			first = 0;
			i = start;
			while (i < end)
			{
				write(1, &argv[1][i], 1);
				i++;
			}
			end = start;
		}
	}
	write(1, "\n", 1);
	return (0);
}