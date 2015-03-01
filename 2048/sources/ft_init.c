/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:55:20 by igomez            #+#    #+#             */
/*   Updated: 2015/03/01 09:55:20 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_engine.h"

static int      ft_definecolor(void)
{
        init_color(OFFSET + 0x00, 000, 000, 000);
        init_color(OFFSET + 0x01, 999, 999, 999);
        init_color(OFFSET + 0x02, 466, 431, 392);
        init_color(OFFSET + 0x03, 976, 959, 948);
        init_color(OFFSET + 0x04, 733, 678, 619);
        init_color(OFFSET + 0x05, 799, 752, 693);
        init_color(OFFSET + 0x06, 932, 893, 854);
        init_color(OFFSET + 0x07, 929, 878, 784);
        init_color(OFFSET + 0x08, 948, 693, 474);
        init_color(OFFSET + 0x09, 960, 584, 388);
        init_color(OFFSET + 0x0a, 964, 486, 372);
        init_color(OFFSET + 0x0b, 964, 368, 231);
        init_color(OFFSET + 0x0c, 929, 811, 446);
        init_color(OFFSET + 0x0d, 929, 800, 380);
        init_color(OFFSET + 0x0e, 929, 784, 313);
        init_color(OFFSET + 0x0f, 929, 772, 246);
        init_color(OFFSET + 0x10, 929, 760, 180);
        init_color(OFFSET + 0x11, 235, 225, 190);
        init_color(OFFSET + 0x12, 190, 190, 190);
        return (0);
}

static int     ft_initcolor(void)
{
        int i;

        ft_definecolor();
        init_pair(OFFSET + 0, OFFSET + 1, OFFSET + 0);
        init_pair(OFFSET + 1, OFFSET + 0, OFFSET + 1);
        i = 1;
        while (++i < 19)
                init_pair(OFFSET + i, OFFSET + 2 + (i < 9), OFFSET + i);
        return (0);
}

static int      ft_isvalide(void)
{
        int i;

        if ((i = (WIN_VALUE << 1)) < 4)
                return (0);
        while ((i >>= 1) > 1)
                if (i & 1)
                        return (0);
        return (1);
}

int             ft_init(t_game *g, int squ)
{
        int i;

        initscr();
        noecho();
        cbreak();
        raw();
        curs_set(FALSE);
        keypad(stdscr, TRUE);
        if (!can_change_color() && !has_colors() && !ft_isvalide())
                return (0);
        start_color();
        ft_initcolor();
        g->f = 0;
        g->square = squ;
        g->size = g->square * g->square;
        g->line = g->square;
        g->col = g->square;
        if ((g->tab = (int *)malloc(sizeof(int) * g->size)) == NULL)
                return (0);
        i = -1;
        while (++i < g->size)
                g->tab[i] = 0;
        return (1);
}
