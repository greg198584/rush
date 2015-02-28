/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:35:24 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/28 15:39:26 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int	ft_move_right(t_game *g)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	while (++i < g->square)
	{
		j = g->square;
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
	ft_debug(g);
}

int	ft_move_left(t_game *g)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	while (++i < g->square)
	{
		j = -1;
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
	ft_debug(g);
}

int	ft_move_up(t_game *g)
{
	int	i;
	int	j;
	int	x;

	j = -1;
	while (++j < g->square)
	{
		i = -1;
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
	ft_debug(g);
}

int	ft_move_down(t_game *g)
{
	int	i;
	int	j;
	int	x;

	j = -1;
	while (++j < g->square)
	{
		i = g->square;
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
	ft_debug(g);
}
