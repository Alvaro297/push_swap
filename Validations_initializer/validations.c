/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:48:29 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:48:29 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	are_all_numbers(int size, char **nbrs, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		if (nbrs[i][j] == '-' || nbrs[i][j] == '+')
			j++;
		while (nbrs[i][j])
		{
			if (ft_isdigit(nbrs[i][j]) == 0)
			{
				if (argc == 2)
					free_split(nbrs);
				print_error(NULL);
			}
			j++;
		}
		i++;
	}
}

int	duplicate(t_node *a, int n)
{
	while (a)
	{
		if (a->number == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	init_validations(t_node **a, char **nbrs, int argc)
{
	size_t	len;
	long	n;
	int		i;

	i = 0;
	len = ft_strlen_push_swap(nbrs);
	are_all_numbers(len, nbrs, argc);
	while (nbrs[i])
	{
		n = ft_atol(nbrs[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			if (argc == 2)
				free_split(nbrs);
			print_error(a);
		}
		if (duplicate(*a, (int)n) == 1)
			print_error(a);
		append_node(a, (int)n);
		++i;
	}
}

bool	already_sorted(t_node *a)
{
	t_node	*tmp;

	if (a == NULL || a->next == NULL)
		return (true);
	tmp = a->next;
	while (tmp != NULL)
	{
		if (a->number > tmp->number)
			return (false);
		a = a->next;
		tmp = tmp->next;
	}
	return (true);
}

int	ft_stack_len(t_node *head)
{
	t_node	*current;
	int		count;

	count = 0;
	current = head;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}
