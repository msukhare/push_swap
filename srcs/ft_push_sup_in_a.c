/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_sup_in_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:40:48 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/13 17:59:04 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_get_high_place(t_pile *b)
{
	int			med;

	med = 0;
	while (b)
	{
		if (b->place >= med)
			med = b->place;
		b = b->next;
	}
	return (med);
}

static int		ft_check_sup(t_pile *b, int med)
{
	while (b)
	{
		if (b->place >= med && b->push == 0)
			return (1);
		b = b->next;
	}
	return (0);
}

void			ft_push_sup_in_a(t_pile **a, t_pile **b, t_data *data)
{
	int			med;

	if (!(*b))
		return ;
	if (ft_lenlst(*b) < 25)
		ft_insertion_sort(a, b);
	else
	{
		med = ((ft_get_high_place(*b) + data->pushed) / 2);
		ft_creat_med(med, data, a, b);
		while ((*b) && ft_check_sup(*b, med) == 1)
		{
			while ((*b) && (*b)->place >= med)
			{
				(*b)->push = 1;
				ft_push(b, a, 1);
			}
			if ((*b) && ft_check_sup(*b, med) == 1)
				ft_rotate(b, 2);
		}
	}
	ft_push_sup_in_a(a, b, data);
}
