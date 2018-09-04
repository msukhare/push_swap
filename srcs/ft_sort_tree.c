/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:16:34 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/16 11:18:24 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_check_sup(t_pile *pile)
{
	t_pile		*tmp;

	tmp = pile;
	while (tmp)
	{
		if (tmp->place > pile->place)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void			ft_sort_tree(t_pile **a, t_pile **b)
{
	if (ft_check_tri(*a) == 1 && !(*b))
		return ;
	if ((*a)->next && (*a)->val < (*a)->next->val)
		ft_swap_in_pile(a, 1);
	else if ((*a)->val > (*a)->next->val && ft_check_sup(*a) == 0)
		ft_swap_in_pile(a, 1);
	if (ft_check_sup(*a) == 1)
		ft_rotate(a, 1);
	ft_sort_tree(a, b);
}
