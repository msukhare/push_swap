/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_inf_in_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:06:31 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/13 18:01:57 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_check_inf(t_pile *a, int med)
{
	while (a)
	{
		if (a->place < med && a->push == 0)
			return (1);
		a = a->next;
	}
	return (0);
}

static int		ft_get_med_a(t_pile *pile, t_data *data)
{
	int			med;
	t_med		*tmp;

	while (data->med && ft_check_inf(pile, data->med->val) == 0)
	{
		tmp = data->med;
		data->med = data->med->next;
		free(tmp);
	}
	if (data->med)
		med = data->med->val;
	else
		med = ((data->max_ele - data->pushed) / 2) + data->pushed;
	return (med);
}

void			ft_push_inf_in_b(t_pile **a, t_pile **b, t_data *data)
{
	int			med;
	int			nb_ra;

	med = ft_get_med_a(*a, data);
	ft_creat_med(med, data, a, b);
	nb_ra = 0;
	while ((*a) && ft_check_inf(*a, med) == 1 && (*a)->push == 0)
	{
		while ((*a) && (*a)->place < med && (*a)->push == 0)
			ft_push(a, b, 2);
		if (ft_check_inf(*a, med) == 1 && (*a)->push == 0)
		{
			ft_rotate(a, 1);
			nb_ra++;
		}
	}
	if (data->pushed > 0)
	{
		while (nb_ra > 0)
		{
			ft_rev_rot(a, 1);
			nb_ra--;
		}
	}
}
