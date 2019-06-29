/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 00:42:06 by anurgali          #+#    #+#             */
/*   Updated: 2019/03/16 02:28:47 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_strsplit(char const *s, char c)
{
	char			**split;
	size_t			i;
	size_t			j;
	int				k;

	if (!(split = (char **)malloc(sizeof(char *) * (ft_wdcount(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (i < ft_wdcount(s, c))
	{
		while (s[k] != '\0' && s[k] == c)
			k++;
		if (s[k] != '\0')
		{
			j = 0;
			split[i] = (char *)malloc(sizeof(char) * (ft_wdl(&s[k], c) + 1));
			while (s[k] != '\0' && s[k] != c)
				split[i][j++] = s[k++];
			split[i][j] = '\0';
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}
