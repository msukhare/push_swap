/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:10:54 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/13 16:50:20 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_rev_rot(t_pile **pile, int act)
{
	t_pile	*end;
	t_pile	*tmp;

	if (!(*pile) || ft_lenlst(*pile) <= 1)
		return ;
	end = *pile;
	while (end->next)
	{
		tmp = end;
		end = end->next;
	}
	tmp->next = NULL;
	end->next = *pile;
	*pile = end;
	if (act == 1)
		ft_putstr("rra\n");
	else if (act == 2)
		ft_putstr("rrb\n");
}
