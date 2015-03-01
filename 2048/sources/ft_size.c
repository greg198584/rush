/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:55:20 by igomez            #+#    #+#             */
/*   Updated: 2015/03/01 09:55:20 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_engine.h"

static int	ft_nbrlen(int n)
{
    int i;

    i = (n < 0);
    while (n != 0 && ++i)
        n /= 10;
    return (i);
}

static int	ft_getmaxsize(t_game *g)
{
        int		i;
        int		j;
        int		ret;
        int		tmp;

        ret = 1;
        i = -1;
        while (++i < g->line)
        {
                j = -1;
                while (++j < g->col)
                {
                        tmp = ft_nbrlen(g->tab[i * g->square + j]);
                        if (tmp > ret)
                                ret = tmp;
				}
        }
        return (ret);
}

int			ft_getsize(t_game *g)
{
        int		val;

        g->f = 0;
        getmaxyx(stdscr, g->winy, g->winx);
        if ((g->winy - (2 * g->line + 1)) < 0)
                g->f = 1;
        else
                g->tiley = (g->winy - (g->line + 1)) / g->line;
        val = ft_getmaxsize(g);
        if ((g->winx - (g->col * (val + 1) + 1)) < 0)
                g->f = 1;
        else
                g->tilex = (g->winx - (g->col + 1)) / g->col;
        return (1);
}