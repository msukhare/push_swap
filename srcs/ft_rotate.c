/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:56:56 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/13 16:51:46 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_rotate(t_pile **pile, int act)
{
	t_pile	*tmp;
	t_pile	*index;

	if (!(*pile) || ft_lenlst(*pile) <= 1)
		return ;
	tmp = *pile;
	(*pile) = (*pile)->next;
	tmp->next = NULL;
	index = (*pile);
	while (index->next)
		index = index->next;
	index->next = tmp;
	if (act == 1)
		ft_putstr("ra\n");
	else if (act == 2)
		ft_putstr("rb\n");
}
