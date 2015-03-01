/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:14:26 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/28 18:57:17 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_engine.h"

static int	ft_merge_right(t_game *g, int key)
{
	int	i;
	int	j;

	i = -1;
	ft_move(g, key);
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
	ft_move(g, key);
	return (ft_newvalue(g));
}

static int	ft_merge_left(t_game *g, int key)
{
	int	i;
	int	j;

	i = -1;
	ft_move(g, key);
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
	ft_move(g, key);
	return (ft_newvalue(g));
}

static int	ft_merge_up(t_game *g, int key)
{
	int	i;
	int	j;

	j = -1;
	ft_move(g, key);
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
	ft_move(g, key);
	return (ft_newvalue(g));
}

static int	ft_merge_down(t_game *g, int key)
{
	int	i;
	int	j;

	j = -1;
	ft_move(g, key);
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
	ft_move(g, key);
	return (ft_newvalue(g));
}

int			ft_merge(t_game *g, int key)
{
	if (key == KEY_RIGHT)
		ft_merge_right(g, key);
	else if (key == KEY_LEFT)
		ft_merge_left(g, key);
	else if (key == KEY_UP)
		ft_merge_up(g, key);
	else if (key == KEY_DOWN)
		ft_merge_down(g, key);
	return (-1);
}
