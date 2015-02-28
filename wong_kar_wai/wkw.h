/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:21:06 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/28 19:09:03 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WKW_H
# define WKW_H

# include <curses.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define DEFAULT	0x00
# define RIGTH		0x01
# define LEFT		0x02
# define UP			0x03
# define DOWN		0x04

enum				e_const
{
	WIN_VALUE = 2048
};

typedef struct		s_game
{
	int				*tab;
	int				size;
	int				square;
}					t_game;

typedef struct		s_color
{
	int				key;
	int				color;
}					t_color;

int					ft_checkvalue(t_game *g, int value);
int					ft_newvalue(t_game *g);
int					ft_debug(t_game *g);
int					ft_fprintf(int fd, char const *format, ...);
int					ft_merge(t_game *g, int move);
int					ft_move_down(t_game *g);
int					ft_move_right(t_game *g);
int					ft_move_left(t_game *g);
int					ft_move_up(t_game *g);

#endif
