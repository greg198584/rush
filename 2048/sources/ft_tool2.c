/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 09:55:20 by igomez            #+#    #+#             */
/*   Updated: 2015/03/01 09:55:20 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_engine.h"

int     ft_newvalue(t_game *g)
{
    int value;
    int i;

    if (g == NULL || g->tab == NULL || !ft_checkvalue(g, 0))
        return (0);
    value = (1 + (((rand() % 100) > NEWVALUEPERCENT))) << 1;
    while (g->tab[(i = rand() % g->size)] != 0)
        continue ;
    g->tab[i] = value;
    return (1);
}
