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

int		ft_loop(t_game *g)
{
        int	key;

        key = 0;
        while (key != 27)
        {
                clear();
                ft_getsize(g);
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

#include <unistd.h>
int		main(void)
{
        t_game  g;

        srand(time(NULL));
        if (ft_init(&g))
        {
                ft_newvalue(&g);
                ft_newvalue(&g);
                ft_loop(&g);
        }
        clear();
        endwin();
        return (0);
}
