#include "../push_swap.h"

void	are_all_numbers(int size, char **nbrs)
{
	int i;
	int j;

	i = 0;
	while (i <= size)
	{
		j = 0;
		if (nbrs[i][j] == "-" || nbrs[i][j] == "+")
			j++;
		while (nbrs[i][j])
		{
			if (ft_isdigit(nbrs[i][j]) == 0)
			{
				print_error(ERROR_1);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int		duplicate(t_node *a, int n)
{
	if (!a) //Check for an empty stack
		print_error (ERROR_4);
	while (a != NULL)
	{
		if (a->number == n)
			return (0);
		a = a->next;
	}
	return (1);
}

void	init_validations(t_node **a,char **nbrs)
{
	size_t len;
	long	n;
	int		i;

	i = 0;
	len = ft_strlen_push_swap(nbrs);
	are_all_numbers(len, nbrs);
	while (nbrs[i])
	{
		n = ft_atol(nbrs[i]);
		if (n > INT_MAX || n < INT_MIN)
			print_error(ERROR_3);
		if (duplicate(*a, (int)n))
			print_error(ERROR_2);
		append_node(a, (int)n);
		i++;
	}
}

void	already_sorted(t_node *a)
{
	if (a == NULL || a->next == NULL)
		return ;
	t_node *tmp;

	tmp = a->next;
	while (tmp->next != NULL)
	{
		if (a->number < tmp->number)
		{
			a = a->next;
			tmp = tmp->next;
		}
		else
			return ;
	}
	print_info(INFO_1);
}

int		ft_stack_len(t_node *head)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		head = head->next;
		count++;
	}
	return (count);
}
