Assignment

Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.

Prototype / program

int     *ft_range(int start, int end);

#include <stdlib.h>

int	*ft_range(int start, int end)
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
	if (start <= end)
		step = 1;
	else
		step = -1;
	while (i < len)
	{
		arr[i] = start + i * step;
		i++;
	}
	return (arr);
}