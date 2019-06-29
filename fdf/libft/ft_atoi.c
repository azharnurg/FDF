/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:29:12 by anurgali          #+#    #+#             */
/*   Updated: 2019/02/28 21:40:59 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	int				sign;
	int				result;
	unsigned char	*s;

	s = (unsigned char *)str;
	result = 0;
	sign = 1;
	if (*s == 27)
		return (0);
	while (*s == 32 || *s == '\t' || *s == '\n' || *s == '\v' || \
		*s == '\f' || *s == '\r')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = (result * 10) + (*s - '0');
		s++;
	}
	return (sign * result);
}
