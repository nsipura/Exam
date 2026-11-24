Assignment

Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>

Prototype / program

(see subject - prototype in assignment text)

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*curr;
	t_list	*prev;
	t_list	*next;

	curr = *begin_list;
	prev = NULL;
	while (curr)
	{
		next = curr->next;
		if (cmp(curr->data, data_ref) == 0)
		{
			if (prev)
				prev->next = next;
			else
				*begin_list = next;
			free(curr);
		}
		else
			prev = curr;
		curr = next;
	}
}