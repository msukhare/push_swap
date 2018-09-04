/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_in_pile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:22:37 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/13 16:52:32 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_swap_in_pile(t_pile **pile, int act)
{
	t_pile	*tmp;

	if (!(*pile) || ft_lenlst(*pile) <= 1)
		return ;
	tmp = (*pile)->next;
	(*pile)->next = (*pile)->next->next;
	tmp->next = (*pile);
	(*pile) = tmp;
	if (act == 1)
		ft_putstr("sa\n");
	else if (act == 2)
		ft_putstr("sb\b");
}
