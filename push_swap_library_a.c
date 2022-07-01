/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_library_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:36:25 by akocoglu          #+#    #+#             */
/*   Updated: 2022/06/28 19:01:54 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_sa(t_s *s)
{
	int	temp;

	if ((s->size_a_ar + 1) <= 1)
		return ;
	temp = s->a[s->size_a_ar];
	s->a[s->size_a_ar] = s->a[s->size_a_ar - 1];
	s->a[s->size_a_ar - 1] = temp;
}

void	f_ss(t_s *s)
{
	f_sa(s);
	f_sb(s);
}

void	f_pa(t_s *s)
{
	int	*temp;
	int	i;
	int	j;

	i = s->size_a_ar;
	j = s->size_a_ar;
	if (s->size_b < 1)
		return ;
	temp = (int *)malloc(sizeof(int) * (s->size_a_ar + 1));
	while (i >= 0)
	{
		temp[i] = s->a[i];
		i--;
	}
	free(s->a);
	s->a = (int *)malloc(sizeof(int) * (s->size_a_ar + 2));
	s->a[s->size_a_ar + 1] = s->b[s->size_b - 1];
	while (j >= 0)
	{
		s->a[j] = temp[j];
		j--;
	}
	free(temp);
	s->size_a_ar++;
	change_s_b(s);
}

void	f_ra(t_s *s)
{
	int	temp;
	int	i;
	int	j;

	i = s->size_a_ar;
	j = 1;
	temp = s->a[s->size_a_ar];
	while (i > 0)
	{
		s->a[i] = s->a[s->size_a_ar - j];
		i--;
		j++;
	}
	s->a[0] = temp;
}

void	f_rra(t_s *s)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	temp = s->a[0];
	while (i < s->size_a_ar)
	{
		s->a[0 + j] = s->a[j + 1];
		i++;
		j++;
	}
	s->a[s->size_a_ar] = temp;
}
