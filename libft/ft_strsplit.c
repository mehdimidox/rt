/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:43:35 by hbouchak          #+#    #+#             */
/*   Updated: 2019/04/07 13:44:06 by hbouchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i[3];
	char	**new_s;

	i[0] = 0;
	i[2] = 0;
	if (s == NULL)
		return (NULL);
	if (!(new_s = (char **)malloc((ft_nbr_words(s, c) + 1) * sizeof(char*))))
		return (NULL);
	while (s[i[2]])
	{
		while (s[i[2]] == c && s[i[2]])
			i[2]++;
		if (s[i[2]])
		{
			i[1] = 0;
			if (!(new_s[i[0]] = (char *)malloc(ft_word_size(s, c, i[2]) + 1)))
				return (NULL);
			while (s[i[2]] != c && s[i[2]])
				new_s[i[0]][i[1]++] = s[i[2]++];
			new_s[i[0]++][i[1]] = '\0';
		}
	}
	new_s[i[0]] = 0;
	return (new_s);
}