/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:14:26 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/28 16:51:40 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

int	ft_merge_right(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	ft_move_right(g);
	while (++i < g->square)
	{
		j = g->square;
		while (--j > 0)
		{
			if (g->tab[i * g->square + j] == g->tab[i * g->square + j - 1])
			{
				g->tab[i * g->square + j] <<= 1;
				g->tab[i * g->square + j - 1] = 0;
			}
		}
	}
	ft_move_right(g);
	return (ft_newvalue(g));
}

int	ft_merge_left(t_game *g)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	ft_move_left(g);
	while (++i < g->square)
	{
		j = -1;
		while (++j < g->square)
		{
			if (g->tab[i * g->square + j] == g->tab[i * g->square + j + 1])
			{
				g->tab[i * g->square + j] <<= 1;
				g->tab[i * g->square + j + 1] = 0;
			}
		}
	}
	ft_move_left(g);
	return (ft_newvalue(g));
}

int	ft_merge_up(t_game *g)
{
	int	i;
	int	j;

	j = -1;
	ft_move_up(g);
	while (++j < g->square)
	{
		i = -1;
		while (++i < g->square)
		{
			if (g->tab[i * g->square + j] == g->tab[(i + 1) * g->square + j])
			{
				g->tab[i * g->square + j] <<= 1;
				g->tab[(i + 1) * g->square + j] = 0;
			}
		}
	}
	ft_move_up(g);
	return (ft_newvalue(g));
}

int	ft_merge_down(t_game *g)
{
	int	i;
	int	j;
	int	x;

	j = -1;
	ft_move_down(g);
	while (++j < g->square)
	{
		i = g->square;
		while (--i > 0)
		{
			if (g->tab[i * g->square + j] == g->tab[(i - 1) * g->square + j])
			{
				g->tab[i * g->square + j] <<= 1;
				g->tab[(i - 1) * g->square + j] = 0;
			}
		}
	}
	ft_move_down(g);
	return (ft_newvalue(g));
}
