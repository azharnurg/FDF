/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 23:52:00 by anurgali          #+#    #+#             */
/*   Updated: 2019/03/09 15:29:13 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cdst;
	char		*csrc;
	size_t		i;

	cdst = (char *)dst;
	csrc = (char *)src;
	i = 0;
	if (cdst < csrc)
	{
		while (i < len)
		{
			*(cdst + i) = *(csrc + i);
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			cdst[len] = csrc[len];
	}
	return (dst);
}
