/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:12:58 by akocoglu          #+#    #+#             */
/*   Updated: 2022/07/01 16:36:42 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_s_a(t_s *s)
{
	int	*temp_s;
	int	i;
	int	j;
	int	l;

	l = s->size_a_ar + 1;
	i = s->size_a_ar - 1;
	j = s->size_a_ar - 1;
	temp_s = (int *)malloc(sizeof(int) * (s->size_a_ar));
	while (l - 2 >= 0)
	{
		temp_s[i] = s->a[i];
		i--;
		l--;
	}
	free(s->a);
	s->a = (int *)malloc(sizeof(int) * (s->size_a_ar));
	while (j >= 0)
	{
		s->a[j] = temp_s[j];
		j--;
	}
	free(temp_s);
	s->size_a_ar--;
}

void	change_s_b(t_s *s)
{
	int	*temp_s;
	int	i;
	int	j;
	int	l;

	l = s->size_b;
	i = s->size_b - 2;
	j = s->size_b - 2;
	temp_s = (int *)malloc(sizeof(int) * (s->size_b - 1));
	while (l - 2 >= 0)
	{
		temp_s[i] = s->b[i];
		i--;
		l--;
	}
	free(s->b);
	s->b = (int *)malloc(sizeof(int) * (s->size_b - 1));
	while (j >= 0)
	{
		s->b[j] = temp_s[j];
		j--;
	}
	free(temp_s);
	s->size_b--;
}

void	free_str(char **str)
{
	int	k;

	k = 0;
	while (str[k])
		free(str[k++]);
	free(str);
}

int	check_stack_two(t_s *s)
{
	int	i;
	int	j;

	i = 0;
	while (i <= s->size_a_ar)
	{
		j = i + 1;
		while (j <= s->size_a_ar)
		{
			if (s->a[i] == s->a[j])
			{
				ft_printf("ERROR\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	error(int argc)
{
	if (argc < 1)
	{
		ft_printf("ERROR\n");
		exit(1);
	}
}
