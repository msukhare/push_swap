/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:33:38 by msukhare          #+#    #+#             */
/*   Updated: 2018/04/18 14:50:36 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "checker.h"

typedef struct		s_med
{
	int				val;
	struct s_med	*next;
}					t_med;
typedef struct		s_data
{
	int				pushed;
	int				max_ele;
	t_med			*med;
}					t_data;
void				ft_tri_quick(t_pile **a, t_pile **b, t_data *data);
void				ft_push_inf_in_b(t_pile **a, t_pile **b, t_data *data);
void				ft_insertion_sort(t_pile **a, t_pile **b);
void				ft_push_sup_in_a(t_pile **a, t_pile **b, t_data *data);
void				ft_delmeds(t_med *med);
void				ft_creat_med(int med, t_data *data, t_pile **a, t_pile **b);
void				ft_sort_tree(t_pile **a, t_pile **b);
void				ft_sort_six(t_pile **a, t_pile **b, t_data *data);
int					ft_check_side(t_pile *start, t_pile *end);
#endif
