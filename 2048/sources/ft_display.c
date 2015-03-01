/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:41:43 by igomez            #+#    #+#             */
/*   Updated: 2015/02/28 23:31:46 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_engine.h"

static int  ft_nbrlen(int n)
{
    int i;

    i = (n < 0);
    while (n != 0 && ++i)
        n /= 10;
    return (i);
}

static int	ft_drawtile(int i, int j, t_game *g)
{
        int		y;
        int		x;
        int		start_x;
        int		start_y;
        int		c;

        start_y = i * (g->tiley + 1);
        start_x = j * (g->tilex + 1);
        y = -1;
        while (++y < (g->tiley + 2))
        {
                x = -1;
                while (++x < (g->tilex + 2))
                {
                        if (!(y % (g->tiley + 1)) || !(x % (g->tilex + 1)))
                                c = ft_getcolor(-1);
                        else
                                c = ft_getcolor(g->tab[i * g->square + j]);
                        attron(COLOR_PAIR(c));
                        mvprintw(start_y + y, start_x + x, " ");
                        attroff(COLOR_PAIR(c));
                }
        }
        return (0);
}

static int	ft_drawvalue(int i, int j, t_game *g)
{
        int		sx;
        int		sy;
        int		v;

        v = g->tab[i * g->square + j];
        sy = i * (g->tiley + 1) + 1 + g->tiley / 2;
        sx = j * (g->tilex + 1) + 1 + (g->tilex - ft_nbrlen(v)) / 2;
        if (v)
        {
                attron(COLOR_PAIR(ft_getcolor(v)) | A_BOLD);
                mvprintw(sy, sx, "%d", v);
                attroff(COLOR_PAIR(ft_getcolor(v)) | A_BOLD);
        }
        return (1);
}

int		   ft_display(t_game *g)
{
        int		i;
        int		j;

        i = -1;
        clear();
        endwin();
        while ((j = -1) && ++i < g->line)
                while (++j < g->col)
                {
                        ft_drawtile(i, j, g);
                        ft_drawvalue(i, j, g);
                }
        return (0);
}
