/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_library_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:39:30 by akocoglu          #+#    #+#             */
/*   Updated: 2022/06/28 19:01:40 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_sb(t_s *s)
{
	int	temp;

	if (s->size_b <= 1)
		return ;
	temp = s->b[s->size_b - 1];
	s->b[s->size_b - 1] = s->b[s->size_b - 2];
	s->b[s->size_b - 2] = temp;
}

void	f_pb(t_s *s)
{
	int	*temp;
	int	i;
	int	j;

	i = s->size_b - 1;
	j = s->size_b - 1;
	if ((s->size_a_ar + 1) < 1)
		return ;
	temp = (int *)malloc(sizeof(int) * (s->size_b));
	while (i >= 0)
	{
		temp[i] = s->b[i];
		i--;
	}
	free(s->b);
	s->b = (int *)malloc(sizeof(int) * (s->size_b + 1));
	s->b[s->size_b] = s->a[s->size_a_ar];
	while (j >= 0)
	{
		s->b[j] = temp[j];
		j--;
	}
	free(temp);
	s->size_b++;
	change_s_a(s);
}

void	f_rb(t_s *s)
{
	int	temp;
	int	i;
	int	j;

	i = s->size_b - 1;
	j = 1;
	temp = s->b[s->size_b - 1];
	while (i > 0)
	{
		s->b[i] = s->b[s->size_b - 1 - j];
		i--;
		j++;
	}
	s->b[0] = temp;
}

void	f_rr(t_s *s)
{
	f_ra(s);
	f_rb(s);
}

void	f_rrb(t_s *s)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	temp = s->b[0];
	while (i < s->size_b - 1)
	{
		s->b[0 + j] = s->b[j + 1];
		i++;
		j++;
	}
	s->b[s->size_b - 1] = temp;
}
