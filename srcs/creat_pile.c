/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 09:26:15 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/18 14:40:24 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		ft_add_place(t_pile *begin_list)
{
	int			pl;
	t_pile		*tmp;
	t_pile		*ind;

	ind = begin_list;
	while (ind)
	{
		tmp = begin_list;
		pl = 0;
		while (tmp)
		{
			if (ind->val > tmp->val)
				pl++;
			tmp = tmp->next;
		}
		ind->place = pl;
		ind = ind->next;
	}
}

static void		ft_mv_in_str(char *str, int *i)
{
	if (str[*i] && (str[*i] == '+' || str[*i] == '-'))
		(*i)++;
	while (str[*i] && ((str[*i] >= '0' && str[*i] <= '9')))
		(*i)++;
	if (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
		(*i)++;
}

static t_pile	*ft_createlems(char *str)
{
	int			i;
	t_pile		*to_ret;
	t_pile		*tmp;

	i = 0;
	to_ret = NULL;
	while (str[i])
	{
		if (!to_ret && str[i] != ' ' && str[i] != '\t')
		{
			if (!(to_ret = ft_creatlink(ft_atol((str + i)), str, i)))
				return (NULL);
			tmp = to_ret;
		}
		else if (str[i] != ' ' && str[i] != '\t')
		{
			if (!(tmp->next = ft_creatlink(ft_atol((str + i)), str, i)))
				return (ft_dellist(to_ret));
			tmp = tmp->next;
		}
		ft_mv_in_str(str, &i);
	}
	return (to_ret);
}

static t_pile	*ft_get_pile(char **argv)
{
	int			i;
	t_pile		*begin_list;
	t_pile		*tmp;

	i = 1;
	begin_list = NULL;
	tmp = NULL;
	while (argv[i])
	{
		if (!begin_list && argv[i][0] != '\0' && ft_checkdig(argv[i]))
		{
			if (!(begin_list = ft_createlems(argv[i])))
				return (NULL);
			tmp = begin_list;
		}
		else if (argv[i][0] != '\0' && ft_checkdig(argv[i]))
		{
			if (!(tmp->next = ft_createlems(argv[i])))
				return (ft_dellist(begin_list));
		}
		while (tmp && tmp->next)
			tmp = tmp->next;
		i++;
	}
	return (begin_list);
}

t_pile			*ft_creat_pile(char **argv)
{
	t_pile		*to_ret;

	to_ret = NULL;
	if (ft_checkargv(argv) < 0)
		return (NULL);
	if (!(to_ret = ft_get_pile(argv)))
		return (NULL);
	if (ft_check_double(to_ret) < 0)
		return (ft_dellist(to_ret));
	ft_add_place(to_ret);
	return (to_ret);
}
