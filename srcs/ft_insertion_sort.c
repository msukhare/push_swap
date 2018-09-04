/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:19:09 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/13 17:04:11 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pile	*ft_get_high_link(t_pile *b)
{
	t_pile		*to_ret;

	to_ret = b;
	while (b)
	{
		if (to_ret->place < b->place)
			to_ret = b;
		b = b->next;
	}
	return (to_ret);
}

int				ft_check_side(t_pile *start, t_pile *end)
{
	int			mv;

	mv = 0;
	while (start && start != end)
	{
		mv++;
		start = start->next;
	}
	return (mv);
}

void			ft_insertion_sort(t_pile **a, t_pile **b)
{
	t_pile		*max;

	while (*b)
	{
		max = ft_get_high_link(*b);
		if (ft_check_side(*b, max) < ft_check_side(max, NULL))
		{
			while ((*b) && (*b) != max)
				ft_rotate(b, 2);
		}
		else
		{
			while ((*b) && (*b) != max)
				ft_rev_rot(b, 2);
		}
		(*b)->push = 1;
		ft_push(b, a, 1);
	}
}
