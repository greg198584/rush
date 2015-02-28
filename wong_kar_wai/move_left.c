/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:52:33 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/28 19:04:52 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int	ft_move_left(t_game *g)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	while ((j = -1) && ++i < g->square)
	{
		while (++j < g->square)
		{
			if (g->tab[i * g->square + j] == 0)
			{
				x = j;
				while (x < g->square && g->tab[i * g->square + x] == 0)
					x++;
				if (x == g->square)
					j = g->square;
				else
				{
					g->tab[i * g->square + j] = g->tab[i * g->square + x];
					g->tab[i * g->square + x] = 0;
				}
			}
		}
	}
	return (1);
}
