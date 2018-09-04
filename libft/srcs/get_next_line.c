/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:15:05 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/19 16:48:25 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl		*ft_createlem(const int fd)
{
	t_gnl			*new;

	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	new->next = NULL;
	new->file = fd;
	new->index = 0;
	return (new);
}

static int			ft_readfile(t_gnl *lst, const int fd)
{
	char			*temp;
	int				file;
	char			*to_free;

	if (!(temp = (char *)ft_memalloc((BUFF_SIZE_GNL + 1))))
		return (-1);
	if (!(lst->p_line = (char *)ft_memalloc(1)))
		return (-1);
	while ((file = read(fd, temp, BUFF_SIZE_GNL)) > 0)
	{
		to_free = lst->p_line;
		if (!(lst->p_line = ft_strjoin(lst->p_line, temp)))
			return (-1);
		ft_bzero(temp, (BUFF_SIZE_GNL + 1));
		free(to_free);
	}
	free(temp);
	return (0);
}

static void			ft_del_link(t_gnl *temp, t_gnl *begin_list)
{
	while (begin_list->next && begin_list->next != temp)
		begin_list = begin_list->next;
	begin_list->next = temp->next;
	free(temp->p_line);
	temp->p_line = NULL;
	free(temp);
	temp = NULL;
}

static int			ft_cpy(t_gnl *temp, char **line, t_gnl *begin_list)
{
	int				nb_cara;
	int				help;

	help = 0;
	nb_cara = temp->index;
	while (temp->p_line[nb_cara] != '\n' && temp->p_line[nb_cara])
	{
		help++;
		nb_cara++;
	}
	if (!(line[0] = (char *)malloc(sizeof(char) * (help + 1))))
		return (-1);
	ft_bzero(line[0], (help + 1));
	if (temp->p_line[temp->index] == '\0')
	{
		ft_del_link(temp, begin_list);
		return (0);
	}
	help = 0;
	while (temp->p_line[temp->index] != '\n' && temp->p_line[temp->index])
		line[0][help++] = temp->p_line[temp->index++];
	if (temp->p_line[temp->index] == '\n')
		temp->index++;
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*begin_list;
	t_gnl			*temp;

	if (!line || BUFF_SIZE_GNL < 1 || read(fd, 0, 0) < 0)
		return (-1);
	if (!begin_list)
	{
		if ((!(begin_list = ft_createlem(fd))) ||
			((ft_readfile(begin_list, fd)) < 0))
			return (-1);
	}
	temp = begin_list;
	while (temp->file != fd && temp->next != NULL)
		temp = temp->next;
	if (temp->file != fd)
	{
		if (!(temp->next = ft_createlem(fd)))
			return (-1);
		temp = temp->next;
		if ((ft_readfile(temp, fd)) < 0)
			return (-1);
	}
	return (ft_cpy(temp, line, begin_list));
}
