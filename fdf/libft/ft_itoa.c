/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 22:11:08 by anurgali          #+#    #+#             */
/*   Updated: 2019/03/08 22:19:54 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			find_length(int i)
{
	int				count;

	count = 0;
	if (i == 0)
		return (1);
	while (i)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

char				*ft_itoa(int i)
{
	char			*result;
	int				length;

	length = find_length(i);
	if (i == -2147483648)
		return (ft_strdup("-2147483648"));
	if (i < 0)
		length++;
	if (!(result = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	if (i < 0)
	{
		result[0] = '-';
		i = i * (-1);
	}
	result[length--] = '\0';
	while (i > 9)
	{
		result[length] = '0' + (i % 10);
		i = i / 10;
		length--;
	}
	if (i <= 9 && i >= 0)
		result[length] = i + '0';
	return (result);
}
