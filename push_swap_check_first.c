/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_first.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:48:06 by akocoglu          #+#    #+#             */
/*   Updated: 2022/07/01 16:58:50 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_s *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= s->size_a_ar)
	{
		j = i + 1;
		while (j <= s->size_a_ar)
		{
			if (s->a[i] < s->a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	split_count(char *s, char c)
{
	size_t	i;
	int		click;

	i = 0;
	click = 1;
	while (*s)
	{
		if (*s != c && click)
		{
			i++;
			click = 0;
		}
		else if (*s == c)
		click = 1;
		s++;
	}
	return (i);
}

int	isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	stack_count(t_s *s, char **argv, int argc)
{
	int	m;
	int	stabil_size_arg;

	m = 0;
	stabil_size_arg = argc - 1;
	while (stabil_size_arg >= 1)
	{
		if (isnumber(argv[stabil_size_arg]))
			m++;
		else
			m += split_count(argv[stabil_size_arg], ' ');
			stabil_size_arg--;
	}
	s->a = (int *)malloc(sizeof(int) * m);
	s->b = (int *)malloc(sizeof(int) * m);
	return (m);
}

int	check(char **argv, int argc)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (i <= (argc - 1))
	{
		j = 0;
		c = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-')
			{
				c++;
				if (c > 1 || (argv[i][j - 1] > '0' && argv[i][j - 1] < '9'))
					error_two();
			}
			if (argv[i][j] == ' ')
				c = 0;
			j++;
		}
		i++;
	}
	return (1);
}
