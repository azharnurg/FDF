/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 20:45:21 by anurgali          #+#    #+#             */
/*   Updated: 2019/03/08 02:28:55 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		first;
	int		last;
	int		len;

	if (!s)
		return (NULL);
	first = 0;
	while (s[first] != '\0'
			&& (s[first] == ' ' || s[first] == '\n' || s[first] == '\t'))
		first++;
	last = ft_strlen((char *)s);
	while (first < last && (s[last - 1] == ' ' \
				|| s[last - 1] == '\n' || s[last - 1] == '\t'))
		last--;
	if (first == last)
		return (ft_strnew(1));
	len = last - first;
	return (ft_strsub((char *)s, first, len));
}
