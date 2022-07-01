/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:17:09 by akocoglu          #+#    #+#             */
/*   Updated: 2022/07/01 17:03:52 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_s *s)
{
	int	min_index;
	int	j;
	int	*new_min;

	s->size_ar = s->size_a_ar + 1;
	min_index = 0;
	j = 0;
	new_min = (int *)malloc(sizeof(int) * (s->size_a_ar + 1));
	while (j <= s->size_a_ar)
	{
		min_index = find_always_min_val(s, j, new_min);
		new_min[j] = min_index;
		s->a[min_index] = j;
		j++;
	}
	free(new_min);
	radix_sort(s);
}

void	fill_stack_a(t_s *s, char **argv, int argc_count, char **str)
{
	while (s->t <= s->n && argc_count >= 0)
	{
		if (isnumber(argv[s->t]))
		{
			s->a[argc_count] = ft_atoi(argv[s->t]);
			argc_count--;
		}
		else
		{
			s->j = split_count(argv[s->t], ' ') - 1;
			str = ft_split(argv[s->t], ' ');
			while (s->j >= 0 && argc_count >= 0)
			{
				s->a[argc_count] = ft_atoi(str[s->k]);
				s->k++;
				s->j--;
				argc_count--;
			}
			free_str(str);
			s->j = 0;
			s->k = 0;
		}
		s->t++;
	}
}

void	add_val(t_s *s, int m)
{
	s->size_a_ar = m - 1;
	s->n = m;
	s->j = 0;
	s->k = 0;
	s->t = 1;
	s->size_b = 0;
	s->counter = 0;
}

int	check_stack(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i <= argc - 1)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
			{
				if (argv[i][j + 1] == '\0')
					break ;
				j++;
			}
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
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

int	main(int argc, char **argv)
{
	t_s		*s;
	int		m;
	int		argc_count;
	char	**str;

	str = NULL;
	s = malloc(sizeof(t_s));
	error(argc);
	m = stack_count(s, argv, argc);
	argc_count = m - 1;
	add_val(s, m);
	fill_stack_a(s, argv, argc_count, str);
	if (!check_stack(argv, argc) || !check_stack_two(s) || !check(argv, argc))
		return (0);
	if (check_order(s) == 0 && (s->size_a_ar + 1) >= 2)
	{
		if ((s->size_a_ar + 1) <= 5)
			small_sort(s);
		else
			big_sort(s);
	}
	return (0);
}

// 				   int x = s->size_a_ar;
//    int b = s->size_b - 1;

//     while (x >= 0)

//     {
//         ft_printf("A-%d \n", s->a[x]);
//         x--;
//     }
//     while (b >= 0)
//     {
//         ft_printf("B-%d \n", s->b[b]);
//         b--;
//     }