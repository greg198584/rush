/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:52:51 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/28 19:04:02 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int	ft_move_right(t_game *g)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	while ((j = g->square) && ++i < g->square)
	{
		while (--j >= 0)
		{
			if (g->tab[i * g->square + j] == 0)
			{
				x = j;
				while (x >= 0 && g->tab[i * g->square + x] == 0)
					x--;
				if (x == -1)
					j = 0;
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
