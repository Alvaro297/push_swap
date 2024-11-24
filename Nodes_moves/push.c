/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:48:57 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:48:57 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_x(t_node **stack_src, t_node **stack_dest, char c)
{
	t_node	*node_to_push;

	if (NULL == *stack_src)
		return ;
	node_to_push = *stack_src;
	*stack_src = (*stack_src)->next;
	if (*stack_src)
		(*stack_src)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *stack_dest)
	{
		*stack_dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *stack_dest;
		node_to_push->next->prev = node_to_push;
		*stack_dest = node_to_push;
	}
	set_current_position(*stack_dest, *stack_src);
	ft_printf("p%c\n", c);
}

void	set_current_position(t_node *stack_dest, t_node *stack_src)
{
	int		i;
	t_node	*current;

	current = stack_dest;
	i = 0;
	while (current != NULL)
	{
		current->index = i;
		i++;
		current = current->next;
	}
	i = 0;
	current = stack_src;
	while (current != NULL)
	{
		current->index = i;
		i++;
		current = current->next;
	}
}
