/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_six.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:05:19 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/18 11:20:14 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pile	*ft_get_to_push(t_pile *a, t_data *data)
{
	while (a)
	{
		if (a->place < (data->max_ele - 2))
			return (a);
		a = a->next;
	}
	return (NULL);
}

void			ft_sort_six(t_pile **a, t_pile **b, t_data *data)
{
	t_pile		*push;

	if (ft_check_tri(*a) == 1 && !(*b))
		return ;
	if ((push = ft_get_to_push(*a, data)))
	{
		if (ft_check_side(*a, push) < ft_check_side(push, NULL))
			while ((*a) && (*a) != push)
				ft_rotate(a, 1);
		else
			while ((*a) && (*a) != push)
				ft_rev_rot(a, 1);
		ft_push(a, b, 2);
	}
	else
	{
		ft_sort_tree(a, &push);
		ft_insertion_sort(a, b);
	}
	ft_sort_six(a, b, data);
}
