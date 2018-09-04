/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 10:54:37 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/13 16:55:04 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_exec2_cmd(t_pile **pile_a, t_pile **pile_b, int act)
{
	if (act == 1)
	{
		ft_swap_in_pile(pile_a, 0);
		ft_swap_in_pile(pile_b, 0);
	}
	else if (act == 2)
	{
		ft_rotate(pile_a, 0);
		ft_rotate(pile_b, 0);
	}
	else if (act == 3)
	{
		ft_rev_rot(pile_a, 0);
		ft_rev_rot(pile_b, 0);
	}
}

int			ft_exec_cmd(t_pile **pile_a, t_pile **pile_b, char *cmd)
{
	if ((ft_strcmp("sa", cmd)) == 0)
		ft_swap_in_pile(pile_a, 0);
	else if ((ft_strcmp("sb", cmd)) == 0)
		ft_swap_in_pile(pile_b, 0);
	else if ((ft_strcmp("ss", cmd)) == 0)
		ft_exec2_cmd(pile_a, pile_b, 1);
	else if ((ft_strcmp("pa", cmd)) == 0)
		ft_push(pile_b, pile_a, 0);
	else if ((ft_strcmp("pb", cmd)) == 0)
		ft_push(pile_a, pile_b, 0);
	else if ((ft_strcmp("ra", cmd)) == 0)
		ft_rotate(pile_a, 0);
	else if ((ft_strcmp("rb", cmd)) == 0)
		ft_rotate(pile_b, 0);
	else if ((ft_strcmp("rr", cmd)) == 0)
		ft_exec2_cmd(pile_a, pile_b, 2);
	else if ((ft_strcmp("rra", cmd)) == 0)
		ft_rev_rot(pile_a, 0);
	else if ((ft_strcmp("rrb", cmd)) == 0)
		ft_rev_rot(pile_b, 0);
	else if ((ft_strcmp("rrr", cmd)) == 0)
		ft_exec2_cmd(pile_a, pile_b, 3);
	else
		return (-1);
	return (0);
}
