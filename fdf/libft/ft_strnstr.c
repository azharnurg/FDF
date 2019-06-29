/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:18:06 by anurgali          #+#    #+#             */
/*   Updated: 2019/03/07 17:53:46 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *hay, const char *need, size_t len)
{
	char	*s1;
	char	*s2;
	char	*start;
	size_t	i;

	s1 = (char *)hay;
	if (!(*hay || *need))
		return ((char *)hay);
	while ((*s1 && len > 0) || (len == 0 && *need == '\0'))
	{
		start = s1;
		s2 = (char*)need;
		i = len;
		while (*s1 && *s2 && *s1 == *s2 && i > 0)
		{
			s1++;
			s2++;
			i--;
		}
		if (*s2 == '\0')
			return (start);
		len--;
		s1 = start + 1;
	}
	return (NULL);
}
