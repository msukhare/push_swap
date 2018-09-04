/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 08:55:52 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/18 15:23:04 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_read_cmd(t_pile **pile_a, t_pile **pile_b)
{
	char	*cmd;

	cmd = NULL;
	while (get_next_line(0, &cmd) > 0)
	{
		if ((ft_exec_cmd(pile_a, pile_b, cmd)) < 0)
		{
			free(cmd);
			*pile_a = ft_dellist(*pile_a);
			*pile_b = ft_dellist(*pile_b);
			return (-1);
		}
		free(cmd);
	}
	if (ft_check_tri(*pile_a) > 0 && !(*pile_b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	*pile_a = ft_dellist(*pile_a);
	*pile_b = ft_dellist(*pile_b);
	free(cmd);
	return (0);
}

int			main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	if (argc <= 1)
		exit(0);
	if (!(pile_a = ft_creat_pile(argv)))
		exit(0);
	if ((ft_read_cmd(&pile_a, &pile_b)) < 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	return (0);
}
