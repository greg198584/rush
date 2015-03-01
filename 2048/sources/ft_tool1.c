/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:55:20 by igomez            #+#    #+#             */
/*   Updated: 2015/03/01 09:55:20 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_engine.h"

int	ft_checkvalue(t_game *g, int value)
{
	int	i;

	if (g != NULL && g->tab != NULL && (i = -1))
		while (++i < g->size)
			if (g->tab[i] == value)
				return (1);
	return (0);
}