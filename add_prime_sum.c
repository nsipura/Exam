Assignment

Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

Prototype / program

int main(int argc, char **argv);

#include <unistd.h>

static void	putnbr(int n)
{
	char	c;

	if (n >= 10)
		putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

static int	ft_atoi(char *s)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res);
}

static int	is_prime(int n)
{
	int	i;

	if (n < 2)
		return (0);
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	n;
	int	sum;
	int	i;

	sum = 0;
	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		i = 2;
		while (i <= n)
		{
			if (is_prime(i))
				sum += i;
			i++;
		}
	}
	putnbr(sum);
	write(1, "\n", 1);
	return (0);
}