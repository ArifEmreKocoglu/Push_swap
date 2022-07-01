/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_third.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:46:25 by akocoglu          #+#    #+#             */
/*   Updated: 2022/07/01 15:41:19 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_val(t_s *s)
{
	int	i;
	int	max;
	int	max_index;

	max_index = 0;
	i = s->size_a_ar;
	max = s->a[i];
	while (i >= 0)
	{
		if (max <= s->a[i])
		{
			max = s->a[i];
			max_index = i;
		}
		i--;
	}
	return (max_index);
}

int	check_array(int *new_min, int i, int j)
{
	j = j - 1;
	while (j >= 0)
	{
		if (i == new_min[j])
		{
			return (0);
		}
		j--;
	}
	return (1);
}

int	find_always_min_val(t_s *s, int j, int *new_min)
{
	int	i;
	int	t_min_index;
	int	min;

	i = s->size_a_ar;
	t_min_index = 0;
	min = s->a[find_max_val(s)];
	while (i >= 0)
	{
		if (min >= s->a[i] && check_array(new_min, i, j))
		{
			min = s->a[i];
			t_min_index = i;
		}
		i--;
	}
	return (t_min_index);
}

void	radix_sort_continue(t_s *s, int size_b, int m, int k)
{
	while (m++ < s->size_ar)
	{
		if (((s->a[s->size_a_ar] >> k) & 1) == 1)
		{
			f_ra(s);
			ft_printf("ra\n");
		}
		else
		{
			f_pb(s);
			ft_printf("pb\n");
		}
	}
	size_b = s->size_b;
	while (size_b > 0)
	{
		f_pa(s);
		ft_printf("pa\n");
		size_b--;
	}
}

void	radix_sort(t_s *s)
{
	int	k;
	int	m;
	int	size_b;
	int	max_num;
	int	max_bit;

	k = 0;
	m = 0;
	max_num = s->a[find_max_val(s)];
	max_bit = 0;
	size_b = 0;
	while ((max_num >> max_bit) != 0)
		max_bit++;
	while (k <= (max_bit - 1))
	{
		m = 0;
		radix_sort_continue(s, size_b, m, k);
		k++;
	}
}
