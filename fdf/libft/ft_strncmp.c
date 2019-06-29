/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:57:38 by anurgali          #+#    #+#             */
/*   Updated: 2019/03/08 02:32:07 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	j = 0;
	while ((str1[i] == str2[j]) && str1[i] != '\0' && n > 1)
	{
		i++;
		j++;
		n--;
	}
	if (str1[i] == str2[i] && i == n)
		return (0);
	return ((unsigned int)(str1[i] - str2[i]));
}
