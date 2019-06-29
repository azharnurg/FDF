/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:58:58 by anurgali          #+#    #+#             */
/*   Updated: 2019/03/11 21:18:54 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*mem;
	int		len;

	len = (int)size;
	if (!(mem = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (len >= 0)
		mem[len--] = '\0';
	return (mem);
}
