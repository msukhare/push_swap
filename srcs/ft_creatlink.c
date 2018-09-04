/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatlink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:48:55 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/18 15:07:51 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_number_to_larg(char *str, int i)
{
	int		nb_numb;

	nb_numb = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		i++;
		nb_numb++;
	}
	if (nb_numb >= 12)
		return (1);
	return (0);
}

t_pile		*ft_creatlink(long elem, char *str, int i)
{
	t_pile	*new;

	if (elem > 2147483647 || elem < -2147483648 || ft_number_to_larg(str, i))
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	if (!(new = (t_pile *)malloc(sizeof(t_pile) * 1)))
	{
		ft_putstr_fd("malloc fail\n", 2);
		return (NULL);
	}
	new->next = NULL;
	new->val = (int)elem;
	new->place = 0;
	new->push = 0;
	return (new);
}
