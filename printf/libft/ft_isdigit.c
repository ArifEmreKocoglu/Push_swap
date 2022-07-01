/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:54:43 by akocoglu          #+#    #+#             */
/*   Updated: 2022/06/25 14:51:54 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int k)
{
	if ((k >= '0') && (k <= '9'))
	{
		return (1);
	}
	return (0);
}

// int main(void)
// {
//     int a = ft_isdigit(9);
// 		printf("%d",a);
//     return (0);
// }