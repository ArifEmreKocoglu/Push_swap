/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_second.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:44:49 by akocoglu          #+#    #+#             */
/*   Updated: 2022/07/01 16:40:36 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_sort_continue(t_s *s)
{
	f_pb(s);
	ft_printf("pb\n");
	four_sort(s);
	f_pa(s);
	ft_printf("pa\n");
}

void	five_sort(t_s *s)
{
	if (find_min(s) == s->size_a_ar - 1)
	{
		f_sa(s);
		ft_printf("sa\n");
	}
	else if (find_min(s) == s->size_a_ar - 2)
	{
		f_ra(s);
		f_ra(s);
		ft_printf("ra\nra\n");
	}
	else if (find_min(s) == s->size_a_ar - 3)
	{
		f_rra(s);
		f_rra(s);
		ft_printf("rra\nrra\n");
	}
	else if (find_min(s) == s->size_a_ar - 4)
	{
		f_rra(s);
		ft_printf("rra\n");
	}
	five_sort_continue(s);
}

void	f_rrr(t_s *s)
{
	f_rra(s);
	f_rrb(s);
}

void	error_two(void)
{
	ft_printf("ERROR\n");
	exit(1);
}
