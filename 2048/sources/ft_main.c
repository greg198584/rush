/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:55:20 by igomez            #+#    #+#             */
/*   Updated: 2015/03/01 09:55:20 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_engine.h"

static int      ft_check(t_game *g)
{
    clear();
    mvprintw((g->winy - 1) >> 1, (g->winx - 15) >> 1, "Felicitation!");
    mvprintw(((g->winy - 1) >> 1) + 1, (g->winx - 40) >> 1,
                "Voulez vous continuer votre partie ? (y / n)");
    return (getch() == 'y');
}

static int      ft_loop(t_game *g)
{
        int	key;
        int     check;

        key = 0;
        check = 0;
        while (key != 27 && ft_canmove(g, -1))
        {
                clear();
                ft_getsize(g);
                if (!check && ft_checkvalue(g, WIN_VALUE))
                    if ((check = ft_check(g)) == 0)
                        break ;
                if (g->f)
                        mvprintw((g->winy - 1) >> 1, (g->winx - 20) >> 1,
                                "Fenetre trop petite.");
                else
                        ft_display(g);
                key = getch();
                refresh();
                ft_merge(g, key);
        }
        return (0);
}

int		main(int ac, char **av)
{
        t_game  g;
        int     i;

        srand(time(NULL));
        if (ac != 2 ||
            (ac == 2 && (av[1][1] != 0 || (unsigned int)av[1][0] - '4' > 9)))
            return (ft_fprintf(2, "Erreur: ./game_2048 N (n < 10)\n"));
        if ((i = -1) && ft_init(&g, av[1][0] - '0'))
        {
                ft_newvalue(&g);
                ft_newvalue(&g);
                ft_loop(&g);
        }
        clear();
        endwin();
        i = -1;
        while (++i < g.size)
            if (g.tab[i] >= (int)(enum e_const)WIN_VALUE)
                break ;
        free(g.tab);
        if (i == g.size)
            ft_fprintf(1, "L'objectif n'est pas atteint: %d\n", WIN_VALUE);
        return (0);
}
