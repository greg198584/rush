/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 08:12:55 by igomez            #+#    #+#             */
/*   Updated: 2015/02/25 08:24:25 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENGINE_H
# define FT_ENGINE_H

# define NEWVALUEPERCENT        50
# define OFFSET			31

# include <curses.h>
# include <stdlib.h>
# include <time.h>

enum	e_const
{
        WIN_VALUE = 2048
};

typedef struct                  s_game
{
        int                     f;
        int                     *tab;
        int                     size;
        int                     square;
        int                     col;
        int                     line;
        int                     winx;
        int                     winy;
        int                     tilex;
        int                     tiley;
}                               t_game;

int             ft_init(t_game *g);
int             ft_getcolor(int i);
int             ft_merge(t_game *g, int move);
int             ft_move(t_game *g, int key);
int             ft_newvalue(t_game *g);
int             ft_display(t_game *g);
int             ft_getsize(t_game *g);
int             ft_checkvalue(t_game *g, int value);

int             ft_fprintf(int fd, char const *format, ...);

#endif
