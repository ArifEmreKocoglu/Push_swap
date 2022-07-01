/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:11:08 by akocoglu          #+#    #+#             */
/*   Updated: 2022/06/29 13:31:56 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split_count(const char *s, char c)
{
	size_t		i;
	int			click;

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

char	*word_create(char const *s, int size, int i)
{
	char	*str;
	int		m;
	int		j;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	m = 0;
	j = i - size;
	while (size)
	{
		str[m++] = s[j++];
	size--;
	}
	str[m] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	size_t		i;
	size_t		j;
	size_t		count;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (split_count(s, c) + 1));
	if (!split)
		return (NULL);
	i = -1;
	j = 0;
	count = 0;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && s[i] != '\0' && count >= 0)
			count++;
		else if ((s[i] == c || s[i] == '\0') && count > 0)
		{
			split[j++] = word_create(s, count, i);
			count = 0;
		}
	}
	split[j] = NULL;
	return (split);
}

//  int main(void)
//  {
//      int i;
//      char s[]= "  tripouille  42  ";
//      printf("%s\n",s);
//      char c = ' ';
//      char **k = ft_split(s, c);
// 	 system("leaks a.out");
//      return (0);
//  }