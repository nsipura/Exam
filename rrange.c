Assignment

Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.

Prototype / program

int     *ft_rrange(int start, int end);

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	len;
	int	*arr;
	int	i;
	int	step;

	len = end - start;
	if (len < 0)
		len = -len;
	len++;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = 0;
	if (end >= start)
		step = -1;
	else
		step = 1;
	while (i < len)
	{
		arr[i] = end + i * step;
		i++;
	}
	return (arr);
}