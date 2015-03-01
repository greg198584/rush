/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:53:56 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/28 19:05:10 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_engine.h"

static int      ft_moveup(t_game *g)
{
    int i;
    int j;
    int x;

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

static int      ft_movedown(t_game *g)
{
    int i;
    int j;
    int x;

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

static int          ft_moveright(t_game *g)
{
    int i;
    int j;
    int x;

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

static int          ft_moveleft(t_game *g)
{
    int i;
    int j;
    int x;

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

int                 ft_move(t_game *g, int key)
{
    if (key == KEY_UP)
        return (ft_moveup(g));
    if (key == KEY_DOWN)
        return (ft_movedown(g));
    if (key == KEY_RIGHT)
        return (ft_moveright(g));
    if (key == KEY_LEFT)
        return (ft_moveleft(g));
    return (-1);
}