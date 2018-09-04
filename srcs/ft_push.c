/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:25:20 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/13 16:49:12 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_push(t_pile **to_push, t_pile **in, int act)
{
	t_pile	*tmp;

	if (!(*to_push))
		return ;
	tmp = *to_push;
	(*to_push) = (*to_push)->next;
	tmp->next = (*in);
	*in = tmp;
	if (act == 1)
		ft_putstr("pa\n");
	else if (act == 2)
		ft_putstr("pb\n");
}
