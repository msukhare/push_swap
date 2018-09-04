/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:05:04 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/19 11:30:00 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_signe(char *str, int index)
{
	if (!(str[index + 1] >= '0' && str[index + 1] <= '9'))
		return (-1);
	return (0);
}

int			ft_checkargv(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9') && av[i][j] != '+' &&
					av[i][j] != '-' && av[i][j] != ' ' && av[i][j] != '\t')
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			if ((av[i][j] == '+' || av[i][j] == '-') && ft_signe(av[i], j) < 0)
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_checkdig(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int			ft_check_double(t_pile *begin_list)
{
	t_pile	*tmp;

	while (begin_list)
	{
		tmp = begin_list->next;
		while (tmp)
		{
			if (tmp->val == begin_list->val)
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			tmp = tmp->next;
		}
		begin_list = begin_list->next;
	}
	return (0);
}

int			ft_check_tri(t_pile *pile)
{
	if (!pile)
		return (0);
	while (pile->next)
	{
		if (pile->place > pile->next->place)
			return (0);
		pile = pile->next;
	}
	return (1);
}
