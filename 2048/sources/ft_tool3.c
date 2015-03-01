/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:55:20 by igomez            #+#    #+#             */
/*   Updated: 2015/03/01 09:55:20 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_engine.h"

static int      ft_r(t_game *g)
{
    int i;
    int j;

    i = 0;
    while (i < g->size)
    {
        j = -1;
        while (++j < g->square - 1)
        {
            if (!g->tab[i + j])
                continue ;
            if (g->tab[i + j] == g->tab[i + j + 1] || !g->tab[i + j + 1])
                return (1);
        }
        i += g->square;
    }
    return (0);
}

static int      ft_l(t_game *g)
{
    int i;
    int j;

    i = g->square;
    while (i <= g->size)
    {
        j = 0;
        while (++j < g->square)
        {
            if (!g->tab[i - j])
                continue ;
            if (g->tab[i - j] == g->tab[i - j - 1] || !g->tab[i - j - 1])
                return (1);
        }
        i += g->square;
    }
    return (0);
}

static int      ft_d(t_game *g)
{
    int i;
    int j;

    i = -1;
    while (++i < g->square)
    {
        j = -1;
        while (++j < g->square - 1)
        {
            if (!g->tab[i + j * g->square])
                continue ;
            if (g->tab[i + j * g->square] == g->tab[i + (j + 1) * g->square])
                return (1);
            if (!g->tab[i + (i + 1) * g->square])
                return (1);
        }
    }
    return (0);
}

static int      ft_u(t_game *g)
{
    (void)g;
    return (1);
//    int i;
//    int j;

//    i = -1;
//    while (++j <
}


int             ft_canmove(t_game *g, int key)
{
    if (key == KEY_UP)
        return (ft_u(g));
    if (key == KEY_DOWN)
        return (ft_d(g));
    if (key == KEY_RIGHT)
        return (ft_r(g));
    if (key == KEY_LEFT)
        return (ft_l(g));
    return (ft_u(g) || ft_d(g) || ft_r(g) || ft_l(g));
}
