/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_first.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:43:09 by akocoglu          #+#    #+#             */
/*   Updated: 2022/07/01 15:40:56 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort_cont1(t_s *s)
{
	int	i;

	i = s->size_a_ar;
	if (s->a[i] < s->a[0] && s->a[i] < s->a[i - 1] && s->a[i - 1] > s->a[0])
	{
		f_sa(s);
		f_ra(s);
		ft_printf("sa\nra\n");
	}
	if (s->a[i] > s->a[i - 1] && s->a[i] > s->a[0] && s->a[i - 1] > s->a[0])
	{
		f_sa(s);
		f_rra(s);
		ft_printf("sa\nrra\n");
	}
}

void	three_sort(t_s *s)
{
	int	i;

	i = s->size_a_ar;
	if (s->a[i] < s->a[0] && s->a[i] < s->a[i - 1] && s->a[i - 1] > s->a[0])
		three_sort_cont1(s);
	if (s->a[i] < s->a[i - 1] && s->a[i] > s->a[0] && s->a[i - 1] > s->a[0])
	{
		f_rra(s);
		ft_printf("rra\n");
	}
	if (s->a[i] > s->a[i - 1] && s->a[i] < s->a[0] && s->a[i - 1] < s->a[0])
	{
		f_sa(s);
		ft_printf("sa\n");
	}
	if (s->a[i] > s->a[i - 1] && s->a[i] > s->a[0] && s->a[i - 1] < s->a[0])
	{
		f_ra(s);
		ft_printf("ra\n");
	}
	if (s->a[i] > s->a[i - 1] && s->a[i] > s->a[0] && s->a[i - 1] > s->a[0])
		three_sort_cont1(s);
}

int	find_min(t_s *s)
{
	int	i;
	int	j;
	int	min;
	int	min_index;

	i = s->size_a_ar;
	j = 0;
	min = s->a[i];
	while (i >= 0)
	{
		if (min >= s->a[i])
		{
			min = s->a[i];
			min_index = i;
		}
		i--;
	}
	return (min_index);
}

void	four_sort(t_s *s)
{
	int	min_index;

	min_index = find_min(s);
	if (min_index == s->size_a_ar - 1)
	{
		f_sa(s);
		ft_printf("sa\n");
	}
	else if (min_index == s->size_a_ar - 2)
	{
		f_rra(s);
		f_rra(s);
		ft_printf("rra\nrra\n");
	}
	else if (min_index == s->size_a_ar - 3)
	{
		f_rra(s);
		ft_printf("rra\n");
	}
	f_pb(s);
	ft_printf("pb\n");
	three_sort(s);
	f_pa(s);
	ft_printf("pa\n");
}

void	small_sort(t_s *s)
{
	if ((s->size_a_ar + 1) == 2)
	{
		f_sa(s);
		ft_printf("sa\n");
	}
	if ((s->size_a_ar + 1) == 3)
		three_sort(s);
	if ((s->size_a_ar + 1) == 4)
		four_sort(s);
	if ((s->size_a_ar + 1) == 5)
		five_sort(s);
}
