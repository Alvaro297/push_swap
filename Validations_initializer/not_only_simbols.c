/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_only_simbols.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-28 18:19:58 by alvamart          #+#    #+#             */
/*   Updated: 2024-11-28 18:19:58 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	not_only_simbols(int argc, char c, char **nbrs)
{
	if (c == '\0')
	{
		if (argc == 2)
			free_split(nbrs);
		print_error(NULL);
	}
}
