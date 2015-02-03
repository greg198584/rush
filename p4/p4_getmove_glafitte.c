/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4_getmove_glafitte.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 14:24:50 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/03 16:17:29 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puiss4.h"

int		p4_getmove_yourlogin(t_grid *grid, t_case color, int turn_count)
{

	(void)grid;
	(void)color;
	(void)turn_count;
	int	move;

	move = 0x41;
	return (move);
}

int		p4_getmove_ia(t_grid *grid, t_case color, int turn_count)
{
	int		move;

	(void)grid;
	(void)color;
	(void)turn_count;
	static int start;

	start = 0;
	move = 0;
	if (start == 0)
	{
		start = 1;
		return (3);
	}
	// TODO: find out what's the best move toward winning the game
	return (move);
}
