/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:52:41 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/28 19:08:11 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int	ft_move_down(t_game *g)
{
	int	i;
	int	j;
	int	x;

	j = -1;
	while ((i = g->square) && ++j < g->square)
	{
		while (--i >= 0)
		{
			if (g->tab[i * g->square + j] == 0)
			{
				x = i;
				while (x >= 0 && g->tab[x * g->square + j] == 0)
					x--;
				if (x == -1)
					i = -1;
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
