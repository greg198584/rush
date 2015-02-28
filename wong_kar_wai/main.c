/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glafitte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:15:43 by glafitte          #+#    #+#             */
/*   Updated: 2015/02/28 15:39:50 by glafitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wkw.h"

void	ft_debug(t_game *g)
{
	int i;

	i = -1;
	while (++i < g->size)
	{
		if (!(i % 4))
			ft_fprintf(1, "\n");
		ft_fprintf(1, "%d ", g->tab[i]);
	}
	ft_fprintf(1, "\n---------\n");

}

int		ft_checkvalue(t_game *g, int value)
{
	int	i;

	if (g != NULL && g->tab != NULL && (i = -1))
		while (++i < g->size)
			if (g->tab[i] == value)
				return (1);
	return (0);
}

int		ft_newvalue(t_game *g)
{
	int	value;
	int	i;

	if (g == NULL || g->tab == NULL || !ft_checkvalue(g, 0))
		return (0);
	value = ((rand() % 2) + 1) << 1;
	while (g->tab[(i = rand() % g->size)] != 0)
		continue ;
	g->tab[i] = value;
	return (1);
}

int		main(void)
{
	t_game g;

	srand(time(NULL));
	g.square = 4;
	g.size = g.square * g.square;
	if ((g.tab = (int *)malloc(sizeof(int) * g.size)) == NULL)
		return (write(1, "Error\n", 6));
	ft_newvalue(&g);
	ft_newvalue(&g);
	ft_debug(&g);
	int x = 0;
	while (x++ != 5 && ft_checkvalue(&g, 0) && !ft_checkvalue(&g, 2048))
		ft_newvalue(&g);
	ft_debug(&g);
	if (ft_checkvalue(&g, (enum e_const)WIN_VALUE))
		ft_fprintf(1, "Vous avez gagner\n");
	else
		ft_fprintf(1, "Game Over!\n");
	ft_move_right(&g);
	ft_move_left(&g);
	ft_move_down(&g);
	ft_move_up(&g);
	if (g.tab != NULL)
		free(g.tab);
	return (0);
}
