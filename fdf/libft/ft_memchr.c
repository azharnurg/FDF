/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 00:37:50 by anurgali          #+#    #+#             */
/*   Updated: 2019/03/08 02:29:56 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		fc;
	unsigned char		*cs;
	size_t				i;

	fc = (unsigned char)c;
	cs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == fc)
		{
			return ((void *)&cs[i]);
		}
		i++;
	}
	return (NULL);
}
