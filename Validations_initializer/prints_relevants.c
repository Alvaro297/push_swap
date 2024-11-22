/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_relevants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 11:48:23 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-22 11:48:23 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_error(char *message)
{
	ft_printf("\033[1;31mError: %s\033[0m\n", message);
	exit(1);
}

void	print_info(char *message)
{
	ft_printf("\033[1;33mInfo: %s\033[0m\n", message);
	exit(1);
}
