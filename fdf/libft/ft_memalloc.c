/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:16:18 by anurgali          #+#    #+#             */
/*   Updated: 2019/03/11 19:17:49 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *mem;

	mem = (char *)malloc(sizeof(char) * size);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
