/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:14:09 by akocoglu          #+#    #+#             */
/*   Updated: 2022/07/01 16:46:59 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_s
{
	int	*a;
	int	*b;
	int	arg_c;
	int	size_b;
	int	size_a;
	int	size_a_ar;
	int	counter;
	int	j;
	int	k;
	int	t;
	int	n;
	int	size_ar;
}	t_s;

int		main(int argc, char **argv);

int		stack_count(t_s *s, char **argv, int argc);
int		isnumber(char *str);
int		split_count(char *s, char c);
int		find_always_min_val(t_s *s, int j, int *new_min);
int		check_array(int *new_min, int i, int j);
int		find_max_val(t_s *s);
int		check_order(t_s *s);
int		find_min(t_s *s);

void	three_sort(t_s *s);
void	three_sort_cont1(t_s *s);
void	f_rrr(t_s *s);
void	f_rrb(t_s *s);
void	f_rra(t_s *s);
void	f_rr(t_s *s);
void	f_rb(t_s *s);
void	f_ra(t_s *s);
void	f_pa(t_s *s);
void	f_pb(t_s *s);
void	f_ss(t_s *s);
void	f_sb(t_s *s);
void	f_sa(t_s *s);
void	change_s_b(t_s *s);
void	change_s_a(t_s *s);
void	small_sort(t_s *s);
void	five_sort(t_s *s);
void	five_sort_continue(t_s *s);
void	four_sort(t_s *s);
void	big_sort(t_s *s);
void	radix_sort(t_s *s);
void	radix_sort_continue(t_s *s, int size_b, int m, int k);
void	add_val(t_s *s, int m);
void	fill_stack_a(t_s *s, char **argv, int argc_count, char **str);
void	free_str(char **str);
int		check_stack_two(t_s *s);
int		check(char **argv, int argc);
void	error(int argc);
void	error_two(void);

#endif
