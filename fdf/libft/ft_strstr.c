/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:54:39 by anurgali          #+#    #+#             */
/*   Updated: 2019/03/11 21:15:00 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;
	char	*start;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			start = (char *)&haystack[i];
			k = i;
			while (needle[j] != '\0' && haystack[i++] == needle[j])
				j++;
			if (needle[j] == '\0')
				return (start);
			else
				i = k;
		}
		i++;
	}
	return (NULL);
}
