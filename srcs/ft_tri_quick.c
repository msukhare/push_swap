/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_quick.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:03:28 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/13 17:02:52 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check(t_pile *a)
{
	t_pile	*tmp;

	tmp = a;
	a = a->next;
	while (a && a->push == 1)
	{
		if (tmp->place > a->place)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	ft_unpushed(t_pile *a)
{
	while (a && a->push == 1)
	{
		a->push = 0;
		a = a->next;
	}
}

void		ft_tri_quick(t_pile **a, t_pile **b, t_data *data)
{
	if (ft_check_tri(*a) == 1 && !(*b))
		return ;
	if ((*a) && (*a)->place == (data->max_ele - 1) && (*a)->next->push == 1)
	{
		ft_rotate(a, 1);
		return ;
	}
	ft_push_inf_in_b(a, b, data);
	ft_push_sup_in_a(a, b, data);
	while ((*a) && data->max_ele > (data->pushed + 1) && (*a)->push == 1)
	{
		if ((*a)->next && (*a)->place > (*a)->next->place)
			ft_swap_in_pile(a, 1);
		if (ft_check(*a) == 0)
		{
			ft_rotate(a, 1);
			data->pushed++;
		}
		else
			break ;
	}
	ft_unpushed(*a);
	ft_tri_quick(a, b, data);
}
