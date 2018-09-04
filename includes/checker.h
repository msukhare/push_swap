/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 08:49:59 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/18 13:29:02 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"

typedef struct		s_pile
{
	int				val;
	int				place;
	int				push;
	struct s_pile	*next;
}					t_pile;
t_pile				*ft_creat_pile(char **av);
int					ft_checkargv(char **av);
t_pile				*ft_creatlink(long elem, char *str, int i);
t_pile				*ft_dellist(t_pile *begin_list);
int					ft_checkdig(char *str);
int					ft_check_double(t_pile *begin_list);
int					ft_exec_cmd(t_pile **pile_a, t_pile **pile_b, char *cmd);
int					ft_lenlst(t_pile *begin_list);
int					ft_check_tri(t_pile *pile);
void				ft_swap_in_pile(t_pile **pile, int act);
void				ft_push(t_pile **to_push, t_pile **in, int act);
void				ft_rotate(t_pile **pile, int act);
void				ft_rev_rot(t_pile **pile, int act);
#endif
