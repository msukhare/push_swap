/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:29:36 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/18 15:22:42 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;
	t_data	data;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	if (!(a = ft_creat_pile(argv)))
		exit(-1);
	data.max_ele = ft_lenlst(a);
	data.pushed = 0;
	data.med = NULL;
	if (data.max_ele > 6)
		ft_tri_quick(&a, &b, &data);
	else if (data.max_ele > 3)
		ft_sort_six(&a, &b, &data);
	else
		ft_sort_tree(&a, &b);
	ft_dellist(a);
	ft_delmeds(data.med);
	return (0);
}
