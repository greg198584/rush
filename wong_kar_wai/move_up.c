/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:53:56 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/28 19:05:10 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int	ft_move_up(t_game *g)
{
	int	i;
	int	j;
	int	x;

	j = -1;
	while ((i = -1) && ++j < g->square)
	{
		while (++i < g->square)
		{
			if (g->tab[i * g->square + j] == 0)
			{
				x = i;
				while (x < g->square && g->tab[x * g->square + j] == 0)
					x++;
				if (x == g->square)
					i = g->square;
				else
				{
					g->tab[i * g->square + j] = g->tab[x * g->square + j];
					g->tab[x * g->square + j] = 0;
				}
			}
		}
	}
	return (1);
}
