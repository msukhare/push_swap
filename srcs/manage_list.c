/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:33:14 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/13 16:45:26 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_lenlst(t_pile *begin_list)
{
	int		size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

t_pile		*ft_dellist(t_pile *begin_list)
{
	t_pile	*tmp;

	while (begin_list)
	{
		tmp = begin_list;
		begin_list = begin_list->next;
		free(tmp);
	}
	return (NULL);
}

void		ft_delmeds(t_med *med)
{
	t_med	*tmp;

	while (med)
	{
		tmp = med;
		med = med->next;
		free(tmp);
	}
}

void		ft_creat_med(int med, t_data *data, t_pile **a, t_pile **b)
{
	t_med	*new;

	if (!(new = (t_med*)malloc(sizeof(t_med) * 1)))
	{
		ft_dellist(*a);
		ft_dellist(*b);
		ft_delmeds(data->med);
		ft_putstr_fd("malloc fail\n", 2);
		exit(1);
	}
	new->next = data->med;
	data->med = new;
	data->med->val = med;
}
